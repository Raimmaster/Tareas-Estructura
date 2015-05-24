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
        else if(actual->siguiente->num <= num)
            break;

        actual = actual->siguiente;
    }

    Cartas* nuovo = new Cartas(num);
    nuovo->siguiente = actual->siguiente;
    actual->siguiente = nuovo;

    if(inicio->num > nuovo->num)
        inicio = nuovo;

    return true;
}

