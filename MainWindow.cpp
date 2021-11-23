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

    m_button = new QPushButton("send", this);
    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 30)));
    connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);

    m_name = new QLineEdit(this);
    m_name->setGeometry(QRect(QPoint(100, 50), QSize(200, 30)));

    m_affichage = new QLabel("hello", this);
    m_affichage->setGeometry(QRect(QPoint(100, 10), QSize(200, 30)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_button;
    delete m_name;
    delete m_affichage;
    m_shareCount.detach(*this);
}

void MainWindow::update() {
    m_affichage->setText(QString::fromStdString(m_shareCount.get_aled()));
}

void MainWindow::handleButton() {
    m_shareCount.set_aled(m_name->text().toStdString());
    m_shareCount.notify();
}

