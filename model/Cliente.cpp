#include "Cliente.h"

using namespace std;

System::Double^ Cliente::getlimitecred()
{
	return limitecred;
}

System::Double^ Cliente::getlimitedisp()
{
	return limitedisp;
}

void Cliente::setlimitecred(System::Double^ limitecred)
{
	this->limitecred = limitecred;
}

void Cliente::setlimitedisp(System::Double^ limitedisp)
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