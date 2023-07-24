#include <QSqlResult>
#include <QSqlQuery>
#include "daocliente.h"
#include "../model/Cliente.h"
#include "../control/conexao.h"
#include <QMessageBox>




Cliente *daocliente::consultar(QString cpf)
{

    Cliente *cliente = nullptr; // Inicializa o ponteiro como nulo

    //realizando a conexão
    conectarsql sqldb;
    sqldb.iniconexao();

    if(sqldb.getstatus() == "Conexão realizada com sucesso") //verifica se a conexão já está aberta
    {
        //preparando a query
        QSqlQuery query;
        query.prepare("SELECT * FROM CLIENTE WHERE CPF = (?)");

        //adicionando o valor do txtCodigo da Ui a query
        query.addBindValue(cpf);

        //executando a query
        if (query.exec()) {
            if (query.next()) {
                cliente = new Cliente(cpf, query.value(1).toString(), query.value(8).toDouble());
                cliente->setendereco(query.value(2).toString());
                cliente->setcidade(query.value(3).toString());
                cliente->setuf(query.value(4).toString());
                cliente->setcep(query.value(5).toString());
                cliente->setddd(query.value(6).toString());
                cliente->settelefone(query.value(7).toString());
                cliente->setlimitedisp(query.value(9).toDouble());
            }
        }
        // Retornar o ponteiro do Produto recém criado
        return (cliente);
    }else
    {
return nullptr;
    }
    return nullptr;
}

bool daocliente::incluir(Cliente cliente)
{
        QSqlQuery query;
        query.prepare("INSERT INTO CLIENTE (CPF, NOME, ENDERECO, CIDADE, UF, CEP, DDD, TELEFONE, LIMITECRED, LIMITEDISP) VALUES(?,?,?,?,?,?,?,?,?,?)");
        query.addBindValue(cliente.getcpf());
        query.addBindValue(cliente.getnome());
        query.addBindValue(cliente.getendereco());
        query.addBindValue(cliente.getcidade());
        query.addBindValue(cliente.getuf());
        query.addBindValue(cliente.getcep());
        query.addBindValue(cliente.getddd());
        query.addBindValue(cliente.gettelefone());
        query.addBindValue(cliente.getlimitecred());
        query.addBindValue(cliente.getlimitedisp());

        bool resultado = query.exec();

        return resultado;
}

bool daocliente::excluir(Cliente cliente)
{
        QSqlQuery query;
        query.prepare("DELETE FROM CLIENTE WHERE CPF = (?)");
        query.addBindValue(cliente.getcpf());

        bool resultado = query.exec();

        return resultado;
}

bool daocliente::alterar(Cliente cliente)
{
        QSqlQuery query;
        query.prepare("UPDATE CLIENTE SET NOME = ?, ENDERECO = ?, CIDADE = ?, UF = ?, CEP = ?, DDD = ?, TELEFONE = ?, LIMITECRED = ?, LIMITEDISP = ? WHERE CPF = ?");
        query.addBindValue(cliente.getnome());
        query.addBindValue(cliente.getendereco());
        query.addBindValue(cliente.getcidade());
        query.addBindValue(cliente.getuf());
        query.addBindValue(cliente.getcep());
        query.addBindValue(cliente.getddd());
        query.addBindValue(cliente.gettelefone());
        query.addBindValue(cliente.getlimitecred());
        query.addBindValue(cliente.getlimitedisp());
        query.addBindValue(cliente.getcpf());

        bool resultado = query.exec();

        return resultado;
}
