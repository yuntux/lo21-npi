#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>
#include "calculatrice.h"
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
    qDebug() << "CNOSTRUCTEUR DE RATIONEL DEPUIS UNE CONSTANTE";
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
    throw LogMessage(7,"Type de constante non prévu dans la fonction Rationnel::Rationnel(Constante* c).", important);
    /**
      * \brief Constructeur Rationnel
      * \details Dans certains cas, selon le type du paramètre (Entier, Rationnel), on
      *          effectue un dynamic cast sur le paramètre, et on affecte les valeurs aux attributs _numerateur et _denominateur
      * \param c Une \e Constante, donc soit un Entier, soit un Réel, soit un Rationnel, soit un Complexe
      */
}

Rationnel::Rationnel(int num, int den):_numerateur(num), _denominateur(den)
{
    if (_denominateur==0)
    {
    throw LogMessage(1,"Division par zéro", important);
    }
    this->simplification();
    /**
      * \brief Constructeur surchargé
      * \details Passage d'un numérateur et d'un dénominateur en paramètres et affectation des attributs.
      *          On lève une exception si le dénominateur est 0
      * \param num Entier correspondant au numérateur
      * \param den Entier correspondant au dénominateur
      */
}

QString Rationnel::afficher() const{
    if (this->getDenominateur()==1) {
        return QString::number(_numerateur);
    } else {
        if (Calculatrice::getInstance().getModConstante()==entier)
            return QString::number(_numerateur/_denominateur);
         else if (Calculatrice::getInstance().getModConstante()==reel)
            return QString::number(float(_numerateur)/float(_denominateur));
         else
            return QString::number(_numerateur)+"/"+QString::number(_denominateur);
    }
    /**
      * \brief Affichage Rationnel
      * \details Affichage d'un Rationnel, en affichant uniquement le numérateur si le dénominateur est égal à 1
      * \return Une \e QString correspondant à l'affichage du rationnel
      */
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
        int denom = this->getDenominateur() * c_rationnel->getDenominateur();
        int num = (this->getNumerateur() * c_rationnel->getDenominateur()) + (c_rationnel->getNumerateur() * this->getDenominateur());
        Rationnel* tmp = new Rationnel(num, denom);
        tmp->simplification();
        qDebug() << tmp->afficher();
        return new Complexe(tmp);
    } else if (typeid(*c)==typeid(Reel)) {
        //FIXME : doit lever une exeption car perte de précesion
    }
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Rationnel::addition(Constante* c).", important);
    /**
      * \brief Somme de 2 rationnels
      * \details On vérifie le type du paramètre, et on crée une nouvelle instance de ce type en fonction, dont le
      *          ou les attributs seront en fait la somme des 2 rationnels dont l'on veut calculer l'addition.Cependant, si on
      *          est en mode Rationnel, on ne doit pas avoir les autres types de constante.
      * \param c Une constante
      * \return Un \e Complexe, car on utilisera toujours les formes complexes pour les calculs
      */
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
    /**
      * \brief Produit de deux rationnels
      * \details Comme pour la somme, on vérifie le type du paramètre, et on crée une nouvelle instance de ce type qui contiendra
      *          le produit demandé. Cependant, normalement en mode Rationnel, on ne doit avoir que des rationnels.
      * \param c Une Constante
      * \return Un \e Complexe contenant le produit
      */
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
   /**
     * \brief Division de rationnels
     * \details Comme pour la somme et le produit, on vérifie le type du paramètre, et on crée une nouvelle instance de ce type qui contiendra
     *          le quotient demandé. Cependant, normalement en mode Rationnel, on ne doit avoir que des rationnels.
     * \param c Une Constante
     * \return Un \e Complexe contenant le quotient
     */
}

Constante* Rationnel::signe(){
    return new Rationnel(-_numerateur, _denominateur);
    /**
      * \brief Inversion du signe
      * \details Il ne faut inverser le signe que d'un des deux attributs. On fait ici le choix du numérateur
      * \return Un nouveau \e Rationnel avec numérateur opposé
      */
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
    /**
      * \brief Différence de rationnels
      * \details Comme pour les autres opérations, on vérifie le type du paramètre, et on crée une nouvelle instance de ce type qui contiendra
      *          la différence voulue. Cependant, normalement en mode Rationnel, on ne doit avoir que des rationnels.
      * \param c Une Constante
      * \return Un \e Complexe contenant la différence
      */
}

Constante* Rationnel::fact()
{
    throw LogMessage(2,"La fonction factorielle n'est pas implémentée pour les rationnels.", moyen);
    return this;
    /**
      * \brief Factoriel Rationnel
      * \details Cette fonction n'est pas implémentée pour les rationnels, donc on lance un message pour prévenir l'utilisateur
      */
}

Constante* Rationnel::sinus(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(sin(res),1);
    return new Complexe(r);
    /**
      * \brief Sinus Rationnel
      * \details La fonction \e sin de cmath étant implémentée pour un \e float, on fait le rapport du numérateur sur le
      *          dénominateur pour commencer. Ensuite, on teste si on est en degré. Si c'est le cas, on multiplie le résultat
      *          par PI/180 car \e sin est définie en radians. On calcule ensuite le sinus.
      * \param angle Booléen, permet de savoir si l'on est en mode degré
      * \return Un nouveau \e Complexe construit à partir du Rationnel contenant le résultat
      */
}

Constante* Rationnel::cosinus(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(cos(res),1);
    return new Complexe(r);
    /**
      * \brief Cosinus Rationnel
      * \details La fonction \e cos de cmath étant implémentée pour un \e float, on fait le rapport du numérateur sur le
      *          dénominateur pour commencer. Ensuite, on teste si on est en degré. Si c'est le cas, on multiplie le résultat
      *          par PI/180 car \e cos est définie en radians. On calcule ensuite le cosinus.
      * \param angle Booléen, permet de savoir si l'on est en mode degré
      * \return Un nouveau \e Complexe construit à partir du Rationnel contenant le résultat
      */
}

Constante* Rationnel::sinush(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(sinh(res),1);
    return new Complexe(r);
    /**
      * \brief Sinus Hyperbolique Rationnel
      * \details La fonction \e sinh de cmath étant implémentée pour un \e float, on fait le rapport du numérateur sur le
      *          dénominateur pour commencer. Ensuite, on teste si on est en degré. Si c'est le cas, on multiplie le résultat
      *          par PI/180 car \e sinh est définie en radians. On calcule ensuite le sinus hyperbolique.
      * \param angle Booléen, permet de savoir si l'on est en mode degré
      * \return Un nouveau \e Complexe construit à partir du Rationnel contenant le résultat
      */
}

Constante* Rationnel::cosinush(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(cosh(res),1);
    return new Complexe(r);
    /**
      * \brief Cosinus Hyperbolique Rationnel
      * \details La fonction \e cosh de cmath étant implémentée pour un \e float, on fait le rapport du numérateur sur le
      *          dénominateur pour commencer. Ensuite, on teste si on est en degré. Si c'est le cas, on multiplie le résultat
      *          par PI/180 car \e cosh est définie en radians. On calcule ensuite le cosinus hyperbolique.
      * \param angle Booléen, permet de savoir si l'on est en mode degré
      * \return Un nouveau \e Complexe construit à partir du Rationnel contenant le résultat
      */
}


Constante* Rationnel::tangente(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(tan(res),1);
    return new Complexe(r);
    /**
      * \brief Tangente Rationnel
      * \details La fonction \e tan de cmath étant implémentée pour un \e float, on fait le rapport du numérateur sur le
      *          dénominateur pour commencer. Ensuite, on teste si on est en degré. Si c'est le cas, on multiplie le résultat
      *          par PI/180 car \e tan est définie en radians. On calcule ensuite la tangente.
      * \param angle Booléen, permet de savoir si l'on est en mode degré
      * \return Un nouveau \e Complexe construit à partir du Rationnel contenant le résultat
      */
}

Constante* Rationnel::tangenteh(bool angle)
{
    float res= _numerateur/_denominateur;
    if(angle==true)
        res=res*PI/180;
    Rationnel *r = new Rationnel(tanh(res),1);
    return new Complexe(r);
    /**
      * \brief Tangente Hyperbolique Rationnel
      * \details La fonction \e tanh de cmath étant implémentée pour un \e float, on fait le rapport du numérateur sur le
      *          dénominateur pour commencer. Ensuite, on teste si on est en degré. Si c'est le cas, on multiplie le résultat
      *          par PI/180 car \e tanh est définie en radians. On calcule ensuite la tangente hyperbolique.
      * \param angle Booléen, permet de savoir si l'on est en mode degré
      * \return Un nouveau \e Complexe construit à partir du Rationnel contenant le résultat
      */
}

Constante *Rationnel::inv()
{
    Rationnel* tmp = new Rationnel(this->getDenominateur(),this->getNumerateur());
    return tmp;
    /**
      * \brief Inverse Rationnel
      * \details Pour inverser une fraction, il suffit d'échanger le numérateur et le dénominateur
      * \return Un nouveau \e Rationnel contenant l'inverse de la fraction
      */
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
        /**
          * \brief Simplifier fraction
          * \details Permet de simplifier un nombre Rationnel
          */
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
