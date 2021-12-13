/**
 * @brief Gère les collections de cagnottes et liste
 */
#ifndef GESTIONNAIREGROUPE_H
#define GESTIONNAIREGROUPE_H

#include <vector>

#include "gestionnairebdd.h"
#include "GestionnaireCompte.h"
#include "cagnotte.h"

class GestionnaireGroupe
{
public:
    /**
     * @brief GestionnaireGroupe Constructeur par défaut
     * @param gestionnaireCompte Gestionnaire de Compte
     */
    GestionnaireGroupe(GestionnaireCompte *gestionnaireCompte);

    /**
     * @brief addCagnotte Ajoute une cagnotte au gestionnaire
     * @param nom Nom de la cagnotte a ajouter
     * @param createur Créateur de la cagnotte ajoutée
     */
    void addCagnotte(std::string nom, Compte* createur);

    /**
     * @brief getGroupesNom Retourne les cagnottes
     * @return Map de toutes les cagnottes, identifiées par leurs identifiants
     */
    std::map<int, Cagnotte*> getGroupesNom();

    /**
     * @brief recopieBDD Recopie dans la classe tout les groupes de la BDD
     * @param gestionnaireCompte Gestionnaire de Compte courant
     */
    void recopieBDD(GestionnaireCompte *gestionnaireCompte);

    /**
     * @brief setGroupCurrent Définit le groupe sur lequel on est en train de travailler
     * @param cagnotte Groupe sur lequel on travaille
     */
    void setGroupCurrent(Cagnotte *cagnotte);
    Cagnotte* getCagnotte(int id_cagnotte);
    Cagnotte* getGroupCurrent();
    void addToCagnotte(int montant);
    bool cagnotteIsSelected();
    void addParticipant(Compte* compte);
    void updateNomCagnotte(std::string nom);
    void deleteCagnotte(int id_cagnotte);
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
