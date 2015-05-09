#ifndef T7CURSORES_H
#define T7CURSORES_H

#include <QDialog>
#include "CNodo.h"

namespace Ui {
class T7Cursores;
}

class T7Cursores : public QDialog
{
        Q_OBJECT

    public:
        const static int SIZE_LISTAS = 10;
        CNodo espacios[10];
        int inicios[SIZE_LISTAS];
        void inicializar();
        void initEspacios();//init de la lista que contendrá las listas
        void initInicios();//init de la lista que contendrá donde empieza cada lista
        int getInicioVacio();
        void crearLista(char c);
        void agregar(int lista, char c);
        int buscar(int lista, int pos);
        int getAnterior(int lista, int pos);
        void insertar(int lista, int pos, char c);
        void eliminar(int lista, int pos);

        explicit T7Cursores(QWidget *parent = 0);
        ~T7Cursores();

    private:
        Ui::T7Cursores *ui;
};

#endif // T7CURSORES_H
