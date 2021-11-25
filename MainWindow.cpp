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



    /*m_pages = new QStackedWidget(this);
    page1 = new QWidget(m_pages);
    page2 = new QWidget(m_pages);
    QVBoxLayout *vlay = new QVBoxLayout(page1);

    m_button = new QPushButton("send");
    //m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 30)));
    connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
    vlay->addWidget(m_button);
    m_button->show();


    m_name = new QLineEdit();
    //m_name->setGeometry(QRect(QPoint(100, 50), QSize(200, 30)));
    vlay->addWidget(m_name);

    //vlay->setGeometry(QRect(QPoint(0, 0), QSize(this->size().width(), this->size().height())));
    m_pages->setGeometry(QRect(QPoint(0, 0), QSize(this->size().width(), this->size().height())));
    //page1->setGeometry(QRect(QPoint(0, 0), QSize(this->size().width(), this->size().height())));

    m_affichage = new QLabel("hello");
    //m_affichage->setGeometry(QRect(QPoint(100, 10), QSize(200, 30)));
    //vlay->addWidget(m_affichage);

    page1->setLayout(vlay);
    setCentralWidget(page1);
    page1->show();

    m_pages->insertWidget(0, page1);
    m_pages->insertWidget(1, page2);
    m_pages->setCurrentIndex(0);
    m_pages->show();*/
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_button;
    delete m_name;
    delete m_affichage;
    delete m_pages;
    delete page1;
    delete page2;
    m_shareCount.detach(*this);
}

void MainWindow::update() {
    m_affichage->setText(QString::fromStdString(m_shareCount.get_aled()));
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
        ui->labelInfo->setText("Erreur lors de la création de compte");
        textRetour = "Erreur lors de la création de compte";
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
}
