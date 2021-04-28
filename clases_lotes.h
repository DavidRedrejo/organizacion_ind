#ifndef CLASES_LOTES_H
#define CLASES_LOTES_H
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include<string>
using namespace std;

class LoteEconomico{
    protected:
        string Producto;
        float Demandanual;
        float cemision, cposesion;

    public:
        LoteEconomico(string,float,float,float);
        virtual void mostrar();
};

class EOQ:public LoteEconomico{
      protected:
        int tamloteEOQ;
      public:
        EOQ(string,float,float,float);
        void mostrar();
        void calculoEOQ();
};

class POQ:public LoteEconomico{
    protected:
        float demandadiaria,producciondiaria;
        int tamlotePOQ;
    public:
        POQ(string,float,float,float,float,float);
        void mostrar();
        void calculoPOQ();
};

class EOQruptura:public EOQ{
    protected:
        float cruptura;
        int tamloteEOQr;
    public:
        EOQruptura(string,float, float, float, float);
        void mostrar();
        void calculoEOQruptura();
};

class POQruptura: POQ, EOQruptura{
    protected:
        int tamlotePOQr;
    public:
        POQruptura(string,float, float, float, float,float,float);
        void mostrar();
        void calculoPOQruptura();
};

#endif // CLASES_LOTES_H
