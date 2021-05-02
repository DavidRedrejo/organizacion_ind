#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "factura.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    bool recoger_datos();

private slots:
    void on_bt_calcular_tam_lote_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_bt_planificacion_clicked();

    void on_bt_mostrar_fact_clicked();

private:
    Ui::MainWindow *ui;
    QString metodo = "EOQ"; //EOQ porque es la pestaña inicial
    int tamano_lote = -1; //se inicia en -1 para controlar el flujo del programa
    std::string producto;
    int demanda_anual;
    float cEmision, cPosesion;
    float demanda_diaria, prod_diaria;
    float cRuptura;
    float coste_total = 0.0;
public:
    Cliente _cliente;
};
#endif // MAINWINDOW_H
