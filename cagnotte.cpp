#include "cagnotte.h"

using namespace std;

Cagnotte::Cagnotte(std::string nom, int idCagnotte, Compte* createur, int budget) : m_nom(nom), m_idCagnotte(idCagnotte), m_budget(budget)
{
    m_comptes[createur->getIdentifiant()] = createur;
    m_idCreateur = createur->getIdentifiant();

    recupDemandesBdd();
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

void Cagnotte::setNom(std::string nom)
{
    m_nom = nom;
}

void Cagnotte::creerDemande(int montant, int id_demandeur)
{
    int id = GestionnaireBDD::lastIdDemande()+1;
    if (montant<= m_budget){
        m_demandes[id] = new Demande(id, id_demandeur, montant);
        GestionnaireBDD::ajouterDemande(id, montant, m_idCagnotte, id_demandeur);
    }
}

const std::map<int, Demande*> Cagnotte::getDemandes()
{
    return m_demandes;
}

void Cagnotte::recupDemandesBdd()
{
    QVector<QVector<int>> tab = GestionnaireBDD::getDemande(m_idCagnotte);
    for(const auto& value: tab){
        m_demandes[value[0]] = new Demande(value[0], value[1], value[2], value[3]);
    }
}


Cagnotte::~Cagnotte()
{
    for(auto& compte : m_comptes)
        delete compte.second;

    for(auto& demande : m_demandes)
        delete demande.second;
}
