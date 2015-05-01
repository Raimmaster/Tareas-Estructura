#include "t2cartas.h"
#include "ui_t2cartas.h"
#include <iostream>

const int SIZE = 15;
bool check = false;

T2Cartas::T2Cartas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T2Cartas)
{
    ui->setupUi(this);
}

T2Cartas::~T2Cartas()
{
    delete ui;
}

void T2Cartas::on_tValor_returnPressed()
{
    if(cantItems < SIZE){
           QString newValue = ui->tValor->displayText();
           //ui->lwOriginal->addItem(newValue);
           ui->lwOriginal->insertItem(cantItems, newValue);
           ui->tValor->clear();
           oriList[cantItems++] = newValue;
           check = true;
           return;
    }
}

/**
 * @brief T2Cartas::buscar Busca si un valor ya existe en la lista
 * @param q El QString q a comparar
 * @return true si el valor ya existe
 */
bool T2Cartas::buscar(QString q){
    for(int i = 0; i < cantItems; i++){
        if(newList[i] != NULL &&  newList[i] == q)
            return true;
    }

    return false;
}

/**
 * @brief T2Cartas::trim
 * Recorta los objetos duplicados en la lista
 */
void T2Cartas::trim(){
    for(int i = 0; i < ui->lwOriginal->count(); i++){
        if(!buscar(oriList[i]))
            newList[currentInsert++] = oriList[i];
    }

    //delete [] oriList;//eliminar espacio de memoria
    //oriList = new QString[currentInsert];//reinstanciar arreglo
    oriList[currentInsert];
    for(int i = 0; i < currentInsert; i++){
        oriList[i] = newList[i];
        ui->lwNew->addItem(oriList[i]);
    }
}

void T2Cartas::on_bQuitar_clicked()
{
    if(!check){
        ui->lwNew->clear();
        trim();
    }
    check = false;
}
