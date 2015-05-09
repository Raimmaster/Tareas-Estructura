#include "T6Pilas.h"
#include "ui_T6Pilas.h"
#include <QMessageBox>

T6Pilas::T6Pilas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T6Pilas)
{
    ui->setupUi(this);
}

T6Pilas::~T6Pilas()
{
    delete ui;
}

/**
 * @brief T6Pilas::getTope - Obtiene un apuntador del objeto al tope del stack
 * @return El apuntador al tope
 */
Nodo* T6Pilas::getTope(){
    return tope;
}

/**
 * @brief T6Pilas::meter - Inserta un nuevo nodo a la pila
 * @param obj - El apuntador al nodo a insertar
 */
void T6Pilas::meter(Nodo *obj){
    if(tope)
        obj->anterior = tope;

    tope = obj;
}

/**
 * @brief T6Pilas::sacar - Saca un objeto de la lista
 * @return true si la operación se logró hacer
 */
bool T6Pilas::sacar(){
    if(tope){
        Nodo* t = tope;
        tope = tope->anterior;
        delete t;
        return true;
    }

    return false;
}

/**
 * @brief vacia - Comprueba si la pila está vacía
 * @return - false si tiene algo
 */
bool T6Pilas::isEmpty(){
    if(tope)
        return false;

    return true;
}

/**
 * @brief Anular - Vacía la lista
 */
void T6Pilas::anular(){
    while(sacar());
}

void T6Pilas::on_bAgregar_clicked()
{
    QString q = ui->lValor->text();
    if(!q.isEmpty()){
       Nodo* n = new Nodo(q);
       meter(n);
    }
    ui->lValor->clear();
}

void T6Pilas::on_bSacar_clicked()
{
    sacar();
}

void T6Pilas::on_bTope_clicked()
{
    Nodo* n = getTope();
    if(n){
        QString q = ("El tope es: ");
        q += n->valor;
        QMessageBox qM;
        qM.setText(q);
        qM.exec();
    }
}

void T6Pilas::on_bVacia_clicked()
{
    QMessageBox qM;
    if(isEmpty())
        qM.setText("Está vacía.");
    else
        qM.setText("No está vacía.");

    qM.exec();

}

void T6Pilas::on_bAnular_clicked()
{
    anular();
}
