#ifndef GESTIONNAIREBDD_H
#define GESTIONNAIREBDD_H

#define NOMSQL "/data.sql"

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
    void ajouterCompte(int id, std::string nom, std::string prenom, std::string mdp);
    void chercheAlex();
    static int lastId();
};

#endif // GESTIONNAIREBDD_H
