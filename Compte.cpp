#include "Compte.h"
#include <QDebug>
#include <utility>

using namespace std;

Compte::Compte(string nom, string prenom, int identifiant, string mdp, int montant) : m_nom(nom), m_prenom(prenom), m_identifiant(identifiant), m_mdp(mdp), m_montant(montant) {

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
    GestionnaireBDD::updateMontantCompte(m_identifiant, m_montant);
}

void Compte::withdraw(int montant){
    m_montant -= montant;
    GestionnaireBDD::updateMontantCompte(m_identifiant, m_montant);
}

int Compte::getMontant(){
    return m_montant;
}

Compte::~Compte() {}

