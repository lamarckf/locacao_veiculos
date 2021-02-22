#include <iostream>
#include <string>
using std::string;
#include "dados.h"
using namespace std;

typedef struct cliente
{	
	string nome;
	long long int cpf;
	long long int numero_habilitacao;
	string profissao;
	string rua;
	int numero;
	string cidade;
	string estado;
	int CEP;
	
}Cliente;

cliente** cria_clientes(int quantidade)
{
	cliente **clientec;
	clientec=new cliente*[quantidade];
	return clientec;
}

void deleta_cliente (cliente **clientec)
{
	delete[]clientec;
}

cliente* criar_cliente(string nome, long long int cpf, long long int numero_habilitacao, string profissao, string rua, int numero, string cidade, string estado, int CEP)
{

	cliente *clientec;
	clientec=new cliente;

	clientec -> nome = nome;
	clientec -> cpf = cpf;
	clientec -> numero_habilitacao = numero_habilitacao;
	clientec -> profissao = profissao;
	clientec -> rua = rua;
	clientec -> numero = numero;
	clientec -> cidade = cidade;
	clientec -> estado = estado;
	clientec -> CEP = CEP;
	

	return clientec;        

}

int existe_cliente(cliente *clientec, long long int cpf)
{

	if(clientec -> cpf == cpf)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int busca_cliente(cliente **clientec, long long int cpf, int quantcliente)
{
	int aux=0;
	for(int i = 0; i < quantcliente; i++)
	{
		aux = existe_cliente(clientec[i], cpf);
		if(aux == 1)
		{
			return 1;
		}
	}
	return 0;	
}

void exclui_cliente (cliente **clientec, long long int cpf, int quantcliente)
{
	int aux=busca_cliente(clientec, cpf, quantcliente);
	if (aux==0)
	{
		cout<<"Cliente nao existe."<<endl;
	}
	else
	{
		for (aux=aux;aux<quantcliente;aux++)
		{
			if(clientec[aux+1]!=NULL)
			{
				clientec[aux] -> nome = clientec[aux+1]-> nome;
				clientec[aux] -> cpf = clientec[aux+1] -> cpf;
				clientec[aux] -> numero_habilitacao = clientec[aux+1] -> numero_habilitacao;
				clientec[aux] -> profissao = clientec[aux+1] -> profissao;
				clientec[aux] -> rua = clientec[aux+1] -> rua;
				clientec[aux] -> numero = clientec[aux+1] -> numero;
				clientec[aux] -> cidade = clientec[aux+1] -> cidade;
				clientec[aux] -> estado = clientec[aux+1] -> estado;
				clientec[aux] -> CEP = clientec[aux+1] -> CEP;
			}
		}
	}
}

void acessa_cliente (cliente **clientec, string nome, long long int cpf, long long int numero_habilitacao, string profissao, string rua, int numero, string cidade, string estado, int CEP, int quantcliente)
{
	int aux=busca_cliente(clientec, cpf, quantcliente);
	if (aux==0)
	{
		
	}
	else
	{
		nome = clientec[aux]-> nome;
		cpf = clientec[aux] -> cpf;
		numero_habilitacao = clientec[aux] -> numero_habilitacao;
		profissao = clientec[aux] -> profissao;
		rua = clientec[aux] -> rua;
		numero = clientec[aux] -> numero;
		cidade = clientec[aux] -> cidade;
		estado = clientec[aux] -> estado;
		CEP = clientec[aux] -> CEP;
	}
}

void altera_cliente (cliente **clientec, string nome, long long int cpf, long long int numero_habilitacao, string profissao, string rua, int numero, string cidade, string estado, int CEP, int quantcliente)
{
	int aux=busca_cliente(clientec, cpf, quantcliente);
	if (aux==0)
	{
		
	}
	else
	{
		clientec[aux] -> nome = nome;
		clientec[aux] -> cpf = cpf;
		clientec[aux] -> numero_habilitacao = numero_habilitacao;
		clientec[aux] -> profissao = profissao;
		clientec[aux] -> rua = rua;
		clientec[aux] -> numero = numero;
		clientec[aux] -> cidade = cidade;
		clientec[aux] -> estado = estado;
		clientec[aux] -> CEP = CEP;
	}
}

void imprimi_cliente(cliente **clientec, int quantcliente)
{
	cout<<"Clientes armazenados."<<endl;
	for(int i=0; i< quantcliente; i++)
	{
		cout<< "Cliente "<<i+1 <<":"<<endl;
		cout<< "Nome: "<<clientec[i] -> nome<<endl;
		cout<< "CPF: "<<clientec[i] -> cpf <<endl;
		cout<< "Numero de habilitacao: "<<clientec[i] -> numero_habilitacao<<endl;
		cout<< "Profissao: "<<clientec[i] -> profissao <<endl;
		cout<< "Endereco: "<<endl << clientec[i] -> rua<<" numero "<<clientec[i] -> numero <<endl;
		cout<< "Cidade: "<<clientec[i] -> cidade<<endl<<"Estado: "<<clientec[i] -> estado <<" CEP: "<<clientec[i] -> CEP<<endl;
		
	}
}