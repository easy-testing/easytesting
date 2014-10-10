// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_STACK_WITH_ARRAY_TEST_STACK_TEST_H_
#define TRUNK_STACK_WITH_ARRAY_TEST_STACK_TEST_H_

#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "src/stack.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna um ponteiro para o primeiro elemento da pilha.
  SType* array(const stack& p) {
    return p.array_;
  }

  // Retorna o número de elementos na pilha.
  int size(const stack& p) {
    return p.size_;
  }

  // Retorna uma string no formato [a b c d ... ].
  string ToString(const stack& p) {
    stringstream sout;
    sout << "[ ";
    for (int i = p.size_ - 1; i >= 0; i--) {
      sout << p.array_[i] << " ";
    }
    sout << "]";
    return sout.str();
  }

  // Preenche a pilha d com 3 números. 'd' deve ser uma pilha vazia.
  void CriaPilha(SType x1, SType x2, SType x3, stack* d) {
    d->size_ = 3;
    d->capacity_ = 3;
    d->array_ = new SType[d->capacity_];
    d->array_[2] = x1;
    d->array_[1] = x2;
    d->array_[0] = x3;
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  stack atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: stack::stack()\n"
    << "-------------------------------------------------------------------\n"
    << " Número de elementos na pilha maior que zero.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_pilha_vazia) {
  stack p;
  int esperado = 0;
  int atual = p.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int stack::size()\n"
    << "-------------------------------------------------------------------\n"
    << " p = " << ToString(p) << "\n"
    << " \"p.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_pilha_nao_vazia) {
  stack p;
  CriaPilha("a", "b", "c", &p);
  int esperado = 3;
  int atual = p.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int stack::size()\n"
    << "-------------------------------------------------------------------\n"
    << " p = " << ToString(p) << "\n"
    << " \"p.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_pilha_vazia) {
  stack p;
  ASSERT_TRUE(p.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool stack::empty() \n"
      << "------------------------------------------------------------------\n"
      << " A pilha esta vazia e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_pilha_nao_vazia) {
  stack p;
  CriaPilha("12", "14", "15", &p);
  ASSERT_FALSE(p.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool stack::empty() \n"
      << "------------------------------------------------------------------\n"
      << " A pilha tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Top) {
  stack p;
  CriaPilha("12", "14", "15", &p);
  SType atual = p.top();
  SType esperado = "12";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: VType stack::top()\n"
    << "-------------------------------------------------------------------\n"
    << " p = " << "[ 12 14 15 ]" << "\n"
    << " \"p.top()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_em_pilha_vazia) {
  stack p;
  p.push("10");
  string atual = ToString(p);
  string esperado("[ 10 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void stack::push(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << "p = [ ] \n"
      << "\"p.push(10)\" resultou em: p = " << atual << "\n"
      << "Resultado esperado: p = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_em_pilha_nao_vazia) {
  stack p;
  CriaPilha("2", "3", "4", &p);
  p.push("1");
  string atual = ToString(p);
  string esperado("[ 1 2 3 4 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void stack::push(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << "p = [ 2 3 4 ] \n"
      << "\"p.push(1)\" resultou em: "
      << "p = " << atual << "\n"
      << "Resultado esperado: p = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_em_pilha_unitaria) {
  stack p;
  p.push("10");
  p.pop();
  string atual = ToString(p);
  string esperado("[ ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void stack::pop() *\n"
      << "------------------------------------------------------------------\n"
      << "p = [ 10 ] \n"
      << "\"p.pop()\" resultou em: p = " << atual << "\n"
      << "Resultado esperado: p = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_em_pilha_nao_vazia) {
  stack p;
  CriaPilha("2", "3", "4", &p);
  p.pop();
  string atual = ToString(p);
  string esperado("[ 3 4 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void stack::pop() *\n"
      << "------------------------------------------------------------------\n"
      << "l = [ 2 3 4 ] \n"
      << "\"p.pop()\" resultou em: p = " << atual << "\n"
      << "Resultado esperado: p = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_Assign) {
  stack esperado;
  CriaPilha("12", "14", "15", &esperado);
  stack atual;
  atual = esperado;
  ASSERT_NE(array(esperado), array(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void stack::operator=(stack& p)\n"
    << "-------------------------------------------------------------------\n"
    << " Não basta apenas copiar o ponteiro para \"array_\". \n"
    << " Você tem que copiar todos os elementos de p para a pilha corrente.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void stack::operator=(stack& p)\n"
    << "-------------------------------------------------------------------\n"
    << " p = " << ToString(esperado) << "\n"
    << " \"u = p\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_STACK_WITH_ARRAY_TEST_STACK_TEST_H_
