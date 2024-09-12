#include <stdio.h>  //biblioteca de comunica�ao com o usuario
#include <stdlib.h> //biblioteca de aloca�ao de memoria
#include <locale.h> //biblioteca de aloca�ao de texto por regiao
#include <string.h> //bibilioteca responsavel por cuidar das string's
int registro() //Fun�ao responsavel por cadastrar o usuario.
{
	// Inicio da cria�ao de vari�veis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// Final da cria�ao de vari�veis/string
		
		printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o de usu�rio
		scanf("%s", cpf); //%s refere-se a string, que armazena a informa��o trazida pelo usuario
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das string's
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
		fprintf(file, cpf); //salvo valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //Atualiza a informa��o dentro do arquivo "a" significa atualizar
		fprintf(file, ","); //salva as informa�oes dentro do arquivo, a "," serve para espa�amento das informa��es
		fclose(file); //fecha o aqruivo
		
		printf("Digite o nome a ser cadastrado: "); //Coletando inform��es do usuario
		scanf("%s", nome); //Refere-se a string, que armazena a informa��o trazida pelo usuario
		
		file = fopen(arquivo, "a"); //Atualiza a informa��o dentro do arquivo "a" significa atualizar
		fprintf(file, nome); //Salva o valor da variavel
		fclose(file); //Fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usuario
		scanf("%s", sobrenome); //Referente a string, que armazena a informa��o trazida pelo usuario
		
		file = fopen(arquivo, "a"); //Atualiza as informa��es, "a" significa atualizar
		fprintf(file,sobrenome); //Salva a informa��o no aqruivo
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //Atualiza a informa��o dentro do arquivo, "a" significa atualizar
		fprintf(file, ","); //salva as informa�oes dentro do arquivo, a "," serve para espa�amento das informa��es
		fclose(file); //fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: "); //Coletando inform��es do usuario
		scanf("%s",cargo); //%s refere-se a string, que armazena a informa��o trazida pelo usuario
		
		file = fopen(arquivo, "a"); //Atualiza as informa��es, "a" significa atualizar
		fprintf(file,cargo); //Salva as informa�oes dentro do arquivo
		fclose(file); //fecha o arquivo
		
		system("pause"); //Pausa o programa
		
} 	

int consulta() //Fun��o responsavel por consultar um usuario
{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		char cpf[40]; //Variavel do tipo "char"(caracter) string
		char conteudo[200]; //Variavel do tipo "char"(caracter) string
		
		printf("Digite o CPF a ser consultado: "); //Coletando informa��es do usuario
		scanf("%s", cpf); //%s refere-se a string, que armazena as informa��es do usuario
		
		FILE *file; //Cria o arquivo
		file = fopen(cpf, "r"); //Le o arquivo
		
		if(file == NULL) //Refere-se a nao existencia do arquivo
		{
			printf("N�o foi possivel abrir o arquivo, nao localizado! \n"); //Resposta ao usuario caso o arquivo nao exista
		}
	
	
		while(fgets(conteudo, 200, file) != NULL) //La�o de repeti��o "while", 
		{
			printf("\nEssas s�o as informa��es do usu�rio: "); //Resposta ao usu�rio
			printf("%s",conteudo); //Salva o conte�do dentro da string
			printf("\n,\n");
		}
		
		system("pause"); //Pausa o programa
	
}

int deletar() //fun��o responsavel por deletar um usuario
{
		char cpf[40]; //Variavel do tipo "char"
		
		printf("Digite o CPF do usuario a ser deletado: "); //Coletando informa��es do usuario
		scanf("%s", cpf); //Armazena informa��es do usuario na string
		
		remove(cpf); //remove o usuario
		
		FILE *file; //cria o arquivo
		file = fopen(cpf, "r"); //Le o arquivo
		
		if(file == NULL) //Refere-se a nao existencia do arquivo
		{
			printf("O usuario foi deletado com sucesso!. \n"); //Resposta ao usuario
			system("pause"); //Pausa o programa
		}
		
}

int main() //Fun��o responsavel por abrir o menu de op��es ao usuario
{   	int opcao=0; //definindo as variaveis
    	int laco=1;
	
    	for(laco=1;laco=1;)
	{
	
	   system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	   printf("###CART�RIO EBAC###\n\n"); //Inicio do menu
	   printf("Escolha a op�ao desejada no menu\n\n");
       printf("\t1 registrar nomes\n");
	   printf("\t2 consultar nomes\n");
	   printf("\t3 deletar nomes\n"); 
	   printf("\t4 sair do sistema\n\n");
	   printf("Opcao:");// fim do menu
	
    	scanf("%d", &opcao); //armazenando e escolha do usuario
	
	    system("cls"); //Responsavel por limpar a tela
	    
	    
	    switch(opcao) //inicio da sele��o de menu
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
            break;
            
            case 2:
            consulta(); //chamada de fun��es
        	break;
        	
        	case 3:
        	deletar(); //chamada de fun��es
        	break;
        	
        	case 4:
        	printf("Obrigado por utilizar nosso sistema!\n");
        	return 0;
        	break;
        	
        	
        	default:
        	printf("Esta op�ao nao esta disponivel!\n"); //Resposta ao usuario
        	system("pause");
        	break; 
        	//Fim da sele��o
		}
   }

}
