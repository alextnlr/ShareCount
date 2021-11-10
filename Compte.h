//
// Created by timeo on 10/11/2021.
//

#ifndef SHARECOUNT_COMPTE_H
#define SHARECOUNT_COMPTE_H

#include <iostream>

class Compte {
public:
    Compte(std::string nom, std::string prenom, std::string identifiant, std::string mdp);
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getIdentifiant() const;
    std::string getmdp() const;
    ~Compte();


private:
    std::string m_nom;
    std::string m_prenom;
    std::string m_identifiant;
    std::string m_mdp;
};


#endif //SHARECOUNT_COMPTE_H

