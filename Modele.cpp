#include <algorithm>
#include "Modele.h"

void Modele::attach(Vue vue) {
    m_vues.push_back(vue);
}

void Modele::detach(Vue vue) {
    m_vues.erase(std::remove(m_vues.begin(), m_vues.end(), vue), m_vues.end());
}

void Modele::notify() {
    for (Vue vue : m_vues) {
        vue.update();
    }
}