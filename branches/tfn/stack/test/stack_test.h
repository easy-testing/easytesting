// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_STACK_TEST_STACK_TEST_H_
#define BRANCHES_GABARITOS_STACK_TEST_STACK_TEST_H_

#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "stack/src/node.h"
#include "stack/src/stack.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna uma string no formato {a b c d...}.
  string PrintStack(stack& p) {
    stringstream output;
    output << "[";
    for (Node* i = p.end_->next; i != p.end_; i = i->next) {
      output << i->key;
      if (i->next != p.end_) {
        output << ", ";
      }
    }
    output << "]";
    return output.str();
  }

  // Cria uma nó cuja chave é k, o nó anterior é l, e o nó posterior é r.
  Node* NewNode(string k, Node* l, Node* r) {
    Node* aux = new Node();
    aux->key = k;
    aux->prev = l;
    aux->next = r;
    return aux;
  }

  // Preenche a stack passada como parametro com 1 numero.
  // 'p' deve ser uma stack vazia.
  void CriaStack1(string x, stack& p) {
    p.end_->prev = p.end_->next = NewNode(x, p.end_, p.end_);
    p.size_ = 1;
  }

  // Preenche a stack passada como parametro com 3 numeros.
  // 'p' deve ser uma stack vazia.
  void CriaStack3(string x1, string x2, string x3, stack& p) {
    p.end_->next = NewNode(x1, p.end_, NULL);
    p.end_->next->next = NewNode(x2, p.end_->next, NULL);
    p.end_->next->next->next = p.end_->prev =
        NewNode(x3, p.end_->next->next, p.end_);
    p.size_ = 3;
  }
};

TEST_F(Teste, Testar_metodo_empty) {
  stack p1;
  ASSERT_TRUE(p1.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool stack::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A stack esta vazia e a funcao retornou FALSE.\n"
    << "-------------------------------------------------------------------\n";

  stack p2;
  CriaStack3("12", "14", "15", p2);
  ASSERT_FALSE(p2.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool stack::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A stack tem pelo menos um elemento e a funcao retornou TRUE."
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_top_em_stack_com_um_elemento) {
  stack p;
  CriaStack1("2", p);
  string esperado = "2";
  string atual = p.top();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* type stack::top() *\n"
  << "-------------------------------------------------------------------\n"
  << "pilha = " << PrintStack(p) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_top_em_stack_com_mais_de_um_elemento) {
  stack p;
  CriaStack3("3", "7", "8", p);
  string esperado = "3";
  string atual = p.top();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* type stack::top() *\n"
  << "-------------------------------------------------------------------\n"
  << "pilha = " << PrintStack(p) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_stack_vazia) {
  stack p;
  int esperado = 0;
  int atual = p.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int stack::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "pilha = " << PrintStack(p) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_stack_com_um_elemento) {
  stack p;
  CriaStack1("2", p);
  int esperado = 1;
  int atual = p.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int stack::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "pilha = " << PrintStack(p) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_lista_com_varios_elementos) {
  stack p;
  CriaStack3("10", "3", "0", p);
  int esperado = 3;
  int atual = p.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int stack::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "pilha = " << PrintStack(p) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

// Para realizar a comparacao da stack esperada para a stack do aluno, foi
// necessario utilizar a comparacao da classe string (imprimir a stack do
// aluno em uma string).
TEST_F(Teste, Testar_metodo_push_em_stack_vazia) {
  stack p;
  p.push("10");
  string esperado("[10]");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack::push(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Pilha esperada : " << esperado << "\n"
    << "Pilha atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_stack_com_um_elemento) {
  stack p;
  CriaStack1("22", p);
  p.push("12");
  string esperado("[12, 22]");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack::push(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Pilha esperada : " << esperado << "\n"
    << "Pilha atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_stack_com_varios_elementos) {
  stack p;
  CriaStack3("5", "13", "49", p);
  p.push("17");
  string esperado("[17, 5, 13, 49]");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack::push(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Pilha esperada : " << esperado << "\n"
    << "Pilha atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_stack_com_um_elemento) {
  stack p;
  CriaStack1("8", p);
  p.pop();
  string esperado("[]");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Pilha esperada : " << esperado << "\n"
    << "Pilha atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_stack_com_varios_elemento) {
  stack p;
  CriaStack3("8", "0", "-3", p);
  p.pop();
  string esperado("[0, -3]");
  string atual = PrintStack(p);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void stack::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Pilha esperada : " << esperado << "\n"
    << "Pilha atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // BRANCHES_GABARITOS_STACK_TEST_STACK_TEST_H_
