#include "complexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>


Complexe::~Complexe(){
    delete(_reelle);
    delete(_imaginaire);
    /**
    * \brief Destructeru de complexe
    * \details Rétabli le dernier état annulé de la pile Historique.
    */
}

Complexe::Complexe(Constante* r, Constante* i){
    if (typeid(*r)==typeid(Complexe) || typeid(*r)==typeid(Complexe)) {
        throw LogMessage(2,"Les parties réeelles et complexes doivent être des constantes non complexes.", important);
    } else {
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
    if (Complexe *c_complexe=dynamic_cast<Complexe *>(c)){
        _reelle = c_complexe->getPartieReelle()->recopie();
        _imaginaire = c_complexe->getPartieImaginaire()->recopie();
    } else if (typeid(*c)==typeid(Entier)) {
        Entier *c_entier= new Entier (dynamic_cast<Entier *>(c));
        _reelle = c_entier->recopie();
        _imaginaire = new Entier(0);
    } else if (typeid(*c)==typeid(Rationnel)) {
        Rationnel *r=dynamic_cast<Rationnel *>(c);
        _reelle = r->recopie();
        _imaginaire = new Rationnel(0);
    } else if (typeid(*c)==typeid(Reel)) {
        Reel *c_reel= new Reel(dynamic_cast<Reel *>(c));
        _reelle = c_reel->recopie();
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
    if (this->reel_pur())
        return _reelle->afficher();

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
    Complexe tmp(c);
    return new Complexe(
            this->getPartieReelle()->addition(tmp.getPartieReelle()),
            this->getPartieImaginaire()->addition(tmp.getPartieImaginaire())
            );
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
    Complexe tmp(c);
    return new Complexe(
            this->getPartieReelle()->produit(tmp.getPartieReelle())->soustraction(this->getPartieImaginaire()->produit(tmp.getPartieImaginaire())),
            this->getPartieReelle()->produit(tmp.getPartieImaginaire())->addition(tmp.getPartieReelle()->produit(this->getPartieImaginaire()))
            );
    /**
      * \brief Produit de 2 complexes
      * \details Comme pour l'addition, on crée trois complexes. Cette fois, \a re est le produit des parties réelles,
      *          de la forme a*c - b*d, et \a im est le produit des parties imaginaires, de la forme a*d + c*b.
      * \return  Un \e Complexe comme pour l'addition
      */
}

Constante* Complexe::division(Constante *c)
{
    Complexe tmp(c);
    return this->produit(tmp.inv());
    /**
      * \brief Division de 2 complexes
      * \details  On utilise la multiplication par le conjuguÃ© du diviseur au numÃ©rateur et au dÃ©nominateur
      *      a+ib / c+id = (a+ib)*(c-id) / (c+id)*(c-id) = ... = [(ac+bd)/(cÂ²+dÂ²)] + i[(cb-ad)/(cÂ²+dÂ²)]
      * \return Un \e Complexe comme pour les autres opérations
      */
}

Constante* Complexe::signe(){
    Constante* e = new Entier(-1);
    return new Complexe(this->getPartieReelle()->produit(e), this->getPartieImaginaire()->produit(e));
    /**
      * \brief Changement de signe
      * \details On recopie tout d'abord la constante, qu'on caste ensuite en complexe. On crée un entier de valeur -1
      *          qu'on va multiplier avec les parties réelles et imaginaires de 2 nouveaux complexes qui servent temporairement
      *          pour ensuite modifier la valeur du complexe initial
      * \return Le nouveau \e Complexe
      */
}

Constante* Complexe::soustraction(Constante* c){
    Complexe tmp(c);
    return this->addition(tmp.inv());
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
    return new Complexe(
        this->getPartieReelle()->division(this->getPartieReelle()->carre()->addition(this->getPartieImaginaire()->carre())),
        this->getPartieImaginaire()->signe()->division(this->getPartieReelle()->carre()->addition(this->getPartieImaginaire()->carre()))
        );
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
