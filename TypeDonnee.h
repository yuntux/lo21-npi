#ifndef TYPEDONNEE_H
#define TYPEDONNEE_H

#include <iostream>


class Complexe {
    float _reelle;
    float _imaginaire;

public:
    Complexe(float r=0, float i=0):_reelle(r), _imaginaire(i){}
    virtual void Afficher(){ std::cout<<_reelle<<_imaginaire<<"\n";}
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
