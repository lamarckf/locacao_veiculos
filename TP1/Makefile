all: aloca.o carro.o cartao.o dados.o labirinto.o questao1.o questao2.o main.cpp
	g++ -o main main.cpp aloca.o carro.o cartao.o dados.o labirinto.o questao1.o questao2.o

main.o: main.cpp
	g++ -o main.o -c main.cpp

aloca.o: aloca.cpp
	g++ -o aloca.o -c aloca.cpp

carro.o: carro.cpp
	g++ -o carro.o -c carro.cpp

cartao.o: cartao.cpp
	g++ -o cartao.o -c cartao.cpp

dados.o: dados.cpp
	g++ -o dados.o -c dados.cpp

labirinto.o: labirinto.cpp
	g++ -o labirinto.o -c labirinto.cpp

questao1.o: questao1.cpp
	g++ -o questao1.o -c questao1.cpp

questao2.o: questao2.cpp
	g++ -o questao2.o -c questao2.cpp

clean:
	rm -f *.o main

run:
	./main 