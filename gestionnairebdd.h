#ifndef GESTIONNAIREBDD_H
#define GESTIONNAIREBDD_H

#include <QSqlDatabase>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

#include <QApplication>
#include <QDir>

class GestionnaireBDD
{
public:
    GestionnaireBDD();
    void databaseConnect();
    void initBdd();
};

#endif // GESTIONNAIREBDD_H
