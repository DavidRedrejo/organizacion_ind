#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
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

item::item(string _descripcion, QDate _fecha){
    Descripcion=_descripcion;
    fecha=_fecha;
}

void item::setdescripcion(string _descripcion){
    Descripcion=_descripcion;
}

void item::setfecha(QDate _fecha){
    fecha=_fecha;
}

string item::getdescripcion(){
    return Descripcion;
}

QDate item::getfecha(){
    return fecha;
}

Factura::Factura(Cliente _titular, string descp, QDate fecha){
    titular = _titular;
    cosa = new item(descp, fecha);
}

void Factura::mostrar(){
    cout<<"Nombre: "<<titular.getnombre()<<endl;
    cout<<"Apellidos: "<<titular.getapellido()<<endl;
    cout<<"DNI: "<<titular.getDNI()<<endl;
/*
    cout<<cosa->Descripcion<<"\n"<<cosa->fecha<<endl;
    cosa->setdescripcion("Hola");
    cosa->setfecha(90);
    cout<<cosa->Descripcion<<"\n"<<cosa->fecha<<endl;
    */
}
