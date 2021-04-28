#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clases_lotes.h"
#include "dialog_plan.h"
#include <string>
#include <QMessageBox>

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
    bool recoge_bien = true;
    if(metodo=="EOQ"){
        producto = ui->line_producto->text().toStdString();
        demanda_anual = ui->line_dem_anu->text().toFloat();
        cEmision = ui->line_cost_emi->text().toFloat();
        cPosesion = ui->line_cost_pos->text().toFloat();
        if (producto == "" || demanda_anual == 0.0 || cEmision == 0.0 || cPosesion == 0.0)
            return recoge_bien=false;
        qDebug("Recoge datos");
    }
    else if(metodo=="POQ"){qDebug("pruebaPOQ");}
    else if(metodo=="EOQr"){qDebug("pruebaEOQ r");}
    else if(metodo=="POQr"){qDebug("pruebaPOQ r");}
    return recoge_bien;
}

void MainWindow::on_bt_calcular_tam_lote_clicked()
{
    bool calcula = recoger_datos();
    if (calcula == false){ // Falta algun dato por introducir -> no se va a calcular nada.
        QMessageBox::information(this, "Error", "Faltan datos\nNo se puede realizar el cálculo");
        return;
    }
    if(metodo=="EOQ"){
        EOQ lote(producto, demanda_anual, cEmision, cPosesion);
        lote.calculoEOQ();
        lote.mostrar();
        qDebug("calcula eoq");
    }
    else if(metodo=="POQ"){qDebug("pruebaPOQ");}
    else if(metodo=="EOQr"){qDebug("pruebaEOQ r");}
    else if(metodo=="POQr"){qDebug("pruebaPOQ r");}


}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    //qDebug("Está aqui %d",index);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
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
    //esto lanza la otra ventana de dialogo con la vista de planificacion
    Dialog_plan cuadro;
    cuadro.exec();
}
