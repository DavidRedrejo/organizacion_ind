#include <iostream>
#include <math.h>
#include <stdlib.h>
#include<string>
#include "clases_lotes.h"
#include "factura.h"

using namespace std;

void Cliente::setnombre(string _nombre){
    nombre=_nombre;

}

void Cliente::setapellidos(string _apellidos){
    apellidos=_apellidos;
    }

void Cliente::setDNI(int _DNI){
    DNI=_DNI;
}

string Cliente::getnombre(){
    return nombre;
}

string Cliente::getapellido(){
    return apellidos;
}

int Cliente::getDNI(){
    return DNI;
}

item::item(string _descripcion, int _fecha){
    Descripcion=_descripcion;
    fecha=_fecha;
}

void item::setdescripcion(string _descripcion){
    Descripcion=_descripcion;
}

void item::setfecha(int _fecha){
    fecha=_fecha;
}

string item::getdescripcion(){
    return Descripcion;
}

int item::getfecha(){
    return fecha;
}

Factura::Factura(Cliente _titular){
      titular = _titular;
      cosa = new item("Descripcion,fecha",4);
}

