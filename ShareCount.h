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
    void setCurrentGroup(int id_cagnotte);
    Cagnotte* getCurrentGroup();
    void addToCagnotte(int montant);
    void renameCagnotte(std::string nom);
    bool isCagnotteSelected();
    bool isCompteSelected();
    int trouverCompte(std::string nom, std::string prenom);
    void addParticipant(Compte* compte);
    Compte* getCompte(int id);
    Compte* getCurrentCompte();
    void crediterCompte(int montant);
    void ajouterDemande(int montant);
    void deleteCagnotte(int id_cagnotte);
    ~ShareCount();

private:
    GestionnaireCompte* m_gestionnaireCompte;
    GestionnaireGroupe* m_gestionnaireGroupe;
};


#endif //SHARECOUNT_SHARECOUNT_H
