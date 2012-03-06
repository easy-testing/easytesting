# Compilador utilizado
cc = g++
# PATH raiz para includes
path = ../
# Nome da lista de exercicios
program = classes
type = _

# Gera o binario do programa e de testes e mantem dependencias
all: clean main.o ponto.o retangulo.o triangulo.o circunferencia.o $(program)_test.o gtest.o
	$(cc) -I $(path) main.o ponto.o retangulo.o triangulo.o circunferencia.o -o main
	$(cc) -I $(path) ponto.o retangulo.o triangulo.o circunferencia.o $(program)_test.o gtest.o -o easy_testing
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

ponto.o:
	$(cc) -I $(path) -c src/ponto.cc -D$(type)

triangulo.o:
	$(cc) -I $(path) -c src/triangulo.cc -D$(type)

retangulo.o:
	$(cc) -I $(path) -c src/retangulo.cc -D$(type)

circunferencia.o:
	$(cc) -I $(path) -c src/circunferencia.cc -D$(type)

$(program)_test.o:
	$(cc) -I $(path) -c test/$(program)_test.cc -D$(type)

gtest.o:
	$(cc) -I $(path) -c ../gtest/gtest.cc

clean:
	@rm -f main.o $(program).o $(program)_test.o gtest.o a.out
