#include <QFile>
#include <QDebug>
#include "gestionnairebdd.h"

GestionnaireBDD* GestionnaireBDD::m_instance = new GestionnaireBDD();

GestionnaireBDD::GestionnaireBDD()
{
    databaseConnect();
    initBdd();
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
        QSqlQuery query("CREATE TABLE if not exists compte (id INTEGER PRIMARY KEY, nom TEXT, prenom TEXT, mdp TEXT)");

        if(!query.isActive())
            qWarning() << "GestionnaireBDD::initBDD - ERROR: " << query.lastError().text();
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

