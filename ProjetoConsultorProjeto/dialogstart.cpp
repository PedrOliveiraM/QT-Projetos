#include "dialogstart.h"
#include "ui_dialogstart.h"
#include <QMessageBox>
DialogStart::DialogStart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStart)
{
    ui->setupUi(this);
}

DialogStart::~DialogStart()
{
    delete ui;
}

void DialogStart::on_pushButtonConsultores_clicked()
{

}




void DialogStart::on_pushButtonProjetos_clicked()
{

}


void DialogStart::on_pushButtonSair_clicked()
{
    QMessageBox::question(this,"Aviso","Deseja Fechar ?",QMessageBox::Yes,QMessageBox::No);
}

