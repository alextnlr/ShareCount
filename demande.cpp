#include "demande.h"

Demande::Demande(int idDemande, int idDemandeur, int montant, int nbAcceptation) : m_idDemande(idDemande), m_idDemandeur(idDemandeur), m_montant(montant), m_nbAcceptation(nbAcceptation)
{
    recupAcceptationsBDD();
}


void Demande::ajouterReponse(int id, bool reponse){
    m_compte[id] = reponse;
    if(GestionnaireBDD::acceptationExist(m_idDemande, id))
        GestionnaireBDD::updateAcceptation(m_idDemande, id, reponse);
    else
        GestionnaireBDD::ajouterAcceptation(m_idDemande, id, reponse);
}

int Demande::aAccepte(int idCompte){
    int reponse = 0;
    int i = 0;
    for (const auto& compte : m_compte){
        if (compte.first == idCompte){
            reponse = compte.second;
        }
        else
        {
            i++;
        }
    }
    if(i == m_compte.size())
        reponse = -1;
    return reponse;
}

void Demande::recupAcceptationsBDD()
{
    m_compte = GestionnaireBDD::getAcceptation(m_idDemande);
}
