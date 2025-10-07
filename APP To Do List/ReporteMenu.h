#pragma once
#include "ReporteManager.h"
#include "Menu.h"

class ReporteMenu: public Menu {

    protected:

        ReporteManager _reporteManager ;

        //  metodos para el menu, que estan en protected por si los deseo heredar en otras clases

        void mostrarOpciones();

        void ejecutarOpcion(int opcion) ;





    public:

        ReporteMenu() ; // constructor



};
