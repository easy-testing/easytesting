# Compilador utilizado
cc = g++
# PATH raiz para includes
path = ../
# Nome da lista de exercicios
program = condicionais
type = _

# Gera o binario do programa e de testes e mantem dependencias
all: clean main.o $(program).o $(program)_test.o gtest.o
	$(cc) -I $(path) main1.o $(program).o -o main1
	$(cc) -I $(path) main2.o $(program).o -o main2
	$(cc) -I $(path) $(program).o $(program)_test.o gtest.o -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main1: executa o programa em main1.cc."
	@echo "main2: executa o programa em main2.cc."
	@echo "easy_testing: testa as funções implementadas em $(program).cc."
	@echo "--------------------------------------------------------------"

# Roda o programa e deleta dependencias e o binario
run_main1: clean main1.o $(program).o
	$(cc) -I $(path) main1.o $(program).o
	@./a.out
	@rm -f $(program).o main1.o a.out

# Roda o programa e deleta dependencias e o binario
run_main2: clean main2.o $(program).o
	$(cc) -I $(path) main2.o $(program).o
	@./a.out
	@rm -f $(program).o main2.o a.out

# Roda testes e deleta dependencias e o binario
test: clean $(program).o $(program)_test.o gtest.o
	$(cc) -I $(path) $(program).o $(program)_test.o gtest.o
	@./a.out
	@rm -f $(program).o $(program)_test.o gtest.o a.out

main1.o:
	$(cc) -I $(path) -c src/main1.cc -D$(type)
main2.o:
	$(cc) -I $(path) -c src/main2.cc -D$(type)

$(program).o:
	$(cc) -I $(path) -c src/$(program).cc -D$(type)

$(program)_test.o:
	$(cc) -I $(path) -c test/$(program)_test.cc -D$(type)

gtest.o:
	$(cc) -I $(path) -c ../gtest/gtest.cc

clean:
	@rm -f main1.o main2.o $(program).o $(program)_test.o gtest.o a.out
