#include "consultor.h"
namespace ejm {
int Consultor::getID() const
{
    return ID;
}

void Consultor::setID(int newID)
{
    ID = newID;
}

const QString &Consultor::getNomeCompleto() const
{
    return nomeCompleto;
}

void Consultor::setNomeCompleto(const QString &newNomeCompleto)
{
    nomeCompleto = newNomeCompleto;
}

const QString &Consultor::getEmail() const
{
    return email;
}

void Consultor::setEmail(const QString &newEmail)
{
    email = newEmail;
}

const Telefone &Consultor::getTelefone() const
{
    return telefone;
}

void Consultor::setTelefone(const Telefone &newTelefone)
{
    telefone = newTelefone;
}

const Endereco &Consultor::getEndereco() const
{
    return endereco;
}

void Consultor::setEndereco(const Endereco &newEndereco)
{
    endereco = newEndereco;
}
QString Consultor::toString()const{
    QString saida = QString::number(ID);
    saida +=";";
    saida += nomeCompleto;
    saida +=";";
    saida += email;
    saida +=";";
    saida += telefone.toString();
    saida +=";";
    saida += endereco.toString();
    return saida;
}
Consultor::Consultor()
{
}
Consultor::Consultor(int ID, const QString &nomeCompleto, const QString &email, const Telefone &telefone, const Endereco &endereco) :
    ID(ID),
    nomeCompleto(nomeCompleto),
    email(email),
    telefone(telefone),
    endereco(endereco)
{
}
bool Consultor::em_ordemPorID(Consultor &p1 , Consultor &p2 ){

        if (p1.getID() < p2.getID())
            return true;
        else
            return false;

}
bool Consultor::em_ordemPorNome(Consultor &p1 , Consultor &p2 ){
    if (p1.getNomeCompleto() < p2.getNomeCompleto())
        return true;
    else
        return false;
}
}
