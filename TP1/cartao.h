#ifndef CARTAO_H
#define CARTAO_H
#include<string>

typedef struct cartao Cartao;

cartao** cria_cartao(int quantidade);
void deleta_cartao (cartao **cartaoc);
cartao* criar_cartao(long long int cpf, string nome, int numero, int dia, int mes, int ano, int codigo, string bandeira);
int existe_cartao (cartao *cartaoc, long long int cpf);
int busca_cartao(cartao ** listaDecartao, long long int cpf, int quantcartao);
void exclui_cartao(cartao ** listaDecartao, long long int cpf, int quantcartao);
void acessa_cartao(cartao ** listaDecartao, long long int cpf, string nome, int numero, int dia, int mes, int ano, int codigo, string bandeira, int quantcartao);
void altera_cartao(cartao ** listaDecartao, long long int cpf, string nome, int numero, int dia, int mes, int ano, int codigo, string bandeira, int quantcartao);

#endif