#include "pile.h"

using namespace std;


Pile::Pile()
{
    //FIXME
}

Pile::~Pile()
{
//FIXME
}

QString Pile::afficher() const {
    //FIXME : affichage ne devrait pas DETRUIRE LA PILE !
    QString pile;
    pile = pile + "### DEBUT PILE###\n";
    QStack<Constante*> copie(this->p);
    while (!copie.isEmpty())
         pile = pile + copie.pop()->afficher() + "\n";
    pile = pile + "### FIN PILE###";
    return pile;
}

Constante* Pile::pop()
{
    return p.pop();
}

Constante* Pile::top()
{
    return p.top();

}

Constante* Pile::sum(unsigned int x)
{
    Constante* res= new Complexe;
    res = 0;
    for(int i=0;i<x;i++)
    {
        res=res->addition(top());
        this->pop();
    }
    this->push(res);
    return res;
}
