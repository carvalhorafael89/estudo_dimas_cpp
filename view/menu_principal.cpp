#include "menu_principal.h"
#include "ui_menu_principal.h"
#include <QDialog>
#include "../control/conexao.h"

menu_principal::menu_principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu_principal)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Pronto!");
}

menu_principal::~menu_principal()
{
    delete ui;
}


void menu_principal::on_actionSair_triggered()
{
    this->close();
}


void menu_principal::on_actionProdutos_triggered()
{
    janelaprod.show();
    this->destroy();
}

void menu_principal::on_actionClientes_triggered()
{
    janelacliente.show();
    this->destroy();
}

