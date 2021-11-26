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
    static void ajouterCompte(int id, std::string nom, std::string prenom, std::string mdp);
    static void chercheAlex();
    static void hardReset();
    static int lastId();
    static int nbCompte();
    static QVector<QVector<QString> > getCompteBdd();
    static void initInstance();
private:
    GestionnaireBDD();
    static void databaseConnect();
    static void initBdd();

    static GestionnaireBDD* m_instance;
};

#endif // GESTIONNAIREBDD_H
