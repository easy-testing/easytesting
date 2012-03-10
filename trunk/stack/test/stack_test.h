// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_STACK_TEST_STACK_TEST_H_
#define TRUNK_STACK_TEST_STACK_TEST_H_

#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "stack/src/stack.h"

using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Cria uma nó cuja chave é k, o nó anterior é l, e o nó posterior é r.
  Node* NewNode(string k, Node* l, Node* r) {
    Node* aux = new Node;
    aux->key = k;
    aux->prev = l;
    aux->next = r;
    return aux;
  }

  // Retorna um ponteiro para o primeiro elemento da pilha.
  Node* begin(const stack& p) {
    return p.end_->next;
  }

  // Retorna um ponteiro para o elemento seguinte ao último elemento da pilha.
  Node* end(const stack& p) {
    return p.end_;
  }

  // Retorna o número de elementos na pilha.
  int size(const stack& p) {
    return p.size_;
  }

  // Preenche a stack passada como parametro com 1 numero.
  // 'p' deve ser uma stack vazia.
  void CriaStack1(string x, stack& p) {
    p.end_->prev = p.end_->next = NewNode(x, p.end_, p.end_);
    p.size_ = 1;
  }

  // Retorna uma string no formato [a b c d ... ].
  string ToString(const stack& p) {
    stringstream sout;
    sout << "[ ";
    for (Node* i = begin(p) ; i != end(p) ; i = i->next) {
      sout << i->key << " ";
    }
    sout << "]";
    return sout.str();
  }

  // Preenche a pilha d com 3 números. 'd' deve ser uma pilha vazia.
  void CriaPilha(LType x1, LType x2, LType x3, stack* d) {
    d->end_->next = NewNode(x1, d->end_, NULL);
    d->end_->next->next = NewNode(x2, d->end_->next, NULL);
    d->end_->next->next->next = d->end_->prev =
        NewNode(x3, d->end_->next->next, d->end_);
    d->size_ = 3;
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
  ASSERT_EQ(end(atual)->next, end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: stack::stack()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista encadeada vazia, end_->next = end_.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(end(atual)->prev, end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: stack::stack()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista encadeada vazia, end_->prev_ = end_.\n"
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
      << " A pilha tem pelo menos um elemento e a funcao retornou TRUE."
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Top) {
  stack p;
  CriaPilha("12", "14", "15", &p);
  LType atual = p.top();
  LType esperado = "12";
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
      << "Erro na funcao: void stack::push(LType k) *\n"
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
      << "Erro na funcao: void stack::push(LType k) *\n"
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
  ASSERT_NE(end(esperado), end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void stack::operator=(stack& p)\n"
    << "-------------------------------------------------------------------\n"
    << " Não basta apenas copiar o ponteiro para \"end_\". \n"
    << " Você tem que copiar todos os elementos de l para a pilha corrente.\n"
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

#endif  // TRUNK_STACK_TEST_STACK_TEST_H_
