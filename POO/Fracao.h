#ifndef FRACAO_H
#define FRACAO_H

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
    Fracao operator*(const Fracao);
    void print() const;
};
#endif