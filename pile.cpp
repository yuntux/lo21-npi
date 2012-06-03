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
