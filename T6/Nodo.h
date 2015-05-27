#ifndef NODO_H
#define NODO_H
#include <qstring.h>

template <typename Tipo>
class Nodo
{
public:
    Tipo valor;
    Nodo* anterior;
    Nodo(Tipo valor);
};

#endif // NODO_H
