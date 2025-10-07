#pragma once
#include <string>

class Personal {

public:

    Personal() ;
    Personal(int id, std::string nombre) ;

    void setID(int id) ;
    int getID() const ;

    void setNombre(std::string nombre) ;
    std::string getNombre() const ;

    void setEliminado(bool estado);



private:

    int _id ;
    char _nombre[100] ;
    bool _eliminado ;

};
