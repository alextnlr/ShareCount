#include "gestionnairegroupe.h"
#include <QDebug>
#include <QString>

GestionnaireGroupe::GestionnaireGroupe()
{
    nbTemp = 0;
}

void GestionnaireGroupe::addCagnotte(std::string nom, Compte *createur)
{
    m_groupes[nbTemp] = new Cagnotte(nom, nbTemp, createur);
    nbTemp++;
}

std::map<int, Cagnotte*> GestionnaireGroupe::getGroupesNom()
{
    return m_groupes;
}

GestionnaireGroupe::~GestionnaireGroupe()
{
    for(auto& groupe : m_groupes)
    {
        delete groupe.second;
    }
}
