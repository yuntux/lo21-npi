#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <QStack>
#include <string>
#include "TypeDonnee.h"

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

#endif // FONCTIONS_H
