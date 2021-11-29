#ifndef GESTIONNAIREGROUPE_H
#define GESTIONNAIREGROUPE_H

#include <vector>

#include "gestionnairebdd.h"
#include "GestionnaireCompte.h"
#include "cagnotte.h"

class GestionnaireGroupe
{
public:
    GestionnaireGroupe(GestionnaireCompte *gestionnaireCompte);
    void addCagnotte(std::string nom, Compte* createur);
    std::map<int, Cagnotte*> getGroupesNom();
    void recopieBDD(GestionnaireCompte *gestionnaireCompte);
    void setGroupCurrent(Cagnotte *cagnotte);
    Cagnotte* getCagnotte(int id_cagnotte);
    Cagnotte* getGroupCurrent();
    void addToCagnotte(int montant);
    bool cagnotteIsSelected();
    ~GestionnaireGroupe();
private:
    std::map<int, Cagnotte*> m_groupes;
    int nbTemp;

    /**
     * @brief m_groupCurrent groupe actuellement sélectionné
     */
    Cagnotte* m_groupCurrent = nullptr;
};

#endif // GESTIONNAIREGROUPE_H
