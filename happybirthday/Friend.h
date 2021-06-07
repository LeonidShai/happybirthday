#ifndef FRIEND_H
#define FRIEND_H

#include <QString>

class Friend
{
public:
    Friend();
    ~Friend();

    void setName(const QString &name);
    QString name() const;

    void setSurname(const QString &surname);
    QString surname() const;

    void setBirthDate(const QString &birthDate);
    QString birthDate() const;

    bool isEmpty() const;

private:
    QString m_name;
    QString m_surname;
    QString m_birthDate;

    bool m_empty;
};

#endif // FRIEND_H
