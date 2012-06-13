#ifndef REEL_H
#define REEL_H

#include "constante.h"
#include "rationnel.h"

class Reel: public Constante{
    //float _valeur;
    double _valeur;

public:
    Reel(double e):_valeur(e){}
    Reel(Constante* c);
    //virtual ~Reel() {}
    virtual QString afficher() const{ return QString::number(_valeur);}
    double getValeur() const {return _valeur;}
    void setValeur(int v){_valeur=v;}

    Rationnel toRationnel() const;

    virtual Constante* addition(Constante* c);
    virtual Constante* produit(Constante *c);
    virtual Constante* division(Constante* c);
    virtual Constante* signe();
    virtual Constante* soustraction(Constante* c);
    virtual Constante* inv();
    virtual Constante* fact();
    virtual Constante* sinus(bool angle);
    virtual Constante* cosinus(bool angle);
    virtual Constante* sinush(bool angle);
    virtual Constante* cosinush(bool angle);
    virtual Constante* tangente(bool angle);
    virtual Constante* tangenteh(bool angle);
    virtual Constante* logN();
    virtual Constante* log1();
    virtual Constante* puissance(Constante *c);
    virtual Constante* carre();
    virtual Constante* cube();
    virtual Constante* racine();
};

#endif // REEL_H
