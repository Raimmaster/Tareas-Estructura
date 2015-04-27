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

void T1Semaforo::on_bCheck_clicked()
{
    QPalette palette_colors;
    palette_colors.setColor(QPalette::WindowText, Qt::blue);

    ui->lAB->setAutoFillBackground(true);
    ui->lAB->setPalette(palette_colors);
}
