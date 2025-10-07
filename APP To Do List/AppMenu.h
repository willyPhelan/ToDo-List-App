#pragma once
#include "Menu.h"
#include "TareaMenu.h"
#include "PersonalMenu.h"
#include "ReporteMenu.h"


class AppMenu: public Menu{

  private:

        int _cantidadOpciones ;


    protected:

        TareaMenu  _tareaMenu ;

        PersonalMenu _personalMenu ;

        ReporteMenu _reporteMenu ;

        //  metodos para el menu, que estan en protected por si los deseo heredar en otras clases



        void ejecutarOpcion(int opcion) ;

    public:

        AppMenu() ; // constructor

        void mostrarOpciones() ;
        } ;
