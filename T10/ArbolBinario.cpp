#include "ArbolBinario.h"

ArbolBinario::ArbolBinario()
{
    this->raiz = NULL;
    this->leftSon = NULL;
    this->rightSon = NULL;
}

ArbolBinario::~ArbolBinario(){

}

ArbolBinario::ArbolBinario(int valor)
{
    this->raiz = new Node(valor);
    this->leftSon = NULL;
    this->rightSon = NULL;
}

void ArbolBinario::imprimir(Node* root){
    if(root)
        cout<<root->valor<<endl;
}

void ArbolBinario::infix(ArbolBinario* root){
    if(!root)
        return;

    infix(root->leftSon);
    imprimir(root->raiz);
    infix(root->rightSon);
}

void ArbolBinario::prefix(ArbolBinario *root){
    if(!root)
        return;

    imprimir(root->raiz);
    prefix(root->leftSon);
    prefix(root->rightSon);
}

void ArbolBinario::postfix(ArbolBinario *root){
    if(!root)
        return;

    postfix(root->leftSon);
    postfix(root->rightSon);
    imprimir(root->raiz);
}

bool ArbolBinario::buscar(int valor){
    if(!this->raiz)
        return false;

    if(valor == this->raiz->valor)
        return true;

    if(leftSon && leftSon->buscar(valor))
        return true;

    if(rightSon && rightSon->buscar(valor))
        return true;

    return false;
}

void ArbolBinario::insertar(int valor){
    if(!this->raiz){
        this->raiz = new Node(valor);
        return;
    }

    if(this->raiz->valor == valor)
        return;

    if(valor > this->raiz->valor){
        if(!this->rightSon){
            rightSon = new ArbolBinario(valor);
            return;
        }

        rightSon->insertar(valor);
        return;
    }

    if(!this->leftSon){
        leftSon = new ArbolBinario(valor);
        return;
    }

    leftSon->insertar(valor);
}

void ArbolBinario::limpiarArbol(){
    if(!raiz)
        return;

    if(leftSon)
        leftSon->limpiarArbol();

    if(rightSon)
        rightSon->limpiarArbol();

    delete raiz;
    cout<<"Me delete"<<endl;
}
