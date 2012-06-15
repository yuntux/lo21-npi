#include "pile.h"

using namespace std;

void Pile::push(Constante* ptr) {
    p.push_front(ptr);
}

int Pile::rowCount(const QModelIndex &parent) const { return p.size();}


QVariant Pile::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= this->size())
        return QVariant();

    if (role == Qt::DisplayRole)
        //if (p.at(index.row()))
            //return p.at(index.row())->afficher();
        return p.at(index.row())->afficher(); //renvoyer un QStrigng
    else
        return QVariant();
}


Pile::~Pile()
{
    //qDebug() << "Feu la pile que je vais détruire : " << this->afficher();
    int s = this->size(); //ATTENTION : il faut bien fixer la taille avant !
    for(int i=0; i<s; i++){
        Constante* tmp = this->pop();
        delete(tmp);
    }
    //qDebug() << "Après destruction : " << this->afficher();
}

QString Pile::afficher() const {
    QString string_pile;
    string_pile = string_pile + "### DEBUT PILE###\n";

    for(int i=0; i<p.size(); i++){
        string_pile = string_pile + p.at(i)->afficher() + "\n";
    }
    string_pile = string_pile + "### FIN PILE###";
    return string_pile;
}

Constante* Pile::pop()
{
    if (!p.isEmpty()) {
        Constante* tmp = p.at(0);
        p.removeAt(0);
        return tmp;
    } else {
        return NULL;
    }
}

/*Constante* Pile::top()
{
    return p.top;

}*/

Constante* Pile::sum(unsigned int x)
{
    Constante* res = new Complexe(0);

    for(int i=0;i<x;i++)
    {
        res=res->addition(this->pop());
    }
    this->push(res);
    return res;
}

Constante* Pile::mean(unsigned int x)
{
    Constante* tmp = this->sum(x);
    Entier e(x);
    return new Complexe(tmp->division(&e));
}

void Pile::clear(){
    for(int i=0; i<this->size(); i++){
        Constante* tmp = this->pop();
        delete(tmp);
    }
}

void Pile::dup(){
    Constante* tmp = this->p.at(0)->recopie();
    this->push(tmp);
}

Pile* Pile::copier_pile(){
    Pile* nouv = new Pile();
    for(int i =0; i<p.size(); i++){
        Constante* tmp = p.at(i)->recopie();
        nouv->p.push_back(tmp);
    }
    return nouv;
}

void Pile::drop(){
    Constante* tmp = this->pop();
    delete(tmp);
}

void Pile::swap(unsigned int x, unsigned int y){
    Constante* tmp1 = p.at(x);
    Constante* tmp2 = p.at(y);
    p[x] = tmp2;
    p[y] = tmp1;
}
