#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>

Complexe::Complexe(Constante* r, Constante* i){
    if (typeid(*r)==typeid(Complexe) || typeid(*r)==typeid(Complexe)) {
        //FIXME : lève une exeption (éviter les boucles de récursion infinies)
    } else {
        _reelle=r;
        _imaginaire=i;
    }
}

Complexe::Complexe(Constante* c) {
    //FIXME : on réalloue pour Reel(0,0) et Rationnel(0) mais on ne recopie pas le reste ???
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
        _reelle = c_complexe->getPartieReelle();
        _imaginaire = c_complexe->getPartieImaginaire();
    } else if (typeid(*c)==typeid(Entier)) {
        Entier *c_entier= new Entier (dynamic_cast<Entier *>(c));
        _reelle = c_entier;
        _imaginaire = new Entier(0);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel= new Rationnel(dynamic_cast<Rationnel *>(c));
        _reelle = c_rationnel;
        _imaginaire = new Rationnel(0);
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel= new Reel(dynamic_cast<Reel *>(c));
        _reelle = c_reel;
        _imaginaire = new Reel(0.0);
    }
}

QString Complexe::afficher() const{
    if (typeid(this->getPartieImaginaire())==typeid(Entier)) {
        Entier *im_entier=dynamic_cast<Entier *>(this->getPartieImaginaire());
        if (im_entier->getValeur()==0)
            return _reelle->afficher();
    } else if (typeid(this->getPartieImaginaire())==typeid(Rationnel)) {
        Rationnel *im_rationnel=dynamic_cast<Rationnel *>(this->getPartieImaginaire());
        if (im_rationnel->getNumerateur()==0)
            return _reelle->afficher();
    } else if (typeid(this->getPartieImaginaire())==typeid(Reel)) {
       Reel *im_reel=dynamic_cast<Reel *>(this->getPartieImaginaire());
       if (im_reel->getValeur()==0)
           return _reelle->afficher();
   }
    return _reelle->afficher()+"$"+_imaginaire->afficher();
}

Constante* Complexe::addition(Constante* c){
    Complexe *c_complexe = new Complexe(c);
    //les parties imaginaires sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
    Complexe* re = new Complexe(c_complexe->getPartieReelle()->addition(this->getPartieReelle()));
    //les parties réelles sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
    Complexe* im = new Complexe(c_complexe->getPartieImaginaire()->addition(this->getPartieImaginaire()));
    c_complexe->setImaginaire(im->getPartieReelle());
    c_complexe->setReelle(re->getPartieReelle());
    delete(re);
    delete(im);
    return c_complexe;
  /*  if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
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
        Constante* im = this->getPartieImaginaire()->recopie();
        Complexe *tmp = new Complexe;
        tmp->setReelle(re->getPartieReelle());
        tmp->setImaginaire(im);
        return tmp;
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel = dynamic_cast<Rationnel *>(c);

        Complexe* re = new Complexe(this->getPartieReelle()->addition(c_rationnel));
        Constante* im = this->getPartieImaginaire()->recopie();
        Complexe *tmp = new Complexe;
        tmp->setReelle(re->getPartieReelle());
        tmp->setImaginaire(im);
        return tmp;
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        Complexe* re = new Complexe(c_reel->addition(this->getPartieReelle()));
        Constante* im = this->getPartieImaginaire()->recopie();
        Complexe *tmp = new Complexe;
        tmp->setReelle(re->getPartieReelle());
        tmp->setImaginaire(im);
        return tmp;
    }

    */
}

Constante* Complexe::produit(Constante *c)
{
    Complexe *c_complexe = new Complexe(c);
    Complexe* re = new Complexe(c_complexe->getPartieReelle()->produit(_reelle)->soustraction(c_complexe->getPartieImaginaire()->produit(_imaginaire)));
    Complexe* im = new Complexe(c_complexe->getPartieImaginaire()->produit(_reelle)->addition(c_complexe->getPartieReelle()->produit(_imaginaire)));
    c_complexe->setImaginaire(im->getPartieReelle());
    c_complexe->setReelle(re->getPartieReelle());
    delete(re);
    delete(im);
    return c_complexe;
}

Constante* Complexe::division(Constante *c)
{
    /*
    Complexe *c_complexe = new Complexe(c);
    Complexe* re = new Complexe(c_complexe->getPartieReelle()->produit(_reelle)->soustraction(c_complexe->getPartieImaginaire()->produit(_imaginaire)));
    Complexe* im = new Complexe(c_complexe->getPartieImaginaire()->produit(_reelle)->addition(c_complexe->getPartieReelle()->produit(_imaginaire)));
    c_complexe->setImaginaire(im->getPartieReelle());
    c_complexe->setReelle(re->getPartieReelle());
    delete(re);
    delete(im);
    return c_complexe;
    */
}

Constante* Complexe::signe(){
    /*
    Constante *c = this->recopie();
    Complexe *tmp= new Complexe (c);
    Entier e(-1);
    tmp->setImaginaire(_imaginaire->multiplication(&e));
    tmp->setReelle(_reel->multiplication(&e));
    delete c;
    return tmp;
    */
}

Constante* Complexe::soustraction(Constante* c){
    Complexe *c_complexe = new Complexe(c);
    //les parties imaginaires sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
    Complexe* re = new Complexe(this->getPartieReelle()->soustraction(c_complexe->getPartieReelle()));
    //les parties réelles sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
    Complexe* im = new Complexe(this->getPartieImaginaire()->soustraction(c_complexe->getPartieImaginaire()));
    c_complexe->setImaginaire(im->getPartieReelle());
    c_complexe->setReelle(re->getPartieReelle());
    delete(re);
    delete(im);
    return c_complexe;
}


Constante* Complexe::fact()
{
    //FIXME : pas de fact pour les complexes
    return this;
}

Constante* Complexe::sinus()
{
    //FIXME : pas de fact pour les complexes
    return this;
}

Constante* Complexe::inv()
{
    //FIXME : pas d'inverse pour les complexes
    return this;
}
