#include <QtGui/QApplication>
#include "mainwindow.h"
#include "TypeDonnee.h"
#include "fonctions.h"

//qt example calculator
//DESIGN PATTERN : command
//trois Clases : Complexe, Rationnel, MainWindow
//math.h
//Gérer les erreurs => exeptions standards
//Sauvegarde/Chargmenet de la calculatrice

//=> OnClik sur MODE_COMPLEXE on bascule les piles en complexes en vidant tous les nombres en mémoire

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
