#ifndef TELADEALTERACOES_H
#define TELADEALTERACOES_H

#include <QDialog>

namespace Ui {
class telaDeAlteracoes;
}

class telaDeAlteracoes : public QDialog
{
    Q_OBJECT

public:
    explicit telaDeAlteracoes(QWidget *parent = nullptr);
    ~telaDeAlteracoes();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonSalvar_clicked();

private:
    Ui::telaDeAlteracoes *ui;

};

#endif // TELADEALTERACOES_H
