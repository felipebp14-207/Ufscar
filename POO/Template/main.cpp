#include <iostream>
#include "Vetor.h"
using namespace std;

int main()
{
    Vetor <int> pares;

    int i = 0;
    while(pares.set_elemento(i, i*2))
    {
        i++;
    }

    i = 0;
    int aux;
    while(pares.get_elemento(i, aux))
    {
        cout << "Elemento " << i << ": " << aux << endl;
        i++;
    }
    
    return 0;
}