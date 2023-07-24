#include "menu_cliente.h"
#include "ui_menu_cliente.h"
#include "../model/Cliente.h"
#include "../control/daocliente.h"
#include "../control/conexao.h"
#include <QMessageBox>
#include "menu_principal.h"

//#include <QWidget>

menu_cliente::menu_cliente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu_cliente)
{
    ui->setupUi(this);
}

menu_cliente::~menu_cliente()
{
    delete ui;
}

void menu_cliente::on_actionbtnconsultar_triggered()
{
    Cliente *cliente = nullptr;
    daocliente dao;
    cliente = dao.consultar(ui->txtcpf->text());

    if(cliente == nullptr) //não possui o item no banco de dados
    {
        //mudar as caixas de texto - SetEnable
        ui->txtcpf->setEnabled(false);
        ui->txtnome->setEnabled(true);
        ui->txtendereco->setEnabled(true);
        ui->txtcidade->setEnabled(true);
        ui->cbxuf->setEnabled(true);
        ui->txtcep->setEnabled(true);
        ui->txtddd->setEnabled(true);
        ui->txttelefone->setEnabled(true);
        ui->txtlimcred->setEnabled(true);
        ui->txtlimdisp->setEnabled(true);
        //mudar os botoes
        ui->btnconsultar->setEnabled(false);
        ui->btnincluir->setEnabled(true);
        ui->btnexcluir->setEnabled(true);
        //alterar status para
        ui->statusbar->showMessage("Cliente não encontrado, insira as informações para realizar o cadastro");
    }else //possui o item no banco de dados
    {
        //mudar as caixas de texto - SetEnable
        ui->txtcpf->setEnabled(false);
        ui->txtnome->setEnabled(true);
        ui->txtendereco->setEnabled(true);
        ui->txtcidade->setEnabled(true);
        ui->cbxuf->setEnabled(true);
        ui->txtcep->setEnabled(true);
        ui->txtddd->setEnabled(true);
        ui->txttelefone->setEnabled(true);
        ui->txtlimcred->setEnabled(true);
        ui->txtlimdisp->setEnabled(true);
        //inserir dados nas caixas de texto
        ui->txtnome->setText(cliente->getnome());
        ui->txtendereco->setText(cliente->getendereco());
        ui->txtcidade->setText(cliente->getcidade());
        ui->cbxuf->setCurrentIndex(cliente->getuf().toInt());
        ui->txtcep->setText(cliente->getcep());
        ui->txtddd->setText(cliente->getddd());
        ui->txttelefone->setText(cliente->gettelefone());
        ui->txtlimcred->setText(QString::number(cliente->getlimitecred()));
        ui->txtlimdisp->setText(QString::number(cliente->getlimitedisp()));
        //mudar os botoes
        ui->btnconsultar->setEnabled(false);
        ui->btnincluir->setEnabled(false);
        ui->btnexcluir->setEnabled(true);
        ui->btnalterar->setEnabled(true);
        //alterar status para
        ui->statusbar->showMessage("Cliente encontrado, Clique nos botões 'alterar' ou 'excluir' para alterar ou excluir o cliente");
    }
}

void menu_cliente::on_actionbtnincluir_triggered()
{
    daocliente dao;

    Cliente cliente(ui->txtcpf->text(), ui->txtnome->text(), ui->txtlimcred->text().toDouble());
    cliente.setendereco(ui->txtendereco->text());
    cliente.setcidade(ui->txtcidade->text());
    cliente.setuf(QString::number(ui->cbxuf->currentIndex()));
    cliente.setcep(ui->txtcep->text());
    cliente.setddd(ui->txtddd->text());
    cliente.settelefone(ui->txttelefone->text());
    cliente.setlimitedisp(ui->txtlimdisp->text().toDouble());



    if (QMessageBox::question(this,"Confirmação", "Deseja incluir este cliente?", "Sim", "Não") == 0)
        {

            if(dao.incluir(cliente))
            {
                QMessageBox::information(this, "Concluído", "Cliente inserido com sucesso!");
                    menu_cliente::limpar_pesquisa();
            }else{
                QMessageBox::critical(this, "Erro!", "Falha ao inserir cliente!");
                menu_cliente::limpar_pesquisa();
            }
        } else {
            ui->statusbar->showMessage("Por favor, confirme os dados do cliente antes de confirmar cadastro");
        }
}

void menu_cliente::on_actionbtnexcluir_triggered()
{

    Cliente cliente(ui->txtcpf->text(), ui->txtnome->text(), ui->txtlimcred->text().toDouble());

    daocliente dao;

    if(dao.excluir(cliente))
    {
        QMessageBox::information(nullptr, "Concluído", "Cliente excluído com sucesso!");
        menu_cliente::limpar_pesquisa();
    }else
    {
        QMessageBox::critical(nullptr, "Erro!", "Falha ao excluir cliente!");
    }
}


void menu_cliente::on_actionbtnsair_triggered()
{
    menu_principal *janelaprinc = new menu_principal;
    this->close();
    janelaprinc->show();
    this->destroy();
}


void menu_cliente::on_actionbtnalterar_triggered()
{
    Cliente cliente(ui->txtcpf->text(), ui->txtnome->text(), ui->txtlimcred->text().toDouble());
    cliente.setendereco(ui->txtendereco->text());
    cliente.setcidade(ui->txtcidade->text());
    cliente.setuf(QString::number(ui->cbxuf->currentIndex()));
    cliente.setcep(ui->txtcep->text());
    cliente.setddd(ui->txtddd->text());
    cliente.settelefone(ui->txttelefone->text());
    cliente.setlimitecred(ui->txtlimcred->text().toDouble());
    cliente.setlimitedisp(ui->txtlimdisp->text().toDouble());

    daocliente dao;
    if(dao.alterar(cliente))
    {
        QMessageBox::information(nullptr, "Concluído", "Cliente alterado com sucesso!");
            menu_cliente::limpar_pesquisa();
    }else
    {
        QMessageBox::critical(nullptr, "Erro!", "Falha ao alterar cliente!");
    }
}

void menu_cliente::limpar_pesquisa()
{
    //mudar as caixas de texto - SetEnable
    ui->txtcpf->setEnabled(true);
    ui->txtnome->setEnabled(false);
    ui->txtendereco->setEnabled(false);
    ui->txtcidade->setEnabled(false);
    ui->cbxuf->setEnabled(false);
    ui->txtcep->setEnabled(false);
    ui->txtddd->setEnabled(false);
    ui->txttelefone->setEnabled(false);
    ui->txtlimcred->setEnabled(false);
    ui->txtlimdisp->setEnabled(false);
    //inserir dados nas caixas de texto
    ui->txtcpf->setText(NULL);
    ui->txtnome->setText(NULL);
    ui->txtendereco->setText(NULL);
    ui->txtcidade->setText(NULL);
    ui->cbxuf->setCurrentIndex(0);
    ui->txtcep->setText(NULL);
    ui->txtddd->setText(NULL);
    ui->txttelefone->setText(NULL);
    ui->txtlimcred->setText(NULL);
    ui->txtlimdisp->setText(NULL);
    //mudar os botoes
    ui->btnconsultar->setEnabled(true);
    ui->btnincluir->setEnabled(false);
    ui->btnexcluir->setEnabled(false);
    ui->btnalterar->setEnabled(false);
    //alterar status para
    ui->statusbar->showMessage("Insira o CPF e digite em 'Consultar' para realizar uma consulta de um cliente!");
}

