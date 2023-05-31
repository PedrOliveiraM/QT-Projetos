#ifndef TELAPROJETO_H
#define TELAPROJETO_H
#include "telaalteracaop.h"
#include "telainclusaop.h"
#include <QDialog>
#include <QMessageBox>
namespace Ui {
class TelaProjeto;
}

class TelaProjeto : public QDialog
{
    Q_OBJECT

public:
    explicit TelaProjeto(QWidget *parent = nullptr);
    ~TelaProjeto();

    void mostrarDadosDosProjetos() const;

private:


private slots:
    void on_pushButtonIncluir_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonAlterar_clicked();

private:
    Ui::TelaProjeto *ui;
    telaInclusaoP *TelaIP;
    telaAlteracaoP *TelaAlt;
};

#endif // TELAPROJETO_H
