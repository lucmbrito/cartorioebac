#include <stdio.h>// bliblioteca de comunicação com usuario
#include <stdlib.h>//bliblioteca de alocação de espaço de memoria
#include <locale.h>//biblioteca de alocaçao  de texto por regiao
#include <string.h> //biblioteca responsavel cuidar das strings

int registro()
{
	//incio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);//armazena o string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen (arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
		
}

int consulta()
{
	char cpf[40];//criação de variaveis string
	char conteudo[200];
	
	printf("digite o cpf a ser consultado");
	scanf("%s", cpf);//armazena o string
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("nao foi possivel abrir o arquivo, nao localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas sao as informaçoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{

	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuario não se encrontra no sistema. \n");
		system("pause");
		
		
	}

}


int main()
	{
	int opcao=0; //Definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	
	printf("### Cartório do EBAC ###\n\n");
	printf("Login de administrador!\n\n Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	if(senhadigitada[10] == "admin")
	
	{
		for(laco=1;laco=1;)
		{
	  
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório do EBAC ###\n\n"); //incico do menu
		printf("Escolha a Opção desejada do menu:\n\n");
		printf("\t1 -Registrar Nomes\n");
		printf("\t2 -Consultar Nomes\n");
		printf("\t3 -Deletar Nomes\n");
		printf("\t4- Sair do sistema\n");
		printf("\t5- Voltar ao menu\n");
		printf("\t6- Inserir mais dados\n");
		printf("Opção:");//fim do menu
	
		scanf("%s", &opcao);//armazenamento da escolha do usuario
	
		system("cls");
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
				
		
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
				
			case 4:
			printf("obrigada por utilizar o sistema!");
			return 0;
			break;	
	
	        case 5: 
	        printf("voltar ao menu");
	        return 0;
	        break;
	        
	        case 6: 
	        printf("continuar e inserir mais dados");
	        return 0;
	        break;
	        
	        
			default:
			printf("essa opçao nao esta disponivel\n");
			system("pause");
			break;	
		}//fim da seleção
			
		
	    
	  	}  
 
  	}
	
    else
        printf("Senha Incorreta!");
	
	
}

