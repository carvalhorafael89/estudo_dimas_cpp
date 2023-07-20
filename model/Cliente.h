#pragma once
#include "Pessoa.h"
#include <QString>


class Cliente : public Pessoa
{
private:
    double limitecred;
    double limitedisp;

public:
	//construtor
    Cliente(QString cpf, QString nome, double limitecred)
	{
		this->limitecred = limitecred;
		this->limitedisp = limitecred;

    }

    double getlimitecred();
    double getlimitedisp();
    void setlimitecred(double limitecred);
    void setlimitedisp(double limitedisp);
	//void addpedido(pedido pedido);
	//void removepedido(pedido pedido);
};
