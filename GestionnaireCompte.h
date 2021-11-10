//
// Created by niciavel on 10/11/2021.
//

#ifndef SHARECOUNT_GESTIONNAIRECOMPTE_H
#define SHARECOUNT_GESTIONNAIRECOMPTE_H

#include <vector>
#include <string>
#include <map>
#include "Compte.h"

class GestionnaireCompte {
public:
    GestionnaireCompte();
    bool verification_client(std::string* informations);
    void creation_compte(std::string* informations);
    std::string connexion(std::string* informations);
    Compte compte_connecte();
    ~GestionnaireCompte();
private:
    int m_compte_co;
    std::map<int, Compte> m_comptes;
};


#endif //SHARECOUNT_GESTIONNAIRECOMPTE_H
