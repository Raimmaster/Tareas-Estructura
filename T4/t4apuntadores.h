#ifndef T4APUNTADORES_H
#define T4APUNTADORES_H
#include "Cartas.h"
#include <QDialog>

namespace Ui {
class T4Apuntadores;
}

class T4Apuntadores : public QDialog
{
    Q_OBJECT

public:
    explicit T4Apuntadores(QWidget *parent = 0);
    Cartas* getFinal();
    void agregar(int num);
    void eliminar(int pos);
    Cartas* getPos(int pos);
    Cartas* buscar(int num);
    void insertar(int numero, int pos);

    ~T4Apuntadores();

private:
    Ui::T4Apuntadores *ui;
};

#endif // T4APUNTADORES_H
