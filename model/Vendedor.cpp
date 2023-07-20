#include "Vendedor.h"

void Vendedor::settaxacomissao(double salariobase)
{
	System::Double resultado = (*taxacomicao / 100);
	this->taxacomicao = resultado;
}

void Vendedor::setsalariobase(double salariobase)
{
	this->salariobase = salariobase;
}
//getters

System::Double^ Vendedor::getsalariobase()
{
	return salariobase;
}

System::Double^ Vendedor::gettaxacomissao()
{
	System::Double^ resultado = *taxacomicao * 100;
	return resultado;
}

/*
void Vendedor::addpedido(Pedido pedido)
{
	pedidos.push_back(pedido);
	pedido.setvendedor(this);
}

void Vendedor::removepedido(Pedido pedido)
{
	pedidos.erase(pedido);
	if (pedidos.empty())
	{
		pedido.setvendedor(NULL);
	}
}
*/