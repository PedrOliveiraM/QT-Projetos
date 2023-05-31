#include "telaprojeto.h"
#include "ui_telaprojeto.h"
#include <QMessageBox>
TelaProjeto::TelaProjeto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaProjeto)
{
    ui->setupUi(this);

    ejm::ProjetoDAO cadProjetos;
    std::list<ejm::projeto> *listaDeProjeto = 0;
    listaDeProjeto = cadProjetos.listagemP();

    if (!listaDeProjeto->empty()){
         mostrarDadosDosProjetos();
         QStringList aux = {""};
         ui->tableWidgetProjeto->setHorizontalHeaderLabels(aux);
         ui->tableWidgetProjeto->setEditTriggers(QAbstractItemView::NoEditTriggers);
         ui->tableWidgetProjeto->setSelectionBehavior(QAbstractItemView::SelectRows);
         ui->tableWidgetProjeto->verticalHeader()->setVisible(false);
         ui->tableWidgetProjeto->setStyleSheet("QTableView {selection-background-color:blue}");
   }

}

TelaProjeto::~TelaProjeto()
{
    delete ui;
}
void TelaProjeto::on_pushButtonIncluir_clicked()
{
    TelaIP = new telaInclusaoP(this);
    TelaIP->exec();
    mostrarDadosDosProjetos();
}


void TelaProjeto::on_pushButtonExcluir_clicked()
{
    try {

        //**********************************ERRO AO EXCLUIR ----  QUANDO TA VAZIA
        int linha = ui->tableWidgetProjeto->currentRow(); //PEGA O ID
        ui->tableWidgetProjeto->selectRow(linha);
        if (linha == -1)
            throw QString("NÃO FOI SELECIONADO");
        int id = ui->tableWidgetProjeto->item(linha,0)->text().toInt();

        ejm::ProjetoDAO cadProjeto;
        cadProjeto.excluirP(id); // CHAMA O METODO EXCLUIR E PASSA O ID
        mostrarDadosDosProjetos();
    }  catch (QString erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA - Inclusão",erro);
    }
}


void TelaProjeto::on_pushButtonAlterar_clicked()
{
    TelaAlt = new telaAlteracaoP(this);
    TelaAlt->exec();
    mostrarDadosDosProjetos();
}

void TelaProjeto::mostrarDadosDosProjetos() const{

        ejm::ProjetoDAO cadProjetos;
        std::list<ejm::projeto> *listaDeProjeto = 0;
        listaDeProjeto = cadProjetos.listagemP();

        //Limpar a grid
        ui->tableWidgetProjeto->setRowCount(0);
        while(!listaDeProjeto->empty()){
            ejm::projeto objProjeto = listaDeProjeto->front();
            listaDeProjeto->pop_front();
            //Ajustar a coluna da grid ao conteudo dela
           // ui->tableWidgetContato->resizeColumnsToContents();
            //Montado a grid
            QTableWidgetItem *itemId_Projeto = new QTableWidgetItem(QString::number(objProjeto.getId_Projeto()));
            QTableWidgetItem *itemDescriacao = new QTableWidgetItem(objProjeto.getDescricao());
            QTableWidgetItem *itemOrcamento = new QTableWidgetItem(QString::number(objProjeto.getOrcamento()));
            QString endereco = objProjeto.getEndereco().getLogradouro() + " - ";
            endereco += "Numero:  "+ QString::number(objProjeto.getEndereco().getNumero());
            QTableWidgetItem *itemEndereco = new QTableWidgetItem(endereco);
            QTableWidgetItem *itemConsultor = new QTableWidgetItem(objProjeto.getConsultor());

            //Obtendo a quantidade de linhas tem na grid
            int linha = ui->tableWidgetProjeto->rowCount();
            //incluindo uma linha na grid
            ui->tableWidgetProjeto->insertRow(linha);
            ui->tableWidgetProjeto->setItem(linha,0,itemId_Projeto);
            ui->tableWidgetProjeto->setItem(linha,1,itemDescriacao);
            ui->tableWidgetProjeto->setItem(linha,2,itemOrcamento);
            ui->tableWidgetProjeto->setItem(linha,3,itemEndereco);
            ui->tableWidgetProjeto->setItem(linha,4,itemConsultor);

        }
        //AJUSTAR AO CONTEUDO
        ui->tableWidgetProjeto->resizeColumnsToContents();
        delete listaDeProjeto;
}
