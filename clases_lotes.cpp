#include <iostream>
#include <math.h>
#include <stdlib.h>
#include<string>
#include"clases_lotes.h"
using namespace std;


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
    cout<<"El tamano del lote es de: "<<tamloteEOQ<<" unidades"<<endl;
}
int EOQ::calculoEOQ(){
    tamloteEOQ=sqrt((2*Demandanual*cemision)/cposesion);
    return tamloteEOQ;
}
POQ::POQ(string _Producto,float _Demandanual,float _cemision,float _cposesion, float _demandadiaria,float _producciondiaria) : LoteEconomico(_Producto,_Demandanual,_cemision,_cposesion){
    producciondiaria=_producciondiaria;
    demandadiaria=_demandadiaria;
}

void POQ::mostrar(){
    LoteEconomico::mostrar();
    cout<<"La demanda diaria es de: "<<demandadiaria<<" unidades"<<endl;
    cout<<"La produccion diaria es de: "<<producciondiaria<<" unidades"<<endl;
    cout<<"El tamano del lote es de: "<<tamlotePOQ<<" unidades"<<endl;
}
int POQ::calculoPOQ(){
    tamlotePOQ=sqrt((2*Demandanual*cemision)/(cposesion*(1-(demandadiaria/producciondiaria))));
    return tamlotePOQ;
}
EOQruptura::EOQruptura(string _Producto,float _Demandanual,float _cemision,float _cposesion,float _cruptura) : EOQ(_Producto,_Demandanual,_cemision,_cposesion){
    cruptura=_cruptura;
}
void EOQruptura::mostrar(){
    LoteEconomico::mostrar();
    cout<<"El coste de ruptura es de: "<<cruptura<<" euros"<<endl;
    cout<<"El tamano del lote es de: "<<tamloteEOQr<<" unidades"<<endl;
}

int EOQruptura::calculoEOQruptura(){
    calculoEOQ();
    tamloteEOQr=tamloteEOQ*sqrt((cposesion+cruptura)/cruptura);
    return tamloteEOQr;
}

POQruptura::POQruptura(string _Producto,float _Demandanual,float _cemision,float _cposesion, float _demandadiaria,float _producciondiaria, float _cruptura):POQ(_Producto,_Demandanual,_cemision,_cposesion,_demandadiaria,_producciondiaria),EOQruptura(_Producto,_Demandanual,_cemision,_cposesion,_cruptura){

}

void POQruptura::mostrar(){
    POQ::mostrar();
    cout<<"El coste de ruptura es de: "<<cruptura<<" euros"<<endl;
    cout<<"El tamano del lote es de: "<<tamlotePOQr<<" unidades"<<endl;
}

int POQruptura::calculoPOQruptura(){
    calculoPOQ();
    float cpose=POQ::cposesion;
    tamlotePOQr=sqrt((cpose+cruptura)/cruptura)*tamlotePOQ;
    return tamlotePOQr;
}
