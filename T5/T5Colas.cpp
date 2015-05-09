#include "T5Colas.h"
#include "ui_T5Colas.h"
#include <QMessageBox>

T5Colas::T5Colas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T5Colas)
{
    ui->setupUi(this);
}

T5Colas::~T5Colas()
{
    delete ui;
}

/**
 * @brief T5Colas::getFrente - Obtiene el nodo del frente
 * @return Nodo* del frente
 */
Nodo* T5Colas::getFrente(){
    return frente;
}

/**
 * @brief T5Colas::vacia - Determina si la cola está vacía
 * @return - false si tiene un nodo
 */
bool T5Colas::isEmpty(){
    if(frente)
        return false;

    return true;
}

/**
 * @brief T5Colas::ponerEnCola - Agrega un nodo a la cola
 * @param n - Nodo* del que se agregará a la cola
 */
void T5Colas::ponerEnCola(Nodo* n){
    if(!frente){
        frente = n;
        ultimo = n;
        return;
    }

    ultimo->anterior = n;
    ultimo = n;
}

/**
 * @brief T5Colas::quitarDeCola - Quita el frente de la cola
 * @return true si se logró quitar algún nodo
 */
bool T5Colas::quitarDeCola(){
    Nodo* temp;
    if(frente){
        temp = frente;
        frente = frente->anterior;
        delete temp;
        return true;
    }

    return false;
}

/**
 * @brief anular - Vacía la cola
 */
void T5Colas::anular(){
    while(quitarDeCola());
}

void T5Colas::on_bAgregar_clicked()
{
    QString q = ui->lValor->text();
    ui->lValor->clear();

    if(!q.isEmpty())
        ponerEnCola(new Nodo(q));

}

void T5Colas::on_bQuitar_clicked()
{
    quitarDeCola();
}

void T5Colas::on_bTope_clicked()
{
    QMessageBox qM;
    Nodo* n = getFrente();
    QString q = "El valor del frente es: ";
    if(n)
        q += n->valor;

    qM.setText(q);
    qM.exec();
}

void T5Colas::on_bVacia_clicked()
{
    QMessageBox qM;
    if(isEmpty())
        qM.setText("Está vacía.");
    else
        qM.setText("No está vacía.");

    qM.exec();
}

void T5Colas::on_bAnular_clicked()
{
    anular();
}
