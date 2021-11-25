#include <QFile>
#include <QDebug>
#include "gestionnairebdd.h"

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

            db.setDatabaseName(QDir::currentPath() + "/persos.sql");

            if(!db.open())
                qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
        }
        else
            qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}

void GestionnaireBDD::initBdd()
{
        QSqlQuery query("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");

        if(!query.isActive())
            qWarning() << "MainWindow::DatabaseInit - ERROR: " << query.lastError().text();
}
