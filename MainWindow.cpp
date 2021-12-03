#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include "MainWindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(ShareCount& shareCount, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_shareCount(shareCount)
{
    ui->setupUi(this);
    this->setWindowTitle("ShareCount");
    m_shareCount.attach(*this);
    //ui->menuBar->setHidden(true);
    ui->stackedWidget->setEnabled(true);
    ui->page->setEnabled(true);
    ui->page->setHidden(false);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
    m_shareCount.detach(*this);
}

void MainWindow::update() {
    ui->groupList->clear();
    ui->participantList->clear();

    std::map<int, Cagnotte*> cagnottes = m_shareCount.getNomGroupes();
    for (const auto& nom : cagnottes) {
        if (nom.second->participe(m_shareCount.getCurrentCompte()->getIdentifiant()))
        {
            QListWidgetItem* item = new QListWidgetItem;
            if(nom.second->getIdCreateur() == m_shareCount.getCurrentCompte()->getIdentifiant())
                item->setText(QString::fromStdString(nom.second->getNom()) + " (Createur)");
            else
                item->setText(QString::fromStdString(nom.second->getNom()));
            item->setData(Qt::UserRole, nom.second->getIdCagnotte());
            ui->groupList->addItem(item);
        }
    }

    if(m_shareCount.isCagnotteSelected())
    {
        QString nomCagnotte = QString::fromStdString(m_shareCount.getCurrentGroup()->getNom());
        ui->labelNomCagnotte->setText(nomCagnotte);

        int budget = m_shareCount.getCurrentGroup()->getBudget();
        ui->labelSommeCagnotte->setText(QString::fromStdString(std::to_string(budget)) + "€");

        std::map<int, Compte*> compte_co = m_shareCount.getCurrentGroup()->getListeParticipant();
        for (const auto& compte : compte_co){
            QListWidgetItem* item = new QListWidgetItem;
            if(compte.second->getIdentifiant() == m_shareCount.getCurrentGroup()->getIdCreateur())
                item->setText(QString::fromStdString(compte.second->getNom()) + " (Createur)");
            else
                item->setText(QString::fromStdString(compte.second->getNom()));
            item->setData(Qt::UserRole, compte.second->getIdentifiant());
            ui->participantList->addItem(item);
        }

        if(m_shareCount.getCurrentCompte()->getIdentifiant() == m_shareCount.getCurrentGroup()->getIdCreateur() && ui->stackedWidget->currentIndex() == 2)
        {
            ui->actionSupprimer_Cagnotte->setEnabled(true);
            ui->actionRenommer_Cagnotte->setEnabled(true);
        }
        else
        {
            ui->actionSupprimer_Cagnotte->setEnabled(false);
            ui->actionRenommer_Cagnotte->setEnabled(false);
        }

        ui->listWidgetDemandes->clear();
        std::map<int, Demande*> demandes = m_shareCount.getCurrentGroup()->getDemandes();
        for(const auto& demande : demandes)
        {
            QListWidgetItem* item = new QListWidgetItem;
            QString text = QString::fromStdString(m_shareCount.getCompte(demande.second->getIdDemandeur())->getNom())+" "+QString::number(demande.second->getMontant())+"€";
            int accept = demande.second->aAccepte(m_shareCount.getCurrentCompte()->getIdentifiant());
            if(accept == 0)
                text += "  (Refuse)";
            else if(accept == 1)
                text += "  (Accepte)";
            item->setText(text);
            item->setData(Qt::UserRole, demande.first);
            ui->listWidgetDemandes->addItem(item);
        }

    }

    QString montant = QString::number(m_shareCount.getCurrentCompte()->getMontant());
    ui->labelSolde->setText("Solde : " + montant + "€");
}

void MainWindow::on_pushButtonCreationCompte_clicked()
{
    std::string informations[3];
    informations[0] = ui->lineEditNom->text().toStdString();
    informations[1] = ui->lineEditPrenom->text().toStdString();
    informations[2] = ui->lineEdit_MdP->text().toStdString();
    int retour = m_shareCount.creerCompte(informations);
    QString textRetour;

    ui->labelInfo->setEnabled(true);
    if (retour == 1){
        //ui->labelInfo->setText("Compte créé avec succès");
        textRetour = "Compte créé avec succès";
        ui->lineEdit_MdP->clear();
    }
    if (retour == 0){
        //ui->labelInfo->setText("Erreur lors de la création de compte");
        textRetour = "Erreur lors de la création de compte, \n vérifiez que le mot de passe fait plus de 5 caractères";
    }
    if (retour == 2){
        textRetour = "Un compte existe déjà avec ce nom et ce prénom";
    }
    ui->labelInfo->clear(); //Pour éviter les problèmes si déjà écrit
    ui->labelInfo->setText(textRetour);
}

void MainWindow::on_pushButtonConnexion_clicked()
{

    std::string informations[3];
    informations[0] = ui->lineEditNom->text().toStdString();
    informations[1] = ui->lineEditPrenom->text().toStdString();
    informations[2] = ui->lineEdit_MdP->text().toStdString();
    int retour = m_shareCount.connexion(informations);

    QString textRetour;
    ui->labelInfo->setEnabled(true);
    switch (retour){
        case 0:
            textRetour = "Connecté";
            ui->stackedWidget->setCurrentIndex(1);
        break;
        case 1:
            textRetour = "Compte non trouvé, vérifiez les informations";
            ui->lineEdit_MdP->clear();
        break;
        case 2:
            textRetour = "Compte trouvé, Mot de passe incorrect";
            ui->lineEdit_MdP->clear();
        break;
    }
    ui->labelInfo->clear(); //Si il est déjà ecrit, pour éviter les problèmes
    ui->labelInfo->setText(textRetour);

    m_shareCount.notify();
}

void MainWindow::on_actionD_connexion_triggered()
{
    // On réaffiche la page de connexion
    ui->stackedWidget->setCurrentIndex(0);

    // On vide tout les champs déjà rempli
    ui->labelInfo->clear();
    ui->lineEdit_MdP->clear();
    ui->lineEditNom->clear();
    ui->lineEditPrenom->clear();
}


void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}

void MainWindow::on_buttonCreerCagnotte_clicked()
{
    QString result = QInputDialog::getText(0, "Entrer le nom de la cagnotte", "Nom:");
    if(!result.isEmpty())
        m_shareCount.creerCagnotte(result.toStdString());
    m_shareCount.notify();
}

void MainWindow::on_lineEdit_MdP_returnPressed()
{
    on_pushButtonConnexion_clicked();
}

void MainWindow::on_goToGroup_pressed()
{
    ui->stackedWidget->setCurrentIndex(2);

    m_shareCount.setCurrentGroup(ui->groupList->currentItem()->data(Qt::UserRole).toInt());

    QString nomCagnotte = QString::fromStdString(m_shareCount.getCurrentGroup()->getNom());
    ui->labelNomCagnotte->setText(nomCagnotte);

    int budget = m_shareCount.getCurrentGroup()->getBudget();
    ui->labelSommeCagnotte->setText(QString::fromStdString(std::to_string(budget)));
    m_shareCount.notify();
}


void MainWindow::on_groupList_itemDoubleClicked(QListWidgetItem *item)
{
    //En cas de double clik, on appelle simplement la fonction d'appui sur le bouton
    MainWindow::on_goToGroup_pressed();
}

void MainWindow::on_pushButtonBackCagnotte_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    m_shareCount.notify();
}

void MainWindow::on_pushButtonAddMoney_clicked()
{
    QString result = QInputDialog::getText(0, "Entrer montant", "Value:");
    m_shareCount.addToCagnotte(result.toInt());
    m_shareCount.notify();
}

void MainWindow::on_pushButtonAddParticipants_clicked()
{
    QString nomResult = QInputDialog::getText(0, "Entrer coordonnées :", "Nom Prénom:");
    std::string coo = nomResult.toStdString();
    std::string delimiter = " ";
    if (coo.find(delimiter) != std::string::npos)
    {
        std::string nom = coo.substr(0, coo.find(delimiter));
        std::string prenom = coo.substr(nom.length() + 1);
        qDebug() << QString::fromStdString(nom) << " " << QString::fromStdString(prenom);

        if (m_shareCount.trouverCompte(nom, prenom) != -1){
            m_shareCount.addParticipant(m_shareCount.getCompte(m_shareCount.trouverCompte(nom, prenom)));
            m_shareCount.notify();
        }
    }

}


void MainWindow::on_actionSupprimer_Cagnotte_triggered()
{

}

void MainWindow::on_actionRenommer_Cagnotte_triggered()
{
    QString nomResult = QInputDialog::getText(0, "Nom :", "Entrer le nouveau nom :");
    if(!nomResult.isEmpty())
        m_shareCount.renameCagnotte(nomResult.toStdString());

    m_shareCount.notify();
}

void MainWindow::on_buttonAddMontant_clicked()
{
    QString montant = QInputDialog::getText(0, "Montant", "Entrer montant à ajouter :");
    if (montant.toInt() >0)
        m_shareCount.crediterCompte(montant.toInt());
    m_shareCount.notify();
}


void MainWindow::on_pushButtonCreerDemande_clicked()
{
    QString montant = QInputDialog::getText(0, "Montant", "Entrer montant à ajouter :");
    if (montant.toInt() >0)
        m_shareCount.ajouterDemande(montant.toInt());
    m_shareCount.notify();
}

void MainWindow::on_listWidgetDemandes_itemDoubleClicked(QListWidgetItem *item)
{
    int reponse = QMessageBox::question(this, "Valider demande", "Acceptez vous la demande de retrait ", QMessageBox::Cancel | QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes){
        m_shareCount.getCurrentGroup()->getDemande(item->data(Qt::UserRole).toInt())->ajouterReponse(m_shareCount.getCurrentCompte()->getIdentifiant(), true);
    }
    if (reponse == QMessageBox::No){
        m_shareCount.getCurrentGroup()->getDemande(item->data(Qt::UserRole).toInt())->ajouterReponse(m_shareCount.getCurrentCompte()->getIdentifiant(), false);
    }
}


void MainWindow::on_pushButtonRepondre_clicked()
{
    if(ui->listWidgetDemandes->currentItem() != nullptr)
        on_listWidgetDemandes_itemDoubleClicked(ui->listWidgetDemandes->currentItem());
}
