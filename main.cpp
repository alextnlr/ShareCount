#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShareCount shareCount;
    MainWindow w(shareCount);
    w.show();
    return a.exec();
}
