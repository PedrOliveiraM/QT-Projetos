#include "telefone.h"
namespace ejm {
int Telefone::getDDI() const
{
    return DDI;
}
void Telefone::setDDI(int newDDI)
{
    DDI = newDDI;
}
int Telefone::getDDD() const
{
    return DDD;
}
void Telefone::setDDD(int newDDD)
{
    DDD = newDDD;
}
long long Telefone::getNumero() const
{
    return numero;
}
void Telefone::setNumero(long long newNumero)
{
    numero = newNumero;
}
QString Telefone::toString()const{
    QString saida = QString::number(DDI);
    saida +=";";
    saida += QString::number(DDD);
    saida +=";";
    saida += QString::number(numero);
    return saida;
}
Telefone::Telefone(int ddi, int ddd, long long numero):
    DDI(ddi),
    DDD(ddd),
    numero(numero)
{
}
Telefone::Telefone():
    DDI(0),
    DDD(0),
    numero(0)
{
}

}
