// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_TEST_SET_TEST_H_
#define SET_TEST_SET_TEST_H_

#include "stack/src/stack.h"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:

};

TEST_F(Teste, Testar_metodo_) {
}
#endif  // SET_TEST_SET_TEST_H_
