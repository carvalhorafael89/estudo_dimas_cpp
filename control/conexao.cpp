#include <QtSql/QSqlDatabase>
#include "conexao.h"
//#include <QMessageBox>


void conectarsql::iniconexao()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions("SQL_ATTR_LOGIN_TIMEOUT=5");
    db.setDatabaseName("DRIVER={SQL Server Native Client 11.0};"
                       "SERVER=PROFCARVALHO\\SQLEXPRESS;"
                       "DATABASE=EMPRESA;"
                       "Trusted_Connection=yes;");

    if (db.open()) {
        conectarsql::status = "Conexão realizada com sucesso";
       // QMessageBox::information(nullptr, "Conexão Realizada", "Conexão com o servidor realizada com sucesso");

    } else {
        conectarsql::status = "Erro de conexão";
        //QMessageBox::critical(nullptr, "Erro de conexão", "Houve uma falha na conexão com o servidor");
    }

}

QString conectarsql::getstatus()
{
    return status;
}

void conectarsql::fecharconexao()
{
    QSqlDatabase conn;
    conn.close();
}
