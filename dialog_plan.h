#ifndef DIALOG_PLAN_H
#define DIALOG_PLAN_H

#include <QDialog>

namespace Ui {
class Dialog_plan;
}

class Dialog_plan : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_plan(QWidget *parent = nullptr);
    ~Dialog_plan();

private:
    Ui::Dialog_plan *ui;
};

#endif // DIALOG_PLAN_H
