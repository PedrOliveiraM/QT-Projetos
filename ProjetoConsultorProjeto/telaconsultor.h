#ifndef TELACONSULTOR_H
#define TELACONSULTOR_H
#include "teladealteracoes.h"
#include "telainclusao.h"
#include "telaprojeto.h"
#include <QDialog>

namespace Ui {
class telaConsultor;
}

class telaConsultor : public QDialog
{
    Q_OBJECT

public:
    explicit telaConsultor(QWidget *parent = nullptr);
    ~telaConsultor();
    void mostrarDadosDosConsultores();

private slots:
    void on_pushButtonIncluir_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonAlterar_clicked();

    void on_pushButtonOrdenar_clicked();

private:
    Ui::telaConsultor *ui;
    telaDeAlteracoes *form2;
    TelaInclusao *form3;
    TelaProjeto *form4;
};

#endif // TELACONSULTOR_H
