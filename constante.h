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
    //virtual Constante* signe()=0;
};

class FrabriqueConstante{
public:
    //virtual Constante frabriquer()=0;
};

#endif // CONSTANTE_H
