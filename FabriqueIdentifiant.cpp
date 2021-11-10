//
// Created by timeo on 10/11/2021.
//

#include "FabriqueIdentifiant.h"

FabriqueIdentifiant::FabriqueIdentifiant() {
    m_idCurrent = 1;
}

int FabriqueIdentifiant::getIdenfiant() {
    m_idCurrent++;
    return m_idCurrent-1;
}



