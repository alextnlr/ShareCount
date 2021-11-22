#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
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
    void handleButton();
private:
    Ui::MainWindow *ui;
    ShareCount& m_shareCount;
    QPushButton *m_button;
};

/*class ButtonNum : public QPushButton, public Vue
{
    Q_OBJECT
public:
    ButtonNum(ShareCount &shareCount, QWidget *parent = nullptr);
    void update(ShareCount& modele) override;
    void
private:
    ShareCount& m_sharecount;
};*/
#endif // MAINWINDOW_H
