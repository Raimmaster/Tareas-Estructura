#include "T7Cursores.h"
#include "ui_T7Cursores.h"
#include <QMessageBox>
#include <iostream>

using namespace std;

QString valores[10];

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
    initValores();
}

void T7Cursores::initValores(){
    for(int i = 0; i < SIZE_LISTAS; i++){
        valores[i] = "_ ";
        ui->lListas->setText(ui->lListas->text() + valores[i]);
    }
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
bool T7Cursores::crearLista(QString c){
    int disponible = inicios[0];
    if(disponible == -1)//detener si ya está lleno
        return false;

    int newInicioPos = getInicioVacio();

    if(newInicioPos != -1){
        inicios[newInicioPos] = disponible;
        inicios[0] = espacios[disponible].siguiente;

        espacios[disponible].siguiente = -1;
        espacios[disponible].valor = c;
        //Agregar al QLabel de Listas y su QString[]
        valores[disponible] = c + " ";
        return true;
    }

    return false;
}

/**
 * @brief T7Cursores::agregar - Agrega un nuevo valor al final de la lista enviada
 * @param lista - número de la lista
 * @param c - Caracter a ingresar en el primer espacio posible de la lista
 */
bool T7Cursores::agregar(int lista, QString c){
    if(inicios[0] != -1){
        int x = inicios[lista];//obtenemos la posición de la lista
        while(espacios[x].siguiente != -1)
            x = espacios[x].siguiente;

        int y = inicios[0];//obtenemos la posición que tiene disponibles

        espacios[x].siguiente = y;
        espacios[y].valor = c;

        inicios[0] = espacios[y].siguiente;
        espacios[y].siguiente = -1;
        //Actualizar valores
        valores[y] = c + " ";
        return true;
    }

    return false;
}

int T7Cursores::buscar(int lista, QString c){
    if(inicios[lista] != -1){
        int x = inicios[lista];//posición inicial de la lista
        while(espacios[x].valor != c && espacios[x].siguiente != -1)
            x = espacios[x].siguiente;

        if(espacios[x].valor == c)
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
bool T7Cursores::insertar(int lista, QString pos, QString c){
    int x = inicios[0];
    if (x == -1)//Si está llena, simplemente retornar false
        return false;

    int insertarAntes = buscar(lista, pos);

    if(insertarAntes != 1){
        if(insertarAntes == inicios[lista] && espacios[insertarAntes].siguiente == -1){
            inicios[0] = espacios[x].siguiente;//le setteamos el siguiente del espacio disponible actual
            espacios[x].valor = c; //en este espacio agregamos el valor            
            espacios[x].siguiente = inicios[lista];//le damos como siguiente el inicio de la lista
            inicios[lista] = x;//y setteamos como el inicio la posición del nuevo
        }else if(espacios[insertarAntes].siguiente == -1)//si el siguiente de la posición a ingresar es -1, entonces agregar
            agregar(lista, c);
        else{//no es el inicio, ni es el final
            inicios[0] = espacios[x].siguiente;
            espacios[x].valor = c;
            espacios[x].siguiente = espacios[insertarAntes].siguiente;
            espacios[insertarAntes].siguiente = x;
        }

        //Actualizar valores
        valores[x] = c + " ";
        return true;
    }

    return false;
}

/**
 * @brief T7Cursores::agregarEspacio - Elimina el espacio y lo agrega a la lista de disponibles
 * @param pos - Posición a eliminar
 */
void T7Cursores::agregarEspacio(int pos){
    int currentLibre = inicios[0];
    inicios[0] = pos;
    espacios[pos].siguiente = currentLibre;
}

/**
 * @brief T7Cursores::getAnterior - Obtiene el objeto anterior al que tenemos
 * @param lista - Indice de lista donde buscar
 * @param pos - Posicion actual
 * @return int de la posición anterior al actual
 */
int T7Cursores::getAnterior(int lista, int pos){
    int begLista = inicios[lista];

    while(espacios[begLista].siguiente != pos)
        begLista = espacios[begLista].siguiente;

    return begLista;
}

/**
 * @brief T7Cursores::eliminar - Elimina un objeto de la lista
 * @param lista - lista de donde eliminar
 * @param c - Valor a eliminar
 */
bool T7Cursores::eliminar(int lista, QString c){
    int actual = buscar(lista, c);
    if(actual != -1){//comparar que el objeto exista
        if(actual == inicios[lista]){//si es el inicio, cambiar
            inicios[lista] = espacios[actual].siguiente;
        }else{//sino, comparar el resto de casos
            int anterior = getAnterior(lista, actual);
            if(espacios[actual].siguiente == -1)//si es el final
                espacios[anterior].siguiente = -1;
            else{//si está en el medio
                espacios[anterior].siguiente = espacios[actual].siguiente;
            }
        }

        valores[actual] = "_ ";
        agregarEspacio(actual);
        return true;
    }

    return false;
}

/**
 * @brief T7Cursores::actualizarLabelListas
 * Actualiza el lListas con los valores actuales
 */
void T7Cursores::actualizarLabelListas(){
    ui->lListas->clear();
    for(int i = 0; i < SIZE_LISTAS; i++)
        ui->lListas->setText(ui->lListas->text() + valores[i]);
}

QString T7Cursores::obtenerValor(){
    QString q = ui->lValor->text();
    ui->lValor->clear();

    return q;
}

void T7Cursores::showFullMsg(){
    QMessageBox qM;
    qM.setText("Ya no hay espacio.");
    qM.exec();
}

bool T7Cursores::validarListaDisponibles(){
    if(ui->tLista->text().toInt() == 0){
        QMessageBox qM;
        qM.setText("No puede ingresar o eliminar valores en la lista de disponibles.");
        return true;
    }

    return false;
}

/***BOTONES***/

void T7Cursores::printPruebas(){
    cout<<endl<<"LISTAS:"<<endl;
    for(int i = 0; i < SIZE_LISTAS; i++)
        cout<<"Pos: "<<i<<" con valor: "<<espacios[i].valor.toStdString()<<" con su siguiente: "<<espacios[i].siguiente<<endl;

    cout<<endl<<endl<<"INICIOS:"<<endl;

    for(int i = 0; i < SIZE_LISTAS; i++)
        cout<<"Pos: "<<i<<" con su siguiente: "<<inicios[i]<<endl;
}

void T7Cursores::on_bCrear_clicked()
{
    QString q = obtenerValor();

    if(q.isEmpty())
        return;

    if(crearLista(q))
        actualizarLabelListas();
    else
        showFullMsg();

    printPruebas();
}

void T7Cursores::on_bAgregar_clicked()
{
    QString q = obtenerValor();
    if(q.isEmpty() || ui->tLista->text().isEmpty())
        return;

    int lista = ui->tLista->text().toInt();
    if(validarListaDisponibles())
        return;

    ui->tLista->clear();

    if(agregar(lista, q))
        actualizarLabelListas();
    else
        showFullMsg();

    cout<<"*****AGREGAR: "<<endl;

    printPruebas();
}

void T7Cursores::on_bInsertar_clicked()
{
    QString q = obtenerValor();

    if(q.isEmpty() || ui->tLista->text().isEmpty() || ui->tPosicion->text().isEmpty())
        return;

    QString pos = ui->tPosicion->text();
    ui->tPosicion->clear();

    int lista = ui->tLista->text().toInt();
    if(validarListaDisponibles())
        return;

    ui->tLista->clear();

    if(insertar(lista, pos, q))
        actualizarLabelListas();
    else
        showFullMsg();
}

void T7Cursores::on_bEliminar_clicked()
{
    QString q = obtenerValor();

    if(q.isEmpty() || ui->tLista->text().isEmpty())
        return;

    int lista = ui->tLista->text().toInt();
    if(validarListaDisponibles())
        return;

    ui->tLista->clear();

    if(eliminar(lista, q))
        actualizarLabelListas();
}

void T7Cursores::on_pushButton_5_clicked()
{
    QString q = obtenerValor();

    if(q.isEmpty() || ui->tLista->text().isEmpty())
        return;

    int lista = ui->tLista->text().toInt();
    ui->tLista->clear();

    QMessageBox qM;
    if(buscar(lista, q) != -1)
        qM.setText("El valor existe en la lista.");
    else
        qM.setText("El valor no existe en la lista.");

    qM.exec();
}
