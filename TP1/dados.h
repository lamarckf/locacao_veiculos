#ifndef DADOS_H
#define DADOS_H
#include<string>

typedef struct cliente Cliente;

cliente** cria_clientes(int quantidade);
void deleta_cliente (cliente **clientec);
cliente* criar_cliente(string nome, long long int cpf, long long int numero_habilitacao, string profissao, string rua, int numero, string cidade, string estado, int CEP);
int existe_cliente(cliente *clientec, long long int cpf);
int busca_cliente(cliente **clientec, long long int cpf, int quantcliente);
void exclui_cliente (cliente **clientec, long long int cpf, int quantcliente);
void acessa_cliente (cliente **clientec, string nome, long long int cpf, long long int numero_habilitacao, string profissao, string rua, int numero, string cidade, string estado, int CEP, int quantcliente);
void altera_cliente (cliente **clientec, string nome, long long int cpf, long long int numero_habilitacao, string profissao, string rua, int numero, string cidade, string estado, int CEP, int quantcliente);
void imprimi_cliente(cliente **clientec, int quantcliente);

#endif
