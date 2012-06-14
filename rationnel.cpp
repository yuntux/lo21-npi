#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>
#define PI 3.14159265

int pgcd(int a, int b) {
        if (a==0||b==0) return 0;
        if (a<0) a=-a;
        if (b<0) b=-b;
        while(a!=b){
                if (a>b) a=a-b; else b=b-a;
        }
        return a;
}

int ppcm(int X,int Y)
{
  int A=X;
  int B=Y;
  while (A!=B)
  {
    while (A>B) B=B+Y;
    while (A<B) A=A+X;
  }
  return A;
}

Rationnel::Rationnel(Constante* c) {
    if (typeid(*c)==typeid(Complexe)){
        //FIXME : impossible de renvoyer un rationnel Ã  partir d'un complexe
            //SAUF si la partie imaginaire est nulle et que la partie réelle est castable (entier ou rationnel ou réel avec partie décimale nulle)
    } else if (typeid(*c)==typeid(Entier)) {
        Entier *c_entier=dynamic_cast<Entier *>(c);
        _numerateur = c_entier->getValeur();
        _denominateur = 1;
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        _numerateur = c_rationnel->getNumerateur();
        _denominateur = c_rationnel->getDenominateur();
        this->simplification();
    } else if (typeid(*c)==typeid(Reel)) {
        //FIXME : impossible de construire un rationnel Ã  partir d'un rÃ©el SAUF si la partie décimale est nulle
    }
    throw LogMessage(3,"Type de constante non prévu dans la fonction Rationnel::Rationnel(Constante* c).", important);
}

Rationnel::Rationnel(int num, int den):_numerateur(num), _denominateur(den)
{
    if (_denominateur==0)
    {
    throw LogMessage(1,"Division par zéro", important);
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
        //FIXME : doit lever une exeption car perte de précesion
    }
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Rationnel::addition(Constante* c).", important);
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
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Rationnel::produit(Constante* c).", important);
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
       Complexe *c_complexe=dynamic_cast<Complexe *>(c);
       Complexe rationnel_complexe(this);
       return rationnel_complexe.division(c_complexe);
    }
   throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Rationnel::division(Constante* c).", important);
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
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Rationnel::soustraction(Constante* c).", important);
}

Constante* Rationnel::fact()
{
    throw LogMessage(2,"La fonction factorielle n'est pas implémentée pour les rationnels.", moyen);
    return this;
}

Constante* Rationnel::sinus(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(sin(res),1);
    return new Complexe(r);
}

Constante* Rationnel::cosinus(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(cos(res),1);
    return new Complexe(r);
}

Constante* Rationnel::sinush(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(sinh(res),1);
    return new Complexe(r);
}

Constante* Rationnel::cosinush(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(cosh(res),1);
    return new Complexe(r);
}


Constante* Rationnel::tangente(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(tan(res),1);
    return new Complexe(r);
}

Constante* Rationnel::tangenteh(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(tanh(res),1);
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

Constante* Rationnel::logN()
{
    float res = _numerateur/_denominateur;
    float l = log(res);
    Rationnel *r = new Rationnel(l,1);
    return new Complexe(r);
}

Constante* Rationnel::log1()
{
    float res = _numerateur/_denominateur;
    float l = log10(res);
    Rationnel *r = new Rationnel(l,1);
    return new Complexe(r);
}

Constante* Rationnel::puissance(Constante *c)
{
    float num = _numerateur;
    float den = _denominateur;
    if (typeid(*c)==typeid(Rationnel)) {
            Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
    int res = c_rationnel->getNumerateur();

    int num1 = pow(num,res);
    int den1 = pow(den,res);
    Rationnel *r = new Rationnel(num1,den1);
    return new Complexe(r);
}
}

Constante* Rationnel::carre()
{
    int num = _numerateur*_numerateur;
    int den = _denominateur*_denominateur;
    Rationnel *r = new Rationnel(num,den);
    return new Complexe(r);
}

Constante* Rationnel::cube()
{
    int num = _numerateur*_numerateur*_numerateur;
    int den = _denominateur*_denominateur*_denominateur;
    Rationnel *r = new Rationnel(num,den);
    return new Complexe(r);
}

Constante* Rationnel::racine()
{
    float num = _numerateur;
    float den = _denominateur;
    int res1 = sqrt(num);
    int res2 = sqrt(den);
    Rationnel *r = new Rationnel(res1,res2);
    return new Complexe(r);
}
