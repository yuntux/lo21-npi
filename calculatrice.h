#ifndef CALCULATRICE_H
#define CALCULATRICE_H
#include "TypeDonnee.h"
#include <QStack>

enum MesureAngle { degre, radian};
enum TypeConstante { entier, reel, rationnel};

class Calculatrice
{
    enum MesureAngle _modAngles;
    enum TypeConstante _modConstante;
    bool _modComplexe;
    QStack<TypeDonnee*> _pileAffichage;
    QStack<TypeDonnee*> _pileStockage;

public :
      Calculatrice(enum TypeConstante c=entier, enum MesureAngle a=degre, bool comp=false)
           : _modConstante(c), _modAngles(a), _modComplexe(comp) {}
    Calculatrice();
};

#endif // CALCULATRICE_H
