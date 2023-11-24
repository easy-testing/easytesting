# Compilador utilizado
cc = g++
# PATH raiz para includes
path = .
# Nome da lista de exercicios
program = matrizes

# Flags de compilação
CXXFLAGS = -std=c++11

# Gera o binario do programa e de testes e mantem dependencias
all: clean main.o $(program).o $(program)_test.o
	$(cc) -I $(path) $(CXXFLAGS) main.o $(program).o -o main
	$(cc) -I $(path) $(CXXFLAGS) $(program).o $(program)_test.o -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main: executa o programa em main.cpp."
	@echo "easy_testing: testa as funções implementadas em $(program).cpp."
	@echo "--------------------------------------------------------------"

# Roda o programa e deleta dependencias e o binario
run: clean main.o $(program).o
	$(cc) -I $(path) $(CXXFLAGS) main.o $(program).o
	@./main
	@rm -f $(program).o main a.out

# Roda testes e deleta dependencias e o binario
test: clean $(program).o $(program)_test.o
	$(cc) -I $(path) $(CXXFLAGS) $(program).o $(program)_test.o
	@./easy_testing
	@rm -f $(program).o $(program)_test.o a.out easy_testing

main.o:
	$(cc) -I $(path) $(CXXFLAGS) -c src/main.cpp

$(program).o:
	$(cc) -I $(path) $(CXXFLAGS) -c src/$(program).cpp

$(program)_test.o:
	$(cc) -I $(path) $(CXXFLAGS) -c test/$(program)_test.cpp

clean:
	@rm -f main.o $(program).o $(program)_test.o a.out main easy_testing

zip:
	zip -r $(CURDIR).zip . -x ".*"
