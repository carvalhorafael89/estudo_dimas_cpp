#include "menu_produto.h"
#include "ui_menu_produto.h"
#include "../control/daoproduto.h"
#include "../model/Produto.h"
#include <QMessageBox>
#include "menu_principal.h"
#include <QStatusBar>
#include <QWidget>
#include "../control/conexao.h"
menu_produto::menu_produto(QWidget *parent) : QWidget(parent), ui(new Ui::menu_produto)
{
    ui->setupUi(this);
    conectarsql sql;
    sql.iniconexao();
    ui->txtStatus->setText(sql.getstatus());
}

menu_produto::~menu_produto()
{
    delete ui;
}

void menu_produto::on_btnconsultar_clicked()
{
    Produto *produto = nullptr;
    daoproduto dao;
    produto = dao.consultar(ui->txtCodigo->text());

    if(produto == NULL) //não possui o item no banco de dados
    {
        //mudar as caixas de texto - SetEnable
        ui->txtCodigo->setEnabled(false);
        ui->txtDescricao->setEnabled(true);
        ui->txtEstoquemin->setEnabled(true);
        ui->txtEstoquemin->setEnabled(true);
        ui->txtPreco->setEnabled(true);
        ui->txtqtDisp->setEnabled(true);
        //mudar os botoes
        ui->btnconsultar->setEnabled(false);
        ui->btnincluir->setEnabled(true);
        ui->btnexcluir->setEnabled(true);
        //alterar status para
        ui->txtStatus->setText("Produto não encontrado, insira as informações para realizar o cadastro");
    }else //possui o item no banco de dados
    {
        //mudar as caixas de texto - SetEnable
        ui->txtCodigo->setEnabled(false);
        ui->txtDescricao->setEnabled(true);
        ui->txtEstoquemin->setEnabled(true);
        ui->txtPreco->setEnabled(true);
        ui->txtqtDisp->setEnabled(true);
        //inserir dados nas caixas de texto
        ui->txtDescricao->setText(produto->getdescricao());
        ui->txtEstoquemin->setText(QString::number(produto->getestoqueminimo()));
        ui->txtPreco->setText(QString::number(produto->getpreco()));
        ui->txtqtDisp->setText(QString::number(produto->getqtdeestoque()));
        //mudar os botoes
        ui->btnconsultar->setEnabled(false);
        ui->btnincluir->setEnabled(false);
        ui->btnexcluir->setEnabled(true);
        ui->btnalterar->setEnabled(true);
        //alterar status para
        ui->txtStatus->setText("Produto encontrado, Clique nos botões 'alterar' ou 'excluir' para alterar ou excluir o produto");
    }
}

void menu_produto::on_actionbotao_incluir_triggered()
{
    daoproduto dao;

    Produto produto(ui->txtCodigo->text(), ui->txtDescricao->text());
    produto.setqtdeestoque(ui->txtEstoquemin->text().toDouble());
    produto.setpreco(ui->txtPreco->text().toDouble());
    produto.setestoqueminimo(ui->txtEstoquemin->text().toDouble());

    if(dao.incluir(produto))
    {
        QMessageBox::information(nullptr, "Concluído", "Produto inserido com sucesso!");
    }else
    {
        QMessageBox::critical(nullptr, "Erro!", "Falha ao inserir produto!");
    }
}

void menu_produto::on_actionbotao_excluir_triggered()
{
    Produto produto(ui->txtCodigo->text(), ui->txtDescricao->text());
    daoproduto dao;
    if(dao.excluir(produto))
    {
        QMessageBox::information(nullptr, "Concluído", "Produto excluído com sucesso!");
    }else
    {
        QMessageBox::critical(nullptr, "Erro!", "Falha ao excluir produto!");
    }
}


void menu_produto::on_actionbotao_sair_triggered()
{

    menu_principal *janelaprinc = new menu_principal;
    this->close();
    janelaprinc->show();
    this->destroy();
}

