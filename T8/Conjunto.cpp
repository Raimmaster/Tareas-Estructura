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

/**
 * @brief Conjunto::insertar - Inserta un nuovo nodo al conjunto
 * @param num - El número a insertar, si se permite
 * @return true si se pudo insertar
 */
bool Conjunto::insertar(int num){
    actual = inicio;

    if(!actual){//si el inicio está vacío, llenarlo
        actual = new Cartas(num);
        inicio = actual;
        return true;
    }

    if(actual->num == num)//si es igual al inicio, retornar
        return false;

    if(num < actual->num){
        Cartas* nuovo = new Cartas(num);
        nuovo->siguiente = actual;
        inicio = nuovo;

        return true;
    }

    while(actual->siguiente){
        if(actual->siguiente->num == num)
            return false;

        if(actual->num < num && actual->siguiente
                && actual->siguiente->num > num){

            Cartas* nuovo = new Cartas(num);//4
            nuovo->siguiente = actual->siguiente;//4's next is 5
            actual->siguiente = nuovo;//3's next is 4
            return true;
        }

        actual = actual->siguiente;
    }

    Cartas* nuovo = new Cartas(num);//4
    actual->siguiente = nuovo;

    return true;
}

