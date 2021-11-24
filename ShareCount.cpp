#include "ShareCount.h"

#include <utility>

std::string ShareCount::get_aled() const {
    return aled;
}

void ShareCount::set_aled(std::string aled2) {
    aled = std::move(aled2);
}

int ShareCount::creerCompte(std::string *informations){
    return gestionnaireCompte.creation_compte(informations);
}

int ShareCount::connexion(std::string *informations){
    return gestionnaireCompte.connexion(informations);
}
