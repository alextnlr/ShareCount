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
        QSqlQuery queryCompte("CREATE TABLE if not exists compte (id INTEGER PRIMARY KEY, nom TEXT, prenom TEXT, mdp TEXT)");

        if(!queryCompte.isActive())
            qWarning() << "GestionnaireBDD::initBDD - ERROR: " << queryCompte.lastError().text();

        QSqlQuery queryCagnotte("CREATE TABLE if not exists cagnotte (id_cagnotte INTEGER PRIMARY KEY, nom_cagnotte TEXT, budget_cagnotte INT, id_createur INT, FOREIGN KEY(id_createur) REFERENCES compte(id))");

        if(!queryCagnotte.isActive())
            qWarning() << "GestionnaireBDD::initBDD - ERROR: " << queryCagnotte.lastError().text();

}

void GestionnaireBDD::ajouterCompte(int id, std::string nom, std::string prenom, std::string mdp)
{
    QSqlQuery query;

    query.prepare("INSERT INTO compte(id, nom, prenom, mdp) VALUES(:id, :nom, :prenom, :mdp)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom.c_str());
    query.bindValue(":prenom", prenom.c_str());
    query.bindValue(":mdp", mdp.c_str());

    if(!query.exec())
        qWarning() << "GestionnaireBDD::ajouterCompte - ERROR: " << query.lastError().text();
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

int GestionnaireBDD::lastId()
{
    QSqlQuery query;
    int value = -1;
    if (!query.exec("SELECT MAX(id) FROM compte"))
        qWarning() << "GestionnaireBDD::lastId - ERROR: " << query.lastError().text();
    else
    {
        while (query.next()){
            value = query.value(0).toInt();
            qDebug() << value;
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

    if (!query.exec("SELECT id, nom, prenom, mdp FROM compte"))
        qWarning() << "GestionnaireBDD::nbCompte - ERROR: " << query.lastError().text();
    else
    {
        while (query.next()){
            QVector<QString> current = QVector<QString>(4);
            current[0] = query.value(0).toString();
            current[1] = query.value(1).toString();
            current[2] = query.value(2).toString();
            current[3] = query.value(3).toString();
            comptes.push_back(current);
        }
    }

    return comptes;
}
