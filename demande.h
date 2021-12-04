#ifndef DEMANDE_H
#define DEMANDE_H

#include <QVector>
#include <map>

#include "gestionnairebdd.h"

class Demande
{
public:
    /**
     * @brief Demande Constructeur demande
     * @param idDemande Identifiant unique de la demande
     * @param idDemandeur Identifiant du compte demandeur
     * @param montant Montant de la demande
     * @param nbAcceptation Nombre d'acceptations positives
     */
    Demande(int idDemande, int idDemandeur, int montant, int nbAcceptation = 0);

    /**
     * @brief getIdDemande Retourne l'identifiant unique de la demande
     * @return Identifiant de la demande
     */
    int getIdDemande(){
        return m_idDemande;
    }

    /**
     * @brief getIdDemandeur Retourne l'identifiant du compte demandeur
     * @return Identifiant du compte demandeur
     */
    int getIdDemandeur(){
        return m_idDemandeur;
    }

    /**
     * @brief getMontant Retourne le montant de la demande
     * @return Montant de la demande
     */
    int getMontant(){
        return m_montant;
    }

    /**
     * @brief getnbAcceptation Retourne le nombre d'acceptation positive
     * @return Nombre d'acceptation positive
     */
    int getnbAcceptation(){
        return m_nbAcceptation;
    }

    /**
     * @brief getm_compte Retourne les comptes qui ont répondu et leur réponse
     * @return Map des id comptes avec leur réponse
     */
    std::map<int, bool> getm_compte(){
        return m_compte;
    }

    /**
     * @brief ajouterReponse Ajoute une reponse
     * @param id Identifiant du compte qui a repondu
     * @param reponse Réponse positive ou non
     */
    void ajouterReponse(int id, bool reponse);

    /**
     * @brief aAccepte Return true si le compte donné à répondu oui à la demande
     * @param idCompte Identifiant du compte
     * @return bool true si le compte a accepté
     */
    int aAccepte(int idCompte);

    /**
     * @brief recupAcceptationsBDD Recupère les comptes qui ont répondu depuis la bdd
     */
    void recupAcceptationsBDD();


private:
    int m_idDemande;
    int m_idDemandeur;
    int m_montant;
    int m_nbAcceptation;
    std::map<int, bool> m_compte;

};

#endif // DEMANDE_H
