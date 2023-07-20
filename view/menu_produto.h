#ifndef MENU_PRODUTO_H
#define MENU_PRODUTO_H

#include <QWidget>

namespace Ui {
class menu_produto;
}

class menu_produto : public QWidget
{
    Q_OBJECT

public:
    explicit menu_produto(QWidget *parent = nullptr);
    ~menu_produto();

private slots:
    void on_btnconsultar_clicked();

    void on_actionbotao_incluir_triggered();

    void on_actionbotao_excluir_triggered();

    void on_actionbotao_sair_triggered();

private:
    Ui::menu_produto *ui;
};
#endif // MENU_PRODUTO_H
