#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bT1_clicked();

    void on_bT2_clicked();

    void on_bT3_clicked();

    void on_bT4_clicked();

    void on_bT6_clicked();

    void on_bT5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
