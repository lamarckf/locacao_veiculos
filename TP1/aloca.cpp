#include<iostream>
#include<string>
using std::string;
#include "aloca.h"

using namespace std;

typedef struct aluga_carro
{	
	long long int cpf;
	string placa;
	int diaa;
	int mesa;
	int anoa;
	int tempo;
	int diab;
	int mesb;
	int anob;
	
}Aluga_carro;

aluga_carro** cria_aluga(int quantidade)
{
	aluga_carro **aluga_carroc;
	aluga_carroc = new aluga_carro* [quantidade];
	return aluga_carroc;
}



void deleta_aluga (aluga_carro **aluga_carroc)
{
	delete[] aluga_carroc;
}

aluga_carro* criar_aluga (long long int cpf, string placa, int diaa, int mesa, int anoa, int tempo, int diab, int mesb, int anob)
{
	aluga_carro *aluga_carroc;
	aluga_carroc=new aluga_carro;

	aluga_carroc -> cpf = cpf;
	aluga_carroc -> placa = placa;
	aluga_carroc -> diaa = diaa;
	aluga_carroc -> mesa = mesa;
	aluga_carroc -> anoa = anoa;
	aluga_carroc -> tempo = tempo;
	aluga_carroc -> diab = diab;
	aluga_carroc -> mesb = mesb;
	aluga_carroc -> anob = anob;


	return aluga_carroc; 
}

int existe_aluga (aluga_carro *aluga_carroc, long long int cpf)
{

	if(aluga_carroc -> cpf == cpf)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int busca_aluga (aluga_carro **aluga_carroc, long long int cpf,int quantaluga)
{
	int aux=0;
	for(int i = 0; i < quantaluga; i++)
	{
		aux = existe_aluga(aluga_carroc[i], cpf);
		if(aux == 1)
		{
			return i;
		}
	}
	return 0;	
}

void exclui_aluga (aluga_carro **aluga_carroc, long long int cpf,int quantaluga)
{
	int aux=busca_aluga(aluga_carroc, cpf, quantaluga);
	if (aux==0)
	{
		
	}
	else
	{
		for (aux=aux;aux<quantaluga;aux++)
		{
			if(aluga_carroc[aux+1]!=NULL)
			{
				aluga_carroc[aux] -> cpf = aluga_carroc[aux+1] -> cpf;
				aluga_carroc[aux]-> placa = aluga_carroc[aux+1]-> placa;
				aluga_carroc[aux] -> diaa = aluga_carroc[aux+1] -> diaa;
				aluga_carroc[aux] -> mesa = aluga_carroc[aux+1] -> mesa;
				aluga_carroc[aux] -> anoa = aluga_carroc[aux+1] -> anoa;
				aluga_carroc[aux] -> tempo = aluga_carroc[aux+1] -> tempo;
				aluga_carroc[aux] -> diab = aluga_carroc[aux+1] -> diab;
				aluga_carroc[aux] -> mesb = aluga_carroc[aux+1] -> mesb;				
				aluga_carroc[aux] -> anob = aluga_carroc[aux+1] -> anob;
			}
		}
	}
}

void acessa_aluga(aluga_carro **aluga_carroc,long long int cpf, string placa, int diaa, int mesa, int anoa, int tempo, int diab, int mesb, int anob,int quantaluga)
{
	int aux=busca_aluga(aluga_carroc, cpf, quantaluga);
	if (aux==0)
	{
		
	}
	else
	{
		cpf = aluga_carroc[aux] -> cpf;
		placa = aluga_carroc[aux]-> placa;
		diaa = aluga_carroc[aux] -> diaa;
		mesa = aluga_carroc[aux] -> mesa;
		anoa = aluga_carroc[aux] -> anoa;
		tempo = aluga_carroc[aux] -> tempo;
		diab = aluga_carroc[aux] -> diab;
		mesb = aluga_carroc[aux] -> mesb;				
		anob = aluga_carroc[aux] -> anob;
	}
}

void altera_aluga(aluga_carro **aluga_carroc,long long int cpf, string placa, int diaa, int mesa, int anoa, int tempo, int diab, int mesb, int anob,int quantaluga)
{
	int aux=busca_aluga(aluga_carroc, cpf, quantaluga);
	if (aux==0)
	{
		
	}
	else
	{
		aluga_carroc[aux] -> cpf = cpf;
		aluga_carroc[aux]-> placa=placa;
		aluga_carroc[aux] -> diaa=diaa;
		aluga_carroc[aux] -> mesa=mesa;
		aluga_carroc[aux] -> anoa=anoa;
		aluga_carroc[aux] -> tempo=tempo;
		aluga_carroc[aux] -> diab=diab;
		aluga_carroc[aux] -> mesb=mesb;				
		aluga_carroc[aux] -> anob=anob;
	
	}
}

void imprimi_aluga(aluga_carro **aluga_carroc, int quantaluga)
{
	cout<<"Carros alugados."<<endl;
	for(int i=0; i< quantaluga; i++)
	{
		cout<< "Carro "<<i+1 <<":"<<endl;
		cout<<"Alugado para o cliente de cpf: "<< aluga_carroc[i] -> cpf<<endl;
		cout<< "Placa: "<<aluga_carroc[i]-> placa<<endl;
		cout<< "Data do aluguel: "<<aluga_carroc[i] -> diaa<<"/"<<aluga_carroc[i] -> mesa<<"/"<<aluga_carroc[i] -> anoa<<endl;
		cout<< "Tempo de aluguel: "<<aluga_carroc[i] -> tempo<<endl;
		cout<< "Data da entrega: "<<aluga_carroc[i] -> diab<<"/"<<aluga_carroc[i] -> mesb<<"/"<<aluga_carroc[i] -> anob<<endl;
	}
}