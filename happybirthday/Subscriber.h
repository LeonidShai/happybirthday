#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <Subject.h>

class Subscriber : public Observer
{
public:
    Subscriber();
    ~Subscriber();

    void setSubject(Subject* subject);

private:
    Subject*    _subject;
    QString     _msg;

    void update(const QString str) override;
    void PrintInfo();
};

#endif // SUBSCRIBER_H
