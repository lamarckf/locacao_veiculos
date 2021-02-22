#include <iostream>
#include "questao1.h"
#include "questao2.h"
using namespace std;

int main(){


	char escolha_menu;

	cout << "-----------------------------------------------------" << endl;
	cout << "             Trabalho Pratico 01" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl << endl << endl;


	do{

		cout << "-----------------------------------------------------" << endl;
	    cout << "                  MENU PRINCIPAL                     " << endl;
	    cout << "(1) - Questao1                                       " << endl;
	    cout << "(2) - Questao2                                       " << endl;
	    cout << "(0) - Sair                                           " << endl;
	    cout << "Escolha:                                             " << endl;
	    cin  >> escolha_menu;
	    cout << "-----------------------------------------------------" << endl;

	    switch (escolha_menu){
	    	
	    	case '1': {

	    		cout << "-----------------------------------------------------" << endl;
				cout << "          QUESTAO 1 - Locadora de Veiculos           " << endl;

				questao1();

				cout << "-----------------------------------------------------" << endl;

	    	}break;

	    	case '2': {

	    		cout << "-----------------------------------------------------" << endl;
				cout << "               QUESTAO 2 - Labirinto                 " << endl;

				questao2();

				cout << "-----------------------------------------------------" << endl;

	    		
	    	}break;

	    	case '0': {

	    		cout << endl;
	    		cout << "               PROGRAMA FINALIZADO!                  " << endl;
	    		cout << "-----------------------------------------------------" << endl;


	    	}break;

	    	default: {

	    		cout << "Opcao invalida" << endl;

	    	}break;
	    }

	}while(escolha_menu != '0');

	return 0;
}