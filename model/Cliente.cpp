#include "Cliente.h"

Cliente::Cliente(QString cpf, QString nome, double limitecred)
    : Pessoa(cpf, nome) // Chama o construtor da classe Pessoa com os parâmetros cpf e nome
{
    this->limitecred = limitecred;
    this->limitedisp = limitecred;
}

double Cliente::getlimitecred()
{
	return limitecred;
}

double Cliente::getlimitedisp()
{
	return limitedisp;
}

void Cliente::setlimitecred(double limitecred)
{
    this->limitecred = limitecred;
}

void Cliente::setlimitedisp(double limitedisp)
{
	this->limitedisp = limitedisp;
}


/*
void Cliente::addpedido(Pedido pedido)
{
	pedidos.push_back(pedido);
	pedido.setcliente(this);
}


void Cliente::removepedido(Pedido pedido)
{
	pedidos.erase(pedido);
	if (pedidos.empty())
	{
		pedido.setcliente(NULL);
	}
}
*/
