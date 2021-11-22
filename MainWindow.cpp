#include <QPushButton>
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

    m_button = new QPushButton("oui", this);
    connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
}

MainWindow::~MainWindow()
{
    delete ui;
    m_shareCount.detach(*this);
}

void MainWindow::update() {
    m_button->setText("bleg");
}

void MainWindow::handleButton() {
    m_shareCount.notify();
}


/*ButtonNum::ButtonNum(ShareCount &shareCount, QWidget *parent)
    : QPushButton(parent)
    , m_sharecount(shareCount)
{
    m_sharecount.attach(*this);
}

*/
