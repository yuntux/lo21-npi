#include <QtGui/QApplication>
#include "mainwindow.h"
#include "fonctions.h"
#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>
#include <cmath>


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
//implémenter une fonction de simplification pour les rationnels
int main(int argc, char *argv[])
{

    /* DEBUG */

    Entier e1(5);
    Entier e2(2);
    Entier e3(3);
    Rationnel ra1(2,5);
    Rationnel ra2(5,6);
    Rationnel ra3(2,3);
    Reel re1(3.1);
    Reel re2(3.2);
    Reel re3(3.3);
    Complexe c11(&e1, &e2);
    Complexe c12(&e3, &e1);
    Complexe c13(&e1, &re3);
    Complexe c21(&ra1, &ra2);
    Complexe c22(&ra2, &ra3);
    Complexe c23(&ra3, &e3);
    Complexe c31(&re1, &re2);
    Complexe c32(&re1, &ra3);
    Complexe c33(&re1, &e3);

    //IL FAUT QU'ON UTILISE AU PLUS LA SYMETRIE DES OPERATIONS (+ et *) :
    //on implemente la multiplication que d'un coté (complexe) et de l'autre on revoie c_complexe.multiplication(this)
    //utiliser INV et multiplication pour avoir la multiplication ? Fuite de mémoire du à la non libération de l'intermédiaire créé par INV ?

    qDebug() << c11.addition(&c21)->afficher(); //Complexe(int$int) + Complexe (ra$ra) OK
    qDebug() << c21.addition(&c22)->afficher(); //Complexe(ra$ra) + Complexe (ra$ra) OK
    //qDebug() << c23.addition(&c31)->afficher(); //Complexe(ra$e) + Complexe (re$re) KO => ra+re impossible sans perte de précision

    qDebug() << c11.produit(&c12)->afficher();
    qDebug() << c11.soustraction(&c12)->afficher();
    /*qDebug() << e3.addition(&e1)->afficher();
    qDebug()<<re1.addition(&re2)->afficher();
    qDebug()<<ra1.addition(&ra2)->afficher();
    qDebug()<<c21.addition(&ra1)->afficher();
    qDebug()<<e2.produit(&e2)->afficher();
    qDebug()<<e2.soustraction(&re1)->afficher();
    qDebug()<<ra2.division(&ra3)->afficher();
    qDebug()<<c11.produit(&ra1)->afficher();
    qDebug()<<"\n"<<sinush(&ra1);
*/
    /*Constante *a = e1.addition(&e2);
    Complexe *ent = new Complexe(&re1);
    qDebug() << ent->afficher();
    qDebug() << ent->getPartieReelle()->afficher();
    qDebug() << ent->getPartieImaginaire()->afficher();
    //qDebug() << a->afficher();
*/
    return 0;

/*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/

}
