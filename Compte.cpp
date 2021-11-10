/**
 * \file Compte.cpp
 * \brief Classe gérant les comptes utilisateurs
 * \version 1
 * \date 10 novembre 2021
 */

#include "Compte.h"

#include <utility>

using namespace std;

Compte::Compte(string nom, string prenom, string identifiant, string mdp) {
    m_nom = move(nom);
    m_prenom = move(prenom);
    m_identifiant = move(identifiant);
    m_mdp = move(mdp);
}

string Compte::getNom() const{
    return m_nom;
}

string Compte::getIdentifiant() const{
    return m_identifiant;
}

string Compte::getPrenom() const {
    return m_prenom;
}

string Compte::getmdp() const {
    return m_mdp;
}

Compte::~Compte() {}

