#pragma once
#include "TareaArchivo.h"
#include "PersonalArchivo.h"

class ReporteManager {

    private:

        TareaArchivo _repoTareas ;
        PersonalArchivo _repoPersonal ;

    public:

      void tareasAsignadasPersonal() ;
      void personalMayorTareasTerminadas() ;


    protected:

        int cantidadTareasTerminadas(int id) ;

    };
