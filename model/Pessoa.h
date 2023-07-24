#pragma once
#include <QString>

class Pessoa
{
private:
    QString cpf;
    QString nome;
    QString endereco;
    QString cidade;
    QString uf;
    QString cep;
    QString ddd;
    QString telefone;

public:
    //constructor padrao
    //Pessoa(){}

	//construtor da classe Pessoa
    Pessoa(QString cpf, QString nome);

	//setters
    void setendereco(QString endereco);
    void setcidade(QString cidade);
    void setuf(QString uf);
    void setcep(QString cep);
    void setddd(QString ddd);
    void settelefone(QString telefone);

	//getters
    QString getcpf();
    QString getnome();
    QString getendereco();
    QString getcidade();
    QString getuf();
    QString getcep();
    QString getddd();
    QString gettelefone();
};		
