// Testes da lista de exercicios sobre estruturas de dados
// homogenias - Vetores.
//
// Executa todos os testes

#include "vetores_teste.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(print_time) = false;
    return RUN_ALL_TESTS();
}
