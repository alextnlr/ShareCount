#ifndef SHARECOUNT_GESTIONNAIRECOMPTE_H
#define SHARECOUNT_GESTIONNAIRECOMPTE_H

#include <vector>
#include <string>
#include <map>
#include "Compte.h"
#include "FabriqueIdentifiant.h"

class GestionnaireCompte {
public:
    /**
     * Constructeur par défaut
     */
    GestionnaireCompte();

    /**
     * Création d'un nouveau client
     * @param informations Informations du client, tableau du nom, prenom, mdp
     */
    void creation_compte(std::string* informations);

    /**
     * Connexion du bon compte en fonction des informations
     * @param informations Informations du client, tableau du nom, prenom, mdp
     * @return
     */
    void connexion(std::string* informations);

    /**
     * Renvoie un pointeur sur le compte actuellement connecté
     * @return Compte connecté s'il y en a un ou null sinon
     */
    Compte* compte_connecte();
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
    FabriqueIdentifiant* m_fabriqueIdentifiant;
};


#endif //SHARECOUNT_GESTIONNAIRECOMPTE_H
