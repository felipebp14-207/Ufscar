#include "Projeto.h"
#include <string>

int Pedido::nSequencial = 1;

int Pedido::ativos = 0;

int Pedido::quantItens = 0;

int Pedido::getnSequencial()
{
    return nSequencial;
}

int Pedido::getAtivos()
{
    return ativos;
}

int Pedido::quantidadeItens()
{
    return quantItens;
}

Pedido::Pedido(std::string nome, int quantidade) : sequencial(nSequencial++)
{
    this->nome = nome;
    this->quantidade = quantidade;
    this->itens = new std::string[quantidade];
    ativos++;
    quantItens +=quantidade;
}

Pedido::Pedido(const Pedido& outro)
    : sequencial(nSequencial++)
{
    nome = outro.nome;
    quantidade = outro.quantidade;

    itens = new std::string[quantidade];

    for(int i = 0; i < quantidade; i++)
    {
        itens[i] = outro.itens[i];
    }

    ativos++;
    quantItens += quantidade;
}

Pedido::~Pedido()
{
    delete [] this->itens;
    ativos--;
    quantItens -=this->quantidade;
}

bool Pedido::setItem(std::string item, int indice)
{
    if(indice >= this->quantidade || indice < 0)
    {
        return false;
    }
    else
    {
        this->itens[indice] = item;
        return true;
    }
}

std::string Pedido::getNome() const
{
    return this->nome;
}

int Pedido::getQuantidade() const
{
    return this->quantidade;
}

std::string Pedido::getItem(int indice) const
{
    if(indice >= this->quantidade || indice < 0)
    {
        return "ERRO!"
    }
    else
    {
        return this->itens[indice];
    }
}
int Pedido::getnSequencial() const
{
    return this->sequencial;
}
