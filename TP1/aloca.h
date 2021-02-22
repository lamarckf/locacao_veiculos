#ifndef ALOCA_H
#define ALOCA_H
#include<string>

typedef struct aluga_carro Aluga_carro;

aluga_carro** cria_aluga(int tamanho);
void deleta_aluga (aluga_carro **aluga_carroc);
aluga_carro* criar_aluga (long long int cpf, string placa, int diaa, int mesa, int anoa, int tempo, int diab, int mesb, int anob);
int existe_aluga (aluga_carro *aluga_carroc, long long int cpf);
int busca_aluga (aluga_carro **aluga_carroc, long long int cpf,int quantaluga);
void exclui_aluga (aluga_carro **aluga_carroc, long long int cpf,int quantaluga);
void acessa_aluga(aluga_carro **aluga_carroc,long long int cpf, string placa, int diaa, int mesa, int anoa, int tempo, int diab, int mesb, int anob,int quantaluga);
void altera_aluga(aluga_carro **aluga_carroc,long long int cpf, string placa, int diaa, int mesa, int anoa, int tempo, int diab, int mesb, int anob,int quantaluga);
void imprimi_aluga(aluga_carro **aluga_carroc, int quantaluga);
#endif
