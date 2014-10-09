# Compilador utilizado
cc = g++
# PATH raiz para includes
path = .
# Nome da lista de exercicios
program = map
# Tipo da chave dos elementos do vetor no main
type_main = std::string
# Tipo da chave dos elementos do vetor nos testes
type_test = std::string
# Tipo do valor dos elemento
value_type = int

# Gera o binarios do programa e dos testes
all:
	$(cc) -D SType=$(type_main) -D VType=$(value_type) -I $(path) src/$(program).cc src/main.cc -o main
	$(cc) -D SType=$(type_test) -D VType=$(value_type) -I $(path) src/$(program).cc test/$(program)_test.cc gtest/gtest.cc -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main: executa o programa em main.cc."
	@echo "easy_testing: executa os testes dos exercícios."
	@echo "--------------------------------------------------------------"

clean:
	@rm -f main easy_testing

zip:
	zip -r $(CURDIR).zip . -x ".*"
