#include "T7Cursores.h"
#include "ui_T7Cursores.h"
#include <QMessageBox>
#include <iostream>

using namespace std;

void T7Cursores::inicializar(){
    initEspacios();
    initInicios();
}

void T7Cursores::initEspacios(){
    for(int i = 0; i < SIZE_LISTAS - 2; i++)
        espacios[i].siguiente = i + 1;

    espacios[SIZE_LISTAS - 2].siguiente = -1;
    espacios[SIZE_LISTAS - 1].siguiente = 0;

    for(int i = 0; i < SIZE_LISTAS; i++)
        cout<<"Pos: "<<i<<" con su siguiente: "<<espacios[i].siguiente<<endl;
}

void T7Cursores::initInicios(){
    for(int i = 1; i < SIZE_LISTAS; i++)
        inicios[i] = -1;

    inicios[0] = SIZE_LISTAS - 1;
}

T7Cursores::T7Cursores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T7Cursores)
{
    inicializar();
    ui->setupUi(this);
}

T7Cursores::~T7Cursores()
{
    delete ui;
}

int T7Cursores::getInicioVacio(){
    for(int i = 0; i < SIZE_LISTAS; i++){
        if(inicios[i] == -1)
            return i;
    }

    return -1;
}

void T7Cursores::crearLista(char c){
    int disponible = inicios[0];
    int newInicioPos = getInicioVacio();

    if(newInicioPos != -1){
        inicios[newInicioPos] = disponible;
        inicios[0] = espacios[disponible].siguiente;

    }
}
