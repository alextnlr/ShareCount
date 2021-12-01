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
    static void ajouterParticipant(int id_cagnotte, int id_participant);
    static void ajouterCagnotte(int id_cagnotte, std::string nom, int id_createur);
    static void chercheAlex();
    static void hardReset();
    static int lastIdCompte();
    static int lastIdCagnotte();
    static int nbCompte();
    static QVector<QVector<QString> > getCompteBdd();
    static QVector<QVector<QString> > getCagnotteBdd();
    static QVector<int> getParticipation(int id_cagnotte);
    static void updateMontantCagnotte(int id_cagnotte, int montant);
    static void initInstance();
private:
    GestionnaireBDD();
    static void databaseConnect();
    static void initBdd();

    static GestionnaireBDD* m_instance;
};

#endif // GESTIONNAIREBDD_H
