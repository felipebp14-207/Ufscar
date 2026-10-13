#include <iostream>
#include "Fracao.h"
using namespace std;

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

    return 0;
}