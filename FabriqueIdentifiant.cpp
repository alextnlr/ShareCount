#include "FabriqueIdentifiant.h"

FabriqueIdentifiant::FabriqueIdentifiant() {
    m_idCurrent = 1;
}

int FabriqueIdentifiant::getIdenfiant() {
    m_idCurrent++;
    return m_idCurrent-1;
}

FabriqueIdentifiant* FabriqueIdentifiant::getInstance() {
    if (m_instance == nullptr)
    {
        m_instance = new FabriqueIdentifiant();
    }
    return m_instance;
}

FabriqueIdentifiant::~FabriqueIdentifiant() {
    delete m_instance;
}
