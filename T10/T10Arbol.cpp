#include "T10Arbol.h"
#include "ui_T10Arbol.h"

T10Arbol::T10Arbol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T10Arbol)
{    
    ui->setupUi(this);
}

T10Arbol::~T10Arbol()
{
    binaryTree.limpiarArbol();
    delete ui;
}

bool T10Arbol::checkValue(){
    QString valor = ui->lValor->text();
    ui->lValor->clear();

    if(valor.isEmpty())
        return false;

    number = valor.toInt();
    return true;
}

void T10Arbol::on_bInsertar_clicked()
{
    if(!checkValue())
        return;

    binaryTree.insertar(number);
    //Traversals
    cout<<endl<<"Infix:"<<endl;
    binaryTree.infix(&binaryTree);
    cout<<endl<<"Prefix:"<<endl;
    binaryTree.prefix(&binaryTree);
    cout<<endl<<"Postfix:"<<endl;
    binaryTree.postfix(&binaryTree);
}

void T10Arbol::on_bBuscar_clicked()
{
    if(!checkValue())
        return;

    QMessageBox qM;
    qM.setText("No existe.");

    if(binaryTree.buscar(number))
        qM.setText("El número está dentro del árbol.");

    qM.exec();
}
