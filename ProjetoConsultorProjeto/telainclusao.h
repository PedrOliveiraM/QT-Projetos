#ifndef TELAINCLUSAO_H
#define TELAINCLUSAO_H
#include <QString>
#include <QMessageBox>
#include <consultordao.h>
#include <QDialog>

namespace Ui {
class TelaInclusao;
}

class TelaInclusao : public QDialog
{
    Q_OBJECT

public:
    explicit TelaInclusao(QWidget *parent = nullptr);
    ~TelaInclusao();
private:
    void limparTela() const;

private slots:
    void on_pushButtonInclusao_clicked();



private:
    Ui::TelaInclusao *ui;
};

#endif // TELAINCLUSAO_H
