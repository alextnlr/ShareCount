#ifndef SHARECOUNT_OBSERVERPATTERN_H
#define SHARECOUNT_OBSERVERPATTERN_H

#include <vector>
#include <algorithm>

class Modele;

class Vue {
public:
    virtual ~Vue() = default;
    virtual void update() = 0;
};

class Modele {
public:
    void attach(Vue& vue) { m_vues.push_back(&vue); }
    void detach(Vue& vue)
    {
        m_vues.erase(std::remove(m_vues.begin(), m_vues.end(), &vue));
    }
    void notify() {
        for (auto* vue : m_vues) {
            vue->update();
        }
    }
    virtual ~Modele() = default;
private:
    std::vector<Vue*> m_vues;
};

#endif //SHARECOUNT_OBSERVERPATTERN_H
