#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include "entier.h"

class Complexe : public Constante{
    //attention _reel et _imaginaire doivent être de type constante
    Constante* _reelle;
    Constante* _imaginaire;

public:
    Complexe():_reelle(new Entier(0)), _imaginaire(new Entier(0)){}
    Complexe(Constante* r, Constante* i);
    virtual QString afficher() const{ return _reelle->afficher()+"$"+_imaginaire->afficher();}
    Constante* getPartieReelle() const {return _reelle;}
    Constante* getPartieImaginaire() const {return _imaginaire;}
    void setReelle(Constante* re){_reelle=re;}
    void setImaginaire(Constante* im){_imaginaire=im;}

    Complexe(Constante* c);
    //Complexe* conjugue(Complexe* c);
    //Constante* module(Complexe* c);
    //Constante* argument(Complexe* c);

    virtual Constante* addition(Constante* c);
    virtual Constante* produit(Constante *c);
    virtual Constante* division(Constante* c);
    virtual Constante* signe();
    virtual Constante* soustraction(Constante* c);
};

class FrabriqueComplexe : public Complexe{
public:
    Complexe fabriquer();
};

#endif // COMPLEXE_H
