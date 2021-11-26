#include "GestionnaireCompte.h"
#include <QDebug>
#include <string>

using namespace std;

GestionnaireCompte::GestionnaireCompte() {
    m_compte_co = 0;
    recopieBDD();
}

bool GestionnaireCompte::verification_client(std::string *informations) {
    bool valid_infos = true;
    if (informations[0].length() < 1 || informations[1].length() < 1 || informations[2].length() < 5) {
        valid_infos = false;
    }
    return valid_infos;
}

int GestionnaireCompte::creation_compte(std::string *informations) {
    int result = 0;
    if (verification_client(informations)) {
        int id = GestionnaireBDD::lastId()+1; //m_fabriqueIdentifiant.getIdenfiant();
        m_comptes [id] = new Compte(informations[0], informations[1], id, informations[2]);
        GestionnaireBDD::ajouterCompte(id, informations[0], informations[1], informations[2]);
        result = 1;
    }
    return result;
}

int GestionnaireCompte::connexion(std::string *informations) {
    int result = 1; // Si on ne trouve aucun compte, on retournera 1
    if (verification_client(informations)){
        std::map<int, Compte*>::iterator it = m_comptes.begin(); //Itérateur des comptes enregistrés
        bool continu = true;

        while (it != m_comptes.end() && continu == true) { //Tant que on a pas trouvé, ou que la map n'est pas finie
            Compte* current = m_comptes[it->first];

            //Si toutes les infos concordent avec le compte sur lequel on itère
            if (current->getPrenom() == informations[1] && current->getNom() == informations[0] && current->getmdp() == informations[2]){
                m_compte_co = current->getIdentifiant();
                result = 0;
                continu = false;
            } else{
                //Si le nom ou le prénom est correct, mais pas le mdp
                if ((current->getNom() == informations[0] || current->getPrenom() == informations[1]) && current->getmdp() != informations[2]){
                    result = 2;
                    continu = false;
                }
            }
        }
    }
    return result;

}

Compte* GestionnaireCompte::compte_connecte() {
    return m_comptes.at(m_compte_co);
}

GestionnaireCompte::~GestionnaireCompte() {
    for (auto& compte : m_comptes) {
        delete compte.second;
    }
}

void GestionnaireCompte::recopieBDD(){
    QVector<QVector<QString>> tab = GestionnaireBDD::getCompteBdd();
    for(const auto& value: tab){
        m_comptes[std::stoi(value[0].toStdString())] = new Compte(value[1].toStdString(), value[2].toStdString(), std::stoi(value[0].toStdString()), value[3].toStdString());
    }
}

