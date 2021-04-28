#include <MainWindow.h>
#include <Subscriber.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Subscriber* subscriber = new Subscriber;
    subscriber->setSubject(&w);

    w.show();
    return a.exec();
}
