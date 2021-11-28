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

    Compte* getCompte(int i);

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

    /**
     * Singleton pour la fabrique d'identifiant unique
     */
    FabriqueIdentifiant& m_fabriqueIdentifiant = FabriqueIdentifiant::getInstance();
};


#endif //SHARECOUNT_GESTIONNAIRECOMPTE_H
