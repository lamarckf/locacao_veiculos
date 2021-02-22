#include "labirinto.h"
#include <iostream>
#include <cstring>


using namespace std;

//------------------------------------------------------------------------------------------------------------------
struct matriz{

	int linha;
	int coluna;
	string **conteudo;

};
//------------------------------------------------------------------------------------------------------------------
//CRIAR MATRIZ(LABIRINTO)
Matriz *AlocarMatriz(int linha, int coluna){

	Matriz *mat = new Matriz;
	mat -> linha = linha;
	mat -> coluna = coluna;
	mat -> conteudo = new string*[mat -> linha];

	for(int i = 0; i < linha; i ++){
		mat -> conteudo[i] = new string[coluna];
	}

	return mat;
}
//------------------------------------------------------------------------------------------------------------------
//MONTAR LABIRINTO RECEBENDO COMO PARAMETRO PAREDE(***), ESPAÇO VAZIO(000), INICIO(ini), FIM(fim)
void montaLabirinto(Matriz *mat, int linha, int coluna, string conteudo){

	mat -> conteudo[linha][coluna] = conteudo;
}
//------------------------------------------------------------------------------------------------------------------

void imprimirLabirinto(Matriz *mat){

	for(int i = 0; i < mat -> linha; i ++){
		for(int j = 0; j < mat -> coluna; j ++){
			cout << mat -> conteudo[i][j] << "   ";
		}
		cout << endl;
	}
}
//------------------------------------------------------------------------------------------------------------------

void deletarLabirinto(Matriz **mat){

	for(int i = 0; i < (*mat) -> linha; i++){
		delete [](*mat) -> conteudo[i];
	}
	delete [] (*mat) -> conteudo;
	delete *mat;
}

//------------------------------------------------------------------------------------------------------------------

void percorreCaminho_Recirsiva(Matriz **mat, int linhaAux, int colunaAux){

	//condicao de parada
	if(((*mat) -> conteudo[linhaAux][colunaAux]) == "fim")
		return;

	else{

		//faz com que o inicio nao seja preenchido com caminho (111)
		if(((*mat) -> conteudo[linhaAux][colunaAux]) != "ini")
        	marcaCaminho(*mat, linhaAux, colunaAux);

		//Confere a casa de baixo
		if(linhaAux + 1 < (*mat) -> linha && (*mat) -> conteudo[linhaAux + 1][colunaAux] == "000")
            percorreCaminho_Recirsiva(mat, linhaAux + 1, colunaAux);//.....................................CHAMADA RECURSIVA

		//Confere a casa de cima
		if(linhaAux - 1 >= 0 && (*mat) -> conteudo[linhaAux - 1][colunaAux] == "000")
            percorreCaminho_Recirsiva(mat, linhaAux - 1, colunaAux);//.....................................CHAMADA RECURSIVA

		//Comfere a cada da direita
		if(colunaAux + 1 < (*mat) -> coluna && (*mat) -> conteudo[linhaAux][colunaAux + 1] == "000")
            percorreCaminho_Recirsiva(mat, linhaAux, colunaAux + 1);//.....................................CHAMADA RECURSIVA

		//Confere a casa da esquerda
		if(colunaAux - 1 >= 0 && (*mat) -> conteudo[linhaAux][colunaAux - 1] == "000")
            percorreCaminho_Recirsiva(mat, linhaAux, colunaAux - 1);//.....................................CHAMADA RECURSIVA

		return;
	}
}

//------------------------------------------------------------------------------------------------------------------
//MARCA CAMINHO PERCORRIDO PELA FUNÇÃO 
void marcaCaminho(Matriz *mat, int linha, int coluna){

	mat -> conteudo[linha][coluna] = "111";

}


//------------------------------------------------------------------------------------------------------------------

void percorreCaminho_Iterativa(Matriz **mat){

	bool aux = false;
	int linha  = 0;
	int coluna = 0;

	while(aux != true){

		if((*mat) -> conteudo[linha][coluna] == "fim")
			aux = true;

		 if(((linha + 1 < (*mat) -> linha) && ((*mat) -> conteudo[linha + 1][coluna] == "000")) || ((*mat) -> conteudo[linha][coluna] == "fim")){
			linha++;
			marcaCaminho(*mat, linha, coluna);	
			
		}

		 if(((linha - 1 >= 0) && ((*mat) -> conteudo[linha - 1][coluna] == "000")) || ((*mat) -> conteudo[linha][coluna] == "fim")){
			linha--;
			marcaCaminho(*mat, linha, coluna);	
			
		}	
		
		 if(((coluna + 1 < (*mat) -> coluna) && ((*mat) -> conteudo[linha][coluna + 1] == "000")) || ((*mat) -> conteudo[linha][coluna] == "fim")){
			coluna++;
			marcaCaminho(*mat, linha, coluna);	
			
		}
			
		 if(((coluna - 1 >= 0) && ((*mat) -> conteudo[linha][coluna - 1] == "000")) || ((*mat) -> conteudo[linha][coluna] == "fim")){
			coluna--;
			marcaCaminho(*mat, linha, coluna);	
			

		}
	
	}	 
}
