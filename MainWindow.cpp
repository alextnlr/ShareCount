#include <QPushButton>
#include "MainWindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ShareCount");

    QPushButton *button = new QPushButton("aled", this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
