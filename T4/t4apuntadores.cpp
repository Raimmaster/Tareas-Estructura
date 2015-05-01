#include "t4apuntadores.h"
#include "ui_t4apuntadores.h"
#include <QMessageBox>

Cartas* inicio, *final;
int size_lista = 0;

T4Apuntadores::T4Apuntadores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T4Apuntadores)
{
    ui->setupUi(this);
}

T4Apuntadores::~T4Apuntadores()
{
    delete ui;
}

Cartas* T4Apuntadores::getFinal(){
    return final;
}

void T4Apuntadores::agregar(int num){
    size_lista++;
    if(!inicio){
        inicio = new Cartas(num);
        final = inicio;
        return;
    }

    final->siguiente = new Cartas(num);
    final = final->siguiente;
}

Cartas* T4Apuntadores::getPos(int pos){
    if(pos >= 0 && pos < size_lista){
        if(pos == size_lista - 1)
            return final;
        else{
            Cartas* temp = inicio;
            for(int i = 1; i < pos; i++)
                temp = temp->siguiente;

            return temp;
        }
    }
}

Cartas* T4Apuntadores::buscar(int num){
    Cartas* temp = inicio;
    for(int i = 0; i < size_lista; i++){
        if(num == temp->num)
            return temp;

        temp = temp->siguiente;
    }

    return NULL;
}

void T4Apuntadores::eliminar(int pos){
    pos--;
    Cartas* temp = NULL;
    if(pos >= -1 && pos < size_lista - 1){
        if(pos == -1){//borrar el inicio
            temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
        }else if (pos == size_lista - 2){//borrar el final
            temp = getPos(pos);
            temp->siguiente = NULL;
            delete final;
            final = temp;
        }else{//borrar los que están en el medio
            temp = getPos(pos);
            Cartas* temp2 = temp->siguiente;
            temp->siguiente = temp2->siguiente;
            delete temp2;
        }
        size_lista--;
    }
}

bool T4Apuntadores::insertar(int numero, int pos){
    if(pos >= 0 && pos < size_lista){
        if(pos == 0){
            Cartas* temp = new Cartas(numero);
            temp->siguiente = inicio;
            inicio = temp;
        }else if (pos == size_lista - 1){
            agregar(numero);
            return true;
        }
        else{
            Cartas* temp = getPos(pos - 1);
            Cartas* t = new Cartas(numero);
            t->siguiente = temp->siguiente;
            temp->siguiente = t;
        }

        size_lista++;//actualizar cantidad de cartas en lista

        return true;
    }

    return false;
}

void T4Apuntadores::on_bAgregar_clicked()
{
    QString q = ui->lValor->text();
    ui->lValor->clear();

    if(!q.isEmpty()){
        int num = ui->lValor->text().toInt();
        agregar(num);
        ui->listWidget->addItem(q);
    }
}

void T4Apuntadores::on_bEliminar_clicked()
{
    int pos = ui->lPosicion->text().toInt();
    ui->lPosicion->clear();
    eliminar(pos);
    ui->listWidget->takeItem(pos);
}

void T4Apuntadores::on_bBuscar_clicked()
{
    int num = ui->lValor->text().toInt();
    Cartas* temp = buscar(num);
    QMessageBox qMes;
    if(!temp)
        qMes.setText("Existe");
    else
        qMes.setText("No existe");

    qMes.exec();

}

void T4Apuntadores::on_bInsertar_clicked()
{
    int num = ui->lValor->text().toInt();
    int pos = ui->lPosicion->text().toInt();
    QString q = ui->lValor->text();

    ui->lValor->clear();
    ui->lPosicion->clear();

    if(insertar(num, pos)){
        ui->listWidget->insertItem(pos, q);
    }else{
        QMessageBox qMes;
        qMes.setText("No se pudo insertar");
        qMes.exec();
    }
}
