#ifndef CALLE_H
#define CALLE_H

#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

enum Color{
    BLANCO,
    AZUL,
    ROJO,
    VERDE,
    AMARILLO
};

class Calle
{
    private:
        string nombre;
        list<Calle*> adyacentes;
        Color grupo;
    public:
        Calle();
        Calle(string nombre);
        string getNombre();
        list<Calle*> getAdyacente();
        Color getGrupo();
        Calle* existe(string nombre);
        void agregarCalle(Calle* calle);
        void setGrupo(Color color);
        void setNombre(string nombre);
};

#endif // CALLE_H
