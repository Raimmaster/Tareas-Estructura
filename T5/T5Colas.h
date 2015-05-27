#ifndef T5COLAS_H
#define T5COLAS_H

#include <QDialog>
#include "T6/Nodo.h"

namespace Ui {
class T5Colas;
}

class T5Colas : public QDialog
{
    Q_OBJECT

public:
    Nodo<QString>* frente = NULL;
    Nodo<QString>* ultimo = NULL;
    Nodo<QString>* getFrente();
    void anular();
    bool isEmpty();
    void ponerEnCola(Nodo<QString>* n);
    bool quitarDeCola();
    explicit T5Colas(QWidget *parent = 0);
    ~T5Colas();

private slots:
    void on_bAgregar_clicked();

    void on_bQuitar_clicked();

    void on_bTope_clicked();

    void on_bVacia_clicked();

    void on_bAnular_clicked();

private:
    Ui::T5Colas *ui;
};

#endif // T5COLAS_H
