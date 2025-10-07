#pragma once
#include <string>
#include "Personal.h" // Necesario para definir el tipo de objeto que maneja el archivo

class PersonalArchivo{

    public:
        // Constructor, asume un nombre de archivo por defecto
        PersonalArchivo(std::string nombreArchivo = "personal.dat") ;

        // Guardar registro (al final)
        bool guardar(const Personal &registro) ;

        // Guardar registro (en una posici�n espec�fica, para modificar/baja l�gica)
        bool guardar(int pos, const Personal &registro) ;

        // Funciones de Lectura/B�squeda
        int getCantidadRegistros() ;

        int getNuevoID() ;

        int buscarId(int id) ;

        Personal leer(int pos) ;

        int leerTodos(Personal personal[], int cantidad) ;





    private:

        std::string _nombreArchivo ;
};
