#include <iostream>
#include "Fracao.h"
using namespace std;

/*Fracao operator*(Fracao F1, int num)
{
    Fracao resultado;
    resultado.set_numerador(F1.get_numerador()*num);
    resultado.set_denominador(F1.get_denominador());
    return resultado;
}*/

int main()
{
    Fracao F1;
    Fracao F2(2, 3);

    F1.print();
    F2.print();

    F1.set_denominador(0);
    F1.set_numerador(4);

    F1.print();

    Fracao F3;
    F3 = F1 * F2;
    F3.print();

    Fracao F4;
    F4 = F2 * 2;
    F4.print();

    return 0;
}