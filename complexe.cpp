#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>


Complexe::Complexe(Constante* c) {
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
    _reelle = c_complexe->getPartieReelle();
    _imaginaire = c_complexe->getPartieImaginaire();
    } else if (typeid(*c)==typeid(Entier)) {
        //transtypage en entier
        Entier *c_entier=dynamic_cast<Entier *>(c);
        _reelle = c_entier->getValeur();
        _imaginaire = 0;
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        _reelle = c_rationnel->getNumerateur()/c_rationnel->getDenominateur();
        _imaginaire = 0;
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        _reelle = c_reel->getValeur();
        _imaginaire =0;
    }
}

Constante* Complexe::addition(Constante* c){
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
        return new Complexe(c_complexe->getPartieReelle()+_imaginaire, c_complexe->getPartieImaginaire()+_imaginaire);
    } else if (typeid(*c)==typeid(Entier)) {
        //transtypage en entier
        Entier *c_entier=dynamic_cast<Entier *>(c);
        Complexe *c_complexe = new Complexe(c_entier->getValeur());
        return new Complexe(c_complexe->getPartieReelle()+_imaginaire, c_complexe->getPartieImaginaire()+_imaginaire);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        //FIXME : on doit pouvoir mettre des type constantes pour les réels et rationnel => PAS DE CAST SUR LA CLASSE COMPLEXE
        Complexe *c_complexe = new Complexe(c_rationnel->getNumerateur()/c_rationnel->getDenominateur());
        return new Complexe(c_complexe->getPartieReelle()+_reelle, c_complexe->getPartieImaginaire()+_imaginaire);
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        Complexe *c_complexe = new Complexe(c_reel->getValeur());
        return new Complexe(c_complexe->getPartieReelle()+_reelle, c_complexe->getPartieImaginaire()+_imaginaire);
    }
}

Constante* Complexe::signe(){
    return new Complexe(-_reelle, _imaginaire);
}

Constante* Complexe::soustraction(Constante* c){
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
