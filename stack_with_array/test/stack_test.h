// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_STACK_WITH_ARRAY_TEST_STACK_TEST_H_
#define TRUNK_STACK_WITH_ARRAY_TEST_STACK_TEST_H_

#include <sstream>
#include <string>

#include "../doctest/doctest.h"
#include "src/stack.h"

using std::string;
using std::stringstream;

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


TEST_CASE("Testa_construtor_vazio") {
  stack atual;
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: stack::stack()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Número de elementos na pilha maior que zero.\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Size_para_pilha_vazia") {
  stack p;
  int esperado = 0;
  int atual = p.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int stack::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" p = " << ToString(p) << "\n");
  INFO(" \"p.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Size_para_pilha_nao_vazia") {
  stack p;
  CriaPilha("a", "b", "c", &p);
  int esperado = 3;
  int atual = p.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int stack::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" p = " << ToString(p) << "\n");
  INFO(" \"p.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Empty_com_pilha_vazia") {
  stack p;
  CHECK_UNARY(p.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool stack::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" A pilha esta vazia e a funcao retornou FALSE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Empty_com_pilha_nao_vazia") {
  stack p;
  CriaPilha("12", "14", "15", &p);
  CHECK_UNARY_FALSE(p.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool stack::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" A pilha tem pelo menos um elemento e a funcao retornou TRUE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Top") {
  stack p;
  CriaPilha("12", "14", "15", &p);
  SType atual = p.top();
  SType esperado = "12";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: VType stack::top()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" p = " << "[ 12 14 15 ]" << "\n");
  INFO(" \"p.top()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Push_em_pilha_vazia") {
  stack p;
  p.push("10");
  string atual = ToString(p);
  string esperado("[ 10 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void stack::push(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO("p = [ ] \n");
  INFO("\"p.push(10)\" resultou em: p = " << atual << "\n");
  INFO("Resultado esperado: p = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Push_em_pilha_nao_vazia") {
  stack p;
  CriaPilha("2", "3", "4", &p);
  p.push("1");
  string atual = ToString(p);
  string esperado("[ 1 2 3 4 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void stack::push(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO("p = [ 2 3 4 ] \n");
  INFO("\"p.push(1)\" resultou em: ");
  INFO("p = " << atual << "\n");
  INFO("Resultado esperado: p = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Pop_em_pilha_unitaria") {
  stack p;
  p.push("10");
  p.pop();
  string atual = ToString(p);
  string esperado("[ ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void stack::pop() *\n");
  INFO("------------------------------------------------------------------\n");
  INFO("p = [ 10 ] \n");
  INFO("\"p.pop()\" resultou em: p = " << atual << "\n");
  INFO("Resultado esperado: p = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Pop_em_pilha_nao_vazia") {
  stack p;
  CriaPilha("2", "3", "4", &p);
  p.pop();
  string atual = ToString(p);
  string esperado("[ 3 4 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void stack::pop() *\n");
  INFO("------------------------------------------------------------------\n");
  INFO("l = [ 2 3 4 ] \n");
  INFO("\"p.pop()\" resultou em: p = " << atual << "\n");
  INFO("Resultado esperado: p = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_Assign") {
  stack esperado;
  CriaPilha("12", "14", "15", &esperado);
  stack atual;
  atual = esperado;
  CHECK_NE(array(esperado), array(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void stack::operator=(stack& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Não basta apenas copiar o ponteiro para \"array_\". \n");
  INFO(" Você tem que copiar todos os elementos de p para a pilha corrente.\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void stack::operator=(stack& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" p = " << ToString(esperado) << "\n");
  INFO(" \"u = p\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_STACK_WITH_ARRAY_TEST_STACK_TEST_H_
