#ifndef GESTIONNAIREGROUPE_H
#define GESTIONNAIREGROUPE_H

#include <vector>

#include "cagnotte.h"

class GestionnaireGroupe
{
public:
    GestionnaireGroupe();
    void addCagnotte(std::string nom, Compte* createur);
    std::map<int, Cagnotte*> getGroupesNom();
    ~GestionnaireGroupe();
private:
    std::map<int, Cagnotte*> m_groupes;
    int nbTemp;
};

#endif // GESTIONNAIREGROUPE_H
