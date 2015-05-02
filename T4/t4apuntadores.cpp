#include "t4apuntadores.h"
#include "ui_t4apuntadores.h"
#include <QMessageBox>

Cartas* inicio = NULL, *final = NULL;
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

/**
 * @brief T4Apuntadores::agregar - Agrega al final de la lista
 * @param num - Número a agregar a la lista
 */
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

/**
 * @brief T4Apuntadores::getPos - Devuelve un apuntador a la posición especificada
 * @param pos Posición a obtener
 * @return Carta* de la posición
 */
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

/**
 * @brief T4Apuntadores::buscar - Buscar si existe el objeto en la lista
 * @param num - Número de carta a buscar
 * @return Carta* si el número se encuentra
 */
Cartas* T4Apuntadores::buscar(int num){
    Cartas* temp = inicio;
    for(int i = 0; i < size_lista; i++){
        if(num == temp->num)
            return temp;

        std::cout<<temp->num<<std::endl;

        temp = temp->siguiente;
    }
    std::cout<<"OUT!"<<std::endl;
    return NULL;
}

/**
 * @brief T4Apuntadores::eliminar - Elimina la carta de la lista
 * @param pos - Posición a eliminar
 */
void T4Apuntadores::eliminar(int pos){
    pos--;
    Cartas* temp = NULL;
    if(pos >= -1 && pos < size_lista - 1){
        if(pos == -1){//borrar el inicio
            temp = inicio;
            if(size_lista == 1)
                inicio = NULL;
            else
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

/**
 * @brief T4Apuntadores::insertar - Inserta una carta en la posición dada
 * @param numero - Número de carta a insertar
 * @param pos - Posición donde insertar
 * @return - True si se logró insertar
 */
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

    if(!q.isEmpty()){
        int num = ui->lValor->text().toInt();
        agregar(num);
        ui->listWidget->addItem(q);
    }

    ui->lValor->clear();
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

    if(temp != NULL)
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
