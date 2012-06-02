#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include <iostream>

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

#endif // RATIONNEL_H
