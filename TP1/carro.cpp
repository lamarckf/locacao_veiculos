#include<iostream>
#include<string>
using std::string;
#include "carro.h"

using namespace std;

typedef struct carro
{	
	int ano;
	string fabricante;
	string modelo;
	string placa;
	int valor;
	int aluga;
	
}Carro;

carro** cria_carros(int quantidade)
{
	carro **carroc;
	carroc = new carro* [quantidade];
	return carroc;
}

void deleta_carro (carro **carroc)
{
	delete[] carroc;
}

carro* criar_carro(int ano, string fabricante, string modelo, string placa, int valor, int aluga)
{

	carro *carroc;
	carroc= new carro;

	carroc -> ano = ano;
	carroc -> fabricante = fabricante;
	carroc -> modelo = modelo;
	carroc -> placa = placa;
	carroc -> valor = valor;
	carroc -> aluga = aluga;
	return carroc;        

}

int existe_carro(Carro *carroc, string placa)
{

	if(carroc -> placa == placa)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int busca_carro(carro ** listaDeCarros, string placa, int quantCarros)
{
	int aux=0;
	for(int i = 0; i < quantCarros; i++)
	{
		aux = existe_carro(listaDeCarros[i], placa);
		if(aux == 1)
		{
			return i;
		}
	}
	return 0;	
}
int busca_disponivel(Carro *carroc)
{

	if(carroc -> aluga == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}


void exclui_carro (carro ** listaDeCarros, string placa, int quantidade_carros)
{
	int aux=busca_carro(listaDeCarros, placa, quantidade_carros);
	if (aux==0)
	{
		cout<<"Carro nao existe."<<endl;
	}
	else
	{
		for (aux=aux;aux<quantidade_carros;aux++)
		{
			if(listaDeCarros[aux+1]!=NULL)
			{
				listaDeCarros[aux]-> ano = listaDeCarros[aux+1]-> ano;
				listaDeCarros[aux] -> fabricante = listaDeCarros[aux+1] -> fabricante;
				listaDeCarros[aux] -> modelo = listaDeCarros[aux+1] -> modelo;
				listaDeCarros[aux] -> placa = listaDeCarros[aux+1] -> placa;
				listaDeCarros[aux] -> valor = listaDeCarros[aux+1] -> valor;
				listaDeCarros[aux] -> aluga = listaDeCarros[aux+1] -> aluga;
			}
		}
	}
}

void acessa_carro (carro **listaDeCarros, int ano, string fabricante, string modelo, string placa, int valor, int aluga, int quantidade_carros)
{
	int aux=busca_carro(listaDeCarros, placa, quantidade_carros);
	if (aux==0)
	{
		
	}
	else
	{
		ano = listaDeCarros[aux]-> ano;
		fabricante = listaDeCarros[aux] -> fabricante;
		modelo = listaDeCarros[aux] -> modelo;
		placa = listaDeCarros[aux] -> placa;
		valor = listaDeCarros[aux] -> valor;
		aluga = listaDeCarros[aux] -> aluga;
	}
}

void altera_carro (carro **listaDeCarros, int ano, string fabricante, string modelo, string placa, int valor, int aluga, int quantidade_carros)
{
	int aux=busca_carro(listaDeCarros, placa, quantidade_carros);
	if (aux==0)
	{
		
	}
	else
	{
		listaDeCarros[aux]-> ano = ano;
		listaDeCarros[aux] -> fabricante = fabricante;
		listaDeCarros[aux] -> modelo = modelo;
		listaDeCarros[aux] -> placa = placa;
		listaDeCarros[aux] -> valor = valor;
		listaDeCarros[aux] -> aluga = aluga;
	}
}

void imprimi_carro(carro ** listaDeCarros, int quantidade_carros)
{
	cout<<"Carros armazenados."<<endl;
	for(int i=0; i< quantidade_carros; i++)
	{
		cout<< "Carro "<<i+1 <<":"<<endl;
		cout<< "Ano: "<<listaDeCarros[i]-> ano<<endl;
		cout<< "Fabricante: "<<listaDeCarros[i] -> fabricante<<endl;
		cout<< "Modeo: "<<listaDeCarros[i] -> modelo<<endl;
		cout<< "Placa: "<<listaDeCarros[i] -> placa<<endl;
		cout<< "Valor de locacao: "<<listaDeCarros[i] -> valor<<endl;
		if(listaDeCarros[i] -> aluga==0)
		{
			cout<<"Carro disponivel"<<endl;
		}
		else
		{
			cout<<"Carro alugado"<<endl;
		}
		
	}
}