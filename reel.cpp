#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>
#include <QString>
#include <iostream>

Rationnel Reel::toRationnel() const {
    //DANS LE BUT DE NE PAS PERDRE DE PRÉCISION LORS DES DIVISIONS ON A BESOIN DE TRANSFORMER LES RÉELS EN RATIONNELS
/*    int partie_entiere = floor(this->getValeur());
    float partie_decimale = this->getValeur()-partie_entiere;
    std::cout<<partie_decimale;
*/
    //NUL => ETANT DONNE LA MEMORISATION DU FLOAT (virgule flottante) CA SERVIRA A RIEN
}

Reel::Reel(Constante* c) {
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        _valeur = c_entier->getValeur();
    } else if (typeid(*c)==typeid(Complexe)) {
        //FIXME : impossible de renvoyer un reel Ã  partir d'un complexe
            //SAUF si la partie imaginaire est nulle et que la partie réelle est castable (entier ou rationnel décimal ou réel)
    } else if (typeid(*c)==typeid(Rationnel)) {
        //FIXME : impossible de construire un réel avec un rationnel sauf si sa partie décimale est nulle
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
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Reel::addition(Constante *c).", important);
}

Constante* Reel::produit(Constante *c)
{
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        return c_entier->produit(this);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        return c_rationnel->produit(this);
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
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Reel::produit(Constante *c).", important);
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
       Complexe *c_complexe=dynamic_cast<Complexe *>(c);
       Complexe reel_complexe(this);
       return reel_complexe.division(c_complexe);

    }
   throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Reel::division(Constante *c).", important);
}

Constante* Reel::signe(){
    return new Reel(-_valeur);
}

Constante* Reel::soustraction(Constante* c){
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
        return new Complexe(this->addition(c_complexe->signe()));
    } else if (typeid(*c)==typeid(Entier)) {
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
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Reel::soustraction(Constante* c).", important);
}

Constante *Reel::inv()
{
    return new Reel(1/this->getValeur());
}

Constante* Reel::sinus()
{
    Reel *e = new Reel(sin(_valeur));
    return new Complexe(e);
}

Constante* Reel::fact()
{
    throw LogMessage(2,"La fonction factorielle n'est pas implémentée pour les réels.", moyen);
    return this;
}
