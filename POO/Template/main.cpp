#include <iostream>
using namespace std;

template <typename T>

void printArray(const T* Ptr, const int tam)
{
    cout << endl;
    for(int i = 0; i < tam; i++)
    {
        cout << "Elemento " << i+1 << ": " << Ptr[i] << endl;
    }
    cout << endl;
}

int main()
{
    int tamanhoI, tamanhoC;

    cout << "Digite o tamanho do array de inteiros:" << endl;
    cin >> tamanhoI;

    int *ptr = new int[tamanhoI];

    for(int i = 0; i < tamanhoI; i++)
    {
        cout << "Digite o inteiro " << i+1 << ":" << endl;
        cin >> ptr[i];
    }

    printArray(ptr, tamanhoI);

    delete [] ptr;

    cout << "Digite o tamanho do array de caracteres:" << endl;
    cin >> tamanhoC;

    char *PtrC = new char[tamanhoC];

    for(int i = 0; i < tamanhoC; i++)
    {
        cout << "Digite o caracter " << i+1 << ":" << endl;
        cin >> PtrC[i];
    }

    printArray(PtrC, tamanhoC);

    delete [] PtrC;

    return 0;
}