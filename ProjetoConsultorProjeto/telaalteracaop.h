#ifndef TELAALTERACAOP_H
#define TELAALTERACAOP_H
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class telaAlteracaoP;
}

class telaAlteracaoP : public QDialog
{
    Q_OBJECT

public:
    explicit telaAlteracaoP(QWidget *parent = nullptr);
    ~telaAlteracaoP();

private slots:
    void on_pushButtonMostrarProjeto_clicked();

    void on_pushButtonSalvar_clicked();

    void on_pushButtonInfo_clicked();

private:
    Ui::telaAlteracaoP *ui;
};

#endif // TELAALTERACAOP_H
