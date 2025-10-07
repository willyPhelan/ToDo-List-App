#include "Personal.h"
#include <cstring>
#include <iostream>

using namespace std ;

    Personal::Personal(): _id(-1), _nombre{} {} ;


    Personal::Personal(int id, std::string nombre){

        setID(id) ;

        setNombre(nombre) ;

        } ;



    void Personal::setID(int id){

    _id = id ; }



    int Personal::getID() const {

    return _id ;

    }



    void Personal::setNombre(string nombre){


    strncpy(_nombre, nombre.c_str(), 99) ; }


    std::string Personal::getNombre() const {

    return string(_nombre) ;

    } ;


    void Personal::setEliminado(bool estado){

    _eliminado = estado ; }
