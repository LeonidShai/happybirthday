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
        search();
    }
}

DbManager::~DbManager()
{
    m_db.close();
}

void DbManager::insert()
{

}

void DbManager::search()
{
    QString queryStr = "select name, surname, birth_date from birthday where name = 'Артем';";
    QSqlQuery query;
    query.prepare(queryStr);

    QString name;
    QString surname;
    QString birth_date;

    if(query.exec()){
        QSqlRecord rec = query.record();
        while(query.next()){
            name = query.value(rec.indexOf("name")).toString();
            surname = query.value(rec.indexOf("surname")).toString();
            birth_date = query.value(rec.indexOf("birth_date")).toString();
        }
        qDebug() << name << " " << surname << " " << birth_date << Qt::endl;
    }
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
