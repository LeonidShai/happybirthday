#include "Subscriber.h"
#include <QDebug>

Subscriber::Subscriber()
{

}

Subscriber::~Subscriber()
{

}

void Subscriber::setSubject(Subject *subject)
{
    _subject = subject;
    _subject->setObserver(this);
}

void Subscriber::update(const QString str)
{
    _msg = str;
    PrintInfo();
}

void Subscriber::PrintInfo() {
    qDebug() << _msg << Qt::endl;
}
