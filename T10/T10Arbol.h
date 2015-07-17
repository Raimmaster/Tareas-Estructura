#ifndef T10ARBOL_H
#define T10ARBOL_H

#include <QDialog>
#include "ArbolBinario.h"
#include <QMessageBox>

namespace Ui {
class T10Arbol;
}

class T10Arbol : public QDialog
{
    Q_OBJECT

public:
    explicit T10Arbol(QWidget *parent = 0);
    ~T10Arbol();

private slots:
    void on_bInsertar_clicked();
    
    void on_bBuscar_clicked();

private:
    Ui::T10Arbol *ui;
    ArbolBinario binaryTree;
    int number;
    bool checkValue();
};

#endif // T10ARBOL_H
