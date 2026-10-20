#include "Funcionario.h"

int Funcionario::nTotalFuncionarios = 0;
int Funcionario::funcionariosAtivos = 0;

Funcionario::Funcionario(std::string nome, int salario, int quantidadeEmpresas) : sequencial(nTotalFuncionarios++)
{
    this->set_nome(nome);
    this->set_salario(salario);
    this->set_quantidadeEmpresas(quantidadeEmpresas);
    this->ptrEmpresas = new std::string[this->get_quantidadeEmpresas()];

    funcionariosAtivos++;
}

Funcionario::~Funcionario()
{
    delete [] this->ptrEmpresas;
    funcionariosAtivos--;
}

Funcionario::Funcionario(const Funcionario &F) : sequencial(F.get_sequencial())
{
    this->set_nome(F.get_nome());
    this->set_salario(F.get_salario());
    this->set_quantidadeEmpresas(F.get_quantidadeEmpresas());
    if(this->get_quantidadeEmpresas() > 0)
    {
        this ->ptrEmpresas = new std::string[this->get_quantidadeEmpresas()];
    }
    else
    {
        this->ptrEmpresas = nullptr;
    }
    std::string empresa;

    for(int i = 0; i < this->get_quantidadeEmpresas(); i++)
    {
        F.get_empresa(i, empresa);
        this->set_empresa(empresa, i);
    }
}

int Funcionario::get_nTotalFuncionarios()
{
    return nTotalFuncionarios;
}

int Funcionario::get_funcionariosAtivos()
{
    return funcionariosAtivos;
}

int Funcionario::get_sequencial() const
{
    return this->sequencial;
}

std::string Funcionario::get_nome() const
{
    return this->nome;
}

int Funcionario::get_salario() const
{
    return this->salario;
}

int Funcionario::get_quantidadeEmpresas() const
{
    return this->quantidadeEmpresas;
}

bool Funcionario::get_empresa(int indice, std::string &empresa) const
{
    if(indice >= this->get_quantidadeEmpresas() || indice < 0)
    {
        return false;
    }
    empresa = this->ptrEmpresas[indice];
    return true;
}

void Funcionario::set_nome(std::string nome)
{
    this->nome = nome;
}

void Funcionario::set_salario(int salario)
{
    this->salario = salario;
}

void Funcionario::set_quantidadeEmpresas(int quantidade)
{
    if(quantidade < 0)
    {
        this->quantidadeEmpresas = 0;
    }
    else
    {
        this->quantidadeEmpresas = quantidade;
    }
}

bool set_empresa(std::string empresa, int indice)
{
    if(indice >= this->get_quantidadeEmpresas() || indice < 0)
    {
        return false;
    }
    this->ptrEmpresas[indice] = empresa;
    return true;
}