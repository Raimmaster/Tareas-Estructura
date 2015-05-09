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

void T7Cursores::inicializar(){
    initEspacios();
    initInicios();
}

void T7Cursores::initEspacios(){
    for(int i = 0; i < SIZE_LISTAS - 1; i++)
        espacios[i].siguiente = -1;

    espacios[SIZE_LISTAS - 1].siguiente = 0;
}

void T7Cursores::initInicios(){
    for(int i = 1; i < SIZE_LISTAS; i++)
        inicios[i] = -1;

    inicios[0] = SIZE_LISTAS - 1;
}
