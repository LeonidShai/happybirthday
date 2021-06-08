#include "DbManager.h"
#include <QDebug>

const QString DbManager::DATABASE_HOST = "localhost";
const QString DbManager::DATABASE_NAME = "../db/birth.db";

DbManager::DbManager(QObject* parent):
    QObject(parent),
    m_isOpen(false)
{
    open();
    if(m_isOpen){
        //search();
    }
}

DbManager::~DbManager()
{
    m_db.close();
}

void DbManager::insert(const Friend &ami)
{
    QString queryStr = "insert into birthday (name, surname, birth_date) "
                       "values (:name, :surname, :birth_date)";
    QSqlQuery query;
    query.prepare(queryStr);

    query.bindValue(":name", ami.name());
    query.bindValue(":surname", ami.surname());
    query.bindValue(":birth_date", ami.birthDate());

    if(query.exec()){
        qDebug() << "data insert into bd" << Qt::endl;
    }
}

Friend DbManager::search(const Friend &ami)
{
    QString queryStr = "select name, surname, birth_date"
                       " from birthday where name = '" + ami.name() + "';";
    QSqlQuery query;
    query.prepare(queryStr);

    Friend amico;

    if(query.exec()){
        QSqlRecord rec = query.record();
        while(query.next()){
            amico.setName(query.value(rec.indexOf("name")).toString());
            amico.setSurname(query.value(rec.indexOf("surname")).toString());
            amico.setBirthDate(query.value(rec.indexOf("birth_date")).toString());
        }
        qDebug() << amico.name() << " " << amico.surname() << " " << amico.birthDate() << Qt::endl;
    }
    return amico;
}

bool DbManager::isOpen()
{
    return m_isOpen;
}

void DbManager::open()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setHostName(DATABASE_HOST);
    m_db.setDatabaseName(DATABASE_NAME);

    if(m_db.open()){
        qDebug() << "database is open" << Qt::endl;
        m_isOpen = true;
    } else {
        qDebug() << "database not open" << Qt::endl;
    }
}
