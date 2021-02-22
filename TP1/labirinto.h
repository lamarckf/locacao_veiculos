#ifndef LABIRINTO_H
#define LABIRINTO_H

#include <iostream>
#include <cstring>
using std::string;

	using namespace std;

	//FUNÇÕES PARA CRIAR, IMPRIMIR E DELETAR O LABIRINTO  
	typedef struct matriz Matriz;
	Matriz *AlocarMatriz(int linha, int coluna);
	void montaLabirinto(Matriz *mat, int linha, int coluna, string conteudo);
	void imprimirLabirinto(Matriz *mat);
	void deletarLabirinto(Matriz **mat);


	//FUNÇÕES PARA ACHAR O CAMINHO NA FOMRA RECURSIVA E INTERATIVA, E MARCAR CAMINHO
    void percorreCaminho_Recirsiva(Matriz **mat, int linhaAux, int colunaAux);
	void marcaCaminho(Matriz *mat, int linha, int coluna);
	void percorreCaminho_Iterativa(Matriz **mat);


#endif
