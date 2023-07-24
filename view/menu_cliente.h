#ifndef MENU_CLIENTE_H
#define MENU_CLIENTE_H

#include <QMainWindow>

namespace Ui {
class menu_cliente;
}

class menu_cliente : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu_cliente(QWidget *parent = nullptr);
    ~menu_cliente();

private slots:
    void on_actionbtnconsultar_triggered();

    void on_actionbtnincluir_triggered();

    void on_actionbtnexcluir_triggered();

    void on_actionbtnsair_triggered();

    void on_actionbtnalterar_triggered();

    void limpar_pesquisa();

private:
    Ui::menu_cliente *ui;
};

#endif // MENU_CLIENTE_H
