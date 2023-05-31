#include "telaconsultor.h"
#include "telainclusao.h"
#include "projeto.h"
#include "projetodao.h"
#include "ui_telaconsultor.h"

telaConsultor::telaConsultor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaConsultor)
{
    ui->setupUi(this);
    mostrarDadosDosConsultores();
    QStringList aux = {""};
    ui->tableWidgetContato->setHorizontalHeaderLabels(aux);
    ui->tableWidgetContato->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetContato->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetContato->verticalHeader()->setVisible(false);
    ui->tableWidgetContato->setStyleSheet("QTableView {selection-background-color:blue}");

}

telaConsultor::~telaConsultor()
{
    delete ui;
}

void telaConsultor::on_pushButtonIncluir_clicked()
{
    try {
        form3 = new TelaInclusao(this);
        form3->exec();
        mostrarDadosDosConsultores(); //**************NAO ATUALIZA
        ui->tableWidgetContato->resizeColumnsToContents();
    }  catch (QString erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA - Inclusão",erro);
    }
}
void telaConsultor::mostrarDadosDosConsultores(){
    try {
        QString tipo = "";
        if (ui->comboBox->currentText() == "ID")
             tipo += "ID";
        else
             tipo +="Nome";
        ejm::ConsultorDAO cadConsultores;
        std::list<ejm::Consultor> *listaDeConsultores = 0;
        listaDeConsultores = cadConsultores.listagem(tipo);
        //Limpar a grid
        ui->tableWidgetContato->setRowCount(0);
        while(!listaDeConsultores->empty()){
            ejm::Consultor objConsultor = listaDeConsultores->front();
            listaDeConsultores->pop_front();
            //Ajustar a coluna da grid ao conteudo dela
           // ui->tableWidgetContato->resizeColumnsToContents();
            //Montado a grid
            QTableWidgetItem *itemId = new QTableWidgetItem(QString::number(objConsultor.getID()));
            QTableWidgetItem *itemNome = new QTableWidgetItem(objConsultor.getNomeCompleto());
            QTableWidgetItem *itemEmail = new QTableWidgetItem(objConsultor.getEmail());
            QString telefone = QString::number(objConsultor.getTelefone().getDDI());
            telefone += "("+ QString::number(objConsultor.getTelefone().getDDD()) + ")";
            telefone += QString::number(objConsultor.getTelefone().getNumero());
            QTableWidgetItem *itemTelefone = new QTableWidgetItem(telefone);
            QString endereco = objConsultor.getEndereco().getLogradouro() + " - ";
            endereco += "Numero:  "+ QString::number(objConsultor.getEndereco().getNumero());
            QTableWidgetItem *itemEndereco = new QTableWidgetItem(endereco);

            //Obtendo a quantidade de linhas tem na grid
            int linha = ui->tableWidgetContato->rowCount();
            //incluindo uma linha na grid
            ui->tableWidgetContato->insertRow(linha);
            ui->tableWidgetContato->setItem(linha,0,itemId);
            ui->tableWidgetContato->setItem(linha,1,itemNome);
            ui->tableWidgetContato->setItem(linha,2,itemEmail);
            ui->tableWidgetContato->setItem(linha,3,itemTelefone);
            ui->tableWidgetContato->setItem(linha,4,itemEndereco);
        }
        //AJUSTAR AO CONTEUDO
        ui->tableWidgetContato->resizeColumnsToContents(); //* ARRUMAR A GRID
        delete listaDeConsultores;
    }  catch (QString erro) {
        QMessageBox::information(this,"Seja bem vindo",erro);
    } catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}

void telaConsultor::on_pushButtonExcluir_clicked() //BOTAO DE EXCLUIR
{
    try {

        int linha = ui->tableWidgetContato->currentRow(); //PEGA O ID

        if (linha == -1)
            throw QString("NÃO FOI SELECIONADO");

        int id = ui->tableWidgetContato->item(linha,0)->text().toInt();
        QString nome = ui->tableWidgetContato->item(linha,1)->text();

        ejm::ProjetoDAO aux;
        if (aux.consultarPorNomeP(nome).getConsultor() == nome)
            throw QString("NÃO FOI POSSIVEL REMOVER,POIS ELE ESTÁ EM UM PROJETO\n"
                                 "TROQUE O CONSULTOR E TENTE NOVAMENTE");


        ejm::ConsultorDAO cadConsultores;
        cadConsultores.excluir(id); // CHAMA O METODO EXCLUIR E PASSA O ID

        mostrarDadosDosConsultores();
    }  catch (QString erro) {
        QMessageBox::warning(this,"ERRO DO SISTEMA - EXCLUSÃO",erro);
    }
}


void telaConsultor::on_pushButtonOrdenar_clicked()
{
    mostrarDadosDosConsultores();
}

void telaConsultor::on_pushButtonAlterar_clicked()
{
    form2 = new telaDeAlteracoes(this);
    form2->exec();
    mostrarDadosDosConsultores();
}
