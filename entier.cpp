#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>

Entier::Entier(Constante* c) {
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        _valeur = c_entier->getValeur();
    } else if (typeid(*c)==typeid(Complexe)) {
        //FIXME : impossible de construire un entier avec un complexe
    } else if (typeid(*c)==typeid(Rationnel)) {
        //FIXME : impossible de construire un entier avec un rationnel
    } else if (typeid(*c)==typeid(Reel)) {
        //FIXME : impossible de construire un entier �  partir d'un réel
    }
}

Constante* Entier::addition(Constante* c){
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        Entier* tmp = new Entier(c_entier->getValeur()+_valeur);
        return new Complexe(tmp);
    }
    if (typeid(*c)==typeid(Complexe)) {
        Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        return c_complexe->addition(this);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        Rationnel* tmp = new Rationnel((_valeur*c_rationnel->getDenominateur())+c_rationnel->getNumerateur(), c_rationnel->getDenominateur());
        return new Complexe(tmp);
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        Reel*  tmp = new Reel(_valeur+c_reel->getValeur());
        return new Complexe(tmp);
    }
}

Constante* Entier::produit(Constante *c)
{
    if(Entier *c_entier=dynamic_cast<Entier *>(c))
    {
        Entier* tmp = new Entier(c_entier->getValeur()*_valeur);
        return new Complexe(tmp);
    }
    else if (typeid(*c)==typeid(Rationnel)) {
            Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
            Rationnel* tmp = new Rationnel((_valeur*c_rationnel->getNumerateur()),c_rationnel->getDenominateur());
            return new Complexe(tmp);
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

Constante* Entier::division(Constante *c)
{
    if(Entier *c_entier=dynamic_cast<Entier *>(c))
    {
        Entier* tmp = new Entier(_valeur/c_entier->getValeur());
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

Constante* Entier::signe(){
    return new Entier(-_valeur);
}

Constante* Entier::soustraction(Constante* c){
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
