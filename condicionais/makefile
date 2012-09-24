# Compilador utilizado
cc = g++
# PATH raiz para includes
path = ../
# Nome da lista de exercicios
program = condicionais
type = _

# Gera o binario do programa e de testes e mantem dependencias
all: clean main.o $(program).o $(program)_test.o gtest.o
	$(cc) -I $(path) main.o $(program).o -o main
	$(cc) -I $(path) $(program).o $(program)_test.o gtest.o -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main: executa o programa em main.cc."
	@echo "easy_testing: testa as funções implementadas em $(program).cc."
	@echo "--------------------------------------------------------------"

# Roda o programa e deleta dependencias e o binario
run: clean main.o $(program).o
	$(cc) -I $(path) main.o $(program).o
	@./a.out
	@rm -f $(program).o main.o a.out

# Roda testes e deleta dependencias e o binario
test: clean $(program).o $(program)_test.o gtest.o
	$(cc) -I $(path) $(program).o $(program)_test.o gtest.o
	@./a.out
	@rm -f $(program).o $(program)_test.o gtest.o a.out

main.o:
	$(cc) -I $(path) -c src/main.cc -D$(type)

$(program).o:
	$(cc) -I $(path) -c src/$(program).cc -D$(type)

$(program)_test.o:
	$(cc) -I $(path) -c test/$(program)_test.cc -D$(type)

gtest.o:
	$(cc) -I $(path) -c ../gtest/gtest.cc

clean:
	@rm -f main.o $(program).o $(program)_test.o gtest.o a.out
