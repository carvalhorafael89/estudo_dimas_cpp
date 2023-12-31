#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <QMainWindow>
#include "menu_produto.h"
#include "menu_cliente.h"

namespace Ui {
class menu_principal;
}

class menu_principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu_principal(QWidget *parent = nullptr);
    ~menu_principal();

private slots:
    void on_actionSair_triggered();

    void on_actionProdutos_triggered();

    void on_actionClientes_triggered();

private:
    Ui::menu_principal *ui;
    menu_produto janelaprod;
    menu_cliente janelacliente;
};

#endif // MENU_PRINCIPAL_H
