#ifndef PROJETO_H
#define PROJETO_H
#include <QString>
#include <consultor.h>
#include <consultordao.h>
#include <IConsultorCRUD.h>
#include <telefone.h>
#include <endereco.h>
namespace ejm{
class projeto
{
private:
    int id_Projeto;
    QString descricao;
    float orcamento;
    Endereco endereco;
    QString  consultor;
public:
    projeto();
    projeto(int id_Projeto, const QString &descricao, float orcamento, const Endereco &endereco , QString  consultor);

    int getId_Projeto() const;
    void setId_Projeto(int newId_Projeto);
    const QString &getDescricao() const;
    void setDescricao(const QString &newDescricao);
    float getOrcamento() const;
    void setOrcamento(float newOrcamento);
    const Endereco &getEndereco() const;
    void setEndereco(const Endereco &newEndereco);

    QString toString()const;

    bool static em_ordemPorID(projeto &p1 , projeto &p2 );

    const QString &getConsultor() const;
    void setConsultor(const QString &newConsultor);
};
}
#endif // PROJETO_H
