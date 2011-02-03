// Lista de exercicio sobre estruturas de dados heterogeneas - Registros.
//
// Executa todos os testes.

#include "registros_teste.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(print_time) = false;
    return RUN_ALL_TESTS();
}
