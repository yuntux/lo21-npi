#ifndef ENTIER_H
#define ENTIER_H

#include "constante.h"

class Entier : public Constante{
    int _valeur;

public:
    Entier(int e):_valeur(e){}
    Entier(Constante* c);
    virtual QString afficher() const{ return QString::number(_valeur);}
    //virtual QString afficher() const{ std::cout<<_valeur; return "a";}
    int getValeur() const {return _valeur;}
    void setValeur(int v){_valeur=v;}

    virtual Constante* addition(Constante* c);
    virtual Constante* produit(Constante *c);
    virtual Constante* signe();
    virtual Constante* division(Constante* c);
    virtual Constante* soustraction(Constante* c);
    int mod(Entier *c);
    virtual Constante* inv();
    virtual Constante* fact();
    virtual Constante* sinus();
};

#endif // ENTIER_H
