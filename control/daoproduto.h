#pragma once
#include "../model/Produto.h"

class daoproduto
{
private:


public:
    daoproduto() {}
    Produto* consultar(QString codigo);
    bool incluir(Produto produto);
    bool alterar(Produto produto);
    bool excluir(Produto produto);
};
