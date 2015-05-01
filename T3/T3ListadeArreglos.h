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
    bool append(int num);
    int search(int num);
    void clear();
    bool insert(int pos, int num);
    ~T3ListadeArreglos();

private:
    Ui::T3ListadeArreglos *ui;
};

#endif // T3LISTADEARREGLOS_H
