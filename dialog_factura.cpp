#include "dialog_factura.h"
#include "ui_dialog_factura.h"
#include <QMessageBox>


Dialog_factura::Dialog_factura(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_factura)
{
    ui->setupUi(this);
}

Dialog_factura::~Dialog_factura()
{
    delete ui;
}

void Dialog_factura::set(Cliente _cliente){
    cli = _cliente;
    ui->nombre->setText(QString::fromStdString(cli.getnombre()));
    ui->apell->setText(QString::fromStdString(cli.getapellido()));
    ui->DNI->setText(QString::number(cli.getDNI()));
}


void Dialog_factura::on_bt_tramit_clicked()
{
    QDate fecha = ui->calendarWidget->selectedDate();
    QString descripcion = ui->descrip->text();
    QString direccion = ui->direcc->text();

    if(descripcion == "" || direccion == ""){
        QMessageBox::information(this, "Error", "Rellene todos los campos antes de tramitar.");
    }
    else{
        Factura fact(cli, descripcion.toStdString(), fecha);
        QMessageBox::information(this, "Información", "Pedido listo para enviar.");
    }
}
