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

    _ui->label_name->setText("---");
    _ui->label_surname->setText("---");
    _ui->label_birthday->setText("---");
}

void MainWindow::on_pushButton_search_clicked()
{
    Friend ami;
    ami.setName(_ui->lineEdit_name->text());
    ami.setSurname(_ui->lineEdit_surname->text());
    // int day = _ui->lineEdit_day->text().toInt();
    // int month = _ui->lineEdit_month->text().toInt();

    // QString birthday = QString(day) + "." + QString(month);

    Friend amico;
    amico = _dbManager->search(ami);

    if(!amico.isEmpty()){
        _ui->label_name->setText(amico.name());
        _ui->label_surname->setText(amico.surname());
        _ui->label_birthday->setText(amico.birthDate());
    }
}

void MainWindow::on_pushButton_save_clicked()
{
    Friend amico;
    amico.setName(_ui->lineEdit_name->text());
    amico.setSurname(_ui->lineEdit_surname->text());
    int day = _ui->lineEdit_day->text().toInt();
    int month = _ui->lineEdit_month->text().toInt();

    QString birthday = _ui->lineEdit_day->text() + "." + _ui->lineEdit_month->text();
    amico.setBirthDate(birthday);

    if(_dbManager->isOpen()){
        _dbManager->insert(amico);
    }
}

void MainWindow::on_pushButton_clearEdit_clicked()
{
    _ui->lineEdit_name->clear();
    _ui->lineEdit_surname->clear();
    _ui->lineEdit_day->clear();
    _ui->lineEdit_month->clear();
}
