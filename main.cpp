#include <QtGui/QApplication>
#include "mainwindow.h"
#include "TypeDonnee.h"

//qt example calculator
//design pattern command
//trois Clases : Complexe, Rationnel, MainWindow
//math.h
//Gérer les exeptions => exeptions standards

//=> OnClik sur MODE_COMPLEXE on bascule les piles en complexes en vidant tous les nombres en mémoire

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
