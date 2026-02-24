#include <fstream>
#include <iostream>

int main() {
    std::ifstream arquivo("test.txt");
    arquivo.is_open() ? std::cout << "Arquivo aberto com sucesso!" << std::endl : std::cout << "Erro ao abrir o arquivo!" << std::endl;
}

