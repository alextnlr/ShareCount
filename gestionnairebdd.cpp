#include <QFile>
#include "gestionnairebdd.h"

GestionnaireBDD::GestionnaireBDD()
{

}

void GestionnaireBDD::initBdd()
{
    if(QFile::exists("Compte.cpp"))
    {
        printf("oui\n");
    }
    else {
        printf("bleg\n");
    }
}
