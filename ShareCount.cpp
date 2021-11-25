#include "ShareCount.h"
#include "gestionnairebdd.h"
#include <utility>

ShareCount::ShareCount() {
    m_gbdd = new GestionnaireBDD();
    m_gestionnaireCompte = new GestionnaireCompte(m_gbdd);
    //m_gbdd->chercheAlex();
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
    delete m_gbdd;
}
