/**
 * Génère des ID qu'on garantit unique, pour identifier les clients
 * @version 1
 * @date 10 novembre 2021
 */
#ifndef SHARECOUNT_FABRIQUEIDENTIFIANT_H
#define SHARECOUNT_FABRIQUEIDENTIFIANT_H


class FabriqueIdentifiant {
public:
    /**
     * @return instance unique de la classe
     */
    FabriqueIdentifiant getInstance();

    /**
     * Donne accès à l'identifiant unique courrant
     * @return id unique
     */
    int getIdenfiant();
    /**
     * Destructeur
     */
    ~FabriqueIdentifiant();
private:
    /**
     * Instance privée unique pour garantir l'unicité de chaque ID
     */
    FabriqueIdentifiant();
    /**
     * Stocke l'id actuelle
     */
    int m_idCurrent;

};


#endif //SHARECOUNT_FABRIQUEIDENTIFIANT_H