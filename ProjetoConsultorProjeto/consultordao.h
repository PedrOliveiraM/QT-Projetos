#ifndef CONSULTORDAO_H
#define CONSULTORDAO_H
#include <IConsultorCRUD.h>
#include <fstream>
#include <QStringList>
namespace ejm{
class ConsultorDAO: public ejm::IConsultorCRUD
{
private:
    QString nomeDoArquivoDisco;
public:
    ConsultorDAO();
    void incluir(const Consultor &obj) const;//FT
    std::list<Consultor>* listagem(QString tipo) const;//FT
    Consultor consultarPorID(int id) const;//FT
    Consultor consultarPorNome(QString nome) const;

    void excluir(int id) const;//FT
};
}
#endif // CONSULTORDAO_H
