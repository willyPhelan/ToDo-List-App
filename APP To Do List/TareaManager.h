#pragma once
#include "TareaManager.h"
#include "TareaArchivo.h"
#include "PersonalArchivo.h"

class TareaManager {

    private:

        TareaArchivo _repo ;
        PersonalArchivo _repoPersonal ;

    public:

        TareaManager() ;

        void cargarTarea() ;
        void mostrarTareas() ;
        void mostrarTareasFaltantes() ;
        void marcarTarea() ;
        void eliminarTarea() ;
        void mostrarOrdenado() ;


    protected:

        void mostrarTareaLista(const Tarea &tarea) ;

    };
