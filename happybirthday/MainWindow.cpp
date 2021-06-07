#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _dbManager = new DbManager;
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
    _ui->label_name->clear();
    _ui->label_surname->clear();
    _ui->label_birthday->clear();
}

void MainWindow::on_pushButton_search_clicked()
{

}

void MainWindow::on_pushButton_save_clicked()
{
    _msg = _ui->lineEdit_name->text();
}

void MainWindow::on_pushButton_clearEdit_clicked()
{
    _ui->lineEdit_name->clear();
    _ui->lineEdit_surname->clear();
    _ui->lineEdit_birthday->clear();
}
