#include "calculatrice.h"
#include <QtGui>

Calculatrice* Calculatrice::instance=0;

Calculatrice::~Calculatrice(){
}

Calculatrice::Calculatrice() : context( new QSettings("context.ini", QSettings::IniFormat))
{
    context->setValue("ModeAngle", _modAngle);
    context->setValue("ModeConstante", _modConstante);
    context->setValue("ModeComplexe", _modComplexe);
    qDebug() << context->value("ModeComplexe").value<bool>();
 //   qDebug() << context->value("ModeAngle").value<enum MesureAngle>();
    qDebug() << "tadta";
        //context->setValue("PileAffichage", _pileAffichage);
//      context->setValue("PileStockage", _pileStockage);
}

Calculatrice& Calculatrice::getInstance(){
    if (!instance) instance= new Calculatrice();
    return *instance;
}

void Calculatrice::libereInstance(){
    delete instance;
}
