#include "ShareCount.h"
#include "gestionnairebdd.h"
#include <utility>

ShareCount::ShareCount() {
    m_gestionnaireCompte = new GestionnaireCompte();
    //GestionnaireBDD::hardReset();
    GestionnaireBDD::chercheAlex();
}

int ShareCount::creerCompte(std::string *informations){
    return m_gestionnaireCompte->creation_compte(informations);
}

int ShareCount::connexion(std::string *informations){
    return m_gestionnaireCompte->connexion(informations);
}

ShareCount::~ShareCount()
{
    delete m_gestionnaireCompte;
}
