#ifndef FRACAO_H
#define FRACAO_H
#include <iostream>
#include <iomanip>
using namespace std;

class Fracao{
    int numerador;
    int denominador;
public:
    Fracao();
    Fracao(int, int);
    void set_numerador(int);
    void set_denominador(int);
    int get_numerador() const;
    int get_denominador() const;
    void print() const;

    Fracao operator*(const Fracao);
    Fracao operator*(int);
    friend Fracao operator*(int, const Fracao);

    Fracao operator-(const Fracao&);
    Fracao operator-(const int&);
    friend Fracao operator-(const int&, const Fracao&);

    Fracao & operator++();
    Fracao operator++(int);
    
    bool operator<(const Fracao&) const;

    friend ostream &operator<<(ostream&, const Fracao&);
    friend istream &operator>>(istrean&, Fracao&);

    Fracao & operator--();
    Fracao operator--(int);
};
#endif