#include <QSqlResult>
#include <QSqlQuery>
#include "daoproduto.h"
#include "../model/Produto.h"
#include "../control/conexao.h"



Produto *daoproduto::consultar(QString codigo)
{
    Produto *p = nullptr; // Inicializa o ponteiro como nulo

    //realizando a conexão
    conectarsql sqldb;
    sqldb.iniconexao();

    if(sqldb.getstatus() == "Conexão realizada com sucesso") //verifica se a conexão já está aberta
        {
        //preparando a query
        QSqlQuery query;
        query.prepare("SELECT * FROM PRODUTO WHERE CODIGO = (?)");

        //adicionando o valor do txtCodigo da Ui a query
        query.addBindValue(codigo);

        //executando a query
        if (query.exec()) {
            if (query.next()) {
                //QString descricao = query.value(1).toString();
                p = new Produto(codigo, query.value(1).toString());
                p->setqtdeestoque(query.value(2).toInt());
                p->setpreco(query.value(3).toDouble());
                p->setestoqueminimo(query.value(4).toInt());
            }
        }
        // Retornar o ponteiro do Produto recém criado
        return p;
    }else
    {
        return nullptr;
    }
}

bool daoproduto::incluir(Produto produto)
{
        QSqlQuery query;
        query.prepare("INSERT INTO PRODUTO (CODIGO, DESCRICAO, QTDISPONIVEL, PRECOUNIT, ESTOQUEMIN) VALUES(?,?,?,?,?)");
        query.addBindValue(produto.getcodigo());
        query.addBindValue(produto.getdescricao());
        query.addBindValue(produto.getqtdeestoque());
        query.addBindValue(produto.getpreco());
        query.addBindValue(produto.getestoqueminimo());

        bool resultado = query.exec();

        return resultado;
}

bool daoproduto::excluir(Produto produto)
{
        QSqlQuery query;
        query.prepare("DELETE FROM PRODUTO WHERE CODIGO = (?)");
        query.addBindValue(produto.getcodigo());

        bool resultado = query.exec();

        return resultado;
}

bool daoproduto::alterar(Produto produto)
{
        QSqlQuery query;
        query.prepare("UPDATE PRODUTO SET DESCRICAO = ?, QTDISPONIVEL = ?, PRECOUNIT = ?, ESTOQUEMIN = ? WHERE CODIGO = ?");
        query.addBindValue(produto.getdescricao());
        query.addBindValue(produto.getqtdeestoque());
        query.addBindValue(produto.getpreco());
        query.addBindValue(produto.getestoqueminimo());
        query.addBindValue(produto.getcodigo());

        bool resultado = query.exec();

        return resultado;
}
