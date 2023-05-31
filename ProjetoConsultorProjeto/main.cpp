#include <telaprincipal.h>
#include <QApplication>

int main(int argc, char *argv[])
{

    std::ifstream arquivoExistente("Projeto.txt");

        if (arquivoExistente) {
            arquivoExistente.close();
        } else {
            std::ofstream novoArquivo("Projeto.txt");
        }

    std::ifstream arquivoExistente2("Consultor.txt");
        if (arquivoExistente2) {
            arquivoExistente2.close();
        } else {
            std::ofstream novoArquivo("Consultor.txt");
        }

    QApplication a(argc, argv);
    //TelaPrincipal w;
    TelaPrincipal w;
    w.show();
    return a.exec();
}
