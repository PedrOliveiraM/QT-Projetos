#include "telainclusaop.h"
#include "ui_telainclusaop.h"

telaInclusaoP::telaInclusaoP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaInclusaoP)
{
    ui->setupUi(this);

    ejm::ConsultorDAO cadConsultores;
    std::list<ejm::Consultor> *listaDeConsultores = 0;
    listaDeConsultores = cadConsultores.listagem("ID");
    while (!listaDeConsultores->empty()){
        ejm::Consultor objConsultor = listaDeConsultores->front();
        listaDeConsultores->pop_front();
        ui->comboBox->addItem(objConsultor.getNomeCompleto());
    }
}

telaInclusaoP::~telaInclusaoP()
{
    delete ui;
}
void telaInclusaoP::limparTela() const{
    ui->lineEditIDprojeto->clear();
    ui->textEditDescricao->clear();
    ui->lineEditOrcamento->clear();
    ui->lineEditEndereco->clear();
    ui->lineEditNumEnde->clear();
}

void telaInclusaoP::on_pushButtonInclusao_clicked()
{
    try {
        ejm::ProjetoDAO aux;
        int id_Projeto = ui->lineEditIDprojeto->text().toInt();
        // ID == 0 || ID == JA EXISTE
        if (id_Projeto == 0){
            limparTela();
            throw QString("ID TEM QUE SER DIFERENTE DE 0");
        }
        if (id_Projeto == aux.consultarPorIDP(id_Projeto).getId_Projeto()){
            limparTela();
            throw QString("ID JÁ EXISTE");
        }
        QString descricao = ui->textEditDescricao->toPlainText();
        float orcamento = ui->lineEditOrcamento->text().toFloat();

        QString logradouro = ui->lineEditEndereco->text();
        int numeroEd = ui->lineEditNumEnde->text().toInt();
        QString consultor = ui->comboBox->currentText();


        ejm::Endereco endereco(logradouro,numeroEd);
        ejm::projeto project(id_Projeto,descricao,orcamento,endereco,consultor);
        ejm::ProjetoDAO cadProjeto;


        cadProjeto.incluirP(project);
        this->limparTela();

        QMessageBox::about(this,"INCLUSAO","INCLUSÃO CONCLUÍDA");
        close();
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }


}

