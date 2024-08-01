# Compilador utilizado
cc = g++ # PATH raiz para includes
path = .
# Nome da lista de exercicios
program = unordered_multiset
# Tipo dos elementos do vetor no main
type_main = std::string
# Tipo dos elementos do vetor nos testes
type_test = std::string

# Gera o binarios do programa e dos testes
all:
	$(cc) -D LType=$(type_main) -D SType=$(type_main) -I $(path) src/multiset.cpp src/$(program).cpp src/main.cpp -o main
	$(cc) -D LType=$(type_test) -D SType=$(type_test) -I $(path) src/multiset.cpp src/$(program).cpp test/$(program)_test.cpp  -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main: executa o programa em main.cpp."
	@echo "easy_testing: executa os testes dos exercícios."
	@echo "--------------------------------------------------------------"

clean:
	@rm -f main easy_testing

zip:
	zip -r $(CURDIR).zip . -x ".*"
