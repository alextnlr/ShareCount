#ifndef GESTIONNAIREBDD_H
#define GESTIONNAIREBDD_H

#define NOMSQL "/data.sql"
/**
 * @brief Gère toutes les actions relatives à la BDD
 */
#include <QSqlDatabase>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

#include <QApplication>
#include <QDir>

class GestionnaireBDD
{
public:
    /**
     * @brief ajouterCompte Ajoute un compte à la BDD
     * @param id Identifiant du nouveau compte
     * @param nom Nom du nouveau compte
     * @param prenom Prénom du nouveau compte
     * @param mdp Mot de Passe du nouveau compte
     */
    static void ajouterCompte(int id, std::string nom, std::string prenom, std::string mdp);

    /**
     * @brief ajouterParticipant Ajoute un participant à une cagnotte dans la BDD
     * @param id_cagnotte Id de la cagnotte où rajouter le participant
     * @param id_participant Id du participant à rajouter
     */
    static void ajouterParticipant(int id_cagnotte, int id_participant);

    /**
     * @brief ajouterCagnotte Ajoute une cagnotte à la BDD
     * @param id_cagnotte id de la cagnotte à ajouter
     * @param nom nom de la cagnotte à ajouter
     * @param id_createur id du compte qui à créer la cagnotte
     */
    static void ajouterCagnotte(int id_cagnotte, std::string nom, int id_createur);

    /**
     * @brief ajouterDemande Ajoute une demande à la bdd
     * @param id_demande Identifiant unique de la demande
     * @param montant Montant de la demande
     * @param id_cagnotte Identifiant de la cagnotte
     * @param id_compte Identifiant du compte demandant
     */
    static void ajouterDemande(int id_demande, int montant, int id_cagnotte, int id_compte);

    /**
     * @brief ajouterAcceptation Ajoute une reponse à la BDD
     * @param id_demande Identifiant de la demande
     * @param id_compte Identifiant du compte
     * @param result Resultat de la reponse
     */
    static void ajouterAcceptation(int id_demande, int id_compte, bool result);

    static void chercheAlex();

    /**
     * @brief hardReset Clear la base de données
     */
    static void hardReset();

    /**
     * @brief lastIdCompte
     * @return dernier identifiant de compte connu par la BDD
     */
    static int lastIdCompte();

    /**
     * @brief lastIdCagnotte
     * @return dernier identifiant de cagnotte connu par la BDD
     */
    static int lastIdCagnotte();

    /**
     * @brief lastIdDemande
     * @return dernier identifiant des demandes connus par la BDD
     */
    static int lastIdDemande();

    /**
     * @brief accepationExist Return true si l'acceptation exist
     * @param id_demande Identifiant de la demande
     * @param id_compte Identifiant du compte demandeur
     * @return bool true si l'accepation exist
     */
    static bool acceptationExist(int id_demande, int id_compte);

    /**
     * @brief nbCompte
     * @return Nombre de compte connu par la BDD
     */
    static int nbCompte();

    /**
     * @brief getCompteBdd
     * @return Collection des comptes connues par la BDD
     */
    static QVector<QVector<QString> > getCompteBdd();

    /**
     * @brief getCagnotteBdd
     * @return Collection des cagnottes connues par la BDD
     */
    static QVector<QVector<QString> > getCagnotteBdd();

    /**
     * @brief getParticipation
     * @param id_cagnotte Id de la cagnotte dont on cherche les participants
     * @return Liste des participants de la cagnotte identifiée
     */
    static QVector<int> getParticipation(int id_cagnotte);

    /**
     * @brief getDemande Renvoie la liste des demandes
     * @param id_cagnotte Identifiant de la cagnotte
     * @return Liste de listes des informations des demandes
     */
    static QVector<QVector<int>> getDemande(int id_cagnotte);

    /**
     * @brief getAcceptation Retourne la liste des acceptations selon une cagnotte
     * @param id_cagnotte Identifiant de la cagnotte
     * @return Map des identifiant des comptes et leur réponse
     */
    static std::map<int, bool> getAcceptation(int id_demande);

    /**
     * @brief updateMontantCagnotte Met à jour le montant de la cagnotte dans la BDD
     * @param id_cagnotte id de la cagnotte à update
     * @param montant montant à ajouter au total de la cagnotte
     */
    static void updateMontantCagnotte(int id_cagnotte, int montant);

    /**
     * @brief updateNomCagnotte Modifie le nom d'une cagnotte dans la BDD
     * @param id_cagnotte Identifiant unique de la cagnotte
     * @param nom Nouveau nom de la cagnotte
     */
    static void updateNomCagnotte(int id_cagnotte, std::string nom);

    /**
     * @brief updateMontantCompte Modifie le montant présent sur le compte
     * @param id_compte Identifiant unique du compte
     * @param montant Nouveau montant
     */
    static void updateMontantCompte(int id_compte, int montant);

    /**
     * @brief updateAcceptationDemande Modifie le nombre d'acceptations pour la demande
     * @param id_demande Identifiant unique de la demande
     * @param acceptations Nombre d'acceptations de la demande
     */
    static void updateAcceptationDemande(int id_demande, int acceptations);

    /**
     * @brief updateAcceptation Update une acceptation
     * @param id_demande Identifiant de la demande
     * @param id_compte Identifiant du compte
     * @param result Resultat de l'acceptation
     */
    static void updateAcceptation(int id_demande, int id_compte, bool result);

    /**
     * @brief deleteCagnotte Supprime une cagnotte dans la bdd
     * @param id_cagnotte Identifiant de la cagnotte
     */
    static void deleteCagnotte(int id_cagnotte);

    /**
     * @brief deleteDemande Supprime une demande dans la bdd
     * @param id_demande Identifiant de la demande
     */
    static void deleteDemande(int id_demande);

    /**
     * @brief initInstance Instancie la BDD
     */
    static void initInstance();
private:
    /**
     * @brief GestionnaireBDD instance unique
     */
    GestionnaireBDD();

    /**
     * @brief databaseConnect Se connecte à la DataBase
     */
    static void databaseConnect();

    /**
     * @brief initBdd Initialise la BDD
     */
    static void initBdd();

    static GestionnaireBDD* m_instance;
};

#endif // GESTIONNAIREBDD_H
