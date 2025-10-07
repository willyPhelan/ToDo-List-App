#pragma once
#include "TareaManager.h"
#include "PersonalManager.h"
#include "Menu.h"

class PersonalMenu: public Menu {

private:

     PersonalManager _personalManager ;

    protected:

        //  metodos para el menu, que estan en protected por si los deseo heredar en otras clases

        void mostrarOpciones();

        void ejecutarOpcion(int opcion) ;

    public:

        PersonalMenu() ; // constructor



};
