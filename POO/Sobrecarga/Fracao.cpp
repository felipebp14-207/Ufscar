#include "Fracao.h"
#include <iostream>

Fracao::Fracao()
{
    set_numerador(0);
    set_denominador(1);
}

Fracao::Fracao(int num, int den)
{
    set_numerador(num);
    set_denominador(den);
}

void Fracao::set_numerador(int num)
{
    numerador = num;
}

void Fracao::set_denominador(int den)
{
    if(den == 0)
    {
        cout << "Denominador Invalido! (Alterado para 1)" << endl;
        denominador = 1;
    }
    else
    {
        if(den < 0)
        {
            set_numerador(-this->get_numerador());
            denominador = -den;
        }
        denominador = den;
    }
}

int Fracao::get_numerador() const
{
    return numerador;
}

int Fracao::get_denominador() const
{
    return denominador;
}

void Fracao::print() const
{
    std::cout << "Numerador: " << get_numerador() << std::endl;
    std::cout << "Denominador: " << get_denominador() << std::endl << std::endl;
}

//Implementação do operador *

Fracao Fracao::operator*(const Fracao &F2) const
{
    Fracao resultado;
    resultado.set_numerador(this->get_numerador()*F2.get_numerador());
    resultado.set_denominador(this->get_denominador()*F2.get_denominador());
    return resultado;
}

Fracao Fracao::operator*(int num) const
{
    Fracao resultado;
    resultado.set_numerador(this->get_numerador()*num);
    resultado.set_denominador(this->get_denominador());
    return resultado;
}

Fracao operator*(int num, const Fracao &F1)
{
    return Fracao(F1.numerador * num, F1.denominador);
}

//Implementação do operador ++(pré e pós-fixado)

Fracao & Fracao::operator++()
{
    set_numerador(get_numerador()+get_denominador());
    return *this;
}

Fracao Fracao::operator++(int inutil)
{
    Fracao antigo = *this;
    this->set_numerador(this->get_numerador() + this->get_denominador());
    return antigo;
}

//Implementação do operador <

bool Fracao::operator<(const Fracao &f2) const
{
    long long a = 1LL * numerador * f2.denominador;
    long long b = 1LL * f2.numerador * denominador;

    if ((denominador < 0) != (f2.denominador < 0))
        return a > b;

    return a < b;
}

bool Fracao::operator<(int num) const
{
    return (*this < Fracao(num, 1));
}

bool operator<(int num, const Fracao &f1)
{
    return (Fracao(num, 1) < f1);
}


//Implementação das operações de entrada e saída de dados

ostream &operator<<(ostream &saida, const Fracao &f)
{
    saida << f.numerador << "/" << f.denominador;
    return saida;
}

istream &operator>>(istream &entrada, Fracao &f)
{
    int num, den;
    char barra;

    if (entrada >> num >> barra >> den)
    {
        if (barra == '/' && den != 0)
        {
            f.set_numerador(num);
            f.set_denominador(den);
        }
        else
        {
            entrada.setstate(ios::failbit);
        }
    }

    return entrada;
}
//Implementação da operação -.

Fracao Fracao::operator-(const Fracao &f2) const
{
    Fracao resultado = *this;

    if(resultado.get_denominador() == f2.get_denominador())
    {
        resultado.set_numerador(this->get_numerador()-f2.get_numerador());
    }
    else
    {
        Fracao aux = f2;

        resultado.set_denominador(this->get_denominador()*f2.get_denominador());
        resultado.set_numerador(this->get_numerador()*f2.get_denominador());
        aux.set_numerador(f2.get_numerador() * this->get_denominador());
        resultado.set_numerador(resultado.get_numerador() - aux.get_numerador());
    }

    return resultado;
}

Fracao Fracao::operator-(const int &num) const
{
    Fracao aux(num*this->get_denominador(), this->get_denominador());
    Fracao resultado(this->get_numerador()-aux.get_numerador(), this->get_denominador());
    return resultado;
}

Fracao operator-(const int &num, const Fracao &f)
{
    Fracao aux(num*f.get_denominador(), f.get_denominador());
    Fracao resultado(aux.get_numerador()-f.get_numerador(), f.get_denominador());
    return resultado;
}

//Implementação do operador --(pré e pós-fixado)

Fracao &Fracao::operator--()
{
    set_numerador(this->get_numerador()-this->get_denominador());
    return *this;
}

Fracao Fracao::operator--(int inutil)
{
    Fracao antigo = *this;
    this->set_numerador(this->get_numerador()-this->get_denominador());
    return antigo;
}

//Implementação do operador >

bool Fracao::operator>(const Fracao &f2) const
{
    return (f2 < *this);
}

bool Fracao::operator>(int num) const
{
    return (Fracao(num, 1) < *this);
}

bool operator>(int num, const Fracao &f1)
{
    return (f1 < num);
}

//Implementação do operador ==

bool Fracao::operator==(const Fracao &f2) const
{
    long long a1 = 1LL * this->get_numerador() * f2.get_denominador();
    long long a2 = 1LL * f2.get_numerador() * this->get_denominador();

    if(a1 == a2)
    {
        return true;
    }
    return false;
}

bool Fracao::operator==(int num) const
{
    return (*this == Fracao(num, 1));
}

bool operator==(int num, const Fracao &f1)
{
    return (Fracao(num, 1) == f1);
}

//Implementação do operador <=

bool Fracao::operator<=(const Fracao &f2) const
{
    return ((*this < f2) || (*this == f2));
}

bool Fracao::operator<=(int num) const
{
    return ((*this < num) || (*this == num));
}

bool operator<=(int num, const Fracao &f1)
{
    return ((num < f1) || (num == f1));
}

//Implementação do operador >=

bool Fracao::operator>=(const Fracao &f2) const
{
    return ((*this > f2) || (*this == f2));
}

bool Fracao::operator>=(int num) const
{
    return ((*this > num) || (*this == num));
}

bool operator>=(int num, const Fracao &f1)
{
    return ((num > f1) || (num == f1));
}

//Implementação do operador !=

bool Fracao::operator!=(const Fracao &f2) const
{
    return !(*this == f2);
}

bool Fracao::operator!=(int num) const
{
    return !(*this == num);
}

bool operator!=(int num, const Fracao &f1)
{
    return !(num == f1);
}

//Implementação operador +

Fracao Fracao::operator+(const Fracao &f2) const
{
    if(this->get_denominador() == f2.get_denominador())
    {
        return Fracao((this->get_numerador()+f2.get_numerador()), this->get_denominador());
    }

    Fracao resultado = *this;
    int aux = (this->get_denominador()*f2.get_numerador());

    resultado.set_numerador(this->get_numerador()*f2.get_denominador()+aux);
    resultado.set_denominador(this->get_denominador()*f2.get_denominador());
    return resultado;
}

Fracao Fracao::operator+(int num) const
{
    return (*this + Fracao(num, 1));
}

Fracao operator+(int num, const Fracao &f1)
{
    return (f1 + num);
}