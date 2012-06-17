#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>
#include <cmath>
#define PI 3.14159265

Entier::Entier(Constante* c) {
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        _valeur = c_entier->getValeur();
    } else if (typeid(*c)==typeid(Complexe)) {
        Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        if (c_complexe->reel_pur()){
            if (Entier *re_entiere=dynamic_cast<Entier *>(c_complexe->getPartieReelle())){
                _valeur = re_entiere->getValeur();
            } else {
                throw LogMessage(3,"Seuls le complexes dont la partie réelle est entière et la partie imaginaire est nulle permettent de construire un entier.", important);
            }
        } else {
            throw LogMessage(3,"Seuls le complexes dont la partie réelle est entière et la partie imaginaire est nulle permettent de construire un entier.", important);
        }
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        if (c_rationnel->getDenominateur()==1)
            _valeur = c_rationnel->getNumerateur();
        else
            throw LogMessage(3,"Impossible de construir un entier à partir d'un rationnel(ayant un dénominateur différent de 1) sans perte de précision.", important);
    } else if (typeid(*c)==typeid(Reel)) {
        throw LogMessage(3,"Impossible de construir un entier à parti d'un réel sans perte de précision.", important);
    }
    /**
      * \brief Constructeur d'entier
      * \details On vérifie le type de la constante passée en paramètre, et si c'est un entier, on
      *          recopie sa valeur dans le nouvel entier, sinon on lève une exception.
      * \param c Une constante, donc entier, réel, rationnel ou complexe
      */
}

Constante* Entier::addition(Constante* c){
    if (Entier *c_entier=dynamic_cast<Entier *>(c)){
        return new Entier(c_entier->getValeur()+_valeur);
    }
    if (typeid(*c)==typeid(Complexe)) {
        Complexe *c_complexe=dynamic_cast<Complexe *>(c);
        return c_complexe->addition(this);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
        return new Rationnel((_valeur*c_rationnel->getDenominateur())+c_rationnel->getNumerateur(), c_rationnel->getDenominateur());
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        return new Reel(_valeur+c_reel->getValeur());
    }
    throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Entier::addition(Constante* c).", important);
    /**
      * \brief Somme de 2 entiers
      * \details On vérifie le type du paramètre, et on crée une nouvelle instance de ce type en fonction, dont le
      *          ou les attributs seront en fait la somme des 2 entiers dont l'on veut calculer l'addition.Cependant, si on
      *          est en mode Entier, on ne doit pas avoir les autres types de constante.
      * \param c Une constante
      * \return Un \e Entier construit, car on utilisera toujours les formes complexes pour les calculs
      */
}

Constante* Entier::produit(Constante *c)
{
    if(Entier *c_entier=dynamic_cast<Entier *>(c))
    {
        return new Entier(c_entier->getValeur()*_valeur);
    }
    else if (typeid(*c)==typeid(Rationnel)) {
            Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
            return new Rationnel((_valeur*c_rationnel->getNumerateur()),c_rationnel->getDenominateur());
    }
    else if (typeid(*c)==typeid(Reel)) {
            Reel *c_reel=dynamic_cast<Reel *>(c);
            return new Reel(_valeur*c_reel->getValeur());
        }
   else if (typeid(*c)==typeid(Complexe)) {
            Complexe *c_complexe=dynamic_cast<Complexe *>(c);
            return c_complexe->produit(this);
    }
       throw LogMessage(3,"Type de constante non prévu dans la fonction Constante* Entier::produit(Constante* c).", important);
       /**
         * \brief Produit de deux entiers
         * \details Comme pour la somme, on vérifie le type du paramètre, et on crée une nouvelle instance de ce type qui contiendra
         *          le produit demandé. Cependant, normalement en mode Entier, on ne doit avoir que des entiers.
         * \param c Une Constante
         * \return Un \e Entier construit contenant le produit
         */
}

Constante* Entier::division(Constante *c)
{
    return this->produit(c->inv());
       /**
         * \brief Division d'entiers
         * \details Comme pour la somme et le produit, on vérifie le type du paramètre, et on crée une nouvelle instance de ce type qui contiendra
         *          le quotient demandé. Cependant, normalement en mode Entier, on ne doit avoir que des entiers.
         * \param c Une Constante
         * \return Un \e Entier construit contenant le quotient
         */
}

Constante* Entier::signe(){
    return new Entier(-_valeur);
    /**
      * \brief Inversion de signe d'un entier
      * \details On crée un nouvel entier dont la valeur est l'opposée de celle initiale
      * \return Un \e Entier, de valeur opposée
      */
}

Constante* Entier::soustraction(Constante* c){
    return this->addition(c->signe());
        /**
          * \brief Différence d'entiers
          * \details Comme pour les autres opérations, on vérifie le type du paramètre, et on crée une nouvelle instance de ce type qui contiendra
          *          la différence voulue. Cependant, normalement en mode Entier, on ne doit avoir que des entiers.
          * \param c Une Constante
          * \return Un \e Entier construit contenant la différence
          */
}

Constante* Entier::fact()
{
    int result=1;
    if (this->getValeur()==0)
    {
        return new Entier(result);
    }
    else
    for(int i=1;i<=this->getValeur();i++)
        result=result*i;
    return new Entier(result);
    /**
      * \brief Calcul du factoriel
      * \details De manière itérative, le résultat est 1 si la valeur de l'entier est 0, et sinon on fait le calcul proprement dit
      * \return Un nouveau \e Complexe, construit à partir de l'entier qui contient la valeur du factoriel
      */
}

Constante* Entier::sinus(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    return new Entier(sin(res));
    /**
      * \brief Calcul du Sinus
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e sin de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Entier construit construit à partir d'un entier contenant la valeur du sinus
      */
}

Constante* Entier::cosinus(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    return new Entier(cos(res));
    /**
      * \brief Calcul du Cosinus
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e cos de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Entier construit construit à partir d'un entier contenant la valeur du cosinus
      */
}

Constante* Entier::sinush(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    return new Entier(sinh(res));
    /**
      * \brief Calcul du Sinus Hyperbolique
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e sinh de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Entier construit construit à partir d'un entier contenant la valeur du sinus hyperbolique
      */
}

Constante* Entier::cosinush(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    return new Entier(cosh(res));
    /**
      * \brief Calcul du Cosinus Hyperbolique
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e cosh de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Entier construit construit à partir d'un entier contenant la valeur du cosinus hyperbolique
      */
}


Constante* Entier::tangente(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    return new Entier(tan(res));
    /**
      * \brief Calcul de la Tangente
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e tan de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Entier construit construit à partir d'un entier contenant la valeur de la tangente
      */

}

Constante* Entier::tangenteh(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    return new Entier(tanh(res));
    /**
      * \brief Calcul de la Tangente Hyperbolique
      * \details Si le paramètre est vrai, on se situe en mode Degré. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e tanh de cmath est définie en radians.
      * \param angle Sert à savoir si l'on est en mode Degré ou non
      * \return Un \e Entier construit construit à partir d'un entier contenant la valeur de la tangente hyperbolique
      */

}

Constante *Entier::inv()
{
    return new Rationnel(1, this->getValeur());
    /**
      * \brief Inverse d'un entier
      * \details L'inverse d'un nombre est situé entre 0 et 1. Si l'on est en mode entier, on a une importante perte
      *          de précision, car on ne retournera que 0 ou 1
      * \return Un \e Rationnel car on perd moins de précisions comme cela
      */
}

Constante* Entier::logN()
{
    float res = _valeur;
    int l = log(res);
    return new Entier(l);
    /**
      * \brief Logarithme népérien
      * \details On crée un nouvel Entier dont la valeur est celle du logarithme népérien de l'entier initial.
      * \return Un \e Entier construit construit avec cet entier
      */
}

Constante* Entier::log1()
{
    float res = _valeur;
    int l = log10(res);
    return new Entier(l);
    /**
      * \brief Logarithme décimal
      * \details On crée un nouvel Entier dont la valeur est celle du logarithme décimal de l'entier initial.
      * \return Un \e Entier construit construit avec cet entier
      */
}

Constante* Entier::puissance(Constante* c)
{
    if (typeid(*c)==typeid(Entier)) {
            //transtypage en entier
            Entier *c_entier=dynamic_cast<Entier *>(c);
            int value;
            value = c_entier->getValeur();
    int res;
    float res2 = _valeur;
    res = pow(res2,value);

    return new Entier(res);
    /**
      * \brief Puissance de deux entiers
      * \details On effectue un transtypage en entier afin de récupérer l'exposant sous forme entière.
      *          On calcule ensuite grâce à la fonction \e pow de la bibliothèque \e cmath.
      * \param c Une \e Constante qui sera l'exposant
      * \return Un \e Entier construit construit à partir du résultat
      */
}
}

Constante* Entier::carre()
{
    int res = _valeur*_valeur;
    return new Entier(res);
    /**
      * \brief Fonction carré
      * \details On crée un nouvel Entier dont la valeur est le résultat du carré
      * \return Un \e Entier construit construit à partir du résultat de la fonction
      */
}

Constante* Entier::cube()
{
    int res = _valeur*_valeur*_valeur;
    return new Entier(res);
    /**
      * \brief Fonction cube
      * \details On crée un nouvel Entier dont la valeur est le résultat du cube
      * \return Un \e Entier construit construit à partir du résultat de la fonction
      */
}

Constante* Entier::racine()
{
    float res = _valeur;
    int res2 = sqrt(res);
    return new Entier(res2);
    /**
      * \brief Fonction racine carrée
      * \details On crée un nouvel Entier dont la valeur est le résultat de la racine carrée
      * \return Un \e Entier construit construit à partir du résultat de la fonction
      */
}
