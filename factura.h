#ifndef FACTURA_H
#define FACTURA_H
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include<string>
using namespace std;

class Cliente{
   protected:
       string nombre;
       string apellidos;
       int DNI;
   public:
       void setnombre(string);
       void setapellidos(string);
       void setDNI(int);
       string getnombre();
       string getapellido();
       int getDNI();

};

class item{
     public:
          string Descripcion;
          int fecha;
     public:
          item(string,int);
          void setdescripcion(string);
          void setfecha(int);
          string getdescripcion();
          int getfecha();

};


class Factura{
   private:
       Cliente titular;
       item *cosa;
   public:
       Factura(Cliente);


};

class Sucursal{
   private:
       int dirrecion;
       Factura pedido;
   public:
       void setdirrecion(int);
       int getdirrecion();
};






#endif // FACTURA_H
