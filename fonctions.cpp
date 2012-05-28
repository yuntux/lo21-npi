#include "fonctions.h"
#include <QStack>
#include <iostream>
#include <string>
using namespace std;

int fact(int n){

    int result=1;
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
