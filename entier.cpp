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
        //FIXME : impossible de construire un entier avec un complexe SAUF si la partie imaginaire est nulle
  //      Complexe *c_complexe=dynamic_cast<Complexe *>(c);
    //    if c_complexe->getPartieImaginaire()
    } else if (typeid(*c)==typeid(Rationnel)) {
        //FIXME : impossible de construire un entier avec un rationnel SAUF si le d�nominateur vaut 1
    } else if (typeid(*c)==typeid(Reel)) {
        //FIXME : impossible de construire un entier �  partir d'un réel SAUF c'est la parti d�cimale est nulle
    }
    /**
      * \brief Constructeur d'entier
      * \details On v�rifie le type de la constante pass�e en param�tre, et si c'est un entier, on
      *          recopie sa valeur dans le nouvel entier, sinon on l�ve une exception.
      * \param c Une constante, donc entier, r�el, rationnel ou complexe
      */
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
    throw LogMessage(3,"Type de constante non pr�vu dans la fonction Constante* Entier::addition(Constante* c).", important);
    /**
      * \brief Somme de 2 entiers
      * \details On v�rifie le type du param�tre, et on cr�e une nouvelle instance de ce type en fonction, dont le
      *          ou les attributs seront en fait la somme des 2 entiers dont l'on veut calculer l'addition.Cependant, si on
      *          est en mode Entier, on ne doit pas avoir les autres types de constante.
      * \param c Une constante
      * \return Un \e Complexe, car on utilisera toujours les formes complexes pour les calculs
      */
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
       throw LogMessage(3,"Type de constante non pr�vu dans la fonction Constante* Entier::produit(Constante* c).", important);
       /**
         * \brief Produit de deux entiers
         * \details Comme pour la somme, on v�rifie le type du param�tre, et on cr�e une nouvelle instance de ce type qui contiendra
         *          le produit demand�. Cependant, normalement en mode Entier, on ne doit avoir que des entiers.
         * \param c Une Constante
         * \return Un \e Complexe contenant le produit
         */
}

Constante* Entier::division(Constante *c)
{
    if(Entier *c_entier=dynamic_cast<Entier *>(c))
    {
        //On renvoie forc�ment un rationnel pour ne pas perdre en pr�cision
        Rationnel* tmp = new Rationnel(_valeur, c_entier->getValeur());
        return new Complexe(tmp);
    }
    else if (typeid(*c)==typeid(Rationnel)) {
            Rationnel *c_rationnel=dynamic_cast<Rationnel *>(c);
            Rationnel* tmp = new Rationnel((_valeur*c_rationnel->getDenominateur()),c_rationnel->getNumerateur());
            return new Complexe(tmp);
    }
    else if (typeid(*c)==typeid(Reel)) {
        //FIXME : perte de pr�cision ???
            Reel *c_reel=dynamic_cast<Reel *>(c);
            Reel*  tmp = new Reel(_valeur/c_reel->getValeur());
            return new Complexe(tmp);
        }
   else if (typeid(*c)==typeid(Complexe)) {
       Complexe *c_complexe=dynamic_cast<Complexe *>(c);
       Complexe entier_complexe(this);
       return entier_complexe.division(c_complexe);
    }
       throw LogMessage(3,"Type de constante non pr�vu dans la fonction Constante* Entier::division(Constante* c).", important);
       /**
         * \brief Division d'entiers
         * \details Comme pour la somme et le produit, on v�rifie le type du param�tre, et on cr�e une nouvelle instance de ce type qui contiendra
         *          le quotient demand�. Cependant, normalement en mode Entier, on ne doit avoir que des entiers.
         * \param c Une Constante
         * \return Un \e Complexe contenant le quotient
         */
}

Constante* Entier::signe(){
    return new Entier(-_valeur);
    /**
      * \brief Inversion de signe d'un entier
      * \details On cr�e un nouvel entier dont la valeur est l'oppos�e de celle initiale
      * \return Un \e Entier, de valeur oppos�e
      */
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
        //FIXME : on doit pouvoir mettre des type constantes pour les réels et rationnel => PAS DE CAST SUR LA CLASSE COMPLEXE
        return new Complexe(this->addition(c_rationnel->signe()));
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel=dynamic_cast<Reel *>(c);
        return new Complexe(this->addition(c_reel->signe()));
    }
        throw LogMessage(3,"Type de constante non pr�vu dans la fonction Constante* Entier::soustraction(Constante* c).", important);
        /**
          * \brief Diff�rence d'entiers
          * \details Comme pour les autres op�rations, on v�rifie le type du param�tre, et on cr�e une nouvelle instance de ce type qui contiendra
          *          la diff�rence voulue. Cependant, normalement en mode Entier, on ne doit avoir que des entiers.
          * \param c Une Constante
          * \return Un \e Complexe contenant la diff�rence
          */
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
    /**
      * \brief Calcul du factoriel
      * \details De mani�re it�rative, le r�sultat est 1 si la valeur de l'entier est 0, et sinon on fait le calcul proprement dit
      * \return Un nouveau \e Complexe, construit � partir de l'entier qui contient la valeur du factoriel
      */
}

Constante* Entier::sinus(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    Entier *e = new Entier(sin(res));
    return new Complexe(e);
    /**
      * \brief Calcul du Sinus
      * \details Si le param�tre est vrai, on se situe en mode Degr�. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e sin de cmath est d�finie en radians.
      * \param angle Sert � savoir si l'on est en mode Degr� ou non
      * \return Un \e Complexe construit � partir d'un entier contenant la valeur du sinus
      */
}

Constante* Entier::cosinus(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    Entier *e = new Entier(cos(res));
    return new Complexe(e);
    /**
      * \brief Calcul du Cosinus
      * \details Si le param�tre est vrai, on se situe en mode Degr�. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e cos de cmath est d�finie en radians.
      * \param angle Sert � savoir si l'on est en mode Degr� ou non
      * \return Un \e Complexe construit � partir d'un entier contenant la valeur du cosinus
      */
}

Constante* Entier::sinush(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    Entier *e = new Entier(sinh(res));
    return new Complexe(e);
    /**
      * \brief Calcul du Sinus Hyperbolique
      * \details Si le param�tre est vrai, on se situe en mode Degr�. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e sinh de cmath est d�finie en radians.
      * \param angle Sert � savoir si l'on est en mode Degr� ou non
      * \return Un \e Complexe construit � partir d'un entier contenant la valeur du sinus hyperbolique
      */
}

Constante* Entier::cosinush(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    Entier *e = new Entier(cosh(res));
    return new Complexe(e);
    /**
      * \brief Calcul du Cosinus Hyperbolique
      * \details Si le param�tre est vrai, on se situe en mode Degr�. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e cosh de cmath est d�finie en radians.
      * \param angle Sert � savoir si l'on est en mode Degr� ou non
      * \return Un \e Complexe construit � partir d'un entier contenant la valeur du cosinus hyperbolique
      */
}


Constante* Entier::tangente(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    Entier *e = new Entier(tan(res));
    return new Complexe(e);
    /**
      * \brief Calcul de la Tangente
      * \details Si le param�tre est vrai, on se situe en mode Degr�. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e tan de cmath est d�finie en radians.
      * \param angle Sert � savoir si l'on est en mode Degr� ou non
      * \return Un \e Complexe construit � partir d'un entier contenant la valeur de la tangente
      */

}

Constante* Entier::tangenteh(bool angle)
{
    float res = _valeur;
    if(angle==true)
        res=res*PI/180;
    Entier *e = new Entier(tanh(res));
    return new Complexe(e);
    /**
      * \brief Calcul de la Tangente Hyperbolique
      * \details Si le param�tre est vrai, on se situe en mode Degr�. Dans ce cas, il faut multiplier la valeur par PI/180,
      *          car la fonction \e tanh de cmath est d�finie en radians.
      * \param angle Sert � savoir si l'on est en mode Degr� ou non
      * \return Un \e Complexe construit � partir d'un entier contenant la valeur de la tangente hyperbolique
      */

}

Constante *Entier::inv()
{
    //FIXME : pas d'inverse pour les entiers sans perte de pr�cision
    return new Rationnel(1, this->getValeur());
    /**
      * \brief Inverse d'un entier
      * \details L'inverse d'un nombre est situ� entre 0 et 1. Si l'on est en mode entier, on a une importante perte
      *          de pr�cision, car on ne retournera que 0 ou 1
      * \return Un \e Rationnel car on perd moins de pr�cisions comme cela
      */
}

Constante* Entier::logN()
{
    float res = _valeur;
    int l = log(res);
    Entier* e = new Entier(l);
    return new Complexe(e);
    /**
      * \brief Logarithme n�p�rien
      * \details On cr�e un nouvel Entier dont la valeur est celle du logarithme n�p�rien de l'entier initial.
      * \return Un \e Complexe construit avec cet entier
      */
}

Constante* Entier::log1()
{
    float res = _valeur;
    int l = log10(res);
    Entier* e = new Entier(l);
    return new Complexe(e);
    /**
      * \brief Logarithme d�cimal
      * \details On cr�e un nouvel Entier dont la valeur est celle du logarithme d�cimal de l'entier initial.
      * \return Un \e Complexe construit avec cet entier
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

    Entier *e = new Entier(res);
    return new Complexe(e);
    /**
      * \brief Puissance de deux entiers
      * \details On effectue un transtypage en entier afin de r�cup�rer l'exposant sous forme enti�re.
      *          On calcule ensuite gr�ce � la fonction \e pow de la biblioth�que \e cmath.
      * \param c Une \e Constante qui sera l'exposant
      * \return Un \e Complexe construit � partir du r�sultat
      */
}
}

Constante* Entier::carre()
{
    int res = _valeur*_valeur;
    Entier *e = new Entier(res);
    return new Complexe(e);
    /**
      * \brief Fonction carr�
      * \details On cr�e un nouvel Entier dont la valeur est le r�sultat du carr�
      * \return Un \e Complexe construit � partir du r�sultat de la fonction
      */
}

Constante* Entier::cube()
{
    int res = _valeur*_valeur*_valeur;
    Entier *e = new Entier(res);
    return new Complexe(e);
    /**
      * \brief Fonction cube
      * \details On cr�e un nouvel Entier dont la valeur est le r�sultat du cube
      * \return Un \e Complexe construit � partir du r�sultat de la fonction
      */
}

Constante* Entier::racine()
{
    float res = _valeur;
    int res2 = sqrt(res);
    Entier *e = new Entier(res2);
    return new Complexe(e);
    /**
      * \brief Fonction racine carr�e
      * \details On cr�e un nouvel Entier dont la valeur est le r�sultat de la racine carr�e
      * \return Un \e Complexe construit � partir du r�sultat de la fonction
      */
}
