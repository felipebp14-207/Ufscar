#ifndef PEDIDOS_H
#define PEDIDOS_H
#include <string>

class Pedido{
    static int ativos;
    static int quantidadeItens;
    static int nSequencial;

    const int sequencial;
    const std::string nome;
    const int quantidade;
    std::string *itens;

public:
    Pedido(std::string, int);
    Pedido(const Pedido &);
    ~Pedido();

    bool setItem(int, std::string);

    int getSequencial() const;
    std::string getNome() const;
    int getQuantidade() const;
    std::string getItem(int) const;

    static int getAtivos();
    static int getQuantidadeItens();
    static int getNumSequencial();
};


#endif