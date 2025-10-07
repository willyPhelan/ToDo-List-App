#include <iostream>
#include <string>
#include "PersonalArchivo.h"
#include "Personal.h"

using namespace std ;


PersonalArchivo::PersonalArchivo(std::string nombreArchivo)

: _nombreArchivo(nombreArchivo) // constructor para asignar el nombre del archivo

{}


// ----------------------------------------------------------------------
// 1. GUARDAR REGISTRO (Al final del archivo, modo "ab")
// ----------------------------------------------------------------------
bool PersonalArchivo::guardar(const Personal &registro){ // Se renombra a 'guardar' para coincidir con PersonalManager.cpp

    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "ab") ;

    if(pFile == nullptr) {

        return false ;
    }

    // fwrite devuelve la cantidad de registros guardados (1 si es exitoso)
    bool result = fwrite(&registro, sizeof(Personal), 1, pFile) ;

    fclose(pFile) ;

    return result ;
}


// ----------------------------------------------------------------------
// 3. LEER REGISTRO (Desde una posición específica)
// ----------------------------------------------------------------------
Personal PersonalArchivo::leer(int pos) {

    Personal registro ;
    // bool result ; // No es necesario, solo verificamos el puntero

    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "rb") ;

    if(pFile == nullptr){

        // En caso de error, marcamos el ID como -1 (asumiendo que Personal tiene un setID)
        registro.setID(-1) ;

        return registro ; }


    // Mueve el puntero
    fseek(pFile, sizeof(Personal) *pos, SEEK_SET) ;

    // Intentamos leer un registro
    fread(&registro, sizeof(Personal), 1, pFile) ;

    fclose(pFile) ;

    return registro ;
}


// ----------------------------------------------------------------------
// 4. LEER TODOS (Carga un vector de registros)
// ----------------------------------------------------------------------
int PersonalArchivo::leerTodos(Personal personal[], int cantidad) {

    // Cambiamos el tipo de retorno de bool a int, ya que fread devuelve la cantidad de elementos leídos
    int leidos ;
    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "rb") ;

    if(pFile == nullptr) {
        return 0 ;
    }

    // Leemos la cantidad especificada de registros del archivo al vector 'personal'
    leidos = fread(personal, sizeof(Personal), cantidad, pFile) ;

    fclose(pFile) ;

    return leidos ;
}


// ----------------------------------------------------------------------
// 5. OBTENER CANTIDAD DE REGISTROS
// ----------------------------------------------------------------------
int PersonalArchivo::getCantidadRegistros(){

    // Tarea registro ; // No es necesario declarar el objeto, solo el tamaño
    int cantidad ;
    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "rb") ;

    if(pFile == nullptr){
        return 0 ;
    }

    // Mueve el puntero al final del archivo
    fseek(pFile, 0, SEEK_END) ;

    // (Tamaño total del archivo) / (Tamaño de un registro) = Cantidad de registros
    cantidad = ftell(pFile) / sizeof(Personal) ;

    fclose(pFile) ;

    return cantidad ;
}

// ----------------------------------------------------------------------
// 6. OBTENER NUEVO ID
// ----------------------------------------------------------------------
int PersonalArchivo::getNuevoID(){

    return getCantidadRegistros() + 1 ;
}

// ----------------------------------------------------------------------
// 7. BUSCAR ID (Retorna la Posición)
// ----------------------------------------------------------------------
int PersonalArchivo::buscarId(int id){

    Personal registro ;
    int pos = -1 ;


    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "rb") ;

    if(pFile == nullptr) {
        return pos ;
    }

    // Leemos registro por registro hasta que fread devuelva 0 (fin del archivo)
    while(fread(&registro, sizeof(Personal), 1, pFile)){

        if(registro.getID() == id){

            pos = ftell(pFile) / sizeof(Personal) -1 ;

            break ; // Encontrado, salimos del bucle

        }
    }

    fclose(pFile) ;

    return pos ;

}


bool PersonalArchivo::guardar(int pos, const Personal &registro){

    FILE *pFile ;

    // "rb+": Lectura y escritura binaria. Permite modificar registros existentes.

    pFile = fopen(_nombreArchivo.c_str(), "rb+") ;

    if(pFile == nullptr) {

        return false ;
    }

    // Mueve el puntero a la posición donde queremos REESCRIBIR.

    fseek(pFile, sizeof(Personal) * pos, SEEK_SET) ;

    // Reescritura: fwrite devuelve 1 si fue exitoso

    bool result = fwrite(&registro, sizeof(Personal), 1, pFile) ;

    fclose(pFile) ;

    return result ;
}


