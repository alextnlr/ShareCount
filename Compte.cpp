//
// Created by timeo on 10/11/2021.
//

#include "Compte.h"

#include <utility>

using namespace std;

Compte::Compte(string nom, string prenom, string identifiant, string mdp) {
    m_nom = move(nom);
    m_prenom = move(prenom);
    m_identifiant = move(identifiant);
    m_mdp = move(mdp);
}