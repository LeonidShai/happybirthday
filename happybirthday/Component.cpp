#include "Component.h"
#include <QDebug>

void Component::printInfo(QString str)
{
    this->_mediator->Notify(this, "A");
    qDebug() << "Component: " << str << Qt::endl;
}
