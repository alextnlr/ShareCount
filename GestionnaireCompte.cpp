//
// Created by niciavel on 10/11/2021.
//

#include "GestionnaireCompte.h"

using namespace std;

GestionnaireCompte::GestionnaireCompte() {
    m_compte_co = 0;
}

bool GestionnaireCompte::verification_client(std::string *informations) {
    return false;
}

void GestionnaireCompte::creation_compte(std::string *informations) {
    if (verification_client(informations)) {
        m_comptes.insert(id, Compte(informations[0], informations[1], id, informations[2]));
    }
}

std::string GestionnaireCompte::connexion(std::string *informations) {
    return std::string();
}

Compte GestionnaireCompte::compte_connecte() {
    return m_comptes.at(m_compte_co);
}

GestionnaireCompte::~GestionnaireCompte() {}
