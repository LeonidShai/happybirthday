#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // выход из программы
    void on_pushButton_quit_clicked();
    // очистка результата поиска
    void on_pushButton_clearResult_clicked();
    // поиск
    void on_pushButton_find_clicked();
    // запомнить дату
    void on_pushButton_save_clicked();
    // очистка ввода
    void on_pushButton_clearEdit_clicked();

private:
    Ui::MainWindow* _ui;
};
#endif // MAINWINDOW_H
