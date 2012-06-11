#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>
#include <cmath>
#define PI 3.14

Entier::Entier(Constante* c) {
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        _valeur = c_entier->getValeur();
    } else if (typeid(*c)==typeid(Complexe)) {
        //FIXME : impossible de construire un entier avec un complexe SAUF si la partie imaginaire est nulle
  //      Complexe *c_complexe=dynamic_cast<Complexe *>(c);
    //    if c_complexe->getPartieImaginaire()
    } else if (typeid(*c)==typeid(Rationnel)) {
        //FIXME : impossible de construire un entier avec un rationnel SAUF si le dénominateur vaut 1
    } else if (typeid(*c)==typeid(Reel)) {
        //FIXME : impossible de construire un entier Ã  partir d'un rÃ©el SAUF c'est la parti décimale est nulle
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
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Entier::addition(Constante* c).", important);
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
       throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Entier::produit(Constante* c).", important);
}

Constante* Entier::division(Constante *c)
{
    if(Entier *c_entier=dynamic_cast<Entier *>(c))
    {
        //On renvoie forcément un rationnel pour ne pas perdre en précision
        Rationnel* tmp = new Rationnel(_valeur, c_entier->getValeur());
        return new Complexe(tmp);
    }
    else if (typeid(*c)==typeid(Rationnel)) {
            Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
            Rationnel* tmp = new Rationnel((_valeur*c_rationnel->getDenominateur()),c_rationnel->getNumerateur());
            return new Complexe(tmp);
    }
    else if (typeid(*c)==typeid(Reel)) {
        //FIXME : perte de précision ???
            Reel *c_reel=dynamic_cast<Reel *>(c);
            Reel*  tmp = new Reel(_valeur/c_reel->getValeur());
            return new Complexe(tmp);
        }
   else if (typeid(*c)==typeid(Complexe)) {
       Complexe *c_complexe=dynamic_cast<Complexe *>(c);
       Complexe entier_complexe(this);
       return entier_complexe.division(c_complexe);
    }
       throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Entier::division(Constante* c).", important);
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
        //FIXME : on doit pouvoir mettre des type constantes pour les rÃ©els et rationnel => PAS DE CAST SUR LA CLASSE COMPLEXE
        return new Complexe(this->addition(c_rationnel->signe()));
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        return new Complexe(this->addition(c_reel->signe()));
    }
        throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Entier::soustraction(Constante* c).", important);
}

Constante* Entier::fact()
{
    int result=1;
    if (this->getValeur()==0)
    {
        Entier *e = new Entier(result);
        return new Complexe(e);
    }
    else
    for(int i=1;i<=this->getValeur();i++)
        result=result*i;
    Entier *e = new Entier(result);
    return new Complexe(e);
}

Constante* Entier::sinus(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    Entier *e = new Entier(sin(res));
    return new Complexe(e);
}

Constante* Entier::cosinus(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    Entier *e = new Entier(cos(res));
    return new Complexe(e);
}


Constante *Entier::inv()
{
    //FIXME : pas d'inverse pour les entiers sans perte de précision
    return new Rationnel(1, this->getValeur());
}
