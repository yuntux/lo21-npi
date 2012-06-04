#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>

Complexe::Complexe(Constante* r, Constante* i){
    if (typeid(*r)==typeid(Complexe) || typeid(*r)==typeid(Complexe)) {
        //FIXME : erreur (boucle infinie)
    } else {
        _reelle=r;
        _imaginaire=i;
    }
}

Complexe::Complexe(Constante* c) {
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
        _reelle = c_complexe->getPartieReelle();
        _imaginaire = c_complexe->getPartieImaginaire();
    } else if (typeid(*c)==typeid(Entier)) {
        //transtypage en entier
        Entier *c_entier= new Entier (dynamic_cast<Entier *>(c));
        _reelle = c_entier;
        _imaginaire = 0;
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel= new Rationnel(dynamic_cast<Rationnel *>(c));
        _reelle = c_rationnel;
        _imaginaire = 0;
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel= new Reel(dynamic_cast<Reel *>(c));
        _reelle = c_reel;
        _imaginaire =0;
    }
}

/*
Constante* Complexe::fabrique_composant_complexe(Complexe* c){
    //PARTIES IMAGINAIRES
if(typeid(*c_complexe->getPartieImaginaire())==typeid(Entier) && typeid(this->getPartieImaginaire())==typeid(Entier)) {
    Entier *im_entier1=dynamic_cast<Entier *>(c_complexe->getPartieImaginaire());
    Entier *im_entier2=dynamic_cast<Entier *>(this->getPartieImaginaire());
    Entier* im = new Entier(im_entier1->getValeur()+im_entier2->getValeur());
    tmp->setImaginaire(im);
}
if(typeid(*c_complexe->getPartieImaginaire())==typeid(Reel) && typeid(this->getPartieImaginaire())==typeid(Reel)) {
    Reel *im_reel1=dynamic_cast<Reel *>(c_complexe->getPartieImaginaire());
    Reel *im_reel2=dynamic_cast<Reel *>(this->getPartieImaginaire());
    Reel* im = new Reel(im_reel1->getValeur()+im_reel2->getValeur());
    tmp->setImaginaire(im);
}
if(typeid(*c_complexe->getPartieImaginaire())==typeid(Rationnel) && typeid(this->getPartieImaginaire())==typeid(Rationnel)) {
    Rationnel *im_rationnel1=dynamic_cast<Rationnel *>(c_complexe->getPartieImaginaire());
    Rationnel *im_rationnel2=dynamic_cast<Rationnel *>(this->getPartieImaginaire());
    Rationnel* im = new Rationnel((im_rationnel1->getNumerateur()*im_rationnel2->getDenominateur())+(im_rationnel2->getNumerateur()*im_rationnel1->getDenominateur()), im_rationnel1->getDenominateur()*im_rationnel2->getDenominateur());
    tmp->setImaginaire(im);
}
//FIWME : entier + rationnel => rationnel
//FIWME : rationnel + entier => rationnel
//FIWME : entier + reel => reel
//FIWME : reel + entier => reel
}
*/

Constante* Complexe::addition(Constante* c){
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
        Complexe* im = new Complexe(c_complexe->getPartieImaginaire()->addition(this->getPartieImaginaire()));
        //les parties imaginaires sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
        Complexe* re = new Complexe(c_complexe->getPartieReelle()->addition(this->getPartieReelle()));
        //les parties réelles sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
        Complexe* tmp = new Complexe;
        tmp->setImaginaire(im->getPartieReelle());
        tmp->setReelle(re->getPartieReelle());
        return tmp;

    } else if (typeid(*c)==typeid(Entier)) {
        Entier *c_entier=dynamic_cast<Entier *>(c);
        Complexe* re = new Complexe(c_entier->addition(this->getPartieReelle()));
        Entier e(0); //FIXME : c'est très moche -> implémenter une fabrique de recopie
        Complexe* im = new Complexe(e.addition(this->getPartieImaginaire()));
        Complexe *tmp = new Complexe;
        tmp->setReelle(re->getPartieReelle());
        tmp->setImaginaire(im->getPartieReelle());
        return tmp;
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel = dynamic_cast<Rationnel *>(c);
        Complexe* re = new Complexe(c_rationnel->addition(this->getPartieReelle()));
        Entier e(0);//FIXME : c'est très moche -> implémenter une fabrique de recopie
        Complexe* im = new Complexe(e.addition(this->getPartieImaginaire()));
        Complexe *tmp = new Complexe;
        tmp->setReelle(re->getPartieReelle());
        tmp->setImaginaire(im->getPartieReelle());
        return tmp;
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        Complexe* re = new Complexe(c_reel->addition(this->getPartieReelle()));
        Entier e(0);//FIXME : c'est très moche -> implémenter une fabrique de recopie
        Complexe* im = new Complexe(e.addition(this->getPartieImaginaire()));
        Complexe *tmp = new Complexe;
        tmp->setReelle(re->getPartieReelle());
        tmp->setImaginaire(im->getPartieReelle());
        return tmp;
    }

    Entier* tmp = new Entier(0);
    return tmp;
}

Constante* Complexe::signe(){
  //  return new Complexe(-_reelle, _imaginaire);
}

Constante* Complexe::soustraction(Constante* c){
  /*  if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
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
    */
    Entier* tmp = new Entier(0);
    return tmp;
}

