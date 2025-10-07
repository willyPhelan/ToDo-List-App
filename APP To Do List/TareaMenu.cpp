#include "TareaMenu.h"
#include "TareaArchivo.h"
#include <iostream>

using namespace std ;

TareaMenu::TareaMenu(){

    _cantidadOpciones = 6 ; } ;



void TareaMenu::mostrarOpciones(){

     cout << "--- MENU TAREAS --------------" << endl ;
     cout << "1 - Crear tarea " << endl ;
     cout << "2 - Mostrar tarea " << endl ;
     cout << "3 - Eliminar tarea " << endl ;
     cout << "4 - Marcar tarea " << endl ;
     cout << "5 - Mostrar tareas pendientes " << endl ;
     cout << "6 - Ordenar tareas alfabeticamente " << endl ;
     cout << "------------------------------" << endl ;
     cout << "0 - Salir " << endl ;
     cout << "------------------------------" << endl ;

} ;

// Agrega esta definici�n, que llama al m�todo de la clase base.
void TareaMenu::mostrar(){

    // Llamamos al m�todo 'mostrar()' de la clase base 'Menu'.
    // Esto asegura que el enlazador encuentre la referencia y,
    // por herencia, ejecutar� la l�gica correcta (incluyendo tu TareaMenu::mostrarOpciones()).
    Menu::mostrar();
}



void TareaMenu::ejecutarOpcion(int opcion){

    switch(opcion) {

    case 1:

        system ("cls") ;

        _tareaManager.cargarTarea() ; // el obj _tareaManager lo cree en le TareaMenu.h, el obj viene de OTRA clase (composicion) y puedo usar todos los metodos definidos por su clase

        cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;


    break ;

    case 2:

        system ("cls") ;

        _tareaManager.mostrarTareas() ;

        cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;

    break ;

    case 3:

        system ("cls") ;

        _tareaManager.eliminarTarea() ;

        cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;

    break ;

    case 4:

        system ("cls") ;

        _tareaManager.marcarTarea() ;

        cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;

    break ;

    case 5:

        system ("cls") ;

        _tareaManager.mostrarTareasFaltantes() ;

        cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;

    case 6:

        system ("cls") ;

        _tareaManager.mostrarOrdenado() ;

        cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;

    break ;




    }
} ;
