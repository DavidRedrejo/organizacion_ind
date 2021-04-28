#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

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

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_tabBarClicked(int index);

    void on_bt_planificacion_clicked();

private:
    Ui::MainWindow *ui;
    QString metodo = "EOQ"; //EOQ porque es la pestaña inicial
    int tamano_lote;
    std::string producto;
    float demanda_anual, cEmision, cPosesion;
    float demanda_diaria, prod_diaria;
    float cRuptura;
};
#endif // MAINWINDOW_H
