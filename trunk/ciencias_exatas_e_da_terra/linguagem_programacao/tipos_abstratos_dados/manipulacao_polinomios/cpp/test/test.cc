#include "test.h"

int ExecutarTodosOsTestes() {
  int argc = 0;
  char** argv = NULL;
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::GTEST_FLAG(print_time) = false;
  int success = RUN_ALL_TESTS();
  return success;
}
