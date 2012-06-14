#include "calculatrice.h"
#include <QtGui>

Calculatrice* Calculatrice::instance=0;

Calculatrice::~Calculatrice(){
}

Calculatrice::Calculatrice() : context( new QSettings("context.ini", QSettings::IniFormat))
{
    Historique.prepend(new Pile);
    indice_pile_actuelle = 0;
    _modComplexe = true;

    context->setValue("ModeAngle", _modAngle);
    context->setValue("ModeConstante", _modConstante);
    context->setValue("ModeComplexe", _modComplexe);
    qDebug() << context->value("ModeComplexe").value<bool>();
 //   qDebug() << context->value("ModeAngle").value<enum MesureAngle>();
    qDebug() << "tadta";
        //context->setValue("PileAffichage", _pileAffichage);
//      context->setValue("PileStockage", _pileStockage);
}

void Calculatrice::saisie_nouvelle_pile(Pile* nouvelle){
    //on enlève tous les potentiels redo
    for(unsigned int i=0; i<indice_pile_actuelle; i++)
        Historique.removeAt(0); // ATTENTION : c'est bien zéro !
    //on ajoute le nouvel état en tête
    Historique.prepend(nouvelle);
    indice_pile_actuelle = 0;

}

void Calculatrice::annuler(){
    if (indice_pile_actuelle != Historique.size()-1){
        indice_pile_actuelle++;
    }
}

void Calculatrice::retablir(){
    if (indice_pile_actuelle != 0)
        indice_pile_actuelle--;
}

void Calculatrice::afficher_toutes_piles_hitorique(){
    qDebug() << "PILES HISTORIQUES\n";
    for(int i=0; i<Historique.size(); i++)
        qDebug() << "PILE " << i << "\n" << Historique.at(i)->afficher();
}

Calculatrice& Calculatrice::getInstance(){
    if (!instance) instance= new Calculatrice();
    return *instance;
}

void Calculatrice::libereInstance(){
    delete instance;
}
