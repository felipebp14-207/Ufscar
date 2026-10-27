#include "Ponto.h"
#include <iostream>

Ponto::Ponto(int x, int y)
{
    setX(x);
    setY(y);
}

void Ponto::setX(int x)
{
    this->x = x;
}

int Ponto::getX() const
{
    return x;
}

void Ponto::setY(int y)
{
    this->y = y;
}

int Ponto::getY() const
{
    return y;
}

void Ponto::print() const
{
    std::cout << "Ponto( " << getX() << ", " << getY() << ")" << std::endl;
}