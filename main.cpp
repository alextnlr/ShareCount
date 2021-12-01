#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShareCount shareCount;
    MainWindow w(shareCount);
    w.show();
    a.setWindowIcon(QIcon("/home/timeo/CLionProjects/sharecount/logo.png"));
    return a.exec();
}
