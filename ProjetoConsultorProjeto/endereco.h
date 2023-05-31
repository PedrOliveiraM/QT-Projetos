#ifndef ENDERECO_H
#define ENDERECO_H
#include <QString>
namespace ejm {
class Endereco
{
private:
    QString logradouro;
    int numero;
public:
    Endereco();
    Endereco(const QString &logradouro, int numero);

    const QString &getLogradouro() const;
    void setLogradouro(const QString &newLogradouro);
    int getNumero() const;
    void setNumero(int newNumero);
    QString toString()const;
};
}
#endif // ENDERECO_H
