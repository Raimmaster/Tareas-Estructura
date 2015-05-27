#ifndef T6PILAS_H
#define T6PILAS_H

#include <QDialog>
#include "Nodo.h"

namespace Ui {
class T6Pilas;
}

class T6Pilas : public QDialog
{
    Q_OBJECT

public:    
    explicit T6Pilas(QWidget *parent = 0);
    Nodo<QString>* getTope();
    void meter(Nodo<QString>* obj);
    bool sacar();
    bool isEmpty();
    void anular();
    ~T6Pilas();

private slots:
    void on_bAgregar_clicked();

    void on_bSacar_clicked();

    void on_bTope_clicked();

    void on_bVacia_clicked();

    void on_bAnular_clicked();

private:
    Ui::T6Pilas *ui;
    Nodo<QString>* tope = NULL;
};

#endif // T6PILAS_H
