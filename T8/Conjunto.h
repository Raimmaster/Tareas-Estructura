#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "T4/Cartas.h"

class Conjunto
{
public:
    Cartas* actual;
    Cartas* inicio;
    bool insertar(int num);
    Cartas* buscar(int num);
    Conjunto();
};

#endif // CONJUNTO_H
