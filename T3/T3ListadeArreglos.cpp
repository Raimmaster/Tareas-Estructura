#include "T3ListadeArreglos.h"
#include "ui_T3ListadeArreglos.h"
#include <QMessageBox>
#include <iostream>

const int SIZE = 15;
QString arreglo[SIZE];
int actual = 0;

T3ListadeArreglos::T3ListadeArreglos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T3ListadeArreglos)
{
    ui->setupUi(this);
}

T3ListadeArreglos::~T3ListadeArreglos()
{
    delete ui;
}

bool T3ListadeArreglos::append(QString value){
    if(actual < SIZE){
        arreglo[actual++] = value;
        return true;
    }

    return false;
}

int T3ListadeArreglos::search(QString value){
    for(int i = 0; i < actual; i++){
        if(arreglo[i] == value)
            return i;
    }

    return -1;
}

void T3ListadeArreglos::clear(){
    for(int i = 0; i < actual; i++){
        arreglo[i] = "0";

        actual = 0;
    }
}

bool T3ListadeArreglos::insert(int pos, QString value){
    std::cout<<"Pos: "<<pos<<" - Actual: "<<actual<<std::endl;

    if(actual < SIZE && pos < actual){
        for(int i = actual - 1; i > pos; i--)
            arreglo[i + 1] = arreglo[i];

        arreglo[pos] = value;
        actual++;
        return true;
    }

    return false;
}

bool T3ListadeArreglos::eliminar(int pos){
    if(pos < actual){
        for(int i = pos; i < actual; i++){
            arreglo[i] = arreglo[i + 1];
        }

        arreglo[--actual] = "0";
        return true;
    }

    return false;
}

void T3ListadeArreglos::on_bAgregar_clicked()
{
    QString q = ui->tValores->displayText();
    if(q.isEmpty())
        return;

    ui->tValores->clear();
    if(append(q)){
        ui->lwLista->addItem(q);
    }else{
        QMessageBox qMes;
        qMes.setText("No se ha podido agregar.");
        qMes.exec();
    }
}

/**
 * @brief T3ListadeArreglos::on_pushButton_clicked
 * Limpia la lista entera, del arreglo y del QListWidget
 */
void T3ListadeArreglos::on_pushButton_clicked()
{
    clear();
    ui->lwLista->clear();
}

void T3ListadeArreglos::on_bBuscar_clicked()
{
    int pos = search(ui->tValores->displayText());
    QMessageBox qMes;

    if(pos != -1){
        QString q = QString("Se encuentra en la posicion: %1").arg(pos);
        qMes.setText(q);
    }else
        qMes.setText("No se encuentra el elemento en la colección.");

    qMes.exec();

    ui->tValores->clear();
}

void T3ListadeArreglos::on_bEliminar_clicked()
{
    int pos = ui->lPosicion->text().toInt();
    if(eliminar(pos))
        ui->lwLista->takeItem(pos);

    ui->lPosicion->clear();
}

void T3ListadeArreglos::on_bInsertar_clicked()
{
    int pos = ui->lPosicion->text().toInt();
    QString q = ui->tValores->text();
    ui->lPosicion->clear();
    ui->tValores->clear();

    QMessageBox qMes;
    if(insert(pos, q)){
        qMes.setText("Se ha podido insertar en esa posición.");
        /*QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(itemText);
        listWidget->insertItem(row, newItem);*/
        ui->lwLista->insertItem(pos, new QListWidgetItem(q));
    }else
        qMes.setText("No se pudo insertar el objeto.");

    qMes.exec();
}
