#pragma once
#include "TareaManager.h"
#include "Menu.h"

class TareaMenu: public Menu {



    protected:

        TareaManager _tareaManager ; // TareaMenu tiene un miembro llamado _tareaManager de tipo TareaManager. -> COMPOSICION

        //  metodos para el menu, que estan en protected por si los deseo heredar en otras clases

        void mostrarOpciones();

        void ejecutarOpcion(int opcion) ;



    public:

        TareaMenu() ; // constructor

        void mostrar() ;

};
