#include <iostream>
#include "TareaManager.h"
#include "Tarea.h"
#include "PersonalManager.h"
#include "Utils.h"
#include "Personal.h"


using namespace std ;


TareaManager::TareaManager(){} ;


void TareaManager::cargarTarea(){

    int id ;

    string descripcion ;

    int idPersonalAsignado = 0;

    Personal personal ;

    int idPersonal, posPersonal=-1;

    id = _repo.getNuevoID() ;

    cout << "Nueva Tarea #" << id << endl ;

    cout << "Ingrese descripcion: " ;

    descripcion = cargarCadena() ;

    do{

    cout << "ID Personal (0 para no asignar personal a la tarea)" << endl ;

    cin >> idPersonal ;

    if(idPersonal != 0){

    posPersonal = _repoPersonal.buscarId(idPersonal) ;

    if(posPersonal == -1) { cout << "El personal no existe! " << endl ;

     }

    } }

    while(posPersonal == -1 && idPersonal != 0) ;

    if(idPersonal == 0) {

        cout << "Sin personal asignado" << endl ;

    } else {

        Personal p ;

        p = _repoPersonal.leer(posPersonal) ;

        cout << "El personal asignado es: " << p.getNombre() << endl ; }


    if(_repo.guardarArchivo(Tarea(id, descripcion, idPersonal, false))) {

       cout << "Tarea guardada con exito" << endl ; }

       else { cout << "Ocurrio un error al cargar la tarea" << endl ; }


    } ;

void TareaManager::mostrarTareas(){

    cout << endl << "Lista de tareas: " << endl ;

    int cantidad = _repo.getCantidadRegistros() ;

    for(int i = 0 ; i < cantidad ; i++ ){

        mostrarTareaLista(_repo.leer(i)) ;

    }

} ;

void TareaManager::mostrarTareasFaltantes(){

    cout << endl << "Lista de tareas pendientes: " << endl ;

    int cantidad = _repo.getCantidadRegistros() ;

    for(int i = 0 ; i < cantidad ; i++ ){

        Tarea reg = _repo.leer(i) ;

        if(!reg.getEstado()) {

            mostrarTareaLista(reg) ;
        }

        mostrarTareaLista(_repo.leer(i)) ;

    }


}

void TareaManager::mostrarTareaLista(const Tarea &tarea) {

        cout << "------------------------------------" << endl ;


        cout << "ID: " << tarea.getID() << endl ;

        cout << "Descripcion: " << tarea.getDescripcion() << endl ;

        cout << "Personal: " ; if(tarea.getIDPersonal() == 0){ cout << "Sin personal asignado" ; } else { int pos = _repoPersonal.buscarId(tarea.getIDPersonal()) ;

        if(pos != -1){

            cout << _repoPersonal.leer(pos).getNombre() ;

        } else { cout << "Personal no encontrado" << endl ; }

        }

        cout << endl ;

        cout << "Estado: " << ( tarea.getEstado() ? "Realizado" : "No realizada" )  ;

        cout << " --> " << (tarea.getEliminado() ? "Eliminada" : "Activo") << endl ; }



void TareaManager::marcarTarea(){

    int id, pos ;

    Tarea tarea ;

    bool estado ;

    cout << "--- Marcar Tarea ------------ " << endl ;

    cout << endl << "Ingrese el Id de la tarea: " << endl ;

    cin >> id ;

    system("cls") ;

     cout << "--- Modificar estado de la tarea ------------ " << endl ;

    cout << "-----------------------------------------------" << endl ;

    pos = _repo.buscarId(id) ;

    if(pos != -1){

         tarea = _repo.leer(pos) ;

    cout << "Tarea a modificar: " << endl ;

    mostrarTareaLista(tarea) ;

    cout << "-----------------------------------------------" << endl ;

    cout << "Ingrese 1 para completar la tarea, 0 para dejar como pendiente: " << endl ;

    cin >> estado ;

    tarea.setEstado(estado) ;

    if(_repo.guardarArchivo(pos, tarea)){

        cout << "-----------------------------" << endl ;

        cout << "Tarea acutalizada" << endl ;

    } else {

    cout << "-----------------------------" << endl ;

    cout << "Ocurrio un error, al actualizar la tarea" << endl ;

    }


    } else { cout << "La tarea con ese ID no existe" << endl ; }



}



void TareaManager::eliminarTarea(){

    int id, pos ;

    Tarea tarea ;

    char respuesta ;

    bool estado ;

    cout << "--- Eliminar tarea ------------ " << endl ;

    cout << endl << "Ingrese el Id de la tarea: " << endl ;

    cin >> id ;

    system("cls") ;

    cout << "--- Eliminar tarea ----------------------------" << endl ;

    cout << "-----------------------------------------------" << endl ;

    pos = _repo.buscarId(id) ;

    if(pos != -1){

         tarea = _repo.leer(pos) ;

    cout << "Tarea a eliminar: " << endl ;

    mostrarTareaLista(tarea) ;

    cout << "-----------------------------------------------" << endl ;

    cout << "Esta seguro de querer eliminar la tarea? (S/N): " << endl ;

    cin >> respuesta ;

    if(respuesta == 'S' || respuesta == 's' ){


        if(_repo.eliminar(pos)){

    cout << "----------------------------------------------" << endl ;

        cout << "Tarea eliminada" << endl ;

    } else {

    cout << "-----------------------------------------------" << endl ;

    cout << "Ocurrio un error, al eliminar la tarea" << endl ;

    }

    }}
}

void TareaManager::mostrarOrdenado(){

    cout << endl << "Lista de tareas: " << endl ;

    int cantidad = _repo.getCantidadRegistros() ;

    Tarea *tareas ; // puntero para asignacion dinamica

    tareas = new Tarea[cantidad] ; // pido memoria para TODOS objetos en TAREA

   _repo.leerTodas(tareas, cantidad) ;

    // ORDENAMIENTO

    for(int i = 0 ; i < cantidad -1 ; i++) {

        bool intercambio = false ;

        for(int j = 0 ; j < cantidad - i - 1 ; j++){

            if(tareas[j].getDescripcion() > tareas[j+1].getDescripcion()){ //descripcion es un string, por lo que puedo comparar con otro string alfabeticamente

                Tarea aux = tareas[j] ;
                tareas[j] = tareas[j +1] ;
                tareas[j+1] = aux ;

                intercambio = true ;

            }
        }

        if(!intercambio) {  break ; } // con ordenado corto el ciclo si ya se encuentra ordenado
}


        for (int i = 0 ; i < cantidad ; i++) {

            mostrarTareaLista(tareas[i]) ;
        }

        delete [] tareas ;
}
