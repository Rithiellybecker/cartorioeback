#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf);
		
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, nao localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	 
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
			
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usu�rio deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
}
int main()
{
	int opcao=0;
	int laco=1;
	char senhadigitada[] = "a";
	int comparacao;
	
	setlocale(LC_ALL, "portuguese");
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login do administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada); //codigo n�o estava funcionando pois coloquei o s maiusculo no %s
	
	comparacao = strcmp(senhadigitada, "admin");
	//strcmp - usado para comparar strings
	
	if(comparacao == 0)
	{
		system("cls");
		for(laco=1;laco=1;)
		{
			
			printf("### Cartorio da EBAC ### \n\n");
			printf("Escolha uma op��o do menu \n\n");
			printf("\t1 - Registro de nomes \n");
			printf("\t2 - Consulta de nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema\n\n");
			printf("op��o: ");
		
			scanf("%d", &opcao);
	
			system("cls");
		
			switch(opcao)
			{
			
				case 1:
					registro();
					break;
				
				case 2:
					consulta();
					break;
				
				case 3:
					deletar();
					break;
				
				case 4:
					printf("Obrigado por utilizar o sistema");
					return 0;
					break;
				
				default:
					printf("Esse usu�rio n�o esta cadastrado no sistema\n\n");
					system("pause");
					break;
			}	
		}
	}
	else
		printf("\nsenha incorreta");
}
