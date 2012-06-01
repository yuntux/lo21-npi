#ifndef TYPEDONNEE_H
#define TYPEDONNEE_H

#include <iostream>
#include <QtGui>

enum Type {
       ent,
       rat,
       real,
       comp,
       expr,
       erreur
    };

class Constante
{
public:
    const Type& getType() { return genre; }
    virtual QString afficher() const = 0;
protected:
    Type genre;
//    virtual void construireConstante(const std::string&) = 0;
};

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

};


class Rationnel {
    int _numerateur;
    int _denominateur;

public:
    Rationnel(int num, int den=1):_numerateur(num), _denominateur(den)
    {
        if (_denominateur==0)
        {
//FIME exeption
            std::cout<<"BOUHHHHHHH";
        }
    }
};

#endif // TYPEDONNEE_H
