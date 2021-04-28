#include "dialog_plan.h"
#include "ui_dialog_plan.h"

Dialog_plan::Dialog_plan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_plan)
{
    ui->setupUi(this);
    //ui->tableWidget->
}

Dialog_plan::~Dialog_plan()
{
    delete ui;
}
