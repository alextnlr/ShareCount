#include <QFile>
#include <QDebug>
#include "gestionnairebdd.h"

GestionnaireBDD* GestionnaireBDD::m_instance = new GestionnaireBDD();

GestionnaireBDD::GestionnaireBDD()
{
    databaseConnect();
    initBdd();
}

void GestionnaireBDD::initInstance()
{

}

void GestionnaireBDD::databaseConnect()
{
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER))
        {
            QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

            db.setDatabaseName(QDir::currentPath() + NOMSQL);

            if(!db.open())
                qWarning() << "GestionnaireBDD::databaseConnect - ERROR: " << db.lastError().text();
        }
        else
            qWarning() << "GestionnaireBDD::databaseConnect - ERROR: no driver " << DRIVER << " available";
}

void GestionnaireBDD::initBdd()
{
        QSqlQuery queryCompte("CREATE TABLE if not exists compte (id INTEGER PRIMARY KEY, nom TEXT, prenom TEXT, mdp TEXT, montant INTEGER)");

        if(!queryCompte.isActive())
            qWarning() << "GestionnaireBDD::initBDD - ERROR: " << queryCompte.lastError().text();

        QSqlQuery queryCagnotte("CREATE TABLE if not exists cagnotte (id_cagnotte INTEGER PRIMARY KEY, nom_cagnotte TEXT, budget_cagnotte INT, id_createur INT, FOREIGN KEY(id_createur) REFERENCES compte(id))");

        if(!queryCagnotte.isActive())
            qWarning() << "GestionnaireBDD::initBDD - ERROR: " << queryCagnotte.lastError().text();

        QSqlQuery queryParticipation("CREATE TABLE if not exists participation (id INTEGER, id_cagnotte INTEGER, PRIMARY KEY(id, id_cagnotte), FOREIGN KEY(id) REFERENCES compte(id), FOREIGN KEY(id_cagnotte) REFERENCES cagnotte(id_cagnotte))");

        if(!queryParticipation.isActive())
            qWarning() << "GestionnaireBDD::initBDD - ERROR: " << queryCagnotte.lastError().text();

}

void GestionnaireBDD::ajouterCompte(int id, std::string nom, std::string prenom, std::string mdp)
{
    QSqlQuery query;

    query.prepare("INSERT INTO compte(id, nom, prenom, mdp, montant) VALUES(:id, :nom, :prenom, :mdp, :montant)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom.c_str());
    query.bindValue(":prenom", prenom.c_str());
    query.bindValue(":mdp", mdp.c_str());
    query.bindValue(":montant", 0);

    if(!query.exec())
        qWarning() << "GestionnaireBDD::ajouterCompte - ERROR: " << query.lastError().text();
}

void GestionnaireBDD::ajouterCagnotte(int id_cagnotte, std::string nom, int id_createur)
{
    QSqlQuery queryCagnotte;

    queryCagnotte.prepare("INSERT INTO cagnotte(id_cagnotte, nom_cagnotte, budget_cagnotte, id_createur) VALUES(:id_cagnotte, :nom_cagnotte, :budget_cagnotte, :id_createur)");
    queryCagnotte.bindValue(":id_cagnotte", id_cagnotte);
    queryCagnotte.bindValue(":nom_cagnotte", nom.c_str());
    queryCagnotte.bindValue(":budget_cagnotte", 0);
    queryCagnotte.bindValue(":id_createur", id_createur);

    if(!queryCagnotte.exec())
        qWarning() << "GestionnaireBDD::ajouterCagnotte cagnotte - ERROR: " << queryCagnotte.lastError().text();

    GestionnaireBDD::ajouterParticipant(id_cagnotte, id_createur);
}

void GestionnaireBDD::ajouterParticipant(int id_cagnotte, int id_participant)
{
    QSqlQuery queryParticipation;

    queryParticipation.prepare("INSERT INTO participation(id, id_cagnotte) VALUES(:id, :id_cagnotte)");
    queryParticipation.bindValue(":id", id_participant);
    queryParticipation.bindValue(":id_cagnotte", id_cagnotte);

    if(!queryParticipation.exec())
        qWarning() << "GestionnaireBDD::ajouterCagnotte participation - ERROR: " << queryParticipation.lastError().text();
}

void GestionnaireBDD::hardReset()
{
    QSqlQuery query;

    if(!query.exec("DELETE FROM compte"))
        qWarning() << "GestionnaireBDD::chercheAlex - ERROR: " << query.lastError().text();
}

void GestionnaireBDD::chercheAlex()
{
    QSqlQuery query;

    if(!query.exec("SELECT id, nom, prenom, mdp FROM compte"))
        qWarning() << "GestionnaireBDD::chercheAlex - ERROR: " << query.lastError().text();
    else
    {
        while (query.next())
            qDebug() << query.value(0).toInt() << " " << query.value(1).toString() << " " << query.value(2).toString() << " " << query.value(3).toString();
    }
}

int GestionnaireBDD::lastIdCompte()
{
    QSqlQuery query;
    int value = -1;
    if (!query.exec("SELECT MAX(id) FROM compte"))
        qWarning() << "GestionnaireBDD::lastIdCompte - ERROR: " << query.lastError().text();
    else
    {
        while (query.next()){
            value = query.value(0).toInt();
        }
    }
    return value;
}

int GestionnaireBDD::lastIdCagnotte()
{
    QSqlQuery query;
    int value = -1;
    if (!query.exec("SELECT MAX(id_cagnotte) FROM cagnotte"))
        qWarning() << "GestionnaireBDD::lastIdCagnotte - ERROR: " << query.lastError().text();
    else
    {
        while (query.next()){
            value = query.value(0).toInt();
        }
    }
    return value;
}

int GestionnaireBDD::nbCompte()
{
    QSqlQuery query;
    int value = 0;
    if (!query.exec("SELECT COUNT(*) FROM compte"))
        qWarning() << "GestionnaireBDD::nbCompte - ERROR: " << query.lastError().text();
    else
    {
        while (query.next())
            value = query.value(0).toInt();
    }
    return value;
}

QVector<QVector<QString>> GestionnaireBDD::getCompteBdd()
{
    QSqlQuery query;
    QVector<QVector<QString>> comptes;

    if (!query.exec("SELECT id, nom, prenom, mdp, montant FROM compte"))
        qWarning() << "GestionnaireBDD::getCompte - ERROR: " << query.lastError().text();
    else
    {
        while (query.next()){
            QVector<QString> current = QVector<QString>(5);
            current[0] = query.value(0).toString();
            current[1] = query.value(1).toString();
            current[2] = query.value(2).toString();
            current[3] = query.value(3).toString();
            current[4] = query.value(4).toString();
            comptes.push_back(current);
        }
    }

    return comptes;
}

QVector<QVector<QString>> GestionnaireBDD::getCagnotteBdd()
{
    QSqlQuery query;
    QVector<QVector<QString>> cagnottes;

    if (!query.exec("SELECT id_cagnotte, nom_cagnotte, budget_cagnotte, id_createur FROM cagnotte"))
        qWarning() << "GestionnaireBDD::getCagnotte - ERROR: " << query.lastError().text();
    else
    {
        while (query.next()){
            QVector<QString> current = QVector<QString>(4);
            current[0] = query.value(0).toString();
            current[1] = query.value(1).toString();
            current[2] = query.value(2).toString();
            current[3] = query.value(3).toString();
            cagnottes.push_back(current);
        }
    }

    return cagnottes;
}

QVector<int> GestionnaireBDD::getParticipation(int id_cagnotte)
{
    QSqlQuery query;
    QVector<int> participants;

    query.prepare("SELECT id FROM participation WHERE id_cagnotte=:id_cagnotte");

    query.bindValue(":id_cagnotte", id_cagnotte);

    if (!query.exec())
        qWarning() << "GestionnaireBDD::getCagnotte - ERROR: " << query.lastError().text();
    else
    {
        while (query.next()){
            participants.push_back(query.value(0).toInt());
        }
    }

    return participants;
}

void GestionnaireBDD::updateMontantCagnotte(int id_cagnotte, int montant)
{
    QSqlQuery query;

    query.prepare("UPDATE cagnotte SET budget_cagnotte=:budget WHERE id_cagnotte=:id");
    query.bindValue(":budget", montant);
    query.bindValue(":id", id_cagnotte);

    if(!query.exec())
        qWarning() << "Gestionnaire::BDD - ERROR " << query.lastError().text();
}

void GestionnaireBDD::updateNomCagnotte(int id_cagnotte, std::string nom)
{
    QSqlQuery query;

    query.prepare("UPDATE cagnotte SET nom_cagnotte=:nom WHERE id_cagnotte=:id");
    query.bindValue(":nom", QString::fromStdString(nom));
    query.bindValue(":id", id_cagnotte);

    if(!query.exec())
        qWarning() << "GestionnaireBDD::updateNomCagnotte - ERROR " << query.lastError().text();
}

void GestionnaireBDD::updateMontantCompte(int id_compte, int montant)
{
    QSqlQuery query;

    query.prepare("UPDATE compte SET montant=:montant WHERE id=:id");
    query.bindValue(":montant", montant);
    query.bindValue(":id", id_compte);

    if(!query.exec())
        qWarning() << "GestionnaireBDD::updateMontantCompte - ERROR " << query.lastError().text();
}
