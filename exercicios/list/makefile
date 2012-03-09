# Compilador utilizado
cc = g++
# PATH raiz para includes
path = ..
# Nome da lista de exercicios
program = list
# Tipo dos elementos do vetor no main
type_main = int
# Tipo dos elementos do vetor nos testes
type_test = std::string

# Gera o binarios do programa e dos testes
all:
	$(cc) -D LType=$(type_main) -I $(path) src/$(program).cc src/main.cc -o main
	$(cc) -D LType=$(type_test) -I $(path) src/$(program).cc test/$(program)_test.cc ../gtest/gtest.cc -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main: executa o programa em main.cc."
	@echo "easy_testing: executa os testes dos exercícios."
	@echo "--------------------------------------------------------------"

clean:
	@rm -f main easy_testing
