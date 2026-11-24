#ifndef VETOR_H
#define VETOR_H

template <class T>

class Vetor{
    int tamanho;
    T* Ptr;
public:
    Vetor(int = 3);
    ~Vetor();
    Vetor(const Vetor&);

    int get_tamanho() const;
    bool get_elemento(int, T&) const;
    bool set_elemento(int, T);
};

    template <class T>
    Vetor<T>::Vetor(int tam)
    {
        if(tam > 0)
        {
            tamanho = tam;
        }
        else
        {
            tamanho = 3;
        }
        Ptr = new T [tamanho];
    }

    template <class T>
    Vetor<T>::~Vetor()
    {
        delete [] Ptr;
    }

    template <class T>
    Vetor<T>::Vetor(const Vetor<T> &copia)
    {
        this->tamanho = copia.get_tamanho();
        this->Ptr = new T [this->get_tamanho()];

        T aux;
        for(int i = 0; i < this->get_tamanho(); i++)
        {
            copia.get_elemento(i, aux);
            this->Ptr[i] = aux;
        }
    }

    template <class T>
    int Vetor<T>::get_tamanho() const
    {
        return tamanho;
    }

    template <class T>
    bool Vetor<T>::get_elemento(int indice, T &elemento) const
    {
        if(indice < 0 || indice >= tamanho)
        {
            return false;
        }
        elemento = Ptr[indice];
        return true;
    }

    template <class T>
    bool Vetor<T>::set_elemento(int indice, T elemento)
    {
        if(indice < 0 || indice >= tamanho)
        {
            return false;
        }
        Ptr[indice] = elemento;
        return true;
    }

#endif