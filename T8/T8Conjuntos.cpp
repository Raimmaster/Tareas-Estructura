#include "T8Conjuntos.h"
#include "ui_T8Conjuntos.h"

T8Conjuntos::T8Conjuntos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T8Conjuntos)
{
    ui->setupUi(this);
}

T8Conjuntos::~T8Conjuntos()
{
    delete ui;
}
