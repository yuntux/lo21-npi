#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"

class Complexe : public Constante{
    double _reelle;
    double _imaginaire;

public:
    Complexe(float r=0, float i=0):_reelle(r), _imaginaire(i){}
    virtual QString afficher() const{ return QString::number(_reelle)+"+"+QString::number(_imaginaire)+"i\n";}
    float getPartieReelle() const {return _reelle;}
    float getPartieImaginaire() const {return _imaginaire;}
    void setReelle(float re){_reelle=re;}
    void setImaginaire(float im){_imaginaire=im;}

    virtual Complexe* operator+(Complexe& c);
};
    //Complexe operator+(Complexe const&a, Complexe const&b);

class FrabriqueComplexe : public Complexe{
public:
    Complexe fabriquer();
};

#endif // COMPLEXE_H
