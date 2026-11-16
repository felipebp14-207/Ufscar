#include <iostream>
using namespace std;

class Animal{
    int x;
    int y;

public:
    Animal(){
        x = 0;
        y = 0;
    }

    Animal(int x, int y)
    {
        setX(x);
        setY(y);
    }

    int getX() const{
        return x;
    }

    int getY() const{
        return y;
    }

    void setX(int num)
    {
        x = num;
    }

    void setY(int num)
    {
        y = num;
    }

    virtual void falar() const{
        cout << "Sou um animal e nao falo" << endl;
    }
};

class Cachorro : public Animal{
public:
    Cachorro():Animal() {}

    Cachorro(int x, int y):Animal(x, y) {}

    void falar() const override{
        cout << "Au au" << endl;
    }
};

class Gato : public Animal{
public:
    Gato():Animal() {}

    Gato(int x, int y):Animal(x, y) {}

    void falar() const override{
        cout << "Miau miau" << endl;
    }
};

class Ovelha : public Animal{
public:
    Ovelha():Animal(){}

    Ovelha(int x, int y) : Animal(x, y) {}

    void falar() const override{
        cout << "Bee bee" << endl;
    }
};

int main(){
    Animal *vetor[10] = {NULL};

    vetor[0] = new Cachorro (1,2);
    vetor[1] = new Gato (1,3);
    vetor[2] = new Ovelha (6,7);
    vetor[3] = new Animal;

    for(int i = 0; i < 10; i++)
    {
        if(vetor[i] != NULL)
        {
            cout << "Posicao e: " << "(" << vetor[i]->getX() << ", " << vetor[i]->getY() << ")" << endl;
            vetor[i]->falar();
        }
    }

    for(int i = 0; i < 10; i++)
    {
        delete vetor[i];
    }
    
    return 0;
}