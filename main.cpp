#include <QtGui/QApplication>
#include "mainwindow.h"

#include "complexe.h"

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
//quid des concepts centraux de LO21 : surcharge, héritage, polymorphisme, designPattern, dynamicCast...

//=> OnClik sur MODE_COMPLEXE on bascule les piles en complexes en vidant tous les nombres en mémoire



//DYNAMIC CAST sur toutes les fonction assymétrique des toutes les classes déivée des constante sauf pour la classe complexe (rationnel?)

int main(int argc, char *argv[])
{

    /* DEBUG */
  /*  Complexe * c1 = new Complexe(3, 3);
    Complexe * c2 = new Complexe(4, 5);
    c1->addition(c2);
    c1->afficher();
    return 0;
*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
