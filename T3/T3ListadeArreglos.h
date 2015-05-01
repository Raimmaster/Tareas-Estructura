#ifndef T3LISTADEARREGLOS_H
#define T3LISTADEARREGLOS_H

#include <QDialog>

namespace Ui {
class T3ListadeArreglos;
}

class T3ListadeArreglos : public QDialog
{
    Q_OBJECT

public:
    explicit T3ListadeArreglos(QWidget *parent = 0);
    bool append(QString value);
    int search(QString value);
    void clear();
    bool insert(int pos, QString value);
    bool eliminar(int pos);
    ~T3ListadeArreglos();

private slots:
    void on_bAgregar_clicked();

    void on_pushButton_clicked();

    void on_bBuscar_clicked();

    void on_bEliminar_clicked();

    void on_bInsertar_clicked();

private:
    Ui::T3ListadeArreglos *ui;
};

#endif // T3LISTADEARREGLOS_H
