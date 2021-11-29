#include <QPushButton>
#include <QVBoxLayout>
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

    std::map<int, Cagnotte*> cagnottes = m_shareCount.getNomGroupes();
    for (const auto& nom : cagnottes) {
        QListWidgetItem* item = new QListWidgetItem;
        item->setText(QString::fromStdString(nom.second->getNom()));
        item->setData(Qt::UserRole, nom.second->getIdCagnotte());
        ui->groupList->addItem(item);
    }
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
    QString result = QInputDialog::getText(0, "Text input", "Value:");
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
}


void MainWindow::on_groupList_itemDoubleClicked(QListWidgetItem *item)
{
    //En cas de double clik, on appelle simplement la fonction d'appui sur le bouton
    MainWindow::on_goToGroup_pressed();
}

void MainWindow::on_pushButtonBackCagnotte_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonAddMoney_clicked()
{
}
