#include "complexe.h"

Complexe* Complexe::operator+(Complexe& c){
    Complexe * tmp = new Complexe;
    tmp->setImaginaire(c.getPartieImaginaire()+_imaginaire);
    return tmp;
}
