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
