# Compilador utilizado
cc = g++
# PATH raiz para includes
path = .
# Nome da lista de exercicios
program = deque
# Tipo dos elementos do vetor no main1
type_main1 = float
# Tipo dos elementos do vetor no main2
type_main2 = std::string
# Tipo dos elementos do vetor nos testes
type_test = std::string

# Gera o binarios do programa e dos testes
all:
	$(cc) -D DType=$(type_main1) -I $(path) src/$(program).cpp src/main1.cpp -o main1
	$(cc) -D DType=$(type_main2) -I $(path) src/$(program).cpp src/main2.cpp -o main2
	$(cc) -D DType=$(type_test) -I $(path) src/$(program).cpp test/$(program)_test.cpp -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main1: executa o programa em main1.cpp."
	@echo "main2: executa o programa em main2.cpp."
	@echo "easy_testing: executa os testes dos exercícios."
	@echo "--------------------------------------------------------------"

clean:	
	@rm -f main easy_testing

zip:
	zip -r $(CURDIR).zip . -x ".*"
