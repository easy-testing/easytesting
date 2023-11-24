# Compilador utilizado
cc = g++
# PATH raiz para includes
path = .
# Nome da lista de exercicios
program = recursao
# Caminho para o diretório do Doctest
doctest_path = ../doctest/doctest.h


# Gera o binario do programa e de testes e mantem dependencias
all: clean main.o $(program).o $(program)_test.o
	$(cc) -I $(path) main.o $(program).o -o main
	$(cc) -I $(path) $(doctest_path) $(program).o $(program)_test.o -o doctest_testing
	@echo "--------------------------------------------------------------"
	@echo "main: executa o programa em main.cpp."
	@echo "doctest_testing: testa as funções implementadas em $(program).cpp."
	@echo "--------------------------------------------------------------"

# Roda o programa e deleta dependencias e o binario
run: clean main.o $(program).o
	$(cc) -I $(path) main.o $(program).o
	@./main
	@rm -f $(program).o main a.out

# Roda testes e deleta dependencias e o binario
test: clean $(program).o $(program)_test.o
	$(cc) -I $(path) $(program).o $(program)_test.o -o doctest_testing
	@./doctest_testing

main.o:
	$(cc) -I $(path) -c src/main.cpp

$(program).o:
	$(cc) -I $(path) -c src/$(program).cpp

$(program)_test.o:
	$(cc) -I $(path) $(doctest_path) -c test/$(program)_test.cpp

clean:
	@rm -f main.o $(program).o $(program)_test.o doctest_testing

zip:
	zip -r $(CURDIR).zip . -x ".*"
