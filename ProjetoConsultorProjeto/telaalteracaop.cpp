#include "telaalteracaop.h"
#include "projeto.h"
#include "projetodao.h"
#include "ui_telaalteracaop.h"

telaAlteracaoP::telaAlteracaoP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaAlteracaoP)
{
    ui->setupUi(this);
    ui->lineEditIDprojeto->setEnabled(false);
    ejm::ProjetoDAO cadProjetos;
    std::list<ejm::projeto> *listaDeprojetos = 0;
    listaDeprojetos = cadProjetos.listagemP();
    while (!listaDeprojetos->empty()){
        ejm::projeto objProjeto = listaDeprojetos->front();
        listaDeprojetos->pop_front();
        ui->comboBox->addItem(QString::number(objProjeto.getId_Projeto()));

    }
}

telaAlteracaoP::~telaAlteracaoP()
{
    delete ui;
}

void telaAlteracaoP::on_pushButtonMostrarProjeto_clicked()
{
    try {
        ejm::ProjetoDAO project; // criei um objeto
        ejm::projeto AUX;

        //int id = ui->lineEditID->text().toInt(); // valor do id
        int id = ui->comboBox->currentText().toInt();
        //AUX = consult.consultarPorID(id);
        AUX = project.consultarPorIDP(id);

        //if (AUX.getNomeCompleto() == "")
            //throw QString ("NÃO FOI POSSIVEL ACHAR ESSE CONSULTOR");
        //mostrar consultor =
        ui->lineEditIDprojeto->setText(QString::number(AUX.getId_Projeto()));
        ui->textEditDescricao->setText(AUX.getDescricao());
        ui->lineEditOrcamento->setText(QString::number(AUX.getOrcamento()));
        ui->lineEditEndereco->setText(AUX.getEndereco().getLogradouro());
        ui->lineEditNumEnde->setText(QString::number(AUX.getEndereco().getNumero()));
        ui->lineEditConsultor->setText(AUX.getConsultor());

    } catch (QString &erro) {
        QMessageBox::about(this,"ERRO",erro);
    } catch (...) {
        QMessageBox::about(this,"ERRO","O ID INFORMADO NÃO EXISTE");
    }
}


void telaAlteracaoP::on_pushButtonSalvar_clicked()
{
    try {

        int id = ui->lineEditIDprojeto->text().toInt();

        ejm::ProjetoDAO aux;


        //verificar
        QString descricao = ui->textEditDescricao->toPlainText();
        //-------------------------------------------------

        float orcamento = ui->lineEditOrcamento->text().toFloat();

        //-------------------------------------------------

        QString logradouro = ui->lineEditEndereco->text();
        int numeroEd = ui->lineEditNumEnde->text().toInt();

        ejm::Endereco endereco(logradouro,numeroEd);

        QString consultor = ui->lineEditConsultor->text();

        ejm::ConsultorDAO paux;
        ejm::Consultor achar = paux.consultarPorNome(consultor);

        if (achar.getNomeCompleto() != consultor)
            throw QString("NAO EXISTE ESSE CONSULTOR");

        //-------------------------------------------------

        ejm::projeto project(id,descricao,orcamento,endereco,consultor);
        ejm::ProjetoDAO projeto;

        projeto.excluirP(ui->lineEditIDprojeto->text().toInt()); // excluir
        projeto.incluirP(project);//incluir

        close();
    } catch (QString &erro) {
        QMessageBox::about(this,"ERRO",erro);
    }

}


void telaAlteracaoP::on_pushButtonInfo_clicked()
{
    ejm::ConsultorDAO cadConsultor;
    std::list<ejm::Consultor> *listaDeConsulor = 0;
    listaDeConsulor = cadConsultor.listagem("ID");
    QString lista = "";
    while (!listaDeConsulor->empty()){
        ejm::Consultor objConsultor = listaDeConsulor->front();
        listaDeConsulor->pop_front();
        lista += objConsultor.getNomeCompleto() + "\n";
    }

    QMessageBox::information(this,"Consultores",lista);
}

