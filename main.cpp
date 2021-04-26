#include <iostream>
#include"clases_lotes.h"
using namespace std;
int main()
{
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
