#include "cagnotte.h"

using namespace std;

Cagnotte::Cagnotte(std::string nom, int idCagnotte, Compte* Createur)
{
    m_nom = nom;
    m_idCagnotte = idCagnotte;
    m_comptes[Createur->getIdentifiant()] = Createur;
    m_idCreateur = Createur->getIdentifiant();
    m_budget = 0;
}

void Cagnotte::addParticipant(Compte* compte){
    m_comptes[compte->getIdentifiant()] = compte;
}

void Cagnotte::addBudget(int toAdd){
    m_budget += toAdd;
}

string Cagnotte::getNom(){
    return m_nom;
}

int Cagnotte::getIdCagnotte(){
    return m_idCagnotte;
}

int Cagnotte::getIdCreateur(){
    return m_idCreateur;
}

int Cagnotte::getBudget(){
    return m_budget;
}

Compte* Cagnotte::getParticipant(int id){
    return m_comptes[id];
}

std::map<int, Compte*> Cagnotte::getListeParticipant(){
    return m_comptes;
}
