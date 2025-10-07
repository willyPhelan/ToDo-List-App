#include "PersonalManager.h" // NECESARIO: Declara la clase PersonalManager
#include "Personal.h"        // NECESARIO: Declara la clase Personal
#include "PersonalArchivo.h" // NECESARIO: Declara la clase PersonalArchivo
#include "Utils.h"

#include <iostream>

using namespace std ;

void mostrarLista(const Personal &personal){

    cout << "ID: " << personal.getID() ;
    cout << " | Nombre: " << personal.getNombre() << endl ;

}

PersonalManager::PersonalManager(){}



void PersonalManager::cargar(){

    int id ;

    string nombre ;

    id = _repo.getNuevoID() ;

    cout << "Cargar Nuevo Personal" << endl ;

    cout << "ID: " << id << endl ;

    cout << "Ingrese nombre: " ;

    nombre = cargarCadena() ;

    if(_repo.guardar(Personal(id, nombre))) {

        cout << "Se agrego correctamente" << endl ;

    } else {

        cout << "Error al intentar guardar el personal" << endl ;


    }

    }


    void PersonalManager::mostrar(){

    int cantidad = _repo.getCantidadRegistros() ;

    Personal *vPersonal = new Personal[cantidad] ;

    if(vPersonal == nullptr){

        cout << "No se pudo asignar memoria..." << endl ;

        exit(-100) ;
    }

    _repo.leerTodos(vPersonal, cantidad) ;

    for(int i = 0 ; i < cantidad ; i++){ mostrarLista(vPersonal[i]) ; }

    delete[] vPersonal ;


    }

   void PersonalManager::eliminar(){

    int id ;

    int pos ;

    Personal registro ;

    char respuesta ;

    cout << "ELIMINAR REGISTRO DE PERSONAL" << endl ;

    cout << "Ingrese el ID de Personal a eliminar: " ;
    cin >> id ;

    // 1. Buscar la posición del registro

    pos = _repo.buscarId(id) ;

    if (pos >= 0) { // Si se encontró

        // 2. Leer el registro completo desde el archivo

        registro = _repo.leer(pos) ;

        // 3. Mostrar el registro antes de eliminar

        cout << endl << "Registro encontrado:" << endl ;

        mostrarLista(registro) ;

        // 4. Confirmación

        cout << "¿Confirma la eliminacion (S/N)? " ;

        cin >> respuesta ;

        if (respuesta == 'S' || respuesta == 's') {

            // 5. Modificar el estado a ELIMINADO
            registro.setEliminado(true) ;

            // 6. Reescribir el registro en la misma posición (asumiendo que PersonalArchivo tiene bool guardar(int pos, const Personal&))

            if(_repo.guardar(pos, registro)) {

                cout << "Personal ID " << id << " eliminado con exito." << endl ;

            } else {

                cout << "Error al intentar reescribir el registro." << endl ;
            }

        } else {

            cout << "Eliminacion cancelada." << endl ;
        }

    } else {

        cout << "No se encontro Personal con ID: " << id << endl ;
    }
}

void PersonalManager::modificar(){

    int id ;

    int pos ;

    Personal registro ;

    string nuevoNombre ;

    cout << "MODIFICAR REGISTRO PERSONAL" << endl ;

    cout << "Ingrese el ID de Personal a modificar: " ;

    cin >> id ;

    // 1. Buscar la posición del registro

    pos = _repo.buscarId(id) ;

    if (pos >= 0) { // Si se encontró

        // 2. Leer el registro completo desde el archivo

        registro = _repo.leer(pos) ;

        // 3. Mostrar el registro actual

        cout << endl << "Registro actual:" << endl ;

        mostrarLista(registro) ;

        // 4. Solicitar el nuevo nombre

        cout << "Ingrese el NUEVO nombre: " ;

        nuevoNombre = cargarCadena() ; // Usamos la función global

        // 5. Modificar el objeto en memoria

        registro.setNombre(nuevoNombre) ;

        // 6. Reescribir el registro en la misma posición

        if(_repo.guardar(pos, registro)) {

            cout << "Personal ID " << id << " modificado con exito." << endl ;

        } else {

            cout << "Error al intentar reescribir el registro." << endl ;

        }

    } else {

        cout << "No se encontro Personal con ID: " << id << endl ;
    }
}
