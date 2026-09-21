#include "Pedidos.h"

int Pedido::ativos = 0;
int Pedido::quantidadeItens = 0;
int Pedido::nSequencial = 1;

Pedido::Pedido(std::string nome, int quantidade) 
: sequencial(nSequencial), nome(nome), quantidade(quantidade)
{
    itens = new std::string[quantidade];
    ativos++;
    quantidadeItens+=quantidade;
    nSequencial++;
}