#include "T3ListadeArreglos.h"
#include "ui_T3ListadeArreglos.h"

T3ListadeArreglos::T3ListadeArreglos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T3ListadeArreglos)
{
    ui->setupUi(this);
}

T3ListadeArreglos::~T3ListadeArreglos()
{
    delete ui;
}
