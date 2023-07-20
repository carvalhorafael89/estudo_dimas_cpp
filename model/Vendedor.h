#pragma once
#include "Pessoa.h"
#include <QString>


class Vendedor : public Pessoa
{
private:
    double salariobase;
    double taxacomicao;
	//System::Collections::Generic::List<pedido>^ pedidos;

public:
	//construtor
    Vendedor(QString cpf, QString nome, double salariobase)
	{
		this->salariobase = salariobase;
		//pedidos = gcnew System::Collections::Generic::List<pedido>();
	}
	//setters
	void settaxacomissao(double salariobase);
	void setsalariobase(double salariobase);
	//getters
    double getsalariobase();
    double gettaxacomissao();
	//void addpedido(Pedido p);
	//void removepedido(Pedido pedido);
};

