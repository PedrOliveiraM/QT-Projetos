#ifndef TELEFONE_H
#define TELEFONE_H
#include <QString>
namespace ejm {
class Telefone
{
private:
    int DDI;
    int DDD;
    long long numero;
public:
    Telefone(int ddi, int ddd, long long numero);
    Telefone();
    int getDDI() const;
    void setDDI(int newDDI);
    int getDDD() const;
    void setDDD(int newDDD);
    long long getNumero() const;
    void setNumero(long long newNumero);

    QString toString()const;
};
}
#endif // TELEFONE_H
