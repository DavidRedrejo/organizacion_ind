#ifndef DIALOG_PLAN_H
#define DIALOG_PLAN_H

#include <QDialog>
#include <vector>

typedef std::vector<int> _vector;
namespace Ui {
class Dialog_plan;
}

class Dialog_plan : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_plan(QWidget *parent = nullptr, int d_anual = 0, int tam = 0, float ce = 0,float cp = 0);
    ~Dialog_plan();

private slots:
    void on_bt_calcular_clicked();

private:
    Ui::Dialog_plan *ui;
    int demanda_nueva; // esta demanda es la división en los 6 periodos
    int tamano;
    float costetotal,cposesion,cemision;
    //_vector v1;
    _vector calcular_primerV(_vector);
    _vector calcular(_vector, _vector);
    float calcularcoste(_vector,_vector,_vector,_vector,_vector,_vector);
};

#endif // DIALOG_PLAN_H
