// copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#define DOCTEST_CONFIG_IMPLEMENT

#include "test/funcoes_test.h"
#include "../doctest/doctest.h"

int main(int argc, char** argv) {
    doctest::Context context(argc, argv);

    // Executa todos os testes
    int result = context.run();

    if(context.shouldExit()) // honor query flags and --exit
        return result;

    // Retorna o resultado da execução dos testes
    return result;
}
