#include "dialog_plan.h"
#include "ui_dialog_plan.h"

// creo que estos dos no valen para nada
#include <math.h> // creo que para el round
//#include "dialog_factura.h"

Dialog_plan::Dialog_plan(QWidget *parent, int d_anual, int tam, float _cemision, float _cposesion) :
    QDialog(parent),
    ui(new Ui::Dialog_plan)
{
    ui->setupUi(this);
    demanda_nueva = round(d_anual/6);
    ui->nb_1->setText(QString::number(demanda_nueva));
    ui->nb_2->setText(QString::number(demanda_nueva));
    ui->nb_3->setText(QString::number(demanda_nueva));
    ui->nb_4->setText(QString::number(demanda_nueva));
    ui->nb_5->setText(QString::number(demanda_nueva));
    ui->nb_6->setText(QString::number(demanda_nueva));
    tamano = tam;
    ui->line_tamano->setText(QString::number(tamano));
    cemision = _cemision;
    cposesion = _cposesion;
}

Dialog_plan::~Dialog_plan()
{
    delete ui;
}

float Dialog_plan::calcularcoste(_vector v1, _vector v2, _vector v3, _vector v4, _vector v5, _vector v6){
    float cp = cposesion*(v1[1] + v2[1] + v3[1] + v4[1] + v5[1] + v6[1]);
    float ce = cemision*((v1[4] + v2[4] + v3[4] + v4[4] + v5[4] + v6[4])/tamano);
    costetotal = ce + cp;
    return costetotal;
}

_vector Dialog_plan::calcular_NN_PPL(_vector V){
    V[3] = V[0] - V[1] - V[2]; // Cálculo de las necesidades netas (NN)

    // Cálculo del pedido (PPL):
    // si NN>0 -> PPL será el tamaño de lote necesario hasta que sea mayor que las NN
    if (V[3] > 0){
        V[4] = tamano;
        while (V[4]<V[3]){
            V[4] = V[4] + tamano;
        }
    }
    else{   // si no hay NN, no hay que hacer pedido -> PPL=0 y las NN se ponen a 0 si fuesen negativas
        V[3] = 0;
        V[4] = 0;
    }
    return V;
}

_vector Dialog_plan::calcular(_vector V, _vector v_anterior){
    V[1] = v_anterior[1] + v_anterior[2] + v_anterior[4] - v_anterior[0]; // Cálculo de disponibilidad
    V = calcular_NN_PPL(V); // Cálculo del NN y PPL
    return V;
}

void Dialog_plan::on_bt_calcular_clicked()
{
    _vector v1;
    v1.push_back(ui->nb_1->text().toInt());
    v1.push_back(ui->nb_7->text().toInt());
    v1.push_back(ui->nb_13->text().toInt());
    v1.push_back(ui->nb_19->text().toInt());
    v1.push_back(ui->nb_25->text().toInt());
    v1 = calcular_NN_PPL(v1);
    ui->nb_19->setText(QString::number(v1[3]));
    ui->nb_25->setText(QString::number(v1[4]));

    _vector v2(5,0);
    v2[0] = ui->nb_2->text().toInt();
    v2[2] = ui->nb_14->text().toInt();
    v2 = calcular(v2, v1);
    ui->nb_8->setText(QString::number(v2[1]));
    ui->nb_20->setText(QString::number(v2[3]));
    ui->nb_26->setText(QString::number(v2[4]));

    _vector v3(5,0);
    v3[0] = ui->nb_3->text().toInt();
    v3[2] = ui->nb_15->text().toInt();
    v3 = calcular(v3, v2);
    ui->nb_9->setText(QString::number(v3[1]));
    ui->nb_21->setText(QString::number(v3[3]));
    ui->nb_27->setText(QString::number(v3[4]));

    _vector v4(5,0);
    v4[0] = ui->nb_4->text().toInt();
    v4[2] = ui->nb_16->text().toInt();
    v4 = calcular(v4, v3);
    ui->nb_10->setText(QString::number(v4[1]));
    ui->nb_22->setText(QString::number(v4[3]));
    ui->nb_28->setText(QString::number(v4[4]));

    _vector v5(5,0);
    v5[0] = ui->nb_5->text().toInt();
    v5[2] = ui->nb_17->text().toInt();
    v5 = calcular(v5, v4);
    ui->nb_11->setText(QString::number(v5[1]));
    ui->nb_23->setText(QString::number(v5[3]));
    ui->nb_29->setText(QString::number(v5[4]));

    _vector v6(5,0);
    v6[0] = ui->nb_6->text().toInt();
    v6[2] = ui->nb_18->text().toInt();
    v6 = calcular(v6, v5);
    ui->nb_12->setText(QString::number(v6[1]));
    ui->nb_24->setText(QString::number(v6[3]));
    ui->nb_30->setText(QString::number(v6[4]));

    costetotal = calcularcoste(v1,v2,v3,v4,v5,v6);
    ui->line_coste_total->setText(QString::number(costetotal));
}
