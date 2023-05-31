#include "telainicio.h"
#include "ui_telainicio.h"

TelaInicio::TelaInicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaInicio)
{
    ui->setupUi(this);
}

TelaInicio::~TelaInicio()
{
    delete ui;
}
