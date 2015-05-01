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
    bool buscar(QString q);
    void trim();
    ~T2Cartas();

private slots:
    void on_tValor_returnPressed();

    void on_bQuitar_clicked();

private:
    Ui::T2Cartas *ui;
    QString oriList[15];
    QString newList[15];
    int cantItems = 0, currentInsert = 0;
};

#endif // T2CARTAS_H
