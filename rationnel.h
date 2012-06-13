#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include <iostream>
#include "logmessage.h"
#include "exception"

class Rationnel : public Constante{
    int _numerateur;
    int _denominateur;

public:

    virtual QString afficher() const;
    float getNumerateur() const {return _numerateur;}
    float getDenominateur() const {return _denominateur;}
    void setNumerateur(int v){_numerateur=v; simplification();}
    void setDenominateur(int v){
        if (v!=0) {
            _denominateur=v;
            simplification();
        } else {
            //throw domain_error("Division par zéro");
            throw LogMessage(1,"Division par zéro", important);
        }
    }
    Rationnel(Constante* c);
    Rationnel(int num=0, int den=1);
    void simplification();
   // virtual ~Rationnel() {}
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
    virtual Constante* puissance(Constante* c);
    virtual Constante* carre();
    virtual Constante* cube();
    virtual Constante* racine();


};

#endif // RATIONNEL_H
