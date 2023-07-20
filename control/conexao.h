#pragma once
#include <Qstring>

class conectarsql
{
private:
    QString status;

public:
    //construtor
    conectarsql() {}

    void iniconexao();
    void fecharconexao();
    QString getstatus();

};
