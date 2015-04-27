#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "T1/T1Semaforo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bT1_clicked()
{
    T1Semaforo t;
    t.setModal(true);
    t.exec();
}
