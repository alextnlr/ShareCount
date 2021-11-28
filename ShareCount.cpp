#include "ShareCount.h"
#include "gestionnairebdd.h"
#include <utility>

ShareCount::ShareCount() {
    GestionnaireBDD::initInstance();
    m_gestionnaireCompte = new GestionnaireCompte();
    m_gestionnaireGroupe = new GestionnaireGroupe();
    //GestionnaireBDD::hardReset();
    GestionnaireBDD::chercheAlex();
}

int ShareCount::creerCompte(std::string *informations){
    return m_gestionnaireCompte->creation_compte(informations);
}

int ShareCount::connexion(std::string *informations){
    return m_gestionnaireCompte->connexion(informations);
}

int ShareCount::creerCagnotte(std::string nom) {
    m_gestionnaireGroupe->addCagnotte(nom, m_gestionnaireCompte->compte_connecte());
    return 0;
}

std::map<int, Cagnotte*> ShareCount::getNomGroupes()
{
    return m_gestionnaireGroupe->getGroupesNom();
}

ShareCount::~ShareCount()
{
    delete m_gestionnaireCompte;
}
