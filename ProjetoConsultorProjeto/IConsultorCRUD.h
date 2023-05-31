#ifndef ICONSULTORCRUD_H
#define ICONSULTORCRUD_H
#include <consultor.h>
#include <list>
namespace ejm{
//Interface de Persistencia
class IConsultorCRUD{
public:
    virtual void incluir(const Consultor &obj) const = 0;
    //virtual void alterar(const Consultor &obj) const = 0;
    virtual void excluir(int id) const = 0;
    virtual Consultor consultarPorID(int id) const = 0;
    virtual std::list<Consultor>* listagem(QString tipo) const = 0;
};
}
#endif // ICONSULTORCRUD_H
