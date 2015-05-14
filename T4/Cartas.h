#ifndef CARTAS_H
#define CARTAS_H
#include <iostream>

class Cartas
{
    public:
        Cartas(int num);
        int num;
        Cartas* siguiente;
};

#endif // CARTAS_H
