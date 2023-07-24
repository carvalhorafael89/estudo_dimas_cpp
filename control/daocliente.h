#pragma once
#include "../model/Cliente.h"

class daocliente
{
private:


public:
    daocliente() {}
    Cliente* consultar(QString cpf);
    bool incluir(Cliente cliente);
    bool alterar(Cliente cliente);
    bool excluir(Cliente cliente);
};
