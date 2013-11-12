# Compilador utilizado
cc = c++
# PATH raiz para includes
path = ..
# Nome da lista de exercicios
program = unordered_map
# Tipo dos elementos do vetor no main
type_key = std::string
# Tipo dos elementos do vetor nos testes
type_value = int

# Gera o binarios do programa e dos testes
all:
	$(cc) -D SType=$(type_key) -D VType=$(type_value) -I $(path) ../ordered_map/src/map.cc src/$(program).cc src/main.cc -o main
	$(cc) -D SType=$(type_key) -D VType=$(type_value) -I $(path) ../ordered_map/src/map.cc src/$(program).cc test/$(program)_test.cc ../gtest/gtest.cc -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main: executa o programa em main.cc."
	@echo "easy_testing: executa os testes dos exercícios."
	@echo "--------------------------------------------------------------"

clean:
	@rm -f main easy_testing
