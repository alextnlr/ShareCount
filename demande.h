#ifndef DEMANDE_H
#define DEMANDE_H

#include <QVector>
#include <map>

class Demande
{
public:
    Demande(int idDemande, int idDemandeur, int montant, int nbAcceptation = 0);

    int getIdDemande(){
        return m_idDemande;
    }

    int getIdDemandeur(){
        return m_idDemandeur;
    }

    int getMontant(){
        return m_montant;
    }

    int getnbAcceptation(){
        return m_nbAcceptation;
    }

    std::map<int, bool> getm_compte(){
        return m_compte;
    }

    void ajouterReponse(int id, bool reponse);

    bool aAccepte(int idCompte);


private:
    int m_idDemande;
    int m_idDemandeur;
    int m_montant;
    int m_nbAcceptation;
    std::map<int, bool> m_compte;

};

#endif // DEMANDE_H
