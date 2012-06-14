#include "constante.h"
#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "expression.h"
#include <typeinfo>

Constante* Constante::recopie(){
    if (Entier *c_entier=dynamic_cast<Entier *>(this)){
        return new Entier(c_entier->getValeur());
    } else if (Expression *c_expression=dynamic_cast<Expression *>(this)){
        return new Expression(c_expression->getExpr());
    } else if (Reel *c_reel=dynamic_cast<Reel *>(this)){
        return new Reel(c_reel->getValeur());
    } else if (Rationnel *c_rationnel=dynamic_cast<Rationnel *>(this)){
        return new Rationnel(c_rationnel->getNumerateur(), c_rationnel->getDenominateur());
    } else if (Complexe *c_complexe=dynamic_cast<Complexe *>(this)){
        Complexe* tmp = new Complexe;
        //on recopie la partie imaginaire
        if (typeid(*c_complexe->getPartieImaginaire())==typeid(Entier)){
            Constante* im = c_complexe->getPartieImaginaire()->recopie();
            tmp->setImaginaire(im);
        } else if (typeid(*c_complexe->getPartieImaginaire())==typeid(Rationnel)){
            Constante* im = c_complexe->getPartieImaginaire()->recopie();
            tmp->setImaginaire(im);
        } else if (typeid(*c_complexe->getPartieImaginaire())==typeid(Reel)){
            Constante* im = c_complexe->getPartieImaginaire()->recopie();
            tmp->setImaginaire(im);
        }
        //on recopie la partie reelle
        if (typeid(*c_complexe->getPartieReelle())==typeid(Entier)){
            Constante* re = c_complexe->getPartieReelle()->recopie();
            tmp->setReelle(re);
        } else if (typeid(*c_complexe->getPartieReelle())==typeid(Rationnel)){
            Constante* re = c_complexe->getPartieReelle()->recopie();
            tmp->setReelle(re);
        } else if (typeid(*c_complexe->getPartieReelle())==typeid(Reel)){
            Constante* re = c_complexe->getPartieReelle()->recopie();
            tmp->setReelle(re);
        }
        return tmp;
    }
}
