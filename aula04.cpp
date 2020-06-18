#include <iostream>
#include <string>
#include <fstream>

void show_usage (const std::string &nome_programa);
int usage_list (const std::string nome_arquivo);
int usage_add (const  std::string mensagem);

int main(int argc, char *argv[]){


    if (argc == 1) {
        show_usage(argv[0]);
        return 1;

    }

    std::string action = argv[1];


    if (action != "add" && action != "list") {
    	show_usage(argv[0]);
    	return 1;
    }

    std::string mensagem;
    std::string nome_arquivo = "diario.txt";

    

    if(action == "list")
    {
    	usage_list(nome_arquivo);
    }
    else{

    	  if (argc == 2) {
        std::cout << "Informe a mensagem " << std::endl;
        std::getline(std::cin, mensagem);

    }

    else {
    	mensagem = argv[2];
    }
    
    usage_add(mensagem);
	std::cout<<"mensagem adcionada"<<std::endl;
}
    

   return 0;
}

int usage_list (const std::string nome_arquivo)
{	

	std::ifstream arquivo_entrada(nome_arquivo, std::ios::in);
	if (arquivo_entrada.fail()){
		std::cerr << "Erro: Arquivo não existe ou sem permissão de leitura." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(arquivo_entrada, line)){
		std::cout << line << std::endl;
	}
	arquivo_entrada.close();

}
void show_usage (const std::string &nome_programa)
{
   std::cout << "Add: Uso " << nome_programa << " add <mensagem>" << std::endl;
   std::cout << "List: Uso " << nome_programa << " list <nome do arquivo>" << std::endl;
}
int usage_add (const std::string mensagem )

{

    std::ofstream arquivo_saida{"diario.txt" , std::ios::app }; 

    if (!arquivo_saida.is_open()){
    	std::cerr << "O arquivo não pode ser criado." << std::endl;
    	return 1;
    }
    arquivo_saida << mensagem << std::endl;
    arquivo_saida.close();

}