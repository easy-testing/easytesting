// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef STACK_TEST_STACK_TEST_H_
#define STACK_TEST_STACK_TEST_H_

#include "stack/src/stack.h"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna uma string no formato {a b c d...}.
  string PrintStack(stack<int>& p) {
    stringstream output;
    output << "{";
    for (Node<int>* i = p.list_.begin() ; i != p.list_.end() ; i = i->next) {
      if (i == p.list_.begin())
        output << i->key;
      else
        output << " " << i->key;
    }
    output << "}";
    return output.str();
  }

  // Preenche a stack passada como parametro com 1 numero.
  // 'p' deve ser uma stack vazia.
  void CriaStack1(int x, stack<int>& p) {
    //l->end_->prev = l->end_->next = new Node<int>(x, l->end_, l->end_);
    p.list_.end_->prev = p.list_.end_->next = new Node<int>(x, p.list_.end_, p.list_.end_);
  }

  // Preenche a lista passada como parametro com 3 numeros.
  // 'l' deve ser uma lista vazia.
  void CriaStack3(int x1, int x2, int x3, stack<int>& p) {
    p.list_.end_->next = new Node<int>(x1, p.list_.end_, NULL);
    p.list_.end_->next->next = new Node<int>(x2, p.list_.end_->next, NULL);
    p.list_.end_->next->next->next = p.list_.end_->prev =
        new Node<int>(x3, p.list_.end_->next->next, p.list_.end_);
  }
};

TEST_F(Teste, Testar_metodo_empty) {
  stack<int> p1;
  ASSERT_TRUE(p1.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool stack<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A stack esta vazia e a funcao retornou FALSE."
    << "-------------------------------------------------------------------\n";

  stack<int> p2;
  CriaStack3(12, 14, 15, p2);
  ASSERT_FALSE(p2.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool stack<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A stack tem pelo menos um elemento e a funcao retornou TRUE."
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_top_em_stack_com_um_elemento) {
  stack<int> p;
  CriaStack1(2, p);
  int esperado = 2;
  int atual = p.top();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type stack<Type>::top() *\n"
  << "-------------------------------------------------------------------\n"
  << "     " << PrintStack(p) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_top_em_stack_com_mais_de_um_elemento) {
  stack<int> p;
  CriaStack3(3, 7, 8, p);
  int esperado = 3;
  int atual = p.top();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type stack<Type>::top() *\n"
  << "-------------------------------------------------------------------\n"
  << "     " << PrintStack(p) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_stack_vazia) {
  stack<int> p;
  int esperado = 0;
  int atual = p.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int stack<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintStack(p) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_stack_com_um_elemento) {
  stack<int> p;
  CriaStack1(2, p);
  int esperado = 1;
  int atual = p.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int stack<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintStack(p) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_lista_com_varios_elementos) {
  stack<int> p;
  CriaStack3(10, 3, 0, p);
  int esperado = 3;
  int atual = p.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int stack<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintStack(p) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

// Para realizar a comparacao da lista esperada para a lista do aluno, foi
// necessario utilizar a comparacao da classe string (imprimir a lista do
// aluno em uma string).
TEST_F(Teste, Testar_metodo_push_em_stack_vazia) {
  stack<int> p;
  p.push(10);
  string esperado("{10}");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack<Type>::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_stack_com_um_elemento) {
  stack<int> p;
  CriaStack1(22, p);
  p.push(12);
  string esperado("{12 22}");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack<Type>::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_stack_com_varios_elementos) {
  stack<int> p;
  CriaStack3(5, 13, 49, p);
  p.push(17);
  string esperado("{17 5 13 49}");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack<Type>::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_stack_com_um_elemento) {
  stack<int> p;
  CriaStack1(8, p);
  p.pop();
  string esperado("{}");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack<Type>::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_stack_com_varios_elemento) {
  stack<int> p;
  CriaStack3(8, 0, -3, p);
  p.pop();
  string esperado("{0 -3}");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack<Type>::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // STACK_TEST_STACK_TEST_H_
