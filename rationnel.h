#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include <iostream>

class Rationnel : public Constante{
    int _numerateur;
    int _denominateur;

public:

    virtual QString afficher() const{ return QString::number(_numerateur)+"/"+QString::number(_denominateur);}
    float getNumerateur() const {return _numerateur;}
    float getDenominateur() const {return _denominateur;}
    void setNumerateur(int v){_numerateur=v;}
    void setDenominateur(int v){_denominateur=v;}
    Rationnel(Constante* c);

    virtual Constante* addition(Constante* c);
    virtual Constante* produit(Constante *c);
    virtual Constante* division(Constante* c);
    virtual Constante* signe();
    virtual Constante* soustraction(Constante* c);

    Rationnel(int num=0, int den=1):_numerateur(num), _denominateur(den)
    {
        if (_denominateur==0)
        {
//FIME exeption
            std::cout<<"BOUHHHHHHH";
        }
    }
};

#endif // RATIONNEL_H
