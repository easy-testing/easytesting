# Compilador utilizado
cc = g++ -std=c++0x
# PATH raiz para includes
path = ..
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
	$(cc) -D LType=$(type_main1) -I $(path) src/$(program).cc src/main1.cc -o main1
	$(cc) -D LType=$(type_main2) -I $(path) src/$(program).cc src/main2.cc -o main2
	$(cc) -D LType=$(type_test) -I $(path) src/$(program).cc test/$(program)_test.cc gtest/gtest.cc -o easy_testing
	@echo "--------------------------------------------------------------"
	@echo "main1: executa o programa em main1.cc."
	@echo "main2: executa o programa em main2.cc."
	@echo "easy_testing: executa os testes dos exercícios."
	@echo "--------------------------------------------------------------"

clean:
	@rm -f main easy_testing
