#include "projetodao.h"
namespace ejm{//Inicio
ProjetoDAO::ProjetoDAO():
    nomeDoArquivoDisco("Projeto.txt")
{

}
void ProjetoDAO::incluirP(const projeto &obj) const{
    std::ofstream arquivoProjeto;
    //arquivoConsultor.open(nomeDoArquivoDisco.toStdString().c_str());
    arquivoProjeto.open(nomeDoArquivoDisco.toStdString().c_str(),
                       std::ios::out|std::ios::app);
    if(!arquivoProjeto.is_open()){
       throw QString("Arquivo de Agenda não foi aberto - Metodo Incluir");
    }
    arquivoProjeto<<obj.toString().toStdString()+"\n";
    arquivoProjeto.close();
}
std::list<projeto>* ProjetoDAO::listagemP() const{
    try {
        std::list<ejm::projeto> *listaDeProjeto = 0;
        listaDeProjeto = new std::list<ejm::projeto>();
        std::ifstream arquivoProjeto;
        arquivoProjeto.open(nomeDoArquivoDisco.toStdString().c_str());
        if(!arquivoProjeto.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto - Metodo Listagem");
        }
        std::string linha;
        getline(arquivoProjeto,linha);
        while(!arquivoProjeto.eof()){
            ejm::projeto objeto;
            QString strLinha = QString::fromStdString(linha);
            QStringList strList = strLinha.split(';');
            objeto.setId_Projeto(strList[0].toInt());
            objeto.setDescricao(strList[1]);
            objeto.setOrcamento(strList[2].toFloat());
            ejm::Endereco end;
            end.setLogradouro(strList[3]);
            end.setNumero(strList[4].toInt());
            objeto.setEndereco(end);
            objeto.setConsultor(strList[5]);
            listaDeProjeto->push_back(objeto);
            getline(arquivoProjeto,linha);
        }
        arquivoProjeto.close();
        listaDeProjeto->sort(ejm::projeto::em_ordemPorID);
        return listaDeProjeto;

    } catch(std::bad_alloc&){
        throw QString("Lista nao foi criada");
    } catch(QString &erro){
        throw erro;
    }
}
projeto ProjetoDAO::consultarPorIDP(int id) const{
    try{
        std::ifstream arquivoProjeto;
        arquivoProjeto.open(nomeDoArquivoDisco.toStdString().c_str());
        if(!arquivoProjeto.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto - Metodo Consultar");
        }
        std::string linha;
        getline(arquivoProjeto,linha);
        while(!arquivoProjeto.eof()){
            ejm::projeto objeto;
            QString strLinha = QString::fromStdString(linha);
            QStringList strList = strLinha.split(';');
            objeto.setId_Projeto(strList[0].toInt());
            objeto.setDescricao(strList[1]);
            objeto.setOrcamento(strList[2].toFloat());
            ejm::Endereco end;
            end.setLogradouro(strList[3]);
            end.setNumero(strList[4].toInt());
            objeto.setEndereco(end);
            objeto.setConsultor(strList[5]);

            if(objeto.getId_Projeto() == id){
                arquivoProjeto.close();
                return objeto;
            }
            getline(arquivoProjeto,linha);
        }
        arquivoProjeto.close();
        ejm::projeto objeto;
        return objeto;
        throw QString("Projeto não foi encontrado");
    }catch(QString &erro){
        throw erro;
    }
}

projeto ProjetoDAO::consultarPorNomeP(QString nome) const
{
    try{
        std::ifstream arquivoProjeto;
        arquivoProjeto.open(nomeDoArquivoDisco.toStdString().c_str());
        if(!arquivoProjeto.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto - Metodo Consultar");
        }
        std::string linha;
        getline(arquivoProjeto,linha);
        while(!arquivoProjeto.eof()){
            ejm::projeto objeto;
            QString strLinha = QString::fromStdString(linha);
            QStringList strList = strLinha.split(';');
            objeto.setId_Projeto(strList[0].toInt());
            objeto.setDescricao(strList[1]);
            objeto.setOrcamento(strList[2].toFloat());
            ejm::Endereco end;
            end.setLogradouro(strList[3]);
            end.setNumero(strList[4].toInt());
            objeto.setEndereco(end);
            objeto.setConsultor(strList[5]);

            if(objeto.getConsultor() == nome){
                arquivoProjeto.close();
                return objeto;
            }
            getline(arquivoProjeto,linha);
        }
        arquivoProjeto.close();
        ejm::projeto objeto;
        return objeto;
        throw QString("Projeto não foi encontrado");
    }catch(QString &erro){
        throw erro;
    }

}
void ProjetoDAO::excluirP(int id) const{
    try {
        std::list<ejm::projeto> *listaDeProjeto = 0;
        listaDeProjeto = this->listagemP();
        std::ofstream arquivoProjeto;
        arquivoProjeto.open(nomeDoArquivoDisco.toStdString().c_str());
        if(!arquivoProjeto.is_open()){
           throw QString("Arquivo de Agenda não foi aberto - Metodo Excluir");
        }
        while(!listaDeProjeto->empty()){
            projeto aux = listaDeProjeto->front();
            if(aux.getId_Projeto() != id){
                arquivoProjeto<<aux.toString().toStdString()+"\n";
            }
            listaDeProjeto->pop_front();
        }
        delete listaDeProjeto;
        arquivoProjeto.close();
    }  catch(QString &erro){
        throw erro;
    }
}
}//Fim namespace
