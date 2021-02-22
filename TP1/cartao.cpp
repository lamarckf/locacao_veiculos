#include<iostream>
#include<string>
using std::string;
#include "cartao.h"

using namespace std;

typedef struct cartao
{	
	long long int cpf;
	string nome;
	int numero;
	int dia;
	int mes;
	int ano;
	int codigo;
	string bandeira;
	
}Cartao;

cartao** cria_cartao(int quantidade)
{
	cartao **cartaoc;
	cartaoc = new cartao* [quantidade];
	return cartaoc;
}

void deleta_cartao (cartao **cartaoc)
{
	delete[] cartaoc;
}

cartao* criar_cartao(long long int cpf, string nome, int numero, int dia, int mes, int ano, int codigo, string bandeira)
{

	cartao *cartaoc;
	cartaoc= new cartao;

	cartaoc -> cpf = cpf;
	cartaoc -> nome = nome;
	cartaoc -> numero = numero;
	cartaoc -> dia = dia;
	cartaoc -> mes = mes;
	cartaoc -> ano = ano;
	cartaoc -> codigo = codigo;
	cartaoc -> bandeira = bandeira;
	return cartaoc;        

}

int existe_cartao (cartao *cartaoc, long long int cpf)
{

	if(cartaoc -> cpf == cpf)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int busca_cartao(cartao ** listaDecartao, long long int cpf, int quantcartao)
{
	int aux=0;
	for(int i = 0; i < quantcartao; i++)
	{
		aux = existe_cartao(listaDecartao[i], cpf);
		if(aux == 1)
		{
			return i;
		}
	}
	return 0;	
}

void exclui_cartao(cartao ** listaDecartao, long long int cpf, int quantcartao)
{
	int aux=busca_cartao(listaDecartao, cpf, quantcartao);
	if (aux==0)
	{
		
	}
	else
	{
		for (aux=aux;aux<quantcartao;aux++)
		{
			if(listaDecartao[aux+1]!=NULL)
			{
				listaDecartao[aux]-> cpf = listaDecartao[aux+1]-> cpf;
				listaDecartao[aux] -> nome = listaDecartao[aux+1] -> nome;
				listaDecartao[aux] -> numero = listaDecartao[aux+1] -> numero;
				listaDecartao[aux] -> dia = listaDecartao[aux+1] -> dia;
				listaDecartao[aux] -> mes = listaDecartao[aux+1] -> mes;
				listaDecartao[aux] -> ano = listaDecartao[aux+1] -> ano;
				listaDecartao[aux] -> codigo = listaDecartao[aux+1] -> codigo;				
				listaDecartao[aux] -> bandeira = listaDecartao[aux+1] -> bandeira;
			}
		}
	}
}

void acessa_cartao(cartao ** listaDecartao, long long int cpf, string nome, int numero, int dia, int mes, int ano, int codigo, string bandeira, int quantcartao)
{
	int aux=busca_cartao(listaDecartao, cpf, quantcartao);
	if (aux==0)
	{
		
	}
	else
	{
		cpf = listaDecartao[aux]-> cpf;
		nome = listaDecartao[aux] -> nome;
		numero = listaDecartao[aux] -> numero;
		dia = listaDecartao[aux] -> dia;
		mes = listaDecartao[aux] -> mes;
		ano = listaDecartao[aux] -> ano;
		codigo = listaDecartao[aux] -> codigo;				
		bandeira = listaDecartao[aux] -> bandeira;
	}
}

void altera_cartao(cartao ** listaDecartao, long long int cpf, string nome, int numero, int dia, int mes, int ano, int codigo, string bandeira, int quantcartao)
{
	int aux=busca_cartao(listaDecartao, cpf, quantcartao);
	if (aux==0)
	{
		
	}
	else
	{
		listaDecartao[aux] -> cpf = cpf;
		listaDecartao[aux] -> nome = nome;
		listaDecartao[aux] -> numero = numero;
		listaDecartao[aux] -> dia = dia;
		listaDecartao[aux] -> mes = mes;
		listaDecartao[aux] -> ano = ano;
		listaDecartao[aux] -> codigo = codigo;
		listaDecartao[aux] -> bandeira = bandeira;
	}
}
