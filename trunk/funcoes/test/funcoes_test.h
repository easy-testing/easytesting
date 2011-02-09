// copyright 2010 Thiago Ferreira de Noronha

#ifndef __
#define __

#include "easytesting/funcoes/src/funcoes.h"

#include <sstream>
#include <string>

#include "easytesting/gtest/gtest.h"

namespace Teste {

TEST(Teste, Exemplo_de_teste) {
  ASSERT_EQ(true, false)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int ...(int) *\n"
    << "-------------------------------------------------------------------\n"
    << "Valor de entrada : " << "..." << "\n"
    << "   Resultado esperado: " << "..." << "\n"
    << "   Resultado retornado: " << "..." << "\n\n"
    << "-------------------------------------------------------------------\n";
}
}  // end namespace

#endif  // __
