#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>
#include <QString>
#include <iostream>
#define PI 3.14159265

/*
Rationnel Reel::toRationnel() const {
    //DANS LE BUT DE NE PAS PERDRE DE PRÉCISION LORS DES DIVISIONS ON A BESOIN DE TRANSFORMER LES RÉELS EN RATIONNELS
    int partie_entiere = floor(this->getValeur());
    float partie_decimale = this->getValeur()-partie_entiere;
    std::cout<<partie_decimale;

    //NUL => ETANT DONNE LA MEMORISATION DU FLOAT (virgule flottante) CA SERVIRA A RIEN
}
*/

Reel::Reel(Constante* c) {
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        _valeur = c_entier->getValeur();
    } else if (typeid(*c)==typeid(Complexe)) {
        Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        if (c_complexe->reel_pur()){
            if (Entier *re_entiere=dynamic_cast<Entier *>(c_complexe->getPartieReelle())){
                _valeur = re_entiere->getValeur();
            } else if (Reel *re_reelle=dynamic_cast<Reel *>(c_complexe->getPartieReelle())){
                _valeur = re_reelle->getValeur();
            } else {
                throw LogMessage(3,"Seuls le complexes dont la partie réelle est entière ou réelle et la partie imaginaire est nulle permettent de construire un réel.", important);
            }
        } else {
            throw LogMessage(3,"Seuls le complexes dont la partie réelle est entière ou réelle et la partie imaginaire est nulle permettent de construire un réel.", important);
        }
        throw LogMessage(3,"Impossible de construir un réel à partir d'un complexe.", important);
    } else if (typeid(*c)==typeid(Rationnel)) {
        throw LogMessage(3,"Impossible de construir un réel à partir d'un rationnel sans perte de précision.", important);
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        _valeur = c_reel->getValeur();
    }
    /**
      * \brief Constructeur de réel
      * \details On vérifie le type de la constante passée en paramètre, et si c'est un réel, on
      *          recopie sa valeur dans le nouvel entier, sinon on lève une exception.
      * \param c Une constante, donc entier, réel, rationnel ou complexe
      */
}

Constante* Reel::addition(Constante* c){
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        return c_entier->addition(this);
    } else if (typeid(*c)==typeid(Complexe)) {
        Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        return c_complexe->addition(this);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        throw LogMessage(3,"Impossible d'additionner un réel et un rationnel sans perte de précision.", important);
        return c_rationnel->addition(this);
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        return new Reel(c_reel->getValeur()+_valeur);
    }
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Reel::addition(Constante *c).", important);
    /**
      * \brief Somme de 2 réels
      * \details On vérifie le type du paramètre, et on crée une nouvelle instance de ce type en fonction, dont le
      *          ou les attributs seront en fait la somme des 2 réels dont l'on veut calculer l'addition.Cependant, si on
      *          est en mode Réel, on ne doit pas avoir les autres types de constante.
      * \param c Une constante
      * \return Un \e Reel construit, car on utilisera toujours les formes complexes pour les calculs
      */
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
            return new Reel(_valeur*c_reel->getValeur());
        }
    else if (typeid(*c)==typeid(Complexe)) {
             Complexe *c_complexe=dynamic_cast<Complexe *>(c);
             return c_complexe->produit(this);
     }
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Reel::produit(Constante *c).", important);
    /**
      * \brief Produit de deux réels
      * \details Comme pour la somme, on vérifie le type du paramètre, et on crée une nouvelle instance de ce type qui contiendra
      *          le produit demandé. Cependant, normalement en mode Réel, on ne doit avoir que des réels.
      * \param c Une Constante
      * \return Un \e Reel construit contenant le produit
      */
}


Constante* Reel::division(Constante *c)
{
    return this->produit(c->inv());
   /**
     * \brief Division de réels
     * \details Comme pour la somme et le produit, on vérifie le type du paramètre, et on crée une nouvelle instance de ce type qui contiendra
     *          le quotient demandé. Cependant, normalement en mode Réel, on ne doit avoir que des réels.
     * \param c Une Constante
     * \return Un \e Reel construit contenant le quotient
     */
}

Constante* Reel::signe(){
    return new Reel(-_valeur);
    /**
      * \brief Inversion de signe d'un réel
      * \details On crée un nouvel entier dont la valeur est l'opposée de celle initiale
      * \return Un \e Réel, de valeur opposée
      */
}

Constante* Reel::soustraction(Constante* c){
    return this->addition(c->signe());
    /**
      * \brief Différence de réels
      * \details Comme pour les autres opérations, on vérifie le type du paramètre, et on crée une nouvelle instance de ce type qui contiendra
      *          la différence voulue. Cependant, normalement en mode Réel, on ne doit avoir que des réels.
      * \param c Une Constante
      * \return Un \e Reel construit contenant la différence
      */
}

Constante *Reel::inv()
{
    if (this->getValeur()==0) {
          throw LogMessage(1,"Division par zéro", important);
          return this;
    }
    return new Reel(1/this->getValeur());
    /**
      * \brief Inversion d'un réel
      * \details Pour un réel, on peut créer un nouveau réel contenant l'inverse de celui que l'on veut
      * \return Un \e Réel contenant le résultat
      */
}

Constante* Reel::sinus(bool angle)
{
    float res = _valeur;
    if(angle)
        res=res*PI/180;
    return new Reel(sin(res));
    /**
      * \brief Calcul du Sinus
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e sin de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Reel construit construit à partir d'un entier contenant la valeur du sinus
      */
}

Constante* Reel::cosinus(bool angle)
{
    float res = _valeur;
    if(angle)
        res=res*PI/180;
    return new Reel(cos(res));
    /**
      * \brief Calcul du Cosinus
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e cos de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Reel construit construit à partir d'un entier contenant la valeur du cosinus
      */
}

Constante* Reel::cosinush(bool angle)
{
    float res = _valeur;
    if(angle)
        res=res*PI/180;
    return new Reel(cosh(res));
    /**
      * \brief Calcul du Cosinus Hyperbolique
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e cosh de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Reel construit construit à partir d'un entier contenant la valeur du cosinus hyperbolique
      */
}


Constante* Reel::tangente(bool angle)
{
    float res = _valeur;
    if(angle)
        res=res*PI/180;
    return new Reel(tan(res));
    /**
      * \brief Calcul de la Tangente
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e tan de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Reel construit construit à partir d'un entier contenant la valeur de la tangente
      */
}

Constante* Reel::tangenteh(bool angle)
{
    float res = _valeur;
    if(angle)
        res=res*PI/180;
    return new Reel(tanh(res));
    /**
      * \brief Calcul de la Tangente Hyperbolique
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e tanh de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Reel la valeur de la tangente hyperbolique
      */
}

Constante* Reel::sinush(bool angle)
{
    float res = _valeur;
    if(angle)
        res=res*PI/180;
    return new Reel(sinh(res));
    /**
      * \brief Sinus Hyperbolique Réel
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e tanh de cmath est définie en radians.
      * \param angle Booléen, permet de savoir si l'on est en mode degré
      * \return Un nouveau \e Reel construit à partir du Reel contenant le résultat
      */
}
Constante* Reel::fact()
{
    throw LogMessage(2,"La fonction factorielle n'est pas implémentée pour les réels.", moyen);
    return this;
}


Constante* Reel::logN()
{
    float res = log(_valeur);
    return new Reel(res);
    /**
      * \brief Logarithme népérien
      * \details On crée un nouveau Réel dont la valeur est celle du logarithme népérien du réel initial.
      * \return Un \e Reel construit avec ce réel
      */
}

Constante* Reel::log1()
{
    float res = log10(_valeur);
    return new Reel(res);
    /**
      * \brief Logarithme décimal
      * \details On crée un nouveau Réel dont la valeur est celle du logarithme décimal du réel initial.
      * \return Un \e Reel construit avec ce réel
      */
}

Constante* Reel::puissance(Constante *c)
{
    if (typeid(*c)==typeid(Reel)) {
            //transtypage en entier
            Reel *c_reel=dynamic_cast<Reel *>(c);
            int value;
            value = c_reel->getValeur();
    float res;
    float res2 = _valeur;
    res = pow(res2,value);

    return new Reel(res);
    }
    /**
      * \brief Puissance de deux réels
      * \details On effectue un transtypage en réel afin de récupérer l'exposant sous forme réelle.
      *          On calcule ensuite grâce à la fonction \e pow de la bibliothèque \e cmath.
      * \param c Une \e Constante qui sera l'exposant
      * \return Un \e Reel construit à partir du résultat
      */
}

Constante* Reel::carre()
{
    float res = _valeur*_valeur;
    return new Reel(res);
    /**
      * \brief Fonction carré
      * \details On crée un nouveau Réel dont la valeur est le résultat du carré
      * \return Un \e Reel construit à partir du résultat de la fonction
      */
}

Constante* Reel::cube()
{
    float res = _valeur*_valeur*_valeur;
    return new Reel(res);
    /**
      * \brief Fonction cube
      * \details On crée un nouveau Réel dont la valeur est le résultat du cube
      * \return Un \e Reel construit à partir du résultat de la fonction
      */
}

Constante* Reel::racine()
{
    float res = sqrt(_valeur);
    return new Reel(res);
    /**
      * \brief Fonction racine carrée
      * \details On crée un nouveau Réel dont la valeur est le résultat de la racine carrée
      * \return Un \e Reel construit à partir du résultat de la fonction
      */
}

