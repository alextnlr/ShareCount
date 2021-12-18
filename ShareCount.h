/**
 * @brief Modèle de l'application
 */
#ifndef SHARECOUNT_SHARECOUNT_H
#define SHARECOUNT_SHARECOUNT_H


#include "ObserverPattern.h"
#include "GestionnaireCompte.h"
#include "gestionnairebdd.h"
#include "gestionnairegroupe.h"

class ShareCount: public Modele {
public:
    /**
     * @brief ShareCount Constructeur par défaut
     */
    ShareCount();

    /**
     * @brief creerCompte Créé un nouveau compte
     * @param informations informations du compte à crééer
     * @return Etat de la création
     * @return 2 en cas de succès
     * @return 0 si les informations ne sont pas valides
     * @return 1 si le compte n'existe pas
     */
    int creerCompte(std::string* informations);

    /**
     * @brief connexion Connecte un compte
     * @param informations Informations du compte à connecter
     * @return Etat de la connexion
     * @return 0 si la connexion s'est bien passée
     * @return 1 si on a pas trouvé le compte
     */
    int connexion(std::string* informations);

    /**
     * @brief creerCagnotte Créer une cagnotte
     * @param nom Nom de la cagnotte
     */
    void creerCagnotte(std::string nom);

    /**
     * @brief getNomGroupes Obtient la liste de tout les groupes
     * @return
     */
    std::map<int, Cagnotte*> getNomGroupes();

    /**
     * @brief setCurrentGroup Change le groupe actuel
     * @param id_cagnotte Identifiant du groupe
     */
    void setCurrentGroup(int id_cagnotte);

    /**
     * @brief getCurrentGroup Renvoie une réference au groupe actuel
     * @return Référence au groupe actuel
     */
    Cagnotte* getCurrentGroup();

    /**
     * @brief addToCagnotte Ajoute un montant à la cagnotte actuel
     * @param montant Montant à ajouter
     */
    void addToCagnotte(int montant);

    /**
     * @brief renameCagnotte Renomme la cagnotte
     * @param nom Nouveau nom
     */
    void renameCagnotte(std::string nom);

    /**
     * @brief isCagnotteSelected Test s'il y a une cagnotte selected
     * @return True si une cagnotte est selectionné, false sinon
     */
    bool isCagnotteSelected();

    /**
     * @brief isCompteSelected Test si un compte est selectionné
     * @return True su un compte est sélectionné
     */
    bool isCompteSelected();

    /**
     * @brief trouverCompte Renvoie l'identifiant d'un compte selon son nom et prenom
     * @param nom Nom du compte
     * @param prenom prenom du compte
     * @return L'identifiant du compte trouvé, -1 sinon
     */
    int trouverCompte(std::string nom, std::string prenom);

    /**
     * @brief addParticipant Ajoute un participant au groupe actuel
     * @param compte Compte du nouveau participant
     */
    void addParticipant(Compte* compte);

    /**
     * @brief getCompte Renvoie la référence au compte actuel
     * @param id Identifiant du compte
     * @return Référence au compte
     */
    Compte* getCompte(int id);

    /**
     * @brief getCurrentCompte renvoie la référence au compte actuel
     * @return Référence au compte actuel
     */
    Compte* getCurrentCompte();

    /**
     * @brief crediterCompte Crédite le compte actuel
     * @param montant Montant à créditer
     */
    void crediterCompte(int montant);

    /**
     * @brief ajouterDemande Ajoute une demande de la part du compte actuel sur la cagnotte actuelle
     * @param montant Montant de la demande
     */
    void ajouterDemande(int montant);

    /**
     * @brief deleteCagnotte Supprime un groupe
     * @param id_cagnotte identifiant de la cagnotte
     */
    void deleteCagnotte(int id_cagnotte);
    ~ShareCount();

private:
    GestionnaireCompte* m_gestionnaireCompte;
    GestionnaireGroupe* m_gestionnaireGroupe;
};


#endif //SHARECOUNT_SHARECOUNT_H
