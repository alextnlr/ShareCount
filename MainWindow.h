#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QStackedWidget>
#include <QInputDialog>
#include <QDebug>
#include "ObserverPattern.h"
#include "ShareCount.h"
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Vue
{
    Q_OBJECT

public:
    MainWindow(ShareCount &shareCount, QWidget *parent = nullptr);
    void update() override;
    ~MainWindow() override;

private slots:
    //void handleButton();
    void on_pushButtonCreationCompte_clicked();

    void on_pushButtonConnexion_clicked();

    void on_actionD_connexion_triggered();

    void on_actionQuitter_triggered();

    void on_buttonCreerCagnotte_clicked();

    void on_lineEdit_MdP_returnPressed();

    void on_goToGroup_pressed();

    void on_groupList_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButtonBackCagnotte_clicked();

    void on_pushButtonAddMoney_clicked();

    void on_pushButtonAddParticipants_clicked();

    void on_actionSupprimer_Cagnotte_triggered();

    void on_actionRenommer_Cagnotte_triggered();

    void on_buttonAddMontant_clicked();

    void on_pushButtonCreerDemande_clicked();

    void on_listWidgetDemandes_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButtonRepondre_clicked();

private:
    Ui::MainWindow *ui;
    ShareCount& m_shareCount;
};

#endif // MAINWINDOW_H
