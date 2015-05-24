#ifndef T8CONJUNTOS_H
#define T8CONJUNTOS_H

#include <QDialog>
#include <QMessageBox>
#include "Conjunto.h"
#include <vector>

using namespace std;

namespace Ui {
class T8Conjuntos;
}

class T8Conjuntos : public QDialog
{
    Q_OBJECT

public:
    void conjuntoUnion();
    void interseccion();
    void diferencia();
    void resetActuales();
    explicit T8Conjuntos(QWidget *parent = 0);
    ~T8Conjuntos();

private slots:
    void on_bInsertar_clicked();

private:
    Conjunto conA, conB;
    vector<int> conC;
    Ui::T8Conjuntos *ui;
};

#endif // T8CONJUNTOS_H
