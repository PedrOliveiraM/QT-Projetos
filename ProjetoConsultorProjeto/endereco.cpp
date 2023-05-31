#include "endereco.h"
namespace ejm {
const QString &Endereco::getLogradouro() const
{
    return logradouro;
}
void Endereco::setLogradouro(const QString &newLogradouro)
{
    logradouro = newLogradouro;
}
int Endereco::getNumero() const
{
    return numero;
}
void Endereco::setNumero(int newNumero)
{
    numero = newNumero;
}
Endereco::Endereco()
{
}
Endereco::Endereco(const QString &logradouro, int numero) :
    logradouro(logradouro),
    numero(numero)
{
}
QString Endereco::toString()const{
    QString saida = logradouro;
    saida +=";";
    saida += QString::number(numero);
    return saida;
}
}
