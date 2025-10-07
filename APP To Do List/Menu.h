#pragma once

class Menu {

    public:

        Menu() ;

        void mostrar() ;

    protected:

        virtual void mostrarOpciones() ;

        int seleccionarOpciones() ;

        virtual void ejecutarOpcion(int opcion) ;

        int _cantidadOpciones ;

    private:



};
