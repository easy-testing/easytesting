// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef POLINOMIO_TEST_POLINOMIO_TEST_H_
#define POLINOMIO_TEST_POLINOMIO_TEST_H_

#include "float_vector/src/float_vector.h"

#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {

};

TEST_F(Teste, Nao_testa_nada_por_enquanto) {
}

#endif  // POLINOMIO_TEST_POLINOMIO_TEST_H_

