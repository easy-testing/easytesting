// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include "test/map_test.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(print_time) = false;
    testing::GTEST_FLAG(break_on_failure) = true;
    return RUN_ALL_TESTS();
}
