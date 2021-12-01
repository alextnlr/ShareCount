#include "gestionnairegroupe.h"
#include <QDebug>
#include <QString>

GestionnaireGroupe::GestionnaireGroupe(GestionnaireCompte* gestionnaireCompte)
{
    recopieBDD(gestionnaireCompte);
}

void GestionnaireGroupe::addCagnotte(std::string nom, Compte *createur)
{
    int id = GestionnaireBDD::lastIdCagnotte()+1;
    m_groupes[id] = new Cagnotte(nom, id, createur, 0);
    GestionnaireBDD::ajouterCagnotte(id, nom, createur->getIdentifiant());
}

std::map<int, Cagnotte*> GestionnaireGroupe::getGroupesNom()
{
    return m_groupes;
}

void GestionnaireGroupe::recopieBDD(GestionnaireCompte* gestionnaireCompte)
{
    QVector<QVector<QString>> cagnotteBdd = GestionnaireBDD::getCagnotteBdd();

    for(const auto& value : cagnotteBdd)
    {
        int id = std::stoi(value[0].toStdString());
        m_groupes[id] = new Cagnotte(value[1].toStdString(), id, gestionnaireCompte->getCompte(std::stoi(value[3].toStdString())), std::stoi(value[2].toStdString()));
    }

    for(const auto& groupe : m_groupes)
    {
        QVector<int> participant = GestionnaireBDD::getParticipation(groupe.second->getIdCagnotte());
        for(const auto& idParticipant : participant)
        {
            groupe.second->addParticipant(gestionnaireCompte->getCompte(idParticipant));
        }
    }
}

void GestionnaireGroupe::setGroupCurrent(Cagnotte* cagnotte){
    m_groupCurrent = cagnotte;
}

Cagnotte* GestionnaireGroupe::getGroupCurrent(){
    return m_groupCurrent;
}

Cagnotte* GestionnaireGroupe::getCagnotte(int id_cagnotte)
{
    return m_groupes[id_cagnotte];
}

void GestionnaireGroupe::addToCagnotte(int montant)
{
    m_groupCurrent->addBudget(montant);
    GestionnaireBDD::updateMontantCagnotte(m_groupCurrent->getIdCagnotte(), m_groupCurrent->getBudget());
}

bool GestionnaireGroupe::cagnotteIsSelected()
{
    bool selected = true;
    if(m_groupCurrent == nullptr)
        selected = false;
    return selected;
}

void GestionnaireGroupe::addParticipant(Compte *compte){
    m_groupCurrent->addParticipant(compte);
    GestionnaireBDD::ajouterParticipant(m_groupCurrent->getIdCagnotte(), compte->getIdentifiant());
}

GestionnaireGroupe::~GestionnaireGroupe()
{
    for(auto& groupe : m_groupes)
    {
        delete groupe.second;
    }
}
