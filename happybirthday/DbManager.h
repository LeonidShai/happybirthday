#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

#include <Friend.h>

class DbManager : public QObject
{
    Q_OBJECT
public:
    explicit DbManager(QObject *parent = nullptr);
    ~DbManager();

    void insert();
    Friend search(const Friend &ami);
    bool isOpen();

private:
    QSqlDatabase  m_db;
    bool          m_isOpen;

    static const QString DATABASE_HOST;
    static const QString DATABASE_NAME;

    void open();
};

#endif // DBMANAGER_H
