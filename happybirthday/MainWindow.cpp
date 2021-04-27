#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}


void MainWindow::on_pushButton_quit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clearResult_clicked()
{

}

void MainWindow::on_pushButton_find_clicked()
{

}

void MainWindow::on_pushButton_remember_clicked()
{

}

void MainWindow::on_pushButton_clearEdit_clicked()
{

}
