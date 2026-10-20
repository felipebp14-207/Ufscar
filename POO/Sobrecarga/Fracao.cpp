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
        denominador = 1;
    }
    else
    {
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

Fracao Fracao::operator*(const Fracao F2)
{
    Fracao resultado;
    resultado.set_numerador(this->get_numerador()*F2.get_numerador());
    resultado.set_denominador(this->get_denominador()*F2.get_denominador());
    return resultado;
}

Fracao Fracao::operator*(int num)
{
    Fracao resultado;
    resultado.set_numerador(this->get_numerador()*num);
    resultado.set_denominador(this->get_denominador());
    return resultado;
}

Fracao operator*(int num, const Fracao F1)
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

bool Fracao::operator<(const Fracao &F2) const
{
    Fracao aux1 = *this;
    Fracao aux2 = F2;

    aux1.set_numerador(aux1.get_numerador()*aux2.get_denominador());

    aux2.set_numerador(aux2.get_numerador()*aux1.get_denominador());

    if(aux1.get_numerador() < aux2.get_numerador())
    {
        return true;
    }
    return false;
}


//Implementação das operações de entrada e saída de dados

ostream &operator<<(ostream &saida, const Fracao &f)
{
    saida << f.numerador << "/" << f.denominador;
    return saida;
}

istream &operator>>(istream &entrada, Fracao &f)
{
    entrada >> setw(1) >> f.numerador;
    entrada.ignore();
    entrada >> setw(1) >> f.denominador;
    return entrada;
}

//Implementação da operação -.

Fracao Fracao::operator-(const Fracao &f2)
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

Fracao Fracao::operator-(const int &num)
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

Fra