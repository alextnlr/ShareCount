/**
 * @brief Classe gérant les comptes utilisateurs
 * @version 1
 * @date 10 novembre 2021
 */

#ifndef SHARECOUNT_COMPTE_H
#define SHARECOUNT_COMPTE_H

#include <iostream>

#include "gestionnairebdd.h"

class Compte {
public:

    /**
     * Constructeur par défaut
     * @param nom Nom du client associé au compte
     * @param prenom Prénom du client associé au compte
     * @param identifiant Identifiant unique
     * @param mdp Mot de Passe de connexion
     */
    Compte(std::string nom, std::string prenom, int identifiant, std::string mdp, int montant = 0);

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
     * @brief addMontant
     * @param montant Montant à ajouter
     */
    void addMontant(int montant);

    /**
     * @brief withdraw Retire une somme d'argent du compte
     * @param montant montant à retirer
     */
    void withdraw(int montant);

    /**
     * @brief getMontant
     * @return montant actuel du compte
     */
    int getMontant();

    /**
     * Destructeur
     */
    ~Compte();


private:
    std::string m_nom;
    std::string m_prenom;
    int m_identifiant;
    std::string m_mdp;
    int m_montant;
};


#endif //SHARECOUNT_COMPTE_H

