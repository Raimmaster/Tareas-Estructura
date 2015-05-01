#include "t4apuntadores.h"
#include "ui_t4apuntadores.h"

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

    return nullptr;
}

void T4Apuntadores::eliminar(int pos){
    pos--;
    Cartas* temp = nullptr;
    if(pos >= -1 && pos < size - 1){
        if(pos == -1){//borrar el inicio
            temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
        }else if (pos == size_lista - 2){//borrar el final
            temp = getPos(pos);
            temp->siguiente = nullptr;
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

void T4Apuntadores::insertar(int numero, int pos){
    if(pos >= 0 && pos < size_lista){
        if(pos == 0){
            Cartas* temp = new Cartas(numero);
            temp->siguiente = inicio;
            inicio = temp;
        }else if (pos == size_lista - 1){
            agregar(numero);
            return;
        }
        else{
            Cartas* temp = getPos(pos - 1);
            Cartas* t = new Cartas(numero);
            t->siguiente = temp->siguiente;
            temp->siguiente = t;
        }

        size_lista++;//actualizar cantidad de cartas en lista
    }
}
