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
}

Constante* Complexe::produit(Constante *c)
{
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
        Complexe* re = new Complexe(c_entier->produit(this->getPartieReelle()));
        Constante* im = this->getPartieImaginaire()->recopie();
        Complexe *tmp = new Complexe;
        tmp->setReelle(re->getPartieReelle());
        tmp->setImaginaire(im);
        return tmp;
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel = dynamic_cast<Rationnel *>(c);

        Complexe* re = new Complexe(this->getPartieReelle()->produit(c_rationnel));
        Constante* im = this->getPartieImaginaire()->recopie();
        Complexe *tmp = new Complexe;
        tmp->setReelle(re->getPartieReelle());
        tmp->setImaginaire(im);
        return tmp;
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        Complexe* re = new Complexe(c_reel->produit(this->getPartieReelle()));
        Constante* im = this->getPartieImaginaire()->recopie();
        Complexe *tmp = new Complexe;
        tmp->setReelle(re->getPartieReelle());
        tmp->setImaginaire(im);
        return tmp;
    }
}

Constante* Complexe::division(Constante *c)
{
    return c;
}

Constante* Complexe::signe(){
    Constante *tmp = this->recopie();

/*    Entier e(-1);
    tmp->setImaginaire(_imaginaire->multiplication(&e));
    tmp->setReelle(_reel->multiplication(&e));
*/
    return tmp;
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

