# Compilador utilizado
cc = g++
# PATH raiz para includes
path = .
# Nome da lista de exercicios
program = vector
# Tipo dos elementos do vetor no main
type_m = double
# Tipo dos elementos do vetor nos testes
type_t = float

# Gera o binarios do programa e dos testes
all:
	$(cc) -D VType=$(type_m) -I $(path) src/$(program).cpp src/main.cpp -o main
	$(cc) -D VType=$(type_t) -I $(path) src/$(program).cpp test/$(program)_test.cpp  -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main: executa o programa em main.cpp."
	@echo "easy_testing: executa os testes dos exercícios."
	@echo "--------------------------------------------------------------"

clean:
	@rm -f main easy_testing

zip:
	zip -r $(CURDIR).zip . -x ".*"
