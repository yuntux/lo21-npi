#include <QtGui/QApplication>
#include "mainwindow.h"

//qt example calculator
//design pattern command
//utiliser les QStack

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
