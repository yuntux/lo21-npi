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

Constante* Pile::pop()
{
    return p.pop();
}

void Pile::append(Constante* ptr)
{
    p.push(ptr);
}

Constante* Pile::top()
{
    return p.top();

}

/*Complexe* Pile::sum(unsigned int x)
{
    Complexe* res= new Complexe;
    res = 0;
    for(int i=0;i<x;i++)
    {
        res=res+this->top();
        this->pop();
    }
    this->push(res);
    return res;
}
*/
