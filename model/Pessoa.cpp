#include "Pessoa.h"

void Pessoa::setcidade(System::String^ cidade)
{
	this->cidade = cidade;
}

void Pessoa::setuf(System::String^ uf)
{
	this->uf = uf;
}

void Pessoa::setcep(System::String^ cep)
{
	this->cep = cep;
}

void Pessoa::setddd(System::String^ ddd)
{
	this->ddd = ddd;
}

void Pessoa::settelefone(System::String^ telefone)
{
	this->telefone = telefone;
}

void Pessoa::setendereco(System::String^ endereco)
{
	this->endereco = endereco;
}

System::String^ Pessoa::getcpf()
{
	return cpf;
}

System::String^ Pessoa::getnome()
{
	return nome;
}

System::String^ Pessoa::getendereco()
{
	return endereco;
}

System::String^ Pessoa::getcidade()
{
	return cidade;
}

System::String^ Pessoa::getuf()
{
	return uf;
}

System::String^ Pessoa::getcep()
{
	return cep;
}

System::String^ Pessoa::getddd()
{
	return ddd;
}

System::String^ Pessoa::gettelefone()
{
	return telefone;
}