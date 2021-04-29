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

void MainWindow::setObserver(Observer* observer)
{
    _observer = observer;
}

void MainWindow::notify()
{
    _observer->update(_msg);
}

void MainWindow::setComponent(Component* component)
{
    _component = component;
    _component->setMediator(this);
}

void MainWindow::Notify(BaseComponent *sender, QString event) const
{

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

void MainWindow::on_pushButton_find_clicked()
{

}

void MainWindow::on_pushButton_save_clicked()
{
    _msg = _ui->lineEdit_name->text();
    notify();
}

void MainWindow::on_pushButton_clearEdit_clicked()
{
    _ui->lineEdit_name->clear();
    _ui->lineEdit_surname->clear();
    _ui->lineEdit_birthday->clear();
}
