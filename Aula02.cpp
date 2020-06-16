//
// Created by irineu on 16/06/2020.
//
#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    std::string mensagem;

    if (argc == 1) {
        std::cout << "Uso " << argv[0] << " add <mensagem>" << std::endl;
        return 1;
    } else if (argc == 2) {
        std::cout << "É necessário add uma mensagem  " << std::endl;
        std::cout << "add" << std::endl;
        std::cout<<"mensagem adcionada"<<std::endl;
        return 1;

    } else {
        std::cout<<"mensagem adcionada"<<std::endl;
    }



    return 0;
}