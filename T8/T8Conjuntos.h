#ifndef T8CONJUNTOS_H
#define T8CONJUNTOS_H

#include <QDialog>

namespace Ui {
class T8Conjuntos;
}

class T8Conjuntos : public QDialog
{
    Q_OBJECT

public:
    explicit T8Conjuntos(QWidget *parent = 0);
    ~T8Conjuntos();

private:
    Ui::T8Conjuntos *ui;
};

#endif // T8CONJUNTOS_H
