#include "Produto.h"
#include <QString>

QString Produto::getcodigo()
{
    return codigo;
}

QString Produto::getdescricao()
{
    return descricao;
}

int Produto::getqtdeestoque()
{
    return qtdeestoque;
}

QString Produto::getunidademedida()
{
    return unidademedida;
}

double Produto::getpreco()
{
    return preco;
}

int Produto::getestoqueminimo()
{
    return estoqueminimo;
}

void Produto::setestoqueminimo(int estoqueminimo)
{
    this->estoqueminimo = estoqueminimo;
}

void Produto::setdescricao(QString descricao)
{
    this->descricao = descricao;
}

void Produto::setqtdeestoque(int qtdeEstoque)
{
    this->qtdeestoque = qtdeEstoque;
}

void Produto::setunidademedida(QString unidademedida)
{
    this->unidademedida = unidademedida;
}

void Produto::setpreco(double preco)
{
    this->preco = preco;
}
