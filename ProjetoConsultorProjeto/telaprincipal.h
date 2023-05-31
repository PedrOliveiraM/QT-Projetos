#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H
#include "telaconsultor.h"
#include "telaprojeto.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class TelaPrincipal; }
QT_END_NAMESPACE

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    TelaPrincipal(QWidget *parent = nullptr);
    ~TelaPrincipal();


private:


private slots:


    void on_actionInforma_oes_triggered();

    void on_actionSair_triggered();

    void on_pushButtonConsultores_clicked();

    void on_pushButtonProjetos_clicked();

    void on_pushButtonSair_clicked();

private:
    Ui::TelaPrincipal *ui;
    telaConsultor *TelaConsultor;
    TelaProjeto *TELAPROJETO;
    telaDeAlteracoes *telateste;
};
#endif // TELAPRINCIPAL_H
