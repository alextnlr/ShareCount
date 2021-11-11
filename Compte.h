/**
 * @brief Classe gérant les comptes utilisateurs
 * @version 1
 * @date 10 novembre 2021
 */

#ifndef SHARECOUNT_COMPTE_H
#define SHARECOUNT_COMPTE_H

#include <iostream>

class Compte {
public:

    /**
     * Constructeur par défaut
     * @param nom Nom du client associé au compte
     * @param prenom Prénom du client associé au compte
     * @param identifiant Identifiant unique
     * @param mdp Mot de Passe de connexion
     */
    Compte(std::string nom, std::string prenom, int identifiant, std::string mdp);

    /**
     * Retourne le nom associé au compte
     * @return nom associé au compte
     */
    std::string getNom() const;

    /**
     * Retourne le prénom associé au compte
     * @return prénom associé au compte
     */
    std::string getPrenom() const;

    /**
     * Retourne l'identifiant unique associé au compte
     * @return identifiant associé au compte
     */
    int getIdentifiant() const;

    /**
     * Retourne le mot de passe du compte
     * @return mot de passe associé au compte
     */
    std::string getmdp() const;

    /**
     * Destructeur
     */
    ~Compte();


private:
    std::string m_nom;
    std::string m_prenom;
    int m_identifiant;
    std::string m_mdp;
};


#endif //SHARECOUNT_COMPTE_H

