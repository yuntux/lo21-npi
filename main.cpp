#include <QtGui/QApplication>
#include "mainwindow.h"
#include "TypeDonnee.h"
#include "fonctions.h"
//qt example calculator
//DESIGN PATTERN : command(Annuler/Rétablir)
//trois Clases : Complexe, Rationnel, MainWindow
//math.h
//Gérer les erreurs => exeptions standards
//Sauvegarde/Chargmenet des piles
//Traiter l'une des trois options : logMessage/onglets/CommmandeUtilisateur
//DocDOXYGEN
//Rapport et modélisation UML(diag de class et diag de séquence)

//mods de la calto en static ???
//quid des concepts centraux de LO21 : surcharge, héritage, polymorphisme, designPattern...

//=> OnClik sur MODE_COMPLEXE on bascule les piles en complexes en vidant tous les nombres en mémoire

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.empiler(5.2);

    return a.exec();
}
