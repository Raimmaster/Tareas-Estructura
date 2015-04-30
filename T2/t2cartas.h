#ifndef T2CARTAS_H
#define T2CARTAS_H

#include <QDialog>

namespace Ui {
    class T2Cartas;
}

class T2Cartas : public QDialog
{
        Q_OBJECT

    public:
        explicit T2Cartas(QWidget *parent = 0);
        void trim();
        bool buscar(QString q);
        //const int SIZE = 20;
        ~T2Cartas();

    private slots:
        void on_tValor_returnPressed();

        void on_bEliminarDuplicados_clicked();

private:
        Ui::T2Cartas *ui;
//        QString* oriList;
//        QString* newList;
        int cantItems = 0, currentInsert = 0;
};

#endif // T2CARTAS_H
