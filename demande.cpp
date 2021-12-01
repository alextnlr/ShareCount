#include "demande.h"

Demande::Demande(int idDemande, int idDemandeur, int montant, int nbAcceptation) : m_idDemande(idDemande), m_idDemandeur(idDemandeur), m_montant(montant), m_nbAcceptation(nbAcceptation)
{

}


void Demande::ajouterReponse(int id, bool reponse){
    m_compte[id] = reponse;
}

bool Demande::aAccepte(int idCompte){
    bool reponse = false;
    for (const auto& compte : m_compte){
        if (compte.first == idCompte){
            reponse = compte.second;
        }
    }
    return reponse;
}
