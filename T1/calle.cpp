#include "calle.h"

Calle::Calle()
{
}

Calle::Calle(string nombre){
    this->nombre = nombre;
    this->grupo = WHITE;
}

string Calle::getNombre(){
    return nombre;
}

list<Calle*> Calle::getAdyacentes(){
    return adyacentes;
}

Color Calle::getGrupo(){
    return grupo;
}

Calle* Calle::existe(string nombre){
    for(list<Calle*>::iterator i = adyacentes.begin(); i != adyacentes.end(); i++){
        if((*i)->getNombre() == nombre)
            return (*i);
    }

    return NULL;
}

void Calle::agregarCalle(Calle *calle){
    adyacentes.push_back(calle);
}

void Calle::setNombre(string nombre){
    this->nombre = nombre;
}

void Calle::setGrupo(Color color){
    this->grupo = color;
}

