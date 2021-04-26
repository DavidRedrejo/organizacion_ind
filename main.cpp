#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

class LoteEconomico{
    protected:
        string Producto;
        float Demandanual,cemision;
        float cposesion;

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

LoteEconomico::LoteEconomico(string _Producto,float _Demandanual,float _cemision,float _cposesion){
    Producto=_Producto;
    Demandanual=_Demandanual;
    cemision=_cemision;
    cposesion=_cposesion;
}

void LoteEconomico::mostrar(){
    cout<<"-"<<Producto<<"-"<<endl;
    cout<<"La demanda anual es de: "<<Demandanual<<" unidades"<<endl;
    cout<<"El coste de emision es de: "<<cemision<<" euros"<<endl;
    cout<<"El coste de posesion es de: "<<cposesion<<" euros"<<endl;
    }

EOQ::EOQ(string _Producto,float _Demandanual,float _cemision,float _cposesion) : LoteEconomico(_Producto,_Demandanual,_cemision,_cposesion){

}
void EOQ::mostrar(){
    LoteEconomico::mostrar();
   }
void EOQ::calculoEOQ(){
    tamloteEOQ=sqrt((2*Demandanual*cemision)/cposesion);
    cout<<"El tamano del lote es de: "<<tamloteEOQ<<" unidades"<<endl;
}
POQ::POQ(string _Producto,float _Demandanual,float _cemision,float _cposesion, float _demandadiaria,float _producciondiaria) : LoteEconomico(_Producto,_Demandanual,_cemision,_cposesion){
    producciondiaria=_producciondiaria;
    demandadiaria=_demandadiaria;
}

void POQ::mostrar(){
    LoteEconomico::mostrar();
    cout<<"La demanda diaria es de: "<<demandadiaria<<" unidades"<<endl;
    cout<<"La produccion diaria es de: "<<producciondiaria<<" unidades"<<endl;
}
void POQ::calculoPOQ(){
    tamlotePOQ=sqrt((2*Demandanual*cemision)/(cposesion*(1-(demandadiaria/producciondiaria))));
    cout<<"El tamano del lote es de: "<<tamlotePOQ<<" unidades"<<endl;
}
EOQruptura::EOQruptura(string _Producto,float _Demandanual,float _cemision,float _cposesion,float _cruptura) : EOQ(_Producto,_Demandanual,_cemision,_cposesion){
    cruptura=_cruptura;
}
void EOQruptura::mostrar(){
    LoteEconomico::mostrar();
    cout<<"El coste de ruptura es de: "<<cruptura<<" euros"<<endl;
}

void EOQruptura::calculoEOQruptura(){
    calculoEOQ();
    tamloteEOQr=tamloteEOQ*sqrt((cposesion+cruptura)/cruptura);
    cout<<"El tamano del lote es de: "<<tamloteEOQr<<" unidades"<<endl;
}

POQruptura::POQruptura(string _Producto,float _Demandanual,float _cemision,float _cposesion, float _demandadiaria,float _producciondiaria, float _cruptura):POQ(_Producto,_Demandanual,_cemision,_cposesion,_demandadiaria,_producciondiaria),EOQruptura(_Producto,_Demandanual,_cemision,_cposesion,_cruptura){

}

void POQruptura::mostrar(){
    POQ::mostrar();
    cout<<"El coste de ruptura es de: "<<cruptura<<" euros"<<endl;
}

void POQruptura::calculoPOQruptura(){
    calculoPOQ();
    float cpose=POQ::cposesion;
    tamlotePOQr=sqrt((cpose+cruptura)/cruptura)*tamlotePOQ;
    cout<<"El tamano del lote es de: "<<tamlotePOQr<<" unidades"<<endl;
}

 int main(){
     EOQ lote1("Cervezas",3000,200,2);
     POQ lote2("Colchones",4000,250,1,75,100);
     EOQruptura lote3("Botellas",3500,150,3,1);
     POQruptura lote4("bolis",4000,250,1,75,100,1);
     lote1.mostrar();
     lote1.calculoEOQ();
     lote2.mostrar();
     lote2.calculoPOQ();
     lote3.mostrar();
     lote3.calculoEOQruptura();
     lote4.mostrar();
     lote4.calculoPOQruptura();
     system("pause");
     return 0;
 }
