#include "cagnotte.h"

using namespace std;

Cagnotte::Cagnotte(std::string nom, int idCagnotte, Compte* createur, int budget) : m_nom(nom), m_idCagnotte(idCagnotte), m_budget(budget)
{
    m_comptes[createur->getIdentifiant()] = createur;
    m_idCreateur = createur->getIdentifiant();
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

bool Cagnotte::participe(int id){
    bool result = false;
    for (const auto& nom : m_comptes){
        if (!result)
        {
            if (nom.second->getIdentifiant() == id){
                result = true;
            }
        }
    }
    return result;
}

Cagnotte::~Cagnotte()
{
    for(auto& compte : m_comptes)
    {
        delete compte.second;
    }
}
