#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>


Reel::Reel(Constante* c) {
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        _valeur = c_entier->getValeur();
    } else if (typeid(*c)==typeid(Complexe)) {
        //FIXME : impossible de construire un entier avec un complexe
    } else if (typeid(*c)==typeid(Rationnel)) {
        //FIXME : impossible de construire un entier avec un rationnel
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        _valeur = c_reel->getValeur();
    }
}

Constante* Reel::addition(Constante* c){
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        return c_entier->addition(this);
    } else if (typeid(*c)==typeid(Complexe)) {
        Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        return c_complexe->addition(this);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        //FIXME : on doit pouvoir mettre des type constantes pour les réels et rationnel => PAS DE CAST SUR LA CLASSE COMPLEXE
        return c_rationnel->addition(this);
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        Reel* tmp = new Reel(c_reel->getValeur()+_valeur);
        return new Complexe(tmp);
    }
}

Constante* Reel::produit(Constante *c)
{
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        return c_entier->addition(this);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        return c_rationnel->addition(this);
    }
    else if (typeid(*c)==typeid(Reel)) {
            Reel *c_reel=dynamic_cast<Reel *>(c);
            Reel*  tmp = new Reel(_valeur*c_reel->getValeur());
            return new Complexe(tmp);
        }
    else if (typeid(*c)==typeid(Complexe)) {
             Complexe *c_complexe=dynamic_cast<Complexe *>(c);
             return c_complexe->produit(this);

     }
}


Constante* Reel::division(Constante *c)
{
    if(Entier *c_entier=dynamic_cast<Entier *>(c))
    {
        Reel* tmp = new Reel(_valeur/c_entier->getValeur());
        return new Complexe(tmp);
    }
    else if (typeid(*c)==typeid(Rationnel)) {
            Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
            Rationnel* tmp = new Rationnel((_valeur*c_rationnel->getDenominateur()),c_rationnel->getNumerateur());
            return new Complexe(tmp);
    }
    else if (typeid(*c)==typeid(Reel)) {
            Reel *c_reel=dynamic_cast<Reel *>(c);
            Reel*  tmp = new Reel(_valeur/c_reel->getValeur());
            return new Complexe(tmp);
        }
   else if (typeid(*c)==typeid(Complexe)) {
       /* Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        Constante* tmp = new Complexe(c_complexe->getPartieReelle()*_valeur, c_complexe->getPartieImaginaire());
        return new Complexe(tmp);*/

    }
}

Constante* Reel::signe(){
    return new Reel(-_valeur);
}

Constante* Reel::soustraction(Constante* c){
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
        return new Complexe(this->addition(c_complexe->signe()));
    } else if (typeid(*c)==typeid(Entier)) {
        //transtypage en entier
        Entier *c_entier=dynamic_cast<Entier *>(c);
        return new Complexe(this->addition(c_entier->signe()));
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        //FIXME : on doit pouvoir mettre des type constantes pour les réels et rationnel => PAS DE CAST SUR LA CLASSE COMPLEXE
        return new Complexe(this->addition(c_rationnel->signe()));
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        return new Complexe(this->addition(c_reel->signe()));
    }
}
