#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>
#include "fonctions.h"

Rationnel::Rationnel(Constante* c) {
    if (typeid(*c)==typeid(Complexe)){
        //FIXME : impossible de renvoyer un rationnel Ã  partir d'un complexe
    } else if (typeid(*c)==typeid(Entier)) {
        //transtypage en entier
        Entier *c_entier=dynamic_cast<Entier *>(c);
        _numerateur = c_entier->getValeur();
        _denominateur = 1;
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        _numerateur = c_rationnel->getNumerateur();
        _denominateur = c_rationnel->getDenominateur();
    } else if (typeid(*c)==typeid(Reel)) {
        //FIXME : impossible de construire un rationnel Ã  partir d'un rÃ©el
    }
}

Constante* Rationnel::addition(Constante* c){
    if (typeid(*c)==typeid(Entier)){
        Entier *c_entier=dynamic_cast<Entier *>(c);
        return c_entier->addition(this);
    } else if (typeid(*c)==typeid(Complexe)) {
        Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        return c_complexe->addition(this);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        if(c_rationnel->getDenominateur()==_denominateur)
        {
            Rationnel* tmp  = new Rationnel(c_rationnel->getNumerateur()+_numerateur, c_rationnel->getDenominateur());
            return new Complexe(tmp);
        }
        else
        {
            int p=ppcm(c_rationnel->getDenominateur(), _denominateur);
            int new_num1=(p/_denominateur*_numerateur);
            int new_num2=(p/c_rationnel->getDenominateur()*c_rationnel->getNumerateur());
            Rationnel* tmp = new Rationnel (new_num1+new_num2,p);
            return new Complexe(tmp);
        }
    } else if (typeid(*c)==typeid(Reel)) {
        //FIXME : doit lever une exeption car perte de précesion
    }
}

Constante* Rationnel::produit(Constante *c)
{
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        return c_entier->produit(this);
    } else if (typeid(*c)==typeid(Rationnel)) {
            Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
            Rationnel* tmp = new Rationnel((_numerateur*c_rationnel->getNumerateur()),(_denominateur*c_rationnel->getDenominateur()));
            return new Complexe(tmp);
    }
    else if (typeid(*c)==typeid(Reel)) {
            Reel *c_reel=dynamic_cast<Reel *>(c);
            Rationnel*  tmp = new Rationnel((c_reel->getValeur()*_numerateur),_denominateur);
            return new Complexe(tmp);
        }
    else if (typeid(*c)==typeid(Complexe)) {
             Complexe *c_complexe=dynamic_cast<Complexe *>(c);
             return c_complexe->produit(this);

     }
}

Constante* Rationnel::division(Constante *c)
{
    if(Entier *c_entier=dynamic_cast<Entier *>(c))
    {
        Rationnel* tmp = new Rationnel(_numerateur,(_denominateur*c_entier->getValeur()));
        return new Complexe(tmp);
    }
    else if (typeid(*c)==typeid(Rationnel)) {
            Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
            int den=c_rationnel->getDenominateur();
            c_rationnel->setDenominateur(c_rationnel->getNumerateur());
            c_rationnel->setNumerateur(den);
            return this->produit(c_rationnel);
    }
    else if (typeid(*c)==typeid(Reel)) {
            Reel *c_reel=dynamic_cast<Reel *>(c);
            Rationnel*  tmp = new Rationnel(_numerateur,(_denominateur*c_entier->getValeur()));
            return new Complexe(tmp);
        }
   else if (typeid(*c)==typeid(Complexe)) {
       /* Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        Constante* tmp = new Complexe(c_complexe->getPartieReelle()*_valeur, c_complexe->getPartieImaginaire());
        return new Complexe(tmp);*/

    }
}

Constante* Rationnel::signe(){
    return new Rationnel(-_numerateur, _denominateur);
}


Constante* Rationnel::soustraction(Constante* c){
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
        return new Complexe(this->addition(c_complexe->signe()));
    } else if (typeid(*c)==typeid(Entier)) {
        //transtypage en entier
        Entier *c_entier=dynamic_cast<Entier *>(c);
        return new Complexe(this->addition(c_entier->signe()));
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        //FIXME : on doit pouvoir mettre des type constantes pour les rÃ©els et rationnel => PAS DE CAST SUR LA CLASSE COMPLEXE
        return new Complexe(this->addition(c_rationnel->signe()));
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        return new Complexe(this->addition(c_reel->signe()));
    }
}









