#include "fonctions.h"
#include <QStack>
#include <iostream>
#include <string>
#include "complexe.h"
#include "constante.h"
#include "rationnel.h"

using namespace std;

float fact(int n){
    int result=1;
    if (n==0)
        return result;
    else
    for(int i=1;i<=n;i++)
        result=result*i;
    return result;
}


float sum(QStack<float>& pile, int x)
{
    float res=0;
    for(int i=0;i<x;i++)
    {
        res=res+pile.top();
        pile.pop();
    }
    pile.push(res);
    return res;
}

float prod(QStack<float>& pile)
{
    float res=1;
    for(int i=0;i<2;i++)
    {
        res=res*pile.top();
        pile.pop();
    }
    pile.push(res);
    return res;
}

float divise(QStack<float>& pile)
{
    float res=pile.top();
    pile.pop();
    res=pile.pop()/res;
    pile.push(res);
    return res;
}

float diff(QStack<float>& pile)
{
    float res=pile.top();
    pile.pop();
    res=pile.pop()-res;
    return res;
}

float mean(QStack<float>& pile, int x)
{
    float res=0;
    for(int i=0;i<x;i++)
    {
        res=res+pile.top();
        pile.pop();
    }
    res=(res/x);
    pile.push(res);
    return res;
}

void dup(QStack<float>& pile)
{
    float tmp;
    tmp=pile.top();
    pile.push(tmp);
}

void afficher(QStack<float>& pile)
{   cout<<"Affichage de la pile"<<endl;
    while (!pile.isEmpty())
        cout<<"haut de la pile : "<<pile.pop()<<endl;
}


void read_expression(string expr,QStack<float>& pile)
{
    int chiffres,i,operateur;
    chiffres=0;
    operateur=0;
    i=0;

    while(expr[i]!=NULL)
    {
        if(expr[i] != ' ' && expr[i]>='0' && expr[i]<='9')
        {
            chiffres++;
            pile.push(expr[i]-48);
        }
        else if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/')
        {
            if(expr[i]='+')
                sum(pile,2);
        }

        i++;
    }


    cout<<"chiffres : "<<chiffres<<endl;
    cout<<"operateurs : "<<operateur<<endl;
}

Complexe sum_comp(QStack<Complexe> &pile, int x)
{
    Complexe res,res2,res3;
    res=pile.pop();
    res2=pile.pop();
    res3.setReelle(res.getPartieReelle()+res2.getPartieReelle());
    res3.setImaginaire(res.getPartieImaginaire()+res2.getPartieImaginaire());

    pile.push(res3);
    return res3;
}

Complexe diff_comp(QStack<Complexe> &pile)
{
    Complexe res,res2,res3;
    res=pile.pop();
    res2=pile.pop();
    res3.setReelle(res2.getPartieReelle()-res.getPartieReelle());
    res3.setImaginaire(res2.getPartieImaginaire()-res.getPartieImaginaire());

    pile.push(res3);
    return res3;
}

Complexe prod_comp(QStack<Complexe> &pile)
{
    Complexe res,res2,res3;
    res=pile.pop();
    res2=pile.pop();
    res3.setReelle((res2.getPartieReelle()*res.getPartieReelle())-(res2.getPartieImaginaire()*res.getPartieImaginaire()));
    res3.setImaginaire((res2.getPartieReelle()*res.getPartieImaginaire())+(res2.getPartieImaginaire()*res.getPartieReelle()));

    pile.push(res3);
    return res3;
}

Complexe conjugue(Complexe c)
{
    Complexe c1;
    c1.setImaginaire(-c.getPartieImaginaire());
    return c1;
}


