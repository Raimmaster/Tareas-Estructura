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

void T8Conjuntos::resetActuales(){
    conA.actual = conA.inicio;
    conB.actual = conB.inicio;
}

void T8Conjuntos::conjuntoUnion(){
    resetActuales();
    conC.clear();
    while(conA.actual || conB.actual){
        if(!conA.actual){//si el conA ha llegado a su fin
            conC.push_back(conB.actual->num);
            conB.actual = conB.actual->siguiente;
            continue;
        }

        if(!conB.actual){//si el conB ha llegado a su fin
            conC.push_back(conA.actual->num);
            conA.actual = conA.actual->siguiente;
            continue;
        }

        if(conA.actual->num < conB.actual->num){//Si el objeto de con A es menor
            conC.push_back(conA.actual->num);
            conA.actual = conA.actual->siguiente;
        }else if(conA.actual->num == conB.actual->num){//Si los objetos son iguales
            conC.push_back(conA.actual->num);
            conA.actual = conA.actual->siguiente;
            conB.actual = conB.actual->siguiente;
        }else{//Si el objeto de con B es menor
            conC.push_back(conB.actual->num);
            conB.actual = conB.actual->siguiente;
        }
    }
}

void T8Conjuntos::diferencia(){
    resetActuales();
    conC.clear();
    while(conB.actual){
        if(!conA.actual){
            conC.push_back(conB.actual->num);
            conB.actual = conB.actual->siguiente;
            continue;
        }

        if(conA.actual->num == conB.actual->num){
            conA.actual = conA.actual->siguiente;
            conB.actual = conB.actual->siguiente;
        }else if(conA.actual->num > conB.actual->num){//si A es mayor, agregar B
            conC.push_back(conB.actual->num);
            conB.actual = conB.actual->siguiente;
        }else if(conA.actual->num < conB.actual->num)
            conA.actual = conA.actual->siguiente;
    }
}

void T8Conjuntos::interseccion(){
    resetActuales();
    conC.clear();
    while(conA.actual && conB.actual){
        if(conA.actual->num > conB.actual->num)
            conB.actual = conB.actual->siguiente;

        if(conB.actual->num > conA.actual->num)
            conA.actual = conA.actual->siguiente;

        if(conA.actual->num == conB.actual->num){
            conC.push_back(conA.actual->num);
            conA.actual = conA.actual->siguiente;
            conB.actual = conB.actual->siguiente;
        }
    }
}

void T8Conjuntos::on_bInsertar_clicked()
{
    if(ui->lNum->text().isEmpty() || ui->tConjunto->text().isEmpty())
        return;

    int num = ui->lNum->text().toInt();
    int opcion = ui->tConjunto->text().toInt();
    QString item = ui->lNum->text();

    ui->lNum->clear();
    ui->tConjunto->clear();

    switch(opcion){
        case 0:        
            if(conA.insertar(num)){
                ui->lwA->clear();
                resetActuales();
                while(conA.actual){
                    ui->lwA->addItem((QString("%1").arg(conA.actual->num)));
                    conA.actual = conA.actual->siguiente;
                }
            }
//                ui->lwA->addItem(item);
        break;
        case 1:            
            if(conB.insertar(num)){
                ui->lwB->clear();
                resetActuales();
                while(conB.actual){
                    ui->lwB->addItem((QString("%1").arg(conB.actual->num)));
                    conB.actual = conB.actual->siguiente;
                }
            }
//                ui->lwB->addItem(item);
        break;
    }
}

void T8Conjuntos::fillLwC(){
    ui->lwC->clear();

    for(unsigned int i = 0; i < conC.size(); i++){
        QString item = QString("%1").arg(conC[i]);
        ui->lwC->addItem(item);
    }
}

void T8Conjuntos::on_bUnion_clicked()
{
    conjuntoUnion();
    fillLwC();
}

void T8Conjuntos::on_bDiferencia_clicked()
{
    diferencia();
    fillLwC();
}

void T8Conjuntos::on_bInterseccion_clicked()
{
    interseccion();
    fillLwC();
}
