#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>


Complexe::~Complexe(){
    delete(_reelle);
    delete(_imaginaire);
}

Complexe::Complexe(Constante* r, Constante* i){
    if (typeid(*r)==typeid(Complexe) || typeid(*r)==typeid(Complexe)) {
        //FIXME : lève une exeption (éviter les boucles de récursion infinies)
    } else {
        //plutot copier les composantes ?
        _reelle = r->recopie();;
        _imaginaire= i->recopie();
    }
    /**
      * \brief Constructeur surchargé de complexe
      * \details On vérifie le type des 2 constantes, et on lève une exception
      *          si ce sont des complexes, car un complexe ne peut pas être composé
      *          lui même de complexes
      * \param r la partie réelle est une Constante
      * \param i la partie imaginaire est une Constante aussi
      */
}

Complexe::Complexe(Constante* c) {
    //FIXME : on réalloue pour Reel(0,0) et Rationnel(0) mais on ne recopie pas le reste ???
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
        _reelle = c_complexe->getPartieReelle();
        _imaginaire = c_complexe->getPartieImaginaire();
    } else if (typeid(*c)==typeid(Entier)) {
        Entier *c_entier= new Entier (dynamic_cast<Entier *>(c));
        _reelle = c_entier;
        _imaginaire = new Entier(0);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *r=dynamic_cast<Rationnel *>(c);
        Constante* r_copie = r->recopie();
        _reelle = r_copie;
        _imaginaire = new Rationnel(0);
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel= new Reel(dynamic_cast<Reel *>(c));
        _reelle = c_reel;
        _imaginaire = new Reel(0.0);
    }
    /**
      * \brief Constructeur surchargé à un paramètre
      * \details On vérifie les types, et on crée un complexe
      *          qui n'aura qu'une partie réelle
      * \param c seul paramètre, qui est une Constante
      */
}

QString Complexe::afficher() const{

    if (typeid(*getPartieImaginaire())==typeid(Entier)) {
        Entier *im_entier=dynamic_cast<Entier *>(this->getPartieImaginaire());
        if (im_entier->getValeur()==0)
            return _reelle->afficher();
    } else if (typeid(*getPartieImaginaire())==typeid(Rationnel)) {
        Rationnel *im_rationnel=dynamic_cast<Rationnel *>(this->getPartieImaginaire());
        if (im_rationnel->getNumerateur()==0)
            return _reelle->afficher();
    } else if (typeid(*getPartieImaginaire())==typeid(Reel)) {
       Reel *im_reel=dynamic_cast<Reel *>(this->getPartieImaginaire());
       if (im_reel->getValeur()==0)
           return _reelle->afficher();
   }
    return _reelle->afficher()+"$"+_imaginaire->afficher();
    /**
      * \brief Méthode d'affichae d'un Complexe
      * \details On vérifie le type de la partie imaginaire, et on crée une nouvelle constante de ce type.
      *          Si la partie imaginaire est nule, on affiche la partie réelle, sinon on affiche la partie réelle,
      *          un $ et la partie imaginaire.
      * \return  Une \e QString permettant l'affichage
      */
}

Constante* Complexe::addition(Constante* c){
    Complexe *c_complexe = new Complexe(c);
    //les parties imaginaires sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
    Complexe* re = new Complexe(c_complexe->getPartieReelle()->addition(this->getPartieReelle()));
    //les parties réelles sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
    Complexe* im = new Complexe(c_complexe->getPartieImaginaire()->addition(this->getPartieImaginaire()));
    c_complexe->setImaginaire(im->getPartieReelle());
    c_complexe->setReelle(re->getPartieReelle());
    //NE PAS DECOMMENTER
    //delete(re);
    //delete(im);
    return c_complexe;
    /**
      * \brief Addition de 2 complexes
      * \details On crée 3 complexes : \a c_entier, construit à partir du paramètre,
      *          \a re, qui est l'addition des 2 parties réelles et
      *          \a im, qui est l'addition des 2 parties imaginaires
      * \return  Une \e Constante, qui est en fait un \e Complexe, dont la partie imaginaire est \a re et la partie imaginaire \a im.
      */
}

Constante* Complexe::produit(Constante *c)
{
    Complexe *c_complexe = new Complexe(c);
    Complexe* re = new Complexe(c_complexe->getPartieReelle()->produit(_reelle)->soustraction(c_complexe->getPartieImaginaire()->produit(_imaginaire)));
    Complexe* im = new Complexe(c_complexe->getPartieImaginaire()->produit(_reelle)->addition(c_complexe->getPartieReelle()->produit(_imaginaire)));
    c_complexe->setImaginaire(im->getPartieReelle());
    c_complexe->setReelle(re->getPartieReelle());
    //delete(re);
    //delete(im);
    return c_complexe;
    /**
      * \brief Produit de 2 complexes
      * \details Comme pour l'addition, on crée trois complexes. Cette fois, \a re est le produit des parties réelles,
      *          de la forme a*c - b*d, et \a im est le produit des parties imaginaires, de la forme a*d + c*b.
      * \return  Un \e Complexe comme pour l'addition
      */
}

Constante* Complexe::division(Constante *c)
{
    // On utilise la multiplication par le conjugué du diviseur au numérateur et au dénominateur
    //    a+ib / c+id = (a+ib)*(c-id) / (c+id)*(c-id) = ... = [(ac+bd)/(c²+d²)] + i[(cb-ad)/(c²+d²)]
    Complexe *dividende = this;
    Complexe *diviseur=dynamic_cast<Complexe *>(c);

    Complexe* denom = new Complexe(diviseur->getPartieReelle()->produit(diviseur->getPartieReelle())->addition(diviseur->getPartieImaginaire()->produit(diviseur->getPartieImaginaire())));

    Complexe* re_num = new Complexe(dividende->getPartieReelle()->produit(diviseur->getPartieReelle())->addition(dividende->getPartieImaginaire()->produit(diviseur->getPartieImaginaire())));
    Complexe* re = new Complexe(re_num->getPartieReelle()->division(denom->getPartieReelle()));

    Complexe* im_num = new Complexe(diviseur->getPartieReelle()->produit(dividende->getPartieImaginaire())->soustraction(dividende->getPartieReelle()->produit(diviseur->getPartieImaginaire())));
    Complexe* im = new Complexe(im_num->getPartieReelle()->division(denom->getPartieReelle()));

    Complexe* res = new Complexe(re->getPartieReelle(), im->getPartieReelle());
    //delete(denom);
    //delete(re_num);
    //delete(im_num);
    return res;
    /**
      * \brief Division de 2 complexes
      * \details  On utilise la multiplication par le conjuguÃ© du diviseur au numÃ©rateur et au dÃ©nominateur
      *      a+ib / c+id = (a+ib)*(c-id) / (c+id)*(c-id) = ... = [(ac+bd)/(cÂ²+dÂ²)] + i[(cb-ad)/(cÂ²+dÂ²)]
      * \return Un \e Complexe comme pour les autres opérations
      */
}

Constante* Complexe::signe(){
    Constante *c = this->recopie();
    Complexe *tmp = dynamic_cast<Complexe *>(c);
    Entier e(-1);
    Complexe tmp1(tmp->getPartieImaginaire()->produit(&e));
    tmp->setImaginaire(tmp1.getPartieReelle());
    Complexe tmp2(tmp->getPartieReelle()->produit(&e));
    tmp->setReelle(tmp2.getPartieReelle());
    return c;
    /**
      * \brief Changement de signe
      * \details On recopie tout d'abord la constante, qu'on caste ensuite en complexe. On crée un entier de valeur -1
      *          qu'on va multiplier avec les parties réelles et imaginaires de 2 nouveaux complexes qui servent temporairement
      *          pour ensuite modifier la valeur du complexe initial
      * \return Le nouveau \e Complexe
      */
}

Constante* Complexe::soustraction(Constante* c){
    Complexe *c_complexe = new Complexe(c);
    //les parties imaginaires sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
    Complexe* re = new Complexe(this->getPartieReelle()->soustraction(c_complexe->getPartieReelle()));
    //les parties réelles sont des reels/rationnels/entiers donc leur somme renvoie un complexe donc l'im est nulle
    Complexe* im = new Complexe(this->getPartieImaginaire()->soustraction(c_complexe->getPartieImaginaire()));
    c_complexe->setImaginaire(im->getPartieReelle());
    c_complexe->setReelle(re->getPartieReelle());
    //delete(re);
    //delete(im);
    return c_complexe;
    /**
      * \brief Différence de deux complexes
      * \details De la même façon, cette fois \a re va être la différence des 2 parties réelles, et \a im la différence des
      *          parties imaginaires.
      * \return  Un \e Complexe dont la partie réelle est \a re et la partie imaginaire est \a im.
      */
}


Constante* Complexe::fact()
{
    if (this->reel_pur())
        return this->getPartieReelle()->fact();
    throw LogMessage(2,"La fonction factorielle n'est pas implémentée pour les complexes.", moyen);
    return this;
}

Constante* Complexe::sinus(bool angle)
{
    if (this->reel_pur())
        return this->getPartieReelle()->sinus(angle);
    throw LogMessage(2,"La fonction SIN n'est pas implémentée pour les complexes.", moyen);
    return this;
}

Constante* Complexe::cosinus(bool angle)
{
    if (this->reel_pur())
        return this->getPartieReelle()->cosinus(angle);
    throw LogMessage(2,"La fonction COS n'est pas implémentée pour les complexes.", moyen);
    return this;
}

Constante* Complexe::sinush(bool angle)
{
    if (this->reel_pur())
        return this->getPartieReelle()->sinush(angle);
    throw LogMessage(2,"La fonction SINH n'est pas implémentée pour les complexes.", moyen);
    return this;
}

Constante* Complexe::cosinush(bool angle)
{
    if (this->reel_pur())
        return this->getPartieReelle()->cosinush(angle);
    throw LogMessage(2,"La fonction COSH n'est pas implémentée pour les complexes.", moyen);
    return this;
}

Constante* Complexe::tangente(bool angle)
{
    if (this->reel_pur())
        return this->getPartieReelle()->tangente(angle);
    throw LogMessage(2,"La fonction TAN n'est pas implémentée pour les complexes.", moyen);
    return this;
}

Constante* Complexe::tangenteh(bool angle)
{
    if (this->reel_pur())
        return this->getPartieReelle()->tangenteh(angle);
    throw LogMessage(2,"La fonction TANH n'est pas implémentée pour les complexes.", moyen);
    return this;
}


Constante* Complexe::inv()
{    
    Complexe *diviseur = this;
    Entier *e1 = new Entier(1);
    Entier *e0 = new Entier(0);
    Complexe *dividende= new Complexe(e1, e0);

    Complexe* denom = new Complexe(diviseur->getPartieReelle()->produit(diviseur->getPartieReelle())->addition(diviseur->getPartieImaginaire()->produit(diviseur->getPartieImaginaire())));

    Complexe* re_num = new Complexe(dividende->getPartieReelle()->produit(diviseur->getPartieReelle())->addition(dividende->getPartieImaginaire()->produit(diviseur->getPartieImaginaire())));
    Complexe* re = new Complexe(re_num->getPartieReelle()->division(denom->getPartieReelle()));

    Complexe* im_num = new Complexe(diviseur->getPartieReelle()->produit(dividende->getPartieImaginaire())->soustraction(dividende->getPartieReelle()->produit(diviseur->getPartieImaginaire())));
    Complexe* im = new Complexe(im_num->getPartieReelle()->division(denom->getPartieReelle()));

    Complexe* res = new Complexe(re->getPartieReelle(), im->getPartieReelle());
    //delete(denom);
    //delete(re_num);
    //delete(im_num);
    return res;
    /*
    if (this->reel_pur())
        return this->getPartieReelle()->inv();
    throw LogMessage(2,"La fonction INV n'est pas implémentée pour les complexes.", moyen);
    return this;
    */
}

Constante* Complexe::carre()
{
    Complexe *c_complexe = new Complexe(this);
    return c_complexe->produit(this);
}

Constante* Complexe::cube()
{
    Complexe *c_complexe = new Complexe(this);
    return c_complexe->produit(this->produit(this));
}

Constante* Complexe::racine()
{
    if (this->reel_pur())
        return this->getPartieReelle()->racine();
    throw LogMessage(2,"La fonction RACINE n'est pas implémentée pour les complexes.", moyen);
    return this;
}

Constante* Complexe::puissance(Constante *c)
{
    if (this->reel_pur())
        return this->getPartieReelle()->puissance(c);
    throw LogMessage(2,"La fonction PUISSANCE n'est pas implémentée pour les complexes.", moyen);
    return this;
}

Constante* Complexe::logN()
{
    if (this->reel_pur())
        return this->getPartieReelle()->logN();
    throw LogMessage(2,"La fonction LN n'est pas implémentée pour les complexes.", moyen);
    return this;
}

Constante* Complexe::log1()
{
    if (this->reel_pur())
        return this->getPartieReelle()->log1();
    throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);
    return this;
}

bool Complexe::reel_pur() const{

    if (typeid(*getPartieImaginaire())==typeid(Entier)) {
        Entier *im_entier=dynamic_cast<Entier *>(this->getPartieImaginaire());
        if (im_entier->getValeur()==0)
            return true;
    } else if (typeid(*getPartieImaginaire())==typeid(Rationnel)) {
        Rationnel *im_rationnel=dynamic_cast<Rationnel *>(this->getPartieImaginaire());
        if (im_rationnel->getNumerateur()==0)
            return true;
    } else if (typeid(*getPartieImaginaire())==typeid(Reel)) {
       Reel *im_reel=dynamic_cast<Reel *>(this->getPartieImaginaire());
       if (im_reel->getValeur()==0)
           return true;
   }
    return false;
}
