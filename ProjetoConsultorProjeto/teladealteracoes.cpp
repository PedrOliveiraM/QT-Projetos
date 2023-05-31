#include "teladealteracoes.h"
#include "telaprincipal.h"
#include "consultor.h"
#include "consultordao.h"
#include "ui_teladealteracoes.h"
#include <QMessageBox>
telaDeAlteracoes::telaDeAlteracoes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaDeAlteracoes)
{
    ui->setupUi(this);
    ui->lineEditID->setEnabled(false);
    ejm::ConsultorDAO cadConsultores;
    std::list<ejm::Consultor> *listaDeConsultores = 0;
    listaDeConsultores = cadConsultores.listagem("ID");
    while (!listaDeConsultores->empty()){
        ejm::Consultor objConsultor = listaDeConsultores->front();
        listaDeConsultores->pop_front();
        ui->comboBox->addItem(objConsultor.getNomeCompleto());
    }
}

telaDeAlteracoes::~telaDeAlteracoes()
{
    delete ui;
}

void telaDeAlteracoes::on_pushButton_clicked() // mostrar
{
    try {
        ejm::ConsultorDAO consult; // criei um objeto
        ejm::Consultor AUX;

        //int id = ui->lineEditID->text().toInt(); // valor do id
        QString nome = ui->comboBox->currentText();
        //AUX = consult.consultarPorID(id);
        AUX = consult.consultarPorNome(nome);

        //if (AUX.getNomeCompleto() == "")
            //throw QString ("NÃO FOI POSSIVEL ACHAR ESSE CONSULTOR");
        //mostrar consultor =
        ui->lineEditID->setText(QString::number(AUX.getID()));
        ui->lineEditNome->setText(AUX.getNomeCompleto());
        ui->lineEditEmail->setText(AUX.getEmail());
        ui->lineEditDDI->setText(QString::number(AUX.getTelefone().getDDI()));
        ui->lineEditDDD->setText(QString::number(AUX.getTelefone().getDDD()));


        ui->lineEditNumero->setText(QString::number(AUX.getTelefone().getNumero()));


        ui->lineEditEndereco->setText(AUX.getEndereco().getLogradouro());
        ui->lineEditNumEnde->setText(QString::number(AUX.getEndereco().getNumero()));

    } catch (QString &erro) {
        QMessageBox::about(this,"ERRO",erro);
    } catch (...) {
        QMessageBox::about(this,"ERRO","O ID INFORMADO NÃO EXISTE");
    }

}


void telaDeAlteracoes::on_pushButtonSalvar_clicked()
{
    ejm::ConsultorDAO aux;
    int id = ui->lineEditID->text().toInt();
    //if(aux.consultarPorID(id).getNomeCompleto() == ""){
        //throw("ESSE ID NÃO ESTÁ REGISTRADO");
   // }
    //verificar
    QString nome = ui->lineEditNome->text();
    QString email = ui->lineEditEmail->text();
    //-------------------------------------------------

    int ddi = ui->lineEditDDI->text().toInt();
    int ddd = ui->lineEditDDD->text().toInt();
    int numero = ui->lineEditNumero->text().toLongLong();

    ejm::Telefone fone(ddi,ddd,numero);

    //-------------------------------------------------

    QString logradouro = ui->lineEditEndereco->text();
    int numeroEd = ui->lineEditNumEnde->text().toInt();

    ejm::Endereco endereco(logradouro,numeroEd); 

    //-------------------------------------------------

    ejm::Consultor pessoa(id,nome,email,fone,endereco);
    ejm::ConsultorDAO consult;

    ejm::projeto paux;
    ejm::ProjetoDAO teste;


    consult.excluir(ui->lineEditID->text().toInt()); // excluir
    consult.incluir(pessoa);//incluir

    close();

}

