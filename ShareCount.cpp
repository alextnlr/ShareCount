#include "ShareCount.h"
#include "gestionnairebdd.h"
#include <utility>

ShareCount::ShareCount() {
    gbdd = new GestionnaireBDD;
}

int ShareCount::creerCompte(std::string *informations){
    return gestionnaireCompte.creation_compte(informations);
}

int ShareCount::connexion(std::string *informations){
    return gestionnaireCompte.connexion(informations);
}

ShareCount::~ShareCount()
{
    delete gbdd;
}
