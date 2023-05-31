#include "consultordao.h"
namespace ejm{//Inicio
ConsultorDAO::ConsultorDAO():
    nomeDoArquivoDisco("Consultor.txt")
{
}
void ConsultorDAO::incluir(const Consultor& obj) const {
    std::ofstream arquivoConsultor;
    arquivoConsultor.open(nomeDoArquivoDisco.toStdString().c_str(),
                         std::ios::out | std::ios::app);
    if (!arquivoConsultor.is_open()) {
        throw QString("Arquivo de Agenda não foi aberto - Método Incluir");
    }
    arquivoConsultor << obj.toString().toStdString() + "\n";
    arquivoConsultor.close();
}


std::list<Consultor>* ConsultorDAO::listagem(QString tipo) const{
    try {
        std::list<ejm::Consultor> *listaDeConsultores = 0;
        listaDeConsultores = new std::list<ejm::Consultor>();
        std::ifstream arquivoConsultor;
        arquivoConsultor.open(nomeDoArquivoDisco.toStdString().c_str());
        if(!arquivoConsultor.is_open()){
            throw QString("Arquivo de Agenda ainda não foi aberto");
        }
        std::string linha;
        getline(arquivoConsultor,linha);
        while(!arquivoConsultor.eof()){
            ejm::Consultor objeto;
            QString strLinha = QString::fromStdString(linha);
            QStringList strList = strLinha.split(';');
            objeto.setID(strList[0].toInt());
            objeto.setNomeCompleto(strList[1]);
            objeto.setEmail(strList[2]);
            ejm::Telefone fone;
            fone.setDDI(strList[3].toInt());
            fone.setDDD(strList[4].toInt());
            fone.setNumero(strList[5].toLongLong());
            objeto.setTelefone(fone);
            ejm::Endereco end;
            end.setLogradouro(strList[6]);
            end.setNumero(strList[7].toInt());
            objeto.setEndereco(end);
            listaDeConsultores->push_back(objeto);
            getline(arquivoConsultor,linha);
        }
        arquivoConsultor.close();
        if (tipo == "ID")
            listaDeConsultores->sort(ejm::Consultor::em_ordemPorID);
        else
            listaDeConsultores->sort(ejm::Consultor::em_ordemPorNome);

        return listaDeConsultores;
    } catch(std::bad_alloc&){
        throw QString("Lista nao foi criada");
    } catch(QString &erro){
        throw erro;
    }
}
Consultor ConsultorDAO::consultarPorID(int id) const{
    try{
        std::ifstream arquivoConsultor;
        arquivoConsultor.open(nomeDoArquivoDisco.toStdString().c_str());
        if(!arquivoConsultor.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto - Metodo Consultar");
        }
        std::string linha;
        getline(arquivoConsultor,linha);
        while(!arquivoConsultor.eof()){
            ejm::Consultor objeto;
            QString strLinha = QString::fromStdString(linha);
            QStringList strList = strLinha.split(';');
            objeto.setID(strList[0].toInt());
            objeto.setNomeCompleto(strList[1]);
            objeto.setEmail(strList[2]);
            ejm::Telefone fone;
            fone.setDDI(strList[3].toInt());
            fone.setDDD(strList[4].toInt());
            fone.setNumero(strList[5].toLongLong());
            objeto.setTelefone(fone);
            ejm::Endereco end;
            end.setLogradouro(strList[6]);
            end.setNumero(strList[7].toInt());
            objeto.setEndereco(end);

            if(objeto.getID() == id){
                arquivoConsultor.close();
                return objeto;
            }
            getline(arquivoConsultor,linha);
        }
        arquivoConsultor.close();
        ejm::Consultor objeto;
        return objeto;
        throw QString("Consultor não foi encontrado");
    }catch(QString &erro){
        throw erro;
    }
}
Consultor ConsultorDAO::consultarPorNome(QString nome) const{
    try{
        std::ifstream arquivoConsultor;
        arquivoConsultor.open(nomeDoArquivoDisco.toStdString().c_str());
        if(!arquivoConsultor.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto - Metodo Consultar");
        }
        std::string linha;
        getline(arquivoConsultor,linha);
        while(!arquivoConsultor.eof()){
            ejm::Consultor objeto;
            QString strLinha = QString::fromStdString(linha);
            QStringList strList = strLinha.split(';');
            objeto.setID(strList[0].toInt());
            objeto.setNomeCompleto(strList[1]);
            objeto.setEmail(strList[2]);
            ejm::Telefone fone;
            fone.setDDI(strList[3].toInt());
            fone.setDDD(strList[4].toInt());
            fone.setNumero(strList[5].toLongLong());
            objeto.setTelefone(fone);
            ejm::Endereco end;
            end.setLogradouro(strList[6]);
            end.setNumero(strList[7].toInt());
            objeto.setEndereco(end);

            if(objeto.getNomeCompleto() == nome){
                arquivoConsultor.close();
                return objeto;
            }
            getline(arquivoConsultor,linha);
        }
        arquivoConsultor.close();
        ejm::Consultor objeto;
        return objeto;
        throw QString("Consultor não foi encontrado");
    }catch(QString &erro){
        throw erro;
    }

}
void ConsultorDAO::excluir(int id) const{
    try {
        QString tipo = "";
        std::list<ejm::Consultor> *listaDeConsultores = 0;
        listaDeConsultores = this->listagem(tipo);
        std::ofstream arquivoConsultor;
        arquivoConsultor.open(nomeDoArquivoDisco.toStdString().c_str());
        if(!arquivoConsultor.is_open()){
           throw QString("Arquivo de Agenda não foi aberto - Metodo Excluir");
        }
        while(!listaDeConsultores->empty()){
            Consultor aux = listaDeConsultores->front();
            if(aux.getID() != id){
                arquivoConsultor<<aux.toString().toStdString()+"\n";
            }
            listaDeConsultores->pop_front();
        }
        delete listaDeConsultores;
        arquivoConsultor.close();
    }  catch(QString &erro){
        throw erro;
    }
}
}//Fim namespace
