#include "Menu.h"
#include <iostream>

using namespace std ;

Menu::Menu(){

    _cantidadOpciones = 3 ;
}

void Menu::mostrar(){

    int opcion ;

    do {

        opcion = seleccionarOpciones() ;

        ejecutarOpcion(opcion) ;

    } while (opcion != 0) ;
}

void Menu::mostrarOpciones(){ // CORRECCIÓN: Ámbito correcto: Menu::

     cout << "--- MENU GENERICO --------------" << endl ;
     cout << "1 - Iniciar" << endl ;
     cout << "------------------------------" << endl ;
     cout << "0 - Salir " << endl ;
     cout << "------------------------------" << endl ;
}

int Menu::seleccionarOpciones(){

    int opcion ;

    mostrarOpciones() ;

    cout << "Opcion: " ;

    cin >> opcion  ;

    while (opcion < 0 || opcion > _cantidadOpciones){

        cout << "Opcion incorrecta" << endl ;

        cout << "Vuelva a ingresar una opcion valida:" << endl ;

        cin >> opcion ;

    }

    return opcion ;
}

void Menu::ejecutarOpcion(int opcion){

    switch(opcion){

    case 1:

        system("cls") ;

        break ;


    }
}

