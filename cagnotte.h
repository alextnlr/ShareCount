/**
 * @brief Objet représantant les cagnottes
 */
#ifndef CAGNOTTE_H
#define CAGNOTTE_H
#include <QVector>
#include <iostream>
#include "Compte.h"
#include "demande.h"
#include "gestionnairebdd.h"
#include <map>

class Cagnotte
{
public:
    /**
     * @brief Constructeur par défaut
     * @param nom nom de la cagnote
     * @param idCagnotte id unique identifiant la cagnotte
     * @param Createur compte créateur de la cagnotte
     */
    Cagnotte(std::string nom, int idCagnotte, Compte* createur, int budget);

    /**
     * @brief getNom retourne le nom de la cagnotte
     * @return retourne le nom de la cagnotte
     */
    std::string getNom();

    /**
     * @brief getIdCagnotte retourne l'id de la cagnotte
     * @return id de la cagnotte
     */
    int getIdCagnotte();

    /**
     * @brief getIdCreateur retourne l'id du créateur de la cagnotte
     * @return id du créateur de la cagnotte
     */
    int getIdCreateur();

    /**
     * @brief getBudget retourne le budget actuel de la cagnotte
     * @return budget actuel de la cagnotte
     */
    int getBudget();

    /**
     * @brief getNbParticipant retourne le nombre de participant à la cagnotte
     * @return nombre de participant à la cagnotte
     */
    int getNbParticipant();

    /**
     * @brief getParticipant retourne un compte participant à la cagnotte, identifié par son identifiant
     * @param id identifiant du compte à retourner
     * @return Compte identifié par l'id passé en paramètres
     */
    Compte* getParticipant(int id);

    /**
     * @brief getListeParticipant retourne la liste complète des participants
     * @return map complète des participants
     */
    std::map<int, Compte*> getListeParticipant();

    /**
     * @brief addParticipant Ajoute un participant à la cagnotte
     * @param compte Compte à ajouter à la cagnotte
     */
    void addParticipant(Compte* compte);

    /**
     * @brief addBudget Ajoute de l'argent à la cagnotte
     * @param toAdd somme d'argent à ajouter
     */
    void addBudget(int toAdd);

    /**
     * @brief participe Permet de savoir si un utilisateur participe ou non à une cagnotte
     * @param id id du compte à chercher
     * @return true si on a trouvé le compte
     */
    bool participe(int id);

    /**
     * @brief setNom Change le nom de la cagnotte
     * @param nom Nouveau nom
     */
    void setNom(std::string nom);

    /**
     * @brief creerDemande Creation d'une demande de retrait
     * @param montant Montant a retirer
     * @param id_demandeur Id du compte qui a fait la demande
     */
    void creerDemande(int montant, int id_demandeur);

    /**
     * @brief getDemandes Renvoie les demandes
     * @return map des demandes
     */
    const std::map<int, Demande*> getDemandes();

    /**
     * @brief getDemande Renvoie la référence a une demande
     * @param id_demande Identifiant de la demande
     * @return Pointeur sur la demande
     */
    Demande* getDemande(int id_demande);

    /**
     * @brief isDemandeAccepte Renvoie l'état d'une demande
     * @param id_demande identidiant de la demande
     * @return 0 si en cours, -1 si refusée, 1 si acceptée
     */
    int isDemandeAccepte(int id_demande);

    /**
     * @brief recupDemandesBdd Recuperation des demandes sur la bdd
     */
    void recupDemandesBdd();

    /**
     * Destructeur
     */
    ~Cagnotte();


private:
    /**
     * @brief m_nom nom de la cagnotte
     */
    std::string m_nom;

    /**
     * @brief m_idCagnotte identifiant de la cagnotte
     */
    int m_idCagnotte;

    /**
     * @brief m_idCreateur identifiant du créateur de la cagnotte
     */
    int m_idCreateur;

    /**
     * @brief m_budget budget actuel de la cagnotte
     */
    int m_budget;

    /**
     * @brief m_comptes map des comptes liés à la cagnotte
     */
    std::map<int, Compte*> m_comptes;

    /**
     * @brief estOuvert Indique si la cagnotte est ouverte ou fermée
     */
    bool estOuvert;

    /**
     * @brief m_demandes map des demandes
     */
    std::map<int, Demande*> m_demandes;
};

#endif // CAGNOTTE_H
