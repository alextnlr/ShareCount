#ifndef SHARECOUNT_SHARECOUNT_H
#define SHARECOUNT_SHARECOUNT_H


#include "ObserverPattern.h"
#include "GestionnaireCompte.h"

class ShareCount: public Modele {
public:
    std::string get_aled() const;
    void set_aled(std::string aled2);
private:
    GestionnaireCompte gestionnaireCompte;
    std::string aled;
};


#endif //SHARECOUNT_SHARECOUNT_H
