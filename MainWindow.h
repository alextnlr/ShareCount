#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QStackedWidget>
#include "ObserverPattern.h"
#include "ShareCount.h"

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

private:
    Ui::MainWindow *ui;
    ShareCount& m_shareCount;
};

#endif // MAINWINDOW_H
