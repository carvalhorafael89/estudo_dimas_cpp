#include "Pessoa.h"
#include <QString>

Pessoa::Pessoa(QString cpf, QString nome)
{
    this->cpf = cpf;
    this->nome = nome;
}

void Pessoa::setcidade(QString cidade)
{
    this->cidade = cidade;
}

void Pessoa::setuf(QString uf)
{
	this->uf = uf;
}

void Pessoa::setcep(QString cep)
{
	this->cep = cep;
}

void Pessoa::setddd(QString ddd)
{
	this->ddd = ddd;
}

void Pessoa::settelefone(QString telefone)
{
	this->telefone = telefone;
}

void Pessoa::setendereco(QString endereco)
{
	this->endereco = endereco;
}

QString Pessoa::getcpf()
{
	return cpf;
}

QString Pessoa::getnome()
{
	return nome;
}

QString Pessoa::getendereco()
{
	return endereco;
}

QString Pessoa::getcidade()
{
    return cidade;
}

QString Pessoa::getuf()
{
	return uf;
}

QString Pessoa::getcep()
{
	return cep;
}

QString Pessoa::getddd()
{
	return ddd;
}

QString Pessoa::gettelefone()
{
	return telefone;
}
