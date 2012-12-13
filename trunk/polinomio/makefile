# Compilador utilizado
cc = g++
# PATH raiz para includes
path = ../
# Nome da lista de exercicios
program = polinomio

# Gera o binario do programa e de testes e mantem dependencias
all: clean main1.o main2.o $(program).o $(program)_test.o gtest.o
	$(cc) -I $(path) main1.o $(program).o -o main1
	$(cc) -I $(path) main2.o $(program).o -o main2
	$(cc) -I $(path) $(program).o $(program)_test.o gtest.o -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main1: executa o programa da questão 2."
	@echo "main2: executa o programa da questão 3."
	@echo "easy_testing: testa as funções implementadas em $(program).cc."
	@echo "--------------------------------------------------------------"

main1.o:
	$(cc) -I $(path) -c src/main1.cc 

main2.o:
	$(cc) -I $(path) -c src/main2.cc 

$(program).o:
	$(cc) -I $(path) -c src/$(program).cc 

$(program)_test.o:
	$(cc) -I $(path) -c test/$(program)_test.cc 

gtest.o:
	$(cc) -I $(path) -c ../gtest/gtest.cc

clean:
	@rm -f main1.o main2.o $(program).o $(program)_test.o gtest.o a.out main1 main2 easy_testing
