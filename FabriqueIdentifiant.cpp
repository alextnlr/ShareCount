#include "FabriqueIdentifiant.h"


FabriqueIdentifiant FabriqueIdentifiant::m_instance = FabriqueIdentifiant();

FabriqueIdentifiant::FabriqueIdentifiant() {
    m_idCurrent = 1;
}

int FabriqueIdentifiant::getIdenfiant() {
    m_idCurrent++;
    return m_idCurrent-1;
}

FabriqueIdentifiant &FabriqueIdentifiant::getInstance() {
    return m_instance;
}

FabriqueIdentifiant::~FabriqueIdentifiant() {
}
