#include <stdio.h>  //biblioteca de comunicaçao com o usuario
#include <stdlib.h> //biblioteca de alocaçao de memoria
#include <locale.h> //biblioteca de alocaçao de texto por regiao
#include <string.h> //bibilioteca responsavel por cuidar das string's
int registro() //Funçao responsavel por cadastrar o usuario.
{
	// Inicio da criaçao de variáveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// Final da criaçao de variáveis/string
		
		printf("Digite o CPF a ser cadastrado: "); //Coletando informação de usuário
		scanf("%s", cpf); //%s refere-se a string, que armazena a informação trazida pelo usuario
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das string's
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
		fprintf(file, cpf); //salvo valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //Atualiza a informação dentro do arquivo "a" significa atualizar
		fprintf(file, ","); //salva as informaçoes dentro do arquivo, a "," serve para espaçamento das informações
		fclose(file); //fecha o aqruivo
		
		printf("Digite o nome a ser cadastrado: "); //Coletando informções do usuario
		scanf("%s", nome); //Refere-se a string, que armazena a informação trazida pelo usuario
		
		file = fopen(arquivo, "a"); //Atualiza a informação dentro do arquivo "a" significa atualizar
		fprintf(file, nome); //Salva o valor da variavel
		fclose(file); //Fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuario
		scanf("%s", sobrenome); //Referente a string, que armazena a informação trazida pelo usuario
		
		file = fopen(arquivo, "a"); //Atualiza as informações, "a" significa atualizar
		fprintf(file,sobrenome); //Salva a informação no aqruivo
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //Atualiza a informação dentro do arquivo, "a" significa atualizar
		fprintf(file, ","); //salva as informaçoes dentro do arquivo, a "," serve para espaçamento das informações
		fclose(file); //fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: "); //Coletando informções do usuario
		scanf("%s",cargo); //%s refere-se a string, que armazena a informação trazida pelo usuario
		
		file = fopen(arquivo, "a"); //Atualiza as informações, "a" significa atualizar
		fprintf(file,cargo); //Salva as informaçoes dentro do arquivo
		fclose(file); //fecha o arquivo
		
		system("pause"); //Pausa o programa
		
} 	

int consulta() //Função responsavel por consultar um usuario
{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		char cpf[40]; //Variavel do tipo "char"(caracter) string
		char conteudo[200]; //Variavel do tipo "char"(caracter) string
		
		printf("Digite o CPF a ser consultado: "); //Coletando informações do usuario
		scanf("%s", cpf); //%s refere-se a string, que armazena as informações do usuario
		
		FILE *file; //Cria o arquivo
		file = fopen(cpf, "r"); //Le o arquivo
		
		if(file == NULL) //Refere-se a nao existencia do arquivo
		{
			printf("Não foi possivel abrir o arquivo, nao localizado! \n"); //Resposta ao usuario caso o arquivo nao exista
		}
	
	
		while(fgets(conteudo, 200, file) != NULL) //Laço de repetição "while", 
		{
			printf("\nEssas são as informações do usuário: "); //Resposta ao usuário
			printf("%s",conteudo); //Salva o conteúdo dentro da string
			printf("\n,\n");
		}
		
		system("pause"); //Pausa o programa
	
}

int deletar() //função responsavel por deletar um usuario
{
		char cpf[40]; //Variavel do tipo "char"
		
		printf("Digite o CPF do usuario a ser deletado: "); //Coletando informações do usuario
		scanf("%s", cpf); //Armazena informações do usuario na string
		
		remove(cpf); //remove o usuario
		
		FILE *file; //cria o arquivo
		file = fopen(cpf, "r"); //Le o arquivo
		
		if(file == NULL) //Refere-se a nao existencia do arquivo
		{
			printf("O usuario foi deletado com sucesso!. \n"); //Resposta ao usuario
			system("pause"); //Pausa o programa
		}
		
}

int main() //Função responsavel por abrir o menu de opções ao usuario
{   	int opcao=0; //definindo as variaveis
    	int laco=1;
	
    	for(laco=1;laco=1;)
	{
	
	   system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	   printf("###CARTÓRIO EBAC###\n\n"); //Inicio do menu
	   printf("Escolha a opçao desejada no menu\n\n");
       printf("\t1 registrar nomes\n");
	   printf("\t2 consultar nomes\n");
	   printf("\t3 deletar nomes\n"); 
	   printf("\t4 sair do sistema\n\n");
	   printf("Opcao:");// fim do menu
	
    	scanf("%d", &opcao); //armazenando e escolha do usuario
	
	    system("cls"); //Responsavel por limpar a tela
	    
	    
	    switch(opcao) //inicio da seleção de menu
	    {
	    	case 1:
	    	registro(); //chamada de funções
            break;
            
            case 2:
            consulta(); //chamada de funções
        	break;
        	
        	case 3:
        	deletar(); //chamada de funções
        	break;
        	
        	case 4:
        	printf("Obrigado por utilizar nosso sistema!\n");
        	return 0;
        	break;
        	
        	
        	default:
        	printf("Esta opçao nao esta disponivel!\n"); //Resposta ao usuario
        	system("pause");
        	break; 
        	//Fim da seleção
		}
   }

}
