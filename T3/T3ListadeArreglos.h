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
    ~T3ListadeArreglos();

private:
    Ui::T3ListadeArreglos *ui;
};

#endif // T3LISTADEARREGLOS_H
