/**
 * \file fonctions.h
 * \brief Calculatrice en polonais inversé. Fonctions outils diverses.
 * \author Aurélien DUMAINE
 * \author Simon LANCELOT
 * \version 0.1
 * \date juin 2012
 *
 * Licence : GNU/GPL version 3 (http://www.gnu.org/copyleft/gpl.html)
 *
 */


#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <QStack>
#include <string>
#include "constante.h"
#include "complexe.h"
#include "rationnel.h"

int pgcd(int a, int b);

int ppcm(int X,int Y);

float sinus(Rationnel *r);

float cosinus(Rationnel *r);

float tangente(Rationnel *r);

float sinush(Rationnel *r);

float cosinush(Rationnel *r);

/*
template <class T>
T inv(T num) {
  T result;
  result=(-num);
  return (result);
}

template <class T>
        T sqr(T num) {
    T result;
    result = num*num;
    return (result);
}

template <class T>
        T cube(T num) {
    T result;
    result = num*num*num;
    return (result);
}

float fact(int n);

float sum(QStack<float>& pile, int x);

float prod(QStack<float>& pile);

float diff(QStack<float>& pile);

float divise(QStack<float>& pile);

float mean(QStack<float>& pile, int x);

void dup(QStack<float>& pile);

void afficher(QStack<float>& pile);

void read_expression(std::string expr, QStack<float>& pile);

Complexe sum_comp(QStack<Complexe> &pile, int x);

Complexe diff_comp(QStack<Complexe> &pile);

Complexe prod_comp(QStack<Complexe> &pile);

Complexe conjugue(Complexe c);
*/
#endif // FONCTIONS_H
