// Testes da lista de exercicios sobre estruturas de dados
// homogenias - Matrizes.
//
// Executa todos os testes

#include "matrizes_teste.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(print_time) = false;
    return RUN_ALL_TESTS();
}
