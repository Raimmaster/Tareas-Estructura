#include "T1Semaforo.h"
#include "ui_t1semaforo.h"

T1Semaforo::T1Semaforo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T1Semaforo)
{
    ui->setupUi(this);
}

T1Semaforo::~T1Semaforo()
{
    delete ui;
}
