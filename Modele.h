//
// Created by niciavel on 03/11/2021.
//

#ifndef SHARECOUNT_MODELE_H
#define SHARECOUNT_MODELE_H

#include <vector>
#include "Vue.h"

class Modele {
public:
    Modele() {};
    void attach(Vue vue);
    void detach(Vue vue);
    void notify();

private:
    std::vector<Vue> m_vues;
};


#endif //SHARECOUNT_MODELE_H
