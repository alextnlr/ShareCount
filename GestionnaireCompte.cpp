#include "GestionnaireCompte.h"

using namespace std;

GestionnaireCompte::GestionnaireCompte() {
    m_compte_co = 0;
    m_fabriqueIdentifiant = FabriqueIdentifiant::getInstance();
}

bool GestionnaireCompte::verification_client(std::string *informations) {
    return false;
}

void GestionnaireCompte::creation_compte(std::string *informations) {
    if (verification_client(informations)) {
        int id = m_fabriqueIdentifiant->getIdenfiant();
        m_comptes [id] = new Compte(informations[0], informations[1], id, informations[2]);
    }
}

std::string GestionnaireCompte::connexion(std::string *informations) {
    return std::string();
}

Compte* GestionnaireCompte::compte_connecte() {
    return m_comptes.at(m_compte_co);
}

GestionnaireCompte::~GestionnaireCompte() {}

