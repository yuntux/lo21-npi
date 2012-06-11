#include <QtGui/QApplication>
#include "mainwindow.h"
#include "fonctions.h"
#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "pile.h"
#include "reel.h"
#include <typeinfo>
#include <cmath>
#include "logmessage.h"
#include "logsystem.h"

//DESIGN PATTERN : command(Annuler/Rétablir), Factory, Composite,
//Gérer les erreurs => exeptions standards
//Sauvegarde/Chargmenet des piles
//Traiter l'une des trois options : logMessage/onglets/CommmandeUtilisateur
//DocDOXYGEN
//Rapport et modélisation UML(diag de class et diag de séquence)

//http://doc.qt.nokia.com/4.7-snapshot/demos-undo.html

//Annuller rétablir doit prendre un int en paramètre
//dans la pile de calcul : on stocke 5,4,+,20
//dans la pile d'affichage : on a que 20

//RAPOPRT : on gère les rationnel sans touche supplémentaire. On considère que le slash est l'opréateur de division que s'il est précédé d'un esdpace
//mods de la calto en static ???
//quid des concepts centraux de LO21 : surcharge, héritage, polymorphisme, designPattern, dynamicCast...

//RAPPORT : Étant donné que dans un ordi un réel non rationnel est stocké comme une approcx (PI, RACINE_2 sont des approx dans un float)
//      On aurait pu représenter les parties imaginaire et réélles d'un complexe par des rationnels et toutes les constantes par des complexes
//      => code simplifié mais gaspillage de mémoire

//DYNAMIC CAST sur toutes les fonction assymétrique des toutes les classes déivée des constante sauf pour la classe complexe (rationnel?)
//implémenter une fonction de simplification pour les rationnels
int main(int argc, char *argv[])
{

    /* DEBUG */

    Entier e1(0);
    Entier e2(2);
    Entier e3(3);
    Rationnel ra1(2,5);
    Rationnel ra2(5,6);
    Rationnel ra3(2,3);
    Reel re1(3.14159265/2);
    Reel re2(90.0);
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
    //qDebug() << re1.cosinus(false)->afficher(); //on passe false en param des fonctions trigo lorsque l'on est en mod rad
    //qDebug() << re2.cosinus(true)->afficher();
    //qDebug() << e1.cosinus(true)->afficher(); //on passe false en param des fonctions trigo lorsque l'on est en mod degres
    try {
        ra1.setDenominateur(0);
    }
    catch(std::exception const& e)
    {
        // FIXME : interagir avec logsystem
        cerr << "ERREUR : " << e.what() << endl;
    }
    Pile Stockage;
    Stockage.push(&e1);
    Stockage.push(&re1);
    Stockage.push(&ra1);
    Stockage.push(&c11);
    qDebug() << Stockage.afficher();
    Stockage.swap(1,3);
    qDebug() << Stockage.afficher();

    //qDebug() << e1.division(&c11)->afficher();
    //qDebug() << ra1.division(&c11)->afficher();
    //qDebug() << re1.division(&c11)->afficher();
    //Stockage.push(c11.division(&c12));
    /*
    QString tmp0 = "100";
    Stockage.push(new Entier(tmp0.toInt()));
    QString tmp1 = "30"; //on detecte que c'est un entier
    Stockage.push(new Entier(tmp1.toInt()));
    QString tmp2 = "2.3"; //on detecte que c'est un réel
    Stockage.push(new Reel(tmp2.toFloat()));
    qDebug() << Stockage.afficher();
    QString tmp3 = "+"; //on détecte que c'est l'opérateur +
    Constante* operande1 = Stockage.pop();
    Constante* operande2 = Stockage.pop();
    Stockage.push(operande1->addition(operande2));
    qDebug() << Stockage.afficher();
    QString tmp4 = "5.3"; //on detecte que c'est un réel
    Stockage.push(new Reel(tmp4.toFloat()));
    qDebug() << Stockage.afficher();
    QString tmp5 = "+"; //on détecte que c'est l'opérateur +
    Constante* operande11 = Stockage.pop();
    Constante* operande12 = Stockage.pop();
    Stockage.push(operande11->addition(operande12));
    //qDebug() << Stockage.afficher();
*/
    //IL FAUT QU'ON UTILISE AU PLUS LA SYMETRIE DES OPERATIONS (+ et *) :
    //on implemente la multiplication que d'un coté (complexe) et de l'autre on revoie c_complexe.multiplication(this)
    //utiliser INV et multiplication pour avoir la multiplication ? Fuite de mémoire du à la non libération de l'intermédiaire créé par INV ?

  //  qDebug() << c11.addition(&c21)->afficher(); //Complexe(int$int) + Complexe (ra$ra) OK
    //qDebug() << c21.addition(&c22)->afficher(); //Complexe(ra$ra) + Complexe (ra$ra) OK
    //qDebug() << c23.addition(&c31)->afficher(); //Complexe(ra$e) + Complexe (re$re) KO => ra+re impossible sans perte de précision

    //qDebug() << c11.produit(&c12)->afficher();
    //qDebug() << c11.soustraction(&c12)->afficher();
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
//    return 0;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}
