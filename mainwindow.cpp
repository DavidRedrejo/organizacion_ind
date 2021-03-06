#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clases_lotes.h"
#include "dialog_plan.h"
#include <string>
#include <QMessageBox>

#include <dialog_factura.h>
#include "factura.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::recoger_datos(){
    // recoge todos los datos necesarios para el método que esté seleccionado
    bool recoge_bien = true;
    if(metodo=="EOQ"){
        producto = ui->line_producto->text().toStdString();
        demanda_anual = ui->line_dem_anu->text().toInt();
        cEmision = ui->line_cost_emi->text().toFloat();
        cPosesion = ui->line_cost_pos->text().toFloat();
        if (producto == "" || demanda_anual == 0.0 || cEmision == 0.0 || cPosesion == 0.0)
            recoge_bien = false;
    }
    else if(metodo=="POQ"){
        producto = ui->line_producto_3->text().toStdString();
        demanda_anual = ui->line_dem_anu_3->text().toInt();
        cEmision = ui->line_cost_emi_3->text().toFloat();
        cPosesion = ui->line_cost_pos_3->text().toFloat();
        demanda_diaria = ui->line_deman_diaria->text().toFloat();
        prod_diaria = ui->line_prod_diaria->text().toFloat();
        if (producto == "" || demanda_anual == 0.0 || cEmision == 0.0 || cPosesion == 0.0 || demanda_diaria == 0.0 || prod_diaria == 0.0)
            recoge_bien = false;
    }
    else if(metodo=="EOQr"){
        producto = ui->line_producto_4->text().toStdString();
        demanda_anual = ui->line_dem_anu_4->text().toInt();
        cEmision = ui->line_cost_emi_4->text().toFloat();
        cPosesion = ui->line_cost_pos_4->text().toFloat();
        cRuptura = ui->line_cost_rupt->text().toFloat();
        if (producto == "" || demanda_anual == 0.0 || cEmision == 0.0 || cPosesion == 0.0 || cRuptura == 0.0)
            recoge_bien = false;
    }
    else if(metodo=="POQr"){
        producto = ui->line_producto_5->text().toStdString();
        demanda_anual = ui->line_dem_anu_5->text().toInt();
        cEmision = ui->line_cost_emi_5->text().toFloat();
        cPosesion = ui->line_cost_pos_5->text().toFloat();
        demanda_diaria = ui->line_deman_diaria_2->text().toFloat();
        prod_diaria = ui->line_prod_diaria_2->text().toFloat();
        cRuptura = ui->line_cost_rupt_2->text().toFloat();
        if (producto == "" || demanda_anual == 0.0 || cEmision == 0.0 || cPosesion == 0.0 || demanda_diaria == 0.0 || prod_diaria == 0.0 || cRuptura == 0.0)
            recoge_bien = false;
    }
    return recoge_bien;
}

void MainWindow::on_bt_calcular_tam_lote_clicked()
{
    bool calcula = recoger_datos();
    if (calcula == false){ // Si falta algun dato por introducir -> no se va a calcular nada y se muestra mensaje.
        QMessageBox::information(this, "Error", "Faltan datos por introducir!\nNo se puede realizar el cálculo.");
        return;
    }
    // Se crea el objeto correspondiente según el método que esté seleccionado
    if(metodo=="EOQ"){
        EOQ lote(producto, demanda_anual, cEmision, cPosesion);
        tamano_lote=lote.calculoEOQ();
        lote.mostrar();
        ui->line_tam_lote->setText(QString::number(tamano_lote));
    }
    else if(metodo=="POQ"){
        POQ lote(producto, demanda_anual, cEmision, cPosesion, demanda_diaria, prod_diaria);
        tamano_lote=lote.calculoPOQ();
        lote.mostrar();
        ui->line_tam_lote->setText(QString::number(tamano_lote));
    }
    else if(metodo=="EOQr"){
        EOQruptura lote(producto, demanda_anual, cEmision, cPosesion, cRuptura);
        tamano_lote=lote.calculoEOQruptura();
        lote.mostrar();
        ui->line_tam_lote->setText(QString::number(tamano_lote));
    }
    else if(metodo=="POQr"){
        POQruptura lote(producto, demanda_anual, cEmision, cPosesion, demanda_diaria, prod_diaria, cRuptura);
        tamano_lote=lote.calculoPOQruptura();
        lote.mostrar();
        ui->line_tam_lote->setText(QString::number(tamano_lote));
    }
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    // Se indica el método según la pesataña que esté seleccionada
    switch (index) {
    case 0:
        metodo = "EOQ";
        break;
    case 1:
        metodo = "POQ";
        break;
    case 2:
        metodo = "EOQr";
        break;
    case 3:
        metodo = "POQr";
        break;
    }
}

void MainWindow::on_bt_planificacion_clicked()
{
    // Se lanza la ventana de dialogo con la vista de planificación (antes se tiene que calcular el lote)
    if (tamano_lote == -1){
        QMessageBox::information(this, "Error", "Se tiene que calcular el tamaño de lote previamente.");
        return;
    }

    Dialog_plan cuadro(nullptr, demanda_anual, tamano_lote, cEmision, cPosesion);
    cuadro.exec();

    coste_total = cuadro.costetotal;
    ui->line_coste_total->setText(QString::number(coste_total));
}

void MainWindow::on_bt_mostrar_fact_clicked()
{
    if (coste_total == 0.0){
        QMessageBox::information(this, "Error", "Se tiene que calcular el coste total previamente.");
        return;
    }

    // Se recogen los datos para agregarlos al objeto cliente
    QString nombre = ui->line_nombre->text();
    QString apellido = ui->line_apell->text();
    QString DNI = ui->line_DNI->text();
    _cliente.setnombre(nombre.toStdString());
    _cliente.setapellidos(apellido.toStdString());
    _cliente.setDNI(DNI.toInt());

    Dialog_factura cuadro_fact;
    cuadro_fact.set(_cliente, coste_total);
    cuadro_fact.exec();
}
