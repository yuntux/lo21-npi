#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>
#include "fonctions.h"

Rationnel::Rationnel(Constante* c) {
    if (typeid(*c)==typeid(Complexe)){
        //FIXME : impossible de renvoyer un rationnel �  partir d'un complexe
    } else if (typeid(*c)==typeid(Entier)) {
        //transtypage en entier
        Entier *c_entier=dynamic_cast<Entier *>(c);
        _numerateur = c_entier->getValeur();
        _denominateur = 1;
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        _numerateur = c_rationnel->getNumerateur();
        _denominateur = c_rationnel->getDenominateur();
        this->simplification();
    } else if (typeid(*c)==typeid(Reel)) {
        //FIXME : impossible de construire un rationnel �  partir d'un réel
    }
}

Rationnel::Rationnel(int num, int den):_numerateur(num), _denominateur(den)
{
    if (_denominateur==0)
    {
    //FIXME : lever une exeption -> d�nminateur nul ill�gal
    }
    this->simplification();
}

QString Rationnel::afficher() const{
    if (this->getDenominateur()==1) {
        return QString::number(_numerateur);
    } else {
         return QString::number(_numerateur)+"/"+QString::number(_denominateur);
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
            Rationnel* tmp = new Rationnel(new_num1+new_num2,p);
            return new Complexe(tmp);
        }
    } else if (typeid(*c)==typeid(Reel)) {
        //FIXME : doit lever une exeption car perte de pr�cesion
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
        //FIXME : on doit pouvoir mettre des type constantes pour les réels et rationnel => PAS DE CAST SUR LA CLASSE COMPLEXE
        return new Complexe(this->addition(c_rationnel->signe()));
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        return new Complexe(this->addition(c_reel->signe()));
    }
}

Constante* Rationnel::fact()
{
    //FIXME : pas de fact pour les complexes
    return this;
}

Constante* Rationnel::sinus()
{

    float num = _numerateur;
    float den = _denominateur;
    float res=num/den;

    Rationnel *r = new Rationnel(sin(res),1);
    return new Complexe(r);

}

Constante *Rationnel::inv()
{
    Rationnel* tmp = new Rationnel(this->getDenominateur(),this->getNumerateur());
    return tmp;
}

void Rationnel::simplification(){
        if (_numerateur==0) { _denominateur=1; return; }
        if (_denominateur==0) return; //FIXME : lever une exeption
        int p=pgcd(_numerateur,_denominateur);
        _numerateur/=p;
        _denominateur/=p;
        if (_denominateur<0) {
                _denominateur=-_denominateur;
                _numerateur=-_numerateur;
        }
}
