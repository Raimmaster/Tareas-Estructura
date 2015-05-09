#include "T7Cursores.h"
#include "ui_T7Cursores.h"
#include <QMessageBox>
#include <iostream>

using namespace std;

/**
 * @brief T7Cursores::inicializar - Ejecuta los métodos necesarios para inicializar las listas
 */
void T7Cursores::inicializar(){
    initEspacios();
    initInicios();
}

/**
 * @brief T7Cursores::initEspacios - Inicializa la lista de espacios
 */
void T7Cursores::initEspacios(){
    for(int i = 0; i < SIZE_LISTAS - 2; i++)
        espacios[i].siguiente = i + 1;

    espacios[SIZE_LISTAS - 2].siguiente = -1;
    espacios[SIZE_LISTAS - 1].siguiente = 0;

    for(int i = 0; i < SIZE_LISTAS; i++)
        cout<<"Pos: "<<i<<" con su siguiente: "<<espacios[i].siguiente<<endl;
}

/**
 * @brief T7Cursores::initInicios - Inicializa la lista de inicios
 */
void T7Cursores::initInicios(){
    for(int i = 1; i < SIZE_LISTAS; i++)
        inicios[i] = -1;

    inicios[0] = SIZE_LISTAS - 1;
}

T7Cursores::T7Cursores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T7Cursores)
{
    inicializar();
    ui->setupUi(this);
}

T7Cursores::~T7Cursores()
{
    delete ui;
}

/**
 * @brief T7Cursores::getInicioVacio - Obtiene el próximo espacio vacío en la lista de inicios
 * @return int i del espacio vacío
 */
int T7Cursores::getInicioVacio(){
    for(int i = 0; i < SIZE_LISTAS; i++){
        if(inicios[i] == -1)
            return i;
    }

    return -1;
}

/**
 * @brief T7Cursores::crearLista - Crea una nueva lista
 * @param c
 */
void T7Cursores::crearLista(char c){
    int disponible = inicios[0];
    int newInicioPos = getInicioVacio();

    if(newInicioPos != -1){
        inicios[newInicioPos] = disponible;
        inicios[0] = espacios[disponible].siguiente;

        espacios[disponible].siguiente = -1;
        espacios[disponible].valor = c;
    }
}

/**
 * @brief T7Cursores::agregar - Agrega un nuevo valor al final de la lista enviada
 * @param lista - número de la lista
 * @param c - Caracter a ingresar en el primer espacio posible de la lista
 */
void T7Cursores::agregar(int lista, char c){
    if(inicios[0] != -1){
        int x = inicios[lista];
        while(espacios[x].siguiente != -1)
            x = espacios[x].siguiente;

        int y = inicios[0];
        espacios[x].siguiente = y;
        espacios[y].valor = c;

        inicios[0] = espacios[y].siguiente;
        espacios[y].siguiente = -1;
    }
}

int  T7Cursores::buscar(int lista, char c){
    if(inicios[lista] != -1){
        int x = inicios[lista];
        while(espacios[x].valor != c && espacios[x].siguiente != -1)
            x = espacios[x].siguiente;

        return x;
    }

    return -1;
}

/**
 * @brief T7Cursores::insertar - Inserta un valor en el espacio indicado
 * @param lista - Lista donde insertar
 * @param pos - Posición donde insertar
 * @param c - Valor a insertar
 */
void T7Cursores::insertar(int lista, int pos, char c){
    int x = inicios[0];
    if(pos >= 0 && pos < SIZE_LISTAS){
        if(pos == inicios[lista] && espacios[pos].siguiente == -1){
            inicios[0] = espacios[x].siguiente;//le setteamos el siguiente del espacio disponible actual
            espacios[x].valor = c; //en este espacio agregamos el valor
            espacios[x].siguiente = inicios[lista];//le damos como siguiente el inicio de la lista
            inicios[lista] = x;//y setteamos como el inicio la posición del nuevo
        }else if(espacios[pos].siguiente == -1)//si el siguiente de la posición a ingresar es -1, entonces agregar
            agregar(lista, c);
        else{//no es el inicio, ni es el final
            inicios[0] = espacios[x].siguiente;
            espacios[x].valor = c;
            espacios[x].siguiente = espacios[pos].siguiente;
            espacios[pos].siguiente = x;
        }

    }
}

int T7Cursores::getAnterior(int lista, int pos){

}

void T7Cursores::eliminar(int lista, int pos){
    int actual = buscar(lista, pos);
    if(actual == inicios[lista]){
        agregar(actual, 0);
        inicios[lista] = espacios[actual].siguiente;
        espacios[actual].siguiente = -1;
    }else if(espacios[actual].siguiente == -1){

    }
}
