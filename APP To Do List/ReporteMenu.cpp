#include <iostream>
#include "ReporteMenu.h"

using namespace std ;

ReporteMenu::ReporteMenu(){

    _cantidadOpciones = 3 ; } ;



void ReporteMenu::mostrarOpciones(){

     cout << "MENU REPORTES ---------------------------" << endl ;

     cout << "1 - Tareas asignadas por personal " << endl ;

     cout << "2 - Personal con mas tareas realizadas " << endl ;

     cout  << "-----------------------------------------" << endl << endl ;

     cout << "0 - Volver al menu principal" << endl << endl ; }




void ReporteMenu::ejecutarOpcion(int opcion) {

switch(opcion){

       case 1:

        system("cls");

        cout << "Tareas Asignadas:" << endl ;

        cout << "---------------------------------" << endl ;

        cout << endl ;

        _reporteManager.tareasAsignadasPersonal() ;

        cout << endl ;

        system("pause");

        system("cls");

       break ;

        case 2:

        system("cls");

        _reporteManager.personalMayorTareasTerminadas() ;

        cout << endl ;

        system("pause");

        system("cls");

       break ;



      case 0:

            cout << "Volviendo al menu principal..." << endl;

            break; }

       }





