// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_DEQUE_TEST_DEQUE_TEST_H_
#define TRUNK_DEQUE_TEST_DEQUE_TEST_H_

#include <sstream>
#include <string>

#include "src/deque.h"
#include "gtest/gtest.h"

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
  Node* NewNode(LType k, Node* l, Node* r) {
    Node* aux = new Node;
    aux->key = k;
    aux->prev = l;
    aux->next = r;
    return aux;
  }

  // Retorna um ponteiro para o primeiro elemento do deque.
  Node* begin(const deque& d) {
    return d.end_->next;
  }

  // Retorna um ponteiro para o elemento seguinte ao último elemento do deque.
  Node* end(const deque& d) {
    return d.end_;
  }

  // Retorna o número de elementos no deque.
  int size(const deque& d) {
    return d.size_;
  }

  // Retorna uma string no formato [a b c d ... ].
  string ToString(const deque& d) {
    stringstream sout;
    sout << "[ ";
    for (Node* i = begin(d) ; i != end(d) ; i = i->next) {
      sout << i->key << " ";
    }
    sout << "]";
    return sout.str();
  }

  // Preenche o deque d com 3 números. 'd' deve ser umo deque vazio.
  void Criadeque(LType x1, LType x2, LType x3, deque* d) {
    d->end_->next = NewNode(x1, d->end_, NULL);
    d->end_->next->next = NewNode(x2, d->end_->next, NULL);
    d->end_->next->next->next = d->end_->prev =
        NewNode(x3, d->end_->next->next, d->end_);
    d->size_ = 3;
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  deque atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: deque::deque()\n"
    << "-------------------------------------------------------------------\n"
    << " Número de elementos no deque maior que zero.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(end(atual)->next, end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: deque::deque()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista encadeada vazia, end_->next = end_.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(end(atual)->prev, end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: deque::deque()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista encadeada vazia, end_->prev_ = end_.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_deque_vazio) {
  deque d;
  int esperado = 0;
  int atual = d.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int deque::size()\n"
    << "-------------------------------------------------------------------\n"
    << " d = " << ToString(d) << "\n"
    << " \"d.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_deque_nao_vazio) {
  deque d;
  Criadeque("a", "b", "c", &d);
  int esperado = 3;
  int atual = d.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int deque::size()\n"
    << "-------------------------------------------------------------------\n"
    << " d = " << ToString(d) << "\n"
    << " \"d.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_deque_vazio) {
  deque d;
  ASSERT_TRUE(d.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool deque::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o deque esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_deque_nao_vazio) {
  deque d;
  Criadeque("12", "14", "15", &d);
  ASSERT_FALSE(d.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool deque::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o deque tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Front) {
  deque d;
  Criadeque("12", "14", "15", &d);
  LType atual = d.front();
  LType esperado = "12";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: VType deque::front()\n"
    << "-------------------------------------------------------------------\n"
    << " d = " << "[ 12 14 15 ]" << "\n"
    << " \"d.front()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Back) {
  deque d;
  Criadeque("12", "14", "15", &d);
  LType atual = d.back();
  LType esperado = "15";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: VType deque::back()\n"
    << "-------------------------------------------------------------------\n"
    << " d = " << "[ 12 14 15 ]" << "\n"
    << " \"d.back()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_Front_em_deque_vazio) {
  deque d;
  d.push_front("10");
  string atual = ToString(d);
  string esperado("[ 10 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void deque::push_front(LType k) *\n"
      << "------------------------------------------------------------------\n"
      << "d = [ ] \n"
      << "\"d.push(10)\" resultou em: d = " << atual << "\n"
      << "Resultado esperado: d = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_Front_em_deque_nao_vazio) {
  deque d;
  Criadeque("1", "2", "3", &d);
  d.push_front("4");
  string atual = ToString(d);
  string esperado("[ 4 1 2 3 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void deque::push_front(LType k) *\n"
      << "------------------------------------------------------------------\n"
      << "d = [ 1 2 3 ] \n"
      << "\"d.push(4)\" resultou em: d = " << atual << "\n"
      << "Resultado esperado: d = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_Back_em_deque_vazio) {
  deque d;
  d.push_back("10");
  string atual = ToString(d);
  string esperado("[ 10 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void deque::push_back(LType k) *\n"
      << "------------------------------------------------------------------\n"
      << "d = [ ] \n"
      << "\"d.push(10)\" resultou em: d = " << atual << "\n"
      << "Resultado esperado: d = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_Back_em_deque_nao_vazio) {
  deque d;
  Criadeque("1", "2", "3", &d);
  d.push_back("4");
  string atual = ToString(d);
  string esperado("[ 1 2 3 4 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void deque::push_back(LType k) *\n"
      << "------------------------------------------------------------------\n"
      << "d = [ 1 2 3 ] \n"
      << "\"d.push(4)\" resultou em: d = " << atual << "\n"
      << "Resultado esperado: d = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_Front_em_deque_unitario) {
  deque d;
  d.push_back("10");
  d.pop_front();
  string atual = ToString(d);
  string esperado("[ ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void deque::pop_front() *\n"
      << "------------------------------------------------------------------\n"
      << "d = [ 10 ] \n"
      << "\"d.pop()\" resultou em: d = " << atual << "\n"
      << "Resultado esperado: d = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_Front_em_deque_nao_vazio) {
  deque d;
  Criadeque("2", "3", "4", &d);
  d.pop_front();
  string atual = ToString(d);
  string esperado("[ 3 4 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void deque::pop_front(LType k) *\n"
      << "------------------------------------------------------------------\n"
      << "d = [ 2 3 4 ] \n"
      << "\"d.pop()\" resultou em: d = " << atual << "\n"
      << "Resultado esperado: d = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}
TEST_F(Teste, Testa_Pop_Back_em_deque_unitario) {
  deque d;
  d.push_back("10");
  d.pop_back();
  string atual = ToString(d);
  string esperado("[ ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void deque::pop_back() *\n"
      << "------------------------------------------------------------------\n"
      << "d = [ 10 ] \n"
      << "\"d.pop()\" resultou em: d = " << atual << "\n"
      << "Resultado esperado: d = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_Back_em_deque_nao_vazio) {
  deque d;
  Criadeque("2", "3", "4", &d);
  d.pop_back();
  string atual = ToString(d);
  string esperado("[ 2 3 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void deque::pop_back(LType k) *\n"
      << "------------------------------------------------------------------\n"
      << "d = [ 2 3 4 ] \n"
      << "\"d.pop()\" resultou em: d = " << atual << "\n"
      << "Resultado esperado: d = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_Assign) {
  deque esperado;
  Criadeque("12", "14", "15", &esperado);
  deque atual;
  atual = esperado;
  ASSERT_NE(end(esperado), end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void deque::operator=(deque& p)\n"
    << "-------------------------------------------------------------------\n"
    << " Não basta apenas copiar o ponteiro para \"end_\". \n"
    << " Você tem que copiar todos os elementos de l para o deque corrente.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void deque::operator=(deque& p)\n"
    << "-------------------------------------------------------------------\n"
    << " q = " << ToString(esperado) << "\n"
    << " \"f = q\" resultou em: f = " << ToString(atual) << "\n"
    << " Resultado esperado: f = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_DEQUE_TEST_DEQUE_TEST_H_
