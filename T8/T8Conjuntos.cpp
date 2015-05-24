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
    while(conA.actual || conB.actual){
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
            if(conA.insertar(num))
                ui->lwA->addItem(item);
        break;
        case 1:
            if(conB.insertar(num))
                ui->lwB->addItem(item);
        break;
    }
}

