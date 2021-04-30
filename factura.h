#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <QDate>

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
          QDate fecha;
     public:
          item(string, QDate);
          void setdescripcion(string);
          void setfecha(QDate);
          string getdescripcion();
          QDate getfecha();
};


class Factura{
   private:
       Cliente titular;
       item *cosa;
   public:
       Factura(Cliente, string, QDate);
       void mostrar();
};

class Sucursal{
   private:
       string direccion;
       Factura pedido;
   public:
       //Sucursal();
       void setdirrecion(string);
       string getdirrecion();
};

#endif // FACTURA_H
