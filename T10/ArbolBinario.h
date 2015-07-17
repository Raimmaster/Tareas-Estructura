#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "Node.h"
#include <iostream>

using namespace std;

class ArbolBinario
{
public:
    Node* raiz;//el valor de sí mismo
    ArbolBinario* leftSon;
    ArbolBinario* rightSon;
    void insertar(int valor);
    bool eliminar(int valor);
    bool buscar(int valor);
    void limpiarArbol();
    void imprimir(Node* root);
    void prefix(ArbolBinario* root);
    void postfix(ArbolBinario* root);
    void infix(ArbolBinario* root);
    ArbolBinario();
    ArbolBinario(int valor);
    ~ArbolBinario();
};

#endif // ARBOLBINARIO_H
