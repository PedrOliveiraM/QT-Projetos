#ifndef DIALOGSTART_H
#define DIALOGSTART_H

#include "telaprincipal.h"
#include "telaprojeto.h"
#include <QDialog>

namespace Ui {
class DialogStart;
}

class DialogStart : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStart(QWidget *parent = nullptr);
    ~DialogStart();

private slots:
    void on_pushButtonConsultores_clicked();



    void on_pushButtonProjetos_clicked();

    void on_pushButtonSair_clicked();

private:
    Ui::DialogStart *ui;
    TelaProjeto *telaProjeto;
    TelaPrincipal *telaConsultor;
};

#endif // DIALOGSTART_H
