#pragma once
#include <QString>

class Produto
{
private:
    //atributos
    QString codigo;
    QString descricao;
    int qtdeestoque;
    QString unidademedida;
    double preco;
    int estoqueminimo;

public:
    //construtor
    Produto(QString codigo, QString descricao)
    {
        this->codigo = codigo;
        this->descricao =descricao;
    }

    //getters
    QString getcodigo();
    QString getdescricao();
    int getqtdeestoque();
    QString getunidademedida();
    double getpreco();
    int getestoqueminimo();

    //setters
    void setestoqueminimo(int estoqueminimo);
    void setdescricao(QString descricao);
    void setqtdeestoque(int qtdeestoque);
    void setunidademedida(QString unidademedida);
    void setpreco(double preco);
};
