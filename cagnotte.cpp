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

void Cagnotte::endDemande(int id_demande, bool result)
{
    if (result)
    {
        m_comptes[m_demandes[id_demande]->getIdDemandeur()]->addMontant(m_demandes[id_demande]->getMontant());
        m_budget -= m_demandes[id_demande]->getMontant();
    }

    m_demandes.erase(id_demande);
    GestionnaireBDD::deleteDemande(id_demande);
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

Demande* Cagnotte::getDemande(int id_demande)
{
    return m_demandes[id_demande];
}

int Cagnotte::isDemandeAccepte(int id_demande)
{
    bool termine = true;
    int nbAccepte = 0;
    int result = 0;
    for (const auto& compte : m_comptes)
    {
        if (m_demandes[id_demande]->aAccepte(compte.second->getIdentifiant()) == 1)
        {
            nbAccepte++;
        }
        else if (m_demandes[id_demande]->getIdDemandeur() != compte.second->getIdentifiant() && m_demandes[id_demande]->aAccepte(compte.second->getIdentifiant()) == -1)
        {
            termine = false;
        }
    }

    if(termine)
        result = -1;

    if(m_comptes.size() == 1)
    {
        result = 1;
    }
    else if(m_comptes.size() == 2)
    {
        if(nbAccepte > 0)
            result = 1;
    }
    else
    {
        if(nbAccepte > 1)
            result = 1;
    }

    return result;
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
