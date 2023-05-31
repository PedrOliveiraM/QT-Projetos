#include "telainclusao.h"
#include "ui_telainclusao.h"

TelaInclusao::TelaInclusao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaInclusao)
{
    ui->setupUi(this);
    //ui->lineEditNumero->setInputMask("99999-9999");
}

TelaInclusao::~TelaInclusao()
{
    delete ui;
}
void TelaInclusao::limparTela() const{
    ui->lineEditID->clear();
    ui->lineEditNome->clear();
    ui->lineEditEmail->clear();
    ui->lineEditDDI->clear();
    ui->lineEditDDD->clear();
    ui->lineEditNumero->clear();
    ui->lineEditEndereco->clear();
    ui->lineEditNumEnde->clear();
}

void TelaInclusao::on_pushButtonInclusao_clicked()
{
    try {
        ejm::ConsultorDAO aux;
        int id = ui->lineEditID->text().toInt();
        // ID == 0 || ID == JA EXISTE
        if (id == 0){
            limparTela();
            throw QString("ID TEM QUE SER DIFERENTE DE 0");
        }
        if (id == aux.consultarPorID(id).getID()){
            limparTela();
            throw QString("ID JÁ EXISTE");
        }
        QString nome = ui->lineEditNome->text();
        QString email = ui->lineEditEmail->text();
        int ddd = ui->lineEditDDD->text().toInt();
        int ddi = ui->lineEditDDI->text().toInt();
        int numero = ui->lineEditNumero->text().toLongLong();
        ejm::Telefone fone(ddi,ddd,numero);
        QString logradouro = ui->lineEditEndereco->text();
        int numeroEd = ui->lineEditNumEnde->text().toInt();

        ejm::Endereco endereco(logradouro,numeroEd);
        ejm::Consultor pessoa(id,nome,email,fone,endereco);
        ejm::ConsultorDAO cadConsultores;


        cadConsultores.incluir(pessoa);
        this->limparTela();

        QMessageBox::about(this,"INCLUSAO","INCLUSÃO CONCLUÍDA");
        close();

    }  catch (QString erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA - Inclusão",erro);
    }
}



