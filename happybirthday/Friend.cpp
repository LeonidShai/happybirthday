#include "Friend.h"

Friend::Friend() : m_empty(true)
{

}

Friend::~Friend()
{

}

void Friend::setName(const QString &name)
{
    if(!name.isEmpty()){
        m_empty = false;
    }
    m_name = name;
}

QString Friend::name() const
{
    return m_name;
}

void Friend::setSurname(const QString &surname)
{
    m_surname = surname;
}

QString Friend::surname() const
{
    return m_surname;
}

void Friend::setBirthDate(const QString &birthDate)
{
    m_birthDate = birthDate;
}

QString Friend::birthDate() const
{
    return m_birthDate;
}

bool Friend::isEmpty() const
{
    return m_empty;
}
