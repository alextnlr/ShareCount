#include "GestionnaireCompte.h"

using namespace std;

GestionnaireCompte::GestionnaireCompte() {
    m_compte_co = 0;
    m_fabriqueIdentifiant = FabriqueIdentifiant::getInstance();
}

bool GestionnaireCompte::verification_client(std::string *informations) {
    bool valid_infos = true;
    if (informations[0].length() < 1 || informations[1].length() < 1 || informations[2].length() < 5) {
        valid_infos = false;
    }
    for (auto& compte : m_comptes) {
        if (informations[0] != compte.second->getNom() && informations[1] != compte.second->getPrenom()) {
            valid_infos = false;
        }
    }
    return valid_infos;
}

void GestionnaireCompte::creation_compte(std::string *informations) {
    if (verification_client(informations)) {
        int id = m_fabriqueIdentifiant->getIdenfiant();
        m_comptes [id] = new Compte(informations[0], informations[1], id, informations[2]);
    }
}

void GestionnaireCompte::connexion(std::string *informations) {
    
}

Compte* GestionnaireCompte::compte_connecte() {
    return m_comptes.at(m_compte_co);
}

GestionnaireCompte::~GestionnaireCompte() {
    for (auto& compte : m_comptes) {
        delete compte.second;
    }
}

