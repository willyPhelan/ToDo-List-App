#pragma once
#include "PersonalArchivo.h"

class PersonalManager {

    private:

        PersonalArchivo _repo ;

    public:


        PersonalManager() ;

        void cargar() ;
        void mostrar() ;
        void eliminar() ;
        void modificar() ;


};
