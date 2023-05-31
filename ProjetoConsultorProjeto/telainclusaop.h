#ifndef TELAINCLUSAOP_H
#define TELAINCLUSAOP_H
#include <QMessageBox>
#include "projeto.h"
#include <projetodao.h>
#include <IProjetoCRUD.h>
#include <QDialog>

namespace Ui {
class telaInclusaoP;
}

class telaInclusaoP : public QDialog
{
    Q_OBJECT

public:
    explicit telaInclusaoP(QWidget *parent = nullptr);
    ~telaInclusaoP();
private:
    void limparTela() const;

private slots:
    void on_pushButtonInclusao_clicked();

private:
    Ui::telaInclusaoP *ui;
};

#endif // TELAINCLUSAOP_H
