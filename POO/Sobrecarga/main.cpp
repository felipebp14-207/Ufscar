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

/*Fracao operator*(int num, Fracao F1)
{
    return F1 * num;
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

    F4 = 2 * F4;
    F4.print();

    Fracao F5(1,5);
    F3 = ++F5;
    F3.print();

    cout << "Fracao 5:" << endl;
    F5.print();

    Fracao F6(1,5);
    F4 = F6++;
    F4.print();

    cout << "Fracao 6:" << endl;
    F6.print();

    /*F1.set_numerador(1);
    F1.set_denominador(2);

    F2.set_numerador(3);
    F2.set_denominador(2);*/
    F1.print();
    F2.print();

    //bool menor = F1<F2;

    cout << (F1<F2) << endl;

    cout << F1 << endl;

    return 0;
}