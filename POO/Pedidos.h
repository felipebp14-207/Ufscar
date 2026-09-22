#ifndef PROJETO_H
#define PROJETO_H

#include <string>

class Pedido{
    static int quantItens;
    static int ativos;
    static int nSequencial;
    const int sequencial;
    std::string nome;
    int quantidade;
    std::string *itens;

public:
    Pedido(std::string, int);
    Pedido(const Pedido&);
    ~Pedido();

    bool setItem(std::string, int);

    std::string getNome() const;
    int getQuantidade() const;
    std::string getItem(int) const;
    int getSequencial() const;
    static int getnSequencial();
    static int getAtivos();
    static int quantidadeItens();
};

#endif
