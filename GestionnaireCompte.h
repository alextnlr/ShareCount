#ifndef SHARECOUNT_GESTIONNAIRECOMPTE_H
#define SHARECOUNT_GESTIONNAIRECOMPTE_H

#include <vector>
#include <string>
#include <map>
#include "Compte.h"
#include "FabriqueIdentifiant.h"
#include "gestionnairebdd.h"

class GestionnaireCompte {
public:
    /**
     * Constructeur par défaut
     */
    GestionnaireCompte();

    /**
     * Création d'un nouveau client
     * @param informations Informations du client, tableau du nom, prenom, mdp
     * @return 0 si les informations saisies étaient incorrects
     * @return 1 si la création de compte s'est bien passée
     */
    int creation_compte(std::string* informations);

    /**
     * Connexion du bon compte en fonction des informations
     * @param informations Informations du client, tableau du nom, prenom, mdp
     * @return 0 si la connexion s'est bien passée
     * @return 1 si le compte n'est pas enregistré
     * @return 2 si le mot de passe est incorrect
     */
    int connexion(std::string* informations);

    void recopieBDD();

    /**
     * Renvoie un pointeur sur le compte actuellement connecté
     * @return Compte connecté s'il y en a un ou null sinon
     */
    Compte* compte_connecte();

    /**
     * @brief getCompte retrouve un compte par son identifiant
     * @param i id du compte à chercher
     * @return Compte trouvé
     */
    Compte* getCompte(int i);

    /**
     * @brief trouverCompte Permet de trouver un compte en se basant sur son nom et prénom
     * @param nom Nom du compte que l'on cherche
     * @param prenom Prénom du compte que l'on cherche
     * @return id du compte si il est trouvé
     * @return -1 si aucun compte n'est trouvé
     */
    int trouverCompte(std::string nom, std::string prenom);

    /**
     * Destructeur par défaut
     */
    ~GestionnaireCompte();
private:
    /**
     * Vérifie si les informations peuvent être utilisé par un client
     * @param informations Informations du client, tableau du nom, prenom, mdp
     * @return Vrai si les informations peuvent être utilisés
     */
    bool verification_client(std::string* informations);

    /**
     * Identifiant du compte connecté
     */
    int m_compte_co;

    /**
     * Map des comptes enregistrés avec comme clé son identifiant int
     */
    std::map<int, Compte*> m_comptes;


};


#endif //SHARECOUNT_GESTIONNAIRECOMPTE_H
