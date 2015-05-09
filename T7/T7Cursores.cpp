#include "T7Cursores.h"
#include "ui_T7Cursores.h"

T7Cursores::T7Cursores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T7Cursores)
{
    ui->setupUi(this);
}

T7Cursores::~T7Cursores()
{
    delete ui;
}
