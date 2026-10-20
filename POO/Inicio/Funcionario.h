#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>

class Funcionario{
    static int nTotalFuncionarios;
    static int funcionariosAtivos;
    const int sequencial;
    std::string nome;
    int salario;
    int quantidadeEmpresas;
    std::string *ptrEmpresas;

public:
    Funcionario(std::string, int, int);
    ~Funcionario();
    Funcionario(const Funcionario&);

    static int get_nTotalFuncionarios();
    static int get_funcionariosAtivos();
    int get_sequencial() const;
    std::string get_nome() const;
    int get_salario() const;
    int get_quantidadeEmpresas() const;
    bool get_empresa(int, std::string&) const;

    void set_nome(std::string);
    void set_salario(int);
    void set_quantidadeEmpresas(int);
    bool set_empresa(std::string, int);
};

#endif