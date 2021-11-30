#ifndef SHARECOUNT_SHARECOUNT_H
#define SHARECOUNT_SHARECOUNT_H


#include "ObserverPattern.h"
#include "GestionnaireCompte.h"
#include "gestionnairebdd.h"
#include "gestionnairegroupe.h"

class ShareCount: public Modele {
public:
    ShareCount();
    int creerCompte(std::string* informations);
    int connexion(std::string* informations);
    int creerCagnotte(std::string nom);
    std::map<int, Cagnotte*> getNomGroupes();
    void setCurrentGroup(int id_cagnotte);
    Cagnotte* getCurrentGroup();
    void addToCagnotte(int montant);
    bool isCagnotteSelected();
    int trouverCompte(std::string nom, std::string prenom);
    void addParticipant(Compte* compte);
    Compte* getCompte(int id);
    ~ShareCount();

private:
    GestionnaireCompte* m_gestionnaireCompte;
    GestionnaireGroupe* m_gestionnaireGroupe;
};


#endif //SHARECOUNT_SHARECOUNT_H
