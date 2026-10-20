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
    void print() const;

    Fracao operator*(const Fracao);
    Fracao operator*(int);
    Fracao & operator++();
    Fracao operator++(int);
    bool operator<(const Fracao&) const;

    friend Fracao operator*(int, const Fracao);
    friend ostream &operator<<(ostream&, const Fracao&);
};
#endif