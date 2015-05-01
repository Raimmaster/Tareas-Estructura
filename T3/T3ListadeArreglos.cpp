#include "T3ListadeArreglos.h"
#include "ui_T3ListadeArreglos.h"

const int SIZE = 15;
int arreglo[SIZE];
int actual = 0;

T3ListadeArreglos::T3ListadeArreglos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::T3ListadeArreglos)
{
    ui->setupUi(this);
}

T3ListadeArreglos::~T3ListadeArreglos()
{
    delete ui;
}

bool T3ListadeArreglos::append(int num){
    if(actual < SIZE){
        arreglo[actual++] ) num;
        return true;
    }

    return false;
}

int T3ListadeArreglos::search(int num){
    for(int i = 0; i < actual; i++){
        if(arreglo[i] == num)
            return i;
    }

    return -1;
}

void T3ListadeArreglos::clear(){
    for(int i = 0; i < actual; i++){
        arreglo[i] = 0;

        actual = 0;
    }
}

bool T3ListadeArreglos::insert(int pos, int num){
    if(actual < SIZE && pos < actual){
        for(int i = actual - 1; i >= pos; i--)
            arreglo[i + 1] = arreglo[i];

        arreglo[pos] = num;
        actual++;
        return true;
    }

    return false;
}
