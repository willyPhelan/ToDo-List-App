#include "PersonalMenu.h"
#include "TareaArchivo.h"
#include <iostream>

using namespace std ;

PersonalMenu::PersonalMenu(){

    _cantidadOpciones = 4 ; } ;


void PersonalMenu::mostrarOpciones(){

     cout << "--- MENU PERSONAL --------------" << endl ;
     cout << "1 - Crear Personal " << endl ;
     cout << "2 - Mostrar Personal " << endl ;
     cout << "3 - Eliminar Personal " << endl ;
     cout << "4 - Modificar Personal " << endl ;
     cout << "------------------------------" << endl ;
     cout << "0 - Salir " << endl ;
     cout << "------------------------------" << endl ;

} ;



void PersonalMenu::ejecutarOpcion(int opcion){

    switch(opcion) {

    case 1:

        system("cls") ;

        _personalManager.cargar() ;

        system("pause") ;

        system("cls") ;

    break ;

    case 2:

        system("cls") ;

        _personalManager.mostrar() ;

        cout << endl ;

        system("pause") ;

         system("cls") ;

    break ;

    case 3:

        system("cls") ;

        _personalManager.eliminar() ;

        system("pause") ;

         system("cls") ;

    break ;

    case 4:

        system("cls") ;

        _personalManager.modificar() ;

        system("pause") ;

        system("cls") ;

    break ;






    }
} ;
