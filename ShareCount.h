#ifndef SHARECOUNT_SHARECOUNT_H
#define SHARECOUNT_SHARECOUNT_H


#include "ObserverPattern.h"
#include "GestionnaireCompte.h"

class ShareCount: public Modele {
public:
    int get_aled() const;
    void inc_aled();
private:
    GestionnaireCompte gestionnaireCompte;
    int aled = 1;
};


#endif //SHARECOUNT_SHARECOUNT_H
