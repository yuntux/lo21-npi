#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <QtGui>

enum Type {
       entier,
       rationnel,
       reel,
       complexe,
       expression,
       //erreur
    };

class Constante
{
public:
    virtual QString afficher() const = 0;
    virtual Constante* addition(Constante* c)=0;
    virtual Constante* produit(Constante* c)=0;
    virtual Constante* division(Constante* c)=0;
    virtual Constante* signe()=0;
    Constante* recopie();
    virtual Constante* soustraction(Constante* c)=0;
    virtual Constante* inv()=0;
    virtual Constante* fact()=0;
    virtual Constante* sinus()=0;
};

class FrabriqueConstante{
public:
    //virtual Constante frabriquer()=0;
};

#endif // CONSTANTE_H
