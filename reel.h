#ifndef REEL_H
#define REEL_H

#include "constante.h"

class Reel: public Constante{
    float _valeur;

public:
    Reel(float e):_valeur(e){}
    Reel(Constante* c);
    virtual QString afficher() const{ return QString::number(_valeur);}
    float getValeur() const {return _valeur;}
    void setValeur(int v){_valeur=v;}

    virtual Constante* addition(Constante* c);
    virtual Constante* signe();
    virtual Constante* soustraction(Constante* c);
};

#endif // REEL_H
