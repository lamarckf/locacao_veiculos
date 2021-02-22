#ifndef CARRO_H
#define CARRO_H
#include<string>

typedef struct carro Carro;

carro** cria_carros(int quantidade);
void deleta_carro (carro **carroc);
carro* criar_carro(int ano, string fabricante, string modelo, string placa, int valor, int aluga);
int existe_carro(Carro *carro, string placa);
int busca_carro(carro ** listaDeCarros, string placa, int quantCarros);
int busca_disponivel(Carro *carroc);
void exclui_carro (carro ** listaDeCarros, string placa, int quantidade_carros);
void acessa_carro (carro **listaDeCarros, int ano, string fabricante, string modelo, string placa, int valor, int aluga, int quantidade_carros);
void altera_carro (carro **listaDeCarros, int ano, string fabricante, string modelo, string placa, int valor, int aluga, int quantidade_carros);
void imprimi_carro(carro ** listaDeCarros, int quantidade_carros);

#endif