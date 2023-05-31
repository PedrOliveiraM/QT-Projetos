#include "telaprincipal.h"
#include "ui_telaprincipal.h"

TelaPrincipal::TelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Projeto Consultor Projeto");
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}

void TelaPrincipal::on_actionInforma_oes_triggered()
{
    QMessageBox::aboutQt(this);
}


void TelaPrincipal::on_actionSair_triggered()
{
    QMessageBox::StandardButton resposta =QMessageBox::question(this,"","Deseja sair ?",QMessageBox::Yes|QMessageBox::No);

    if (resposta == QMessageBox::Yes)
        //close;
        QApplication::quit();
    //else
        //QMessageBox::about(this,"","Programa Não foi Fechado");
}

void TelaPrincipal::on_pushButtonConsultores_clicked()
{
    TelaConsultor = new telaConsultor(this);
    TelaConsultor->exec();
}


void TelaPrincipal::on_pushButtonProjetos_clicked()
{
    TELAPROJETO = new TelaProjeto(this);
    TELAPROJETO->exec();
}

void TelaPrincipal::on_pushButtonSair_clicked()
{
    QMessageBox::StandardButton resposta =QMessageBox::question(this,"","Deseja sair ?",QMessageBox::Yes|QMessageBox::No);

    if (resposta == QMessageBox::Yes)
        //close;
        QApplication::quit();
   // else
       // QMessageBox::about(this,"","Programa Não foi Fechado");
}




