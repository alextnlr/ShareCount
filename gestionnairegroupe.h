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

    /**
     * @brief getCagnotte Retourne une cagnotte précise
     * @param id_cagnotte Id de la cagnotte à retourner
     * @return la cagnotte
     */
    Cagnotte* getCagnotte(int id_cagnotte);

    /**
     * @brief getGroupCurrent Retourne la cagnotte sur laquelle on travaille actuellement
     * @return La cagnotte courante
     */
    Cagnotte* getGroupCurrent();

    /**
     * @brief addToCagnotte Ajoute de l'argent à la cagnotte courante
     * @param montant montant à ajouter
     */
    void addToCagnotte(int montant);

    /**
     * @brief cagnotteIsSelected Indique si une cagnotte est actuellement sélectionnée
     * @return true si une cagnotte est sélectionnée
     */
    bool cagnotteIsSelected();

    /**
     * @brief addParticipant Ajoute un participant à la cagnotte courante
     * @param compte Compte à ajouter
     */
    void addParticipant(Compte* compte);

    /**
     * @brief updateNomCagnotte Modifie le nom de la cagnotte actuelle
     * @param nom Nouveau nom
     */
    void updateNomCagnotte(std::string nom);

    /**
     * @brief deleteCagnotte Supprime une cagnotte en particulier
     * @param id_cagnotte identifiant de la cagnotte à supprimer
     */
    void deleteCagnotte(int id_cagnotte);

    /**
     * @brief Destructeur par défaut
     */
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
