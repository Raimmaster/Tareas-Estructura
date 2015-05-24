#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "T1/T1Semaforo.h"
#include "T2/t2cartas.h"
#include "T3/T3ListadeArreglos.h"
#include "T4/t4apuntadores.h"
#include "T5/T5Colas.h"
#include "T6/T6Pilas.h"
#include "T7/T7Cursores.h"
#include "T8/T8Conjuntos.h"

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

void MainWindow::on_bT2_clicked()
{
    T2Cartas t;
    t.setModal(true);
    t.exec();
}

void MainWindow::on_bT3_clicked()
{
    T3ListadeArreglos t;
    t.setModal(true);
    t.exec();
}

void MainWindow::on_bT4_clicked()
{
    T4Apuntadores t;
    t.setModal(true);
    t.exec();
}

void MainWindow::on_bT6_clicked()
{

    T6Pilas t;
    t.setModal(true);
    t.exec();
}

void MainWindow::on_bT5_clicked()
{
    T5Colas t;
    t.setModal(true);
    t.exec();
}

void MainWindow::on_bT7_clicked()
{
    T7Cursores t;
    t.setModal(true);
    t.exec();
}

void MainWindow::on_bT8_clicked()
{
    T8Conjuntos t;
    t.setModal(true);
    t.exec();
}
