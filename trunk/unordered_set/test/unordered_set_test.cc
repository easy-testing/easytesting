// Copyright 2011 Thiago Noronha
#include "easytesting/unordered_set/test/unordered_set_test.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(print_time) = false;
    return RUN_ALL_TESTS();
}