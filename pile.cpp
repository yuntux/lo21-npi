#include "pile.h"

using namespace std;

void Pile::push(Constante* ptr) {
    p.push_front(ptr);
    emit dataChanged(index(0), index(p.size()));
}

int Pile::rowCount(const QModelIndex &parent) const { return p.size();}


QVariant Pile::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >=  p.size())
        return QVariant();

    if (role == Qt::DisplayRole)
        return p.at(index.row())->afficher(); //renvoyer un QStrigng
    else
        return QVariant();
}

/*
Pile::~Pile()
{
//FIXME
}*/

QString Pile::afficher() const {
    //FIXME : affichage ne devrait pas DETRUIRE LA PILE !
    /*QString pile;
    pile = pile + "### DEBUT PILE###\n";
    QStack<Constante*> copie(this->p);
    while (!copie.isEmpty())
         pile = pile + copie.pop()->afficher() + "\n";
    pile = pile + "### FIN PILE###";
    return pile;
    */
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
    /*
    Constante* res= new Complexe;
    res = 0;
    for(int i=0;i<x;i++)
    {
        res=res->addition(top());
        this->pop();
    }
    this->push(res);
    return res;
    */
}
