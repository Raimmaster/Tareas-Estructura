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
        CNodo espacios[SIZE_LISTAS];
        int inicios[SIZE_LISTAS];
        void inicializar();
        void initEspacios();//init de la lista que contendrá las listas
        void initInicios();//init de la lista que contendrá donde empieza cada lista
        int getInicioVacio();
        bool crearLista(QString c);
        bool agregar(int lista, QString c);
        int buscar(int lista, QString c);
        bool insertar(int lista, int pos, QString c);
        int getAnterior(int lista, int pos);
        void agregarEspacio(int pos);//parámetro es la posición a vaciar
        bool eliminar(int lista, QString c);
        //FUNCIONES RELACIONADAS AL FORM
        void initValores();
        void actualizarLabelListas();
        QString obtenerValor();
        void showFullMsg();
        bool validarListaDisponibles();
        void printPruebas();
        explicit T7Cursores(QWidget *parent = 0);
        ~T7Cursores();

private slots:
        void on_bCrear_clicked();

        void on_bAgregar_clicked();

        void on_bInsertar_clicked();

        void on_bEliminar_clicked();

        void on_pushButton_5_clicked();

private:
        Ui::T7Cursores *ui;
};

#endif // T7CURSORES_H
