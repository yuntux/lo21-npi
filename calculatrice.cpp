#include "calculatrice.h"
#include <QtGui>

Calculatrice* Calculatrice::instance=0;

Calculatrice::~Calculatrice(){
}

Calculatrice::Calculatrice() : context( new QSettings("context.ini", QSettings::IniFormat))
{
    Historique.prepend(new Pile);
    indice_pile_actuelle = 0;

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
    //l'itératerude pile actuelle devient le premier élément de la pile
    indice_pile_actuelle = 0;
    //qDebug() << "Historique.begin()" << Historique[0]->afficher();
    //qDebug() << "Historique.end()" << Historique[Historique.size()-1]->afficher();

}

void Calculatrice::annuler(){

    //qDebug() << "PILE AVANT ANNULATION\n" << this->getInstance().getPileStockage()->afficher();
    if (indice_pile_actuelle != Historique.size()-1){
        //qDebug() << "it_pile_actuelle != Historique.end()";
        indice_pile_actuelle++;
        //qDebug() << "incrémentation de l'itérateur";
    }
    //qDebug() << "PILE APRES ANNULATION\n" << this->getInstance().getPileStockage()->afficher();

}

void Calculatrice::retablir(){
    if (indice_pile_actuelle != 0)
        indice_pile_actuelle--;
}

void Calculatrice::afficher_toutes_piles_hitorique(){
    qDebug() << "PILE HISTORIQUE\n";
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
