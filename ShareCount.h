#ifndef SHARECOUNT_SHARECOUNT_H
#define SHARECOUNT_SHARECOUNT_H


#include "ObserverPattern.h"
#include "GestionnaireCompte.h"
#include "gestionnairebdd.h"

class ShareCount: public Modele {
public:
    ShareCount();
    int creerCompte(std::string* informations);
    int connexion(std::string* informations);
    ~ShareCount();

private:
    GestionnaireBDD* m_gbdd;
    GestionnaireCompte* m_gestionnaireCompte;
};


#endif //SHARECOUNT_SHARECOUNT_H
