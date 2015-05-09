#ifndef NODO_H
#define NODO_H
#include <qstring.h>

class Nodo
{
public:
    QString valor;
    Nodo* anterior;
    Nodo(QString valor);
};

#endif // NODO_H
