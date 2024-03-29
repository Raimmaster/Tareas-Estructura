#ifndef T1SEMAFORO_H
#define T1SEMAFORO_H

#include <QDialog>

namespace Ui {
    class T1Semaforo;
}

class T1Semaforo : public QDialog
{
    Q_OBJECT

    public:
        explicit T1Semaforo(QWidget *parent = 0);
        void setQLabelColors();
        ~T1Semaforo();

private slots:
    void on_bCheck_clicked();

private:
        Ui::T1Semaforo *ui;
};

#endif // T1SEMAFORO_H
