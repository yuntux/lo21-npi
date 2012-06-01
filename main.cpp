#include <QtGui/QApplication>
#include "mainwindow.h"
#include "TypeDonnee.h"
#include "fonctions.h"
//qt example calculator
//
//DESIGN PATTERN : command(Annuler/Rétablir), Factory, Composite,
//trois Clases : Complexe, Rationnel, MainWindow
//math.h
//Gérer les erreurs => exeptions standards
//Sauvegarde/Chargmenet des piles
//Traiter l'une des trois options : logMessage/onglets/CommmandeUtilisateur
//DocDOXYGEN
//Rapport et modélisation UML(diag de class et diag de séquence)

//QListview

//Annuller rétablir doit prendre un int en paramètre
//dans la pile de calcul : on stocke 5,4,+,20
//dans la pile d'affichage : on a que 20

//RAPOPRT : on gère les rationnel sans touche supplémentaire. On considère que le slash est l'opréateur de division que s'il est précédé d'un esdpace
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
