#include "calculatrice.h"

Calculatrice* Calculatrice::instance=0;

Calculatrice::~Calculatrice(){
}

Calculatrice::Calculatrice(){}

Calculatrice& Calculatrice::getInstance(){
    if (!instance) instance= new Calculatrice();
    return *instance;
}

void Calculatrice::libereInstance(){
    delete instance;
}
