#include "ShareCount.h"
#include "gestionnairebdd.h"
#include <utility>

ShareCount::ShareCount() {
    GestionnaireBDD::initInstance();
    m_gestionnaireCompte = new GestionnaireCompte();
    m_gestionnaireGroupe = new GestionnaireGroupe(m_gestionnaireCompte);
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

void ShareCount::setCurrentGroup(int id_cagnotte){
    m_gestionnaireGroupe->setGroupCurrent(m_gestionnaireGroupe->getCagnotte(id_cagnotte));
}

Cagnotte* ShareCount::getCurrentGroup(){
    return m_gestionnaireGroupe->getGroupCurrent();
}

std::map<int, Cagnotte*> ShareCount::getNomGroupes()
{
    return m_gestionnaireGroupe->getGroupesNom();
}

void ShareCount::addToCagnotte(int montant)
{
    m_gestionnaireGroupe->addToCagnotte(montant);
}

ShareCount::~ShareCount()
{
    delete m_gestionnaireCompte;
}
