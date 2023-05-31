#ifndef CONSULTOR_H
#define CONSULTOR_H
#include <QString>
#include <telefone.h>
#include <endereco.h>
namespace ejm {
class Consultor
{
    int ID;
    QString nomeCompleto;
    QString email;
    Telefone telefone;
    Endereco endereco;
public:
    Consultor();
    Consultor(int ID, const QString &nomeCompleto, const QString &email, const Telefone &telefone, const Endereco &endereco);

    int getID() const;
    void setID(int newID);
    const QString &getNomeCompleto() const;
    void setNomeCompleto(const QString &newNomeCompleto);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    const Telefone &getTelefone() const;
    void setTelefone(const Telefone &newTelefone);
    const Endereco &getEndereco() const;
    void setEndereco(const Endereco &newEndereco);
    QString toString()const;

    bool static em_ordemPorID(Consultor &p1 , Consultor &p2 );
    bool static em_ordemPorNome(Consultor &p1 , Consultor &p2 );
};
}
#endif // CONSULTOR_H
