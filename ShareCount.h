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
    GestionnaireCompte gestionnaireCompte;
    std::string aled;
    GestionnaireBDD* gbdd;
};


#endif //SHARECOUNT_SHARECOUNT_H
