#ifndef PROJETODAO_H
#define PROJETODAO_H
#include <IProjetoCRUD.h>
#include <fstream>
#include <QStringList>
namespace ejm{
class ProjetoDAO : public ejm::IProjetoCrud
{
protected:
   QString nomeDoArquivoDisco;
public:
    ProjetoDAO();
    void incluirP(const projeto &obj) const;//VER SE TA CORRETO
    std::list<projeto>* listagemP() const;//
    projeto consultarPorIDP(int id) const;//
    projeto consultarPorNomeP(QString nome) const;//
    void excluirP(int id) const;//
};
}
#endif // PROJETODAO_H
