#include "Compte.h"

#include <utility>

using namespace std;

Compte::Compte(string nom, string prenom, int identifiant, string mdp) {
    m_nom = move(nom);
    m_prenom = move(prenom);
    m_identifiant = identifiant;
    m_mdp = move(mdp);
}

string Compte::getNom() const{
    return m_nom;
}

int Compte::getIdentifiant() const{
    return m_identifiant;
}

string Compte::getPrenom() const {
    return m_prenom;
}

string Compte::getmdp() const {
    return m_mdp;
}

void Compte::addMontant(int montant){
    m_montant += montant;
}

void Compte::withdraw(int montant){
    m_montant -= montant;
}

int Compte::getMontant(){
    return m_montant;
}

Compte::~Compte() {}

