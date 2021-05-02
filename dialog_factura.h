#ifndef DIALOG_FACTURA_H
#define DIALOG_FACTURA_H

#include <QDialog>
#include "factura.h"

namespace Ui {
class Dialog_factura;
}

class Dialog_factura : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_factura(QWidget *parent = nullptr);
    ~Dialog_factura();
    void set(Cliente, float);

private slots:
    void on_bt_tramit_clicked();

private:
    Ui::Dialog_factura *ui;
    Cliente cli;
    float coste;
};

#endif // DIALOG_FACTURA_H
