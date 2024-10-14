#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel pelas string

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/strings
	
	
	printf("digite o CPF a ser cadastrado:\n");//coletando informa��es do usu�rio
	scanf("%s" , cpf);//%s refere-se a salvar a string
	
	strcpy(arquivo, cpf);//respons�vel por copiar os valores da string
	
	FILE *file;//criar o arquivo
	file = fopen(arquivo,"w");//abrindo o arquivo com "w" para ler
	fprintf(file,cpf);//salvar o valor da vari�vel
	fclose(file);//fechando o arquivo
	
	fopen(arquivo , "a");//abrindo o arquivo
	fprintf(file ,",");//salvando o valor da v�riavel
	fclose(file);//fechando o arquivo
	
	printf("digite o nome a ser cadastrado:");//registrando dados 
	scanf("%s", nome);//%s refere-se a salvar a string
	
	file = fopen(arquivo , "a");//abrindo o arquivo
	fprintf(file,nome);//salvando o valor da vari�vel
	fclose(file);//fechando o arquivo
	
	printf("digite o sobrenome a ser cadastrado:");//registrando dados
	scanf("%s", sobrenome);//salvando o valor da vari�vel
	
	file = fopen(arquivo , "a");//abrindo o arquivo
	fprintf(file,sobrenome);//salvando o valor da vari�vel
	fclose(file);//fechando o arquivo
	
	fopen(arquivo , "a");//abrindo o arquivo
	fprintf(file ,",");//salvando o valor da vari�vel
	fclose(file);//fechando o arquivo
	
	printf("digite o cargo a ser cadastrado:");//registrando dados
	scanf("%s", cargo);//salvando o valor da vari�vel
	
	file = fopen(arquivo, "a");//abrindo arquivo
	fprintf(file,cargo);//salvando o valor da var�avel
	fclose(file);//fechando o arquivo
	
	fopen(arquivo , "a");//abrindo o arquivo
	fprintf(file ,",");//salvando o valor da vari�vel
	fclose(file);//fechando o arquivo
		
	
}

int consulta()
{
	//inicio da v�riavel
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser Consultado:");//registrando dados
	scanf("%s", cpf);//refere-se a salvar a string
	
	FILE *file;//consultar o arquivo
	file = fopen(cpf,"r");//abrindo o arquivo "r"
	
	if (file == NULL)
	{
		printf("\n Essas informa��es n�o existem! \n");
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
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
		
	}
}


int main ()
    {  
	int opcao=0; //definindo variaveis
	int x=1;
	
	
	for(x=1;x=1;)
    {
    	system("cls");
    			
     
	setlocale(LC_ALL,"Portuguese");//idioma
	
	printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");	
	printf("\t1 - Registrar nomes\n\n");
	printf("\t2 - Consultar nomes\n\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	
	scanf("%d" , &opcao);//armazenando a escolha do usuario	
	
	system("cls");//falando com o sistema
	
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
		printf("Obrigado por utilizar o sistema!\n ");
		return 0;
		break;
	
		default:
		printf("essa op��o n�o est� dispon�vel. \n");
		system("pause");
		break;
	}
	
	}
    }    
	
