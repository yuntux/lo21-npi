#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>

Constante* Rationnel::addition(Constante* c){
    if (typeid(*c)==typeid(Entier)){
//        return c->addition(this);
    } else if (typeid(*c)==typeid(Complexe)) {
        Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        return new Complexe(c_complexe->getPartieReelle()+(_numerateur/_denominateur), c_complexe->getPartieImaginaire());
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        //FIXME : on doit pouvoir mettre des type constantes pour les réels et rationnel => PAS DE CAST SUR LA CLASSE COMPLEXE
        return new Complexe((c_rationnel->getNumerateur()+_numerateur)/(c_rationnel->getDenominateur()+_denominateur));
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        return new Complexe(c_reel->getValeur()+(_numerateur/_denominateur));
    }
}
