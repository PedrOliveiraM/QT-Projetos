#include "projeto.h"
namespace ejm {
const QString &projeto::getConsultor() const
{
    return consultor;
}

void projeto::setConsultor(const QString &newConsultor)
{
    consultor = newConsultor;
}

projeto::projeto():
    id_Projeto(0),
    descricao(""),
    orcamento(0.0),
    endereco("",0),
    consultor("")
{

}
const QString &projeto::getDescricao() const
{
    return descricao;
}

void projeto::setDescricao(const QString &newDescricao)
{
    descricao = newDescricao;
}

float projeto::getOrcamento() const
{
    return orcamento;
}

void projeto::setOrcamento(float newOrcamento)
{
    orcamento = newOrcamento;
}

const Endereco &projeto::getEndereco() const
{
    return endereco;
}

void projeto::setEndereco(const Endereco &newEndereco)
{
    endereco = newEndereco;
}

int projeto::getId_Projeto() const
{
    return id_Projeto;
}

void projeto::setId_Projeto(int newId_Projeto)
{
    id_Projeto = newId_Projeto;
}

QString projeto::toString()const{
    QString saida = QString::number(id_Projeto);
    saida +=";";
    saida += descricao;
    saida +=";";
    saida += QString::number(orcamento);
    saida +=";";
    saida += endereco.toString();
    saida +=";";
    saida += consultor;
    return saida;
}

bool projeto::em_ordemPorID(projeto &p1, projeto &p2)
{
    if (p1.getId_Projeto() < p2.getId_Projeto())
        return true;
    else
        return false;
}

projeto::projeto(int id_Projeto, const QString &descricao, float orcamento, const Endereco &endereco, QString consultor) :
    id_Projeto(id_Projeto),
    descricao(descricao),
    orcamento(orcamento),
    endereco(endereco),
    consultor(consultor)
{

}

}
