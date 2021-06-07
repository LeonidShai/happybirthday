#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

class DbManager : public QObject
{
    Q_OBJECT
public:
    explicit DbManager(QObject *parent = nullptr);
    ~DbManager();

    void insert();
    void search();
    bool isOpen();

private:
    QSqlDatabase  m_db;
    bool          m_isOpen;

    static const QString DATABASE_HOST;
    static const QString DATABASE_NAME;

    void open();
};

#endif // DBMANAGER_H
