// copyright 2010 Thiago Ferreira de Noronha

#include "iteracao/test/iteracao_test.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(print_time) = false;
    return RUN_ALL_TESTS();
}
