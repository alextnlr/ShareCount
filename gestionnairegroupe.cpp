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
}

void GestionnaireGroupe::setGroupCurrent(Cagnotte *cagnotte){
    m_groupCurrent = cagnotte;
}

Cagnotte* GestionnaireGroupe::getGroupCurrent(){
    return m_groupCurrent;
}

GestionnaireGroupe::~GestionnaireGroupe()
{
    for(auto& groupe : m_groupes)
    {
        delete groupe.second;
    }
}
