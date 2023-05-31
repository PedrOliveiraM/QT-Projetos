#ifndef IPROJETOCRUD_H
#define IPROJETOCRUD_H
#include <projeto.h>//>
#include <list>
namespace ejm{
//Interface de Persistencia
class IProjetoCrud{
public:

    virtual void incluirP(const projeto &obj) const = 0;
    virtual void excluirP(int id) const = 0;
    virtual projeto consultarPorIDP(int id) const = 0;
    virtual std::list<projeto>* listagemP() const = 0;

};
}
#endif // IPROJETOCRUD_H
