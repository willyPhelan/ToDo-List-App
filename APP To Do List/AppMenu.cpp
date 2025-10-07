#include "AppMenu.h"
#include "Menu.h"
#include <iostream>

using namespace std ;

AppMenu::AppMenu(){

    _cantidadOpciones = 3 ; }

void AppMenu::mostrarOpciones(){

     cout << "--- MENU PRINCIPAL --------------" << endl ;
     cout << "1 - Tareas " << endl ;
     cout << "2 - Personal" << endl ;
     cout << "3 - Reportes" << endl ;
     cout << "---------------------------------" << endl ;
     cout << "0 - Salir " << endl ;
     cout << "---------------------------------" << endl ;

} ;



void AppMenu::ejecutarOpcion(int opcion){

    switch(opcion) {

    case 1:

        system ("cls") ;

         _tareaMenu.mostrar() ;

        cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;


    break ;

    case 2:

         system ("cls") ;

        _personalMenu.mostrar() ;

             cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;

        break ;

    case 3:

         system ("cls") ;

        _reporteMenu.mostrar() ;

        cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;

        break ;



    }
} ;
