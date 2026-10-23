
#include "Fracao.h"
#include <iostream>
using namespace std;

int main()
{
    // Declaração das variáveis para testes
    Fracao f1(1, 2);
    Fracao f2(4, 2);

    // Uso do operador >> e <<
    Fracao f3;
    cout << "Digite uma fracao (ex: 2/3): ";
    cin >> f3;

    // Uso do operador <<
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;

    // Uso do operador +
    Fracao f4 = f1 + f2;  // Fracao + Fracao
    f1 = f1 + 1;          // Fracao + int
    f3 = 3 + f3;          // int + Fracao

    // Uso do operador -
    f4 = f4 - f1;         // Fracao - Fracao
    f2 = f2 - 1;          // Fracao - int
    f3 = 2 - f3;          // int - Fracao

    // Uso do operador *
    f4 = f1 * f2;         // Fracao * Fracao
    f1 = f1 * 2;          // Fracao * int
    f3 = 3 * f3;          // int * Fracao

    // Uso do operador ++
    ++f1;                 // Pre-incremento
    f2++;                 // Pos-incremento

    // Uso do operador --
    --f1;                 // Pre-decremento
    f2--;                 // Pos-decremento

    // Uso do operador <
    cout << (f1 < f2) << endl;  // Fracao < Fracao
    cout << (f1 < 2) << endl;   // Fracao < int
    cout << (2 < f1) << endl;   // int < Fracao

    // Uso do operador >
    cout << (f1 > f2) << endl;  // Fracao > Fracao
    cout << (f1 > 2) << endl;   // Fracao > int
    cout << (2 > f1) << endl;   // int > Fracao

    // Uso do operador ==
    cout << (f1 == f2) << endl; // Fracao == Fracao
    cout << (f1 == 2) << endl;  // Fracao == int
    cout << (2 == f1) << endl;  // int == Fracao

    // Uso do operador !=
    cout << (f1 != f2) << endl; // Fracao != Fracao
    cout << (f1 != 2) << endl;  // Fracao != int
    cout << (2 != f1) << endl;  // int != Fracao

    // Uso do operador <=
    cout << (f1 <= f2) << endl; // Fracao <= Fracao
    cout << (f1 <= 2) << endl;  // Fracao <= int
    cout << (2 <= f1) << endl;  // int <= Fracao

    // Uso do operador >=
    cout << (f1 >= f2) << endl; // Fracao >= Fracao
    cout << (f1 >= 2) << endl;  // Fracao >= int
    cout << (2 >= f1) << endl;  // int >= Fracao

    // Exibição dos valores finais
    cout << "\nValores finais:" << endl;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;
    cout << "f4 = " << f4 << endl;

    return 0;
}
