#include "ReporteMenu.h"
#include "TareaArchivo.h"
#include "Utils.h"
#include <iostream>

using namespace std ;

void::ReporteManager::tareasAsignadasPersonal(){

// por cada personal muestro las tareas asignadas

Personal *vPersonal ;

int cantidadPersonal ;

cantidadPersonal = _repoPersonal.getCantidadRegistros() ;

vPersonal = new Personal[cantidadPersonal] ;

_repoPersonal.leerTodos(vPersonal, cantidadPersonal) ;


for (int i = 0 ; i < cantidadPersonal ; i++ ) {

  //  if(vPersonal[i].getEliminado()){ continue ; }


    cout << "Nombre: " << vPersonal[i].getNombre() << endl ;

    cout << "---------------------------------" << endl ;

    int cantidadTareas = _repoTareas.getCantidadRegistros() ;

    int cantidad = 0 ;

    for(int j = 0 ; j < cantidadTareas ; j++){


        Tarea tarea = _repoTareas.leer(j) ;

        if(tarea.getEliminado()){ continue ; }


        if(tarea.getIDPersonal() == vPersonal[i].getID()){

            cantidad++ ;
        }
    }

    cout << "Cantidad de tareas asignadas " << cantidad << endl ;

}

 cout << "---------------------------------" << endl ;

 delete [] vPersonal ;

}

int ReporteManager::cantidadTareasTerminadas(int id){

     int cant=0 ;

     int cantidadTareas = _repoTareas.getCantidadRegistros() ;

    for(int j = 0 ; j < cantidadTareas ; j++){

        Tarea tarea = _repoTareas.leer(j) ;

        if(tarea.getEliminado()){ continue ; }

        if(tarea.getIDPersonal() == id && tarea.getEstado() == true ){

            cant++ ;
        }
    }

return cant ;

} ;

void ReporteManager::personalMayorTareasTerminadas(){

Personal *vPersonal ;

int cantidadPersonal, *vCantidadTerminados ;


cantidadPersonal = _repoPersonal.getCantidadRegistros() ;

vPersonal = new Personal[cantidadPersonal] ;

vCantidadTerminados = new int [cantidadPersonal] {} ; // array memoria dinamica inicializada en 0

_repoPersonal.leerTodos(vPersonal, cantidadPersonal) ;

for (int i = 0 ; i < cantidadPersonal ; i++ ) {

  vCantidadTerminados[i] = cantidadTareasTerminadas(vPersonal[i].getID()) ; }

int posMax = buscarMaximo(vCantidadTerminados, cantidadPersonal) ;

cout << "Personal con mayor cantidad de tareas terminadas: " << endl ;

cout << "--------------------------------------------------" << endl ;

for(int i = 0 ; i < cantidadPersonal ; i++) {

    if(vCantidadTerminados[i] == vCantidadTerminados[posMax]){

        cout << "Nombre: " << vPersonal[i].getNombre() << endl ;
    }


}

delete [] vPersonal ;

delete [] vCantidadTerminados ;

}





