#include <QtGui/QApplication>
#include "mainwindow.h"
#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "pile.h"
#include "reel.h"
#include <typeinfo>
#include <cmath>
#include "logmessage.h"
#include "logsystem.h"



//RAPOPRT : on gère les rationnel sans touche supplémentaire. On considère que le slash est l'opréateur de division que s'il est précédé d'un esdpace
//quid des concepts centraux de LO21 : surcharge, héritage, polymorphisme, designPattern, dynamicCast...

//RAPPORT : Étant donné que dans un ordi un réel non rationnel est stocké comme une approcx (PI, RACINE_2 sont des approx dans un float)
//      On aurait pu représenter les parties imaginaire et réélles d'un complexe par des rationnels et toutes les constantes par des complexes

int main(int argc, char *argv[])
{

    /* DEBUG */
/*
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

    return 0;
    */



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    /**
      * \brief Fonction Main
      * \details On lance l'application correspondant à la calculatrice
      */


}
