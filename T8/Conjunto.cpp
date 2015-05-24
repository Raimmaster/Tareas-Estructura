#include "Conjunto.h"

Conjunto::Conjunto()
{
    this->actual = NULL;
    this->inicio = NULL;
}

Cartas* Conjunto::buscar(int num){
    actual = inicio;

    while(actual){
        if(actual->num == num)
            return actual;

        actual = actual->siguiente;
    }

    return NULL;
}

bool Conjunto::insertar(int num){
    actual = inicio;

    if(!actual){
        actual = new Cartas(num);
        inicio = actual;
        return true;
    }

    if(actual->num == num)
        return false;

    while(actual->siguiente){
        if(actual->siguiente->num == num)
            return false;

        if(actual->siguiente->num < num && actual->siguiente->siguiente
                && actual->siguiente->siguiente->num > num){

            Cartas* nuovo = new Cartas(num);//4
            nuovo->siguiente = actual->siguiente->siguiente;//4's next is 5
            actual->siguiente = nuovo;//3's next is 4

            if(inicio->num > nuovo->num)
                inicio = nuovo;//reset inicio si se ha desplazado

            return true;
        }


        actual = actual->siguiente;
    }

    Cartas* nuovo = new Cartas(num);//4
    actual->siguiente = nuovo;

    return true;
}

