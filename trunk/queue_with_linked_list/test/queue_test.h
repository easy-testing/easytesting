// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TEST_QUEUE_TEST_H_
#define TEST_QUEUE_TEST_H_

#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "src/queue.h"

using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  QType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Cria uma nó cuja chave é k, o nó anterior é l, e o nó posterior é r.
  Node* NewNode(QType k, Node* l, Node* r) {
    Node* aux = new Node;
    aux->key = k;
    aux->prev = l;
    aux->next = r;
    return aux;
  }

  // Retorna um ponteiro para o primeiro elemento da fila.
  Node* begin(const queue& q) {
    return q.end_->next;
  }

  // Retorna um ponteiro para o elemento seguinte ao último elemento da fila.
  Node* end(const queue& q) {
    return q.end_;
  }

  // Retorna o número de elementos na fila.
  int size(const queue& q) {
    return q.size_;
  }

  // Retorna uma string no formato [a b c d ... ].
  string ToString(const queue& q) {
    stringstream sout;
    sout << "[ ";
    for (Node* i = begin(q) ; i != end(q) ; i = i->next) {
      sout << i->key << " ";
    }
    sout << "]";
    return sout.str();
  }

  // Preenche a fila d com 3 números. 'd' deve ser uma fila vazia.
  void CriaFila(QType x1, QType x2, QType x3, queue* d) {
    d->end_->next = NewNode(x1, d->end_, NULL);
    d->end_->next->next = NewNode(x2, d->end_->next, NULL);
    d->end_->next->next->next = d->end_->prev =
        NewNode(x3, d->end_->next->next, d->end_);
    d->size_ = 3;
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  queue atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: queue::queue()\n"
    << "-------------------------------------------------------------------\n"
    << " Número de elementos na fila maior que zero.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(end(atual)->next, end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: queue::queue()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista encadeada vazia, end_->next = end_.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(end(atual)->prev, end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: queue::queue()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista encadeada vazia, end_->prev_ = end_.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_fila_vazia) {
  queue q;
  int esperado = 0;
  int atual = q.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int queue::size()\n"
    << "-------------------------------------------------------------------\n"
    << " q = " << ToString(q) << "\n"
    << " \"q.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_fila_nao_vazia) {
  queue q;
  CriaFila("a", "b", "c", &q);
  int esperado = 3;
  int atual = q.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int queue::size()\n"
    << "-------------------------------------------------------------------\n"
    << " q = " << ToString(q) << "\n"
    << " \"q.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_fila_vazia) {
  queue q;
  ASSERT_TRUE(q.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool queue::empty() \n"
      << "------------------------------------------------------------------\n"
      << " A fila esta vazia e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_fila_nao_vazia) {
  queue q;
  CriaFila("12", "14", "15", &q);
  ASSERT_FALSE(q.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool queue::empty() \n"
      << "------------------------------------------------------------------\n"
      << " A fila tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Front) {
  queue q;
  CriaFila("12", "14", "15", &q);
  QType atual = q.front();
  QType esperado = "12";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: VType queue::front()\n"
    << "-------------------------------------------------------------------\n"
    << " q = " << "[ 12 14 15 ]" << "\n"
    << " \"q.front()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Back) {
  queue q;
  CriaFila("12", "14", "15", &q);
  QType atual = q.back();
  QType esperado = "15";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: VType queue::back()\n"
    << "-------------------------------------------------------------------\n"
    << " q = " << "[ 12 14 15 ]" << "\n"
    << " \"q.back()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_em_fila_vazia) {
  queue q;
  q.push("10");
  string atual = ToString(q);
  string esperado("[ 10 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void queue::push(QType k) *\n"
      << "------------------------------------------------------------------\n"
      << "q = [ ] \n"
      << "\"q.push(10)\" resultou em: q = " << atual << "\n"
      << "Resultado esperado: q = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Push_em_fila_nao_vazia) {
  queue q;
  CriaFila("1", "2", "3", &q);
  q.push("4");
  string atual = ToString(q);
  string esperado("[ 1 2 3 4 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void queue::push(QType k) *\n"
      << "------------------------------------------------------------------\n"
      << "q = [ 1 2 3 ] \n"
      << "\"q.push(4)\" resultou em: q = " << atual << "\n"
      << "Resultado esperado: q = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_em_fila_unitaria) {
  queue q;
  q.push("10");
  q.pop();
  string atual = ToString(q);
  string esperado("[ ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void queue::pop() *\n"
      << "------------------------------------------------------------------\n"
      << "q = [ 10 ] \n"
      << "\"q.pop()\" resultou em: q = " << atual << "\n"
      << "Resultado esperado: q = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pop_em_fila_nao_vazia) {
  queue q;
  CriaFila("2", "3", "4", &q);
  q.pop();
  string atual = ToString(q);
  string esperado("[ 3 4 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void queue::pop() *\n"
      << "------------------------------------------------------------------\n"
      << "q = [ 2 3 4 ] \n"
      << "\"q.pop()\" resultou em: q = " << atual << "\n"
      << "Resultado esperado: q = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_Assign) {
  queue esperado;
  CriaFila("12", "14", "15", &esperado);
  queue atual;
  atual = esperado;
  ASSERT_NE(end(esperado), end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void queue::operator=(queue& p)\n"
    << "-------------------------------------------------------------------\n"
    << " Não basta apenas copiar o ponteiro para \"end_\". \n"
    << " Você tem que copiar todos os elementos de l para a fila corrente.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void queue::operator=(queue& p)\n"
    << "-------------------------------------------------------------------\n"
    << " q = " << ToString(esperado) << "\n"
    << " \"f = q\" resultou em: f = " << ToString(atual) << "\n"
    << " Resultado esperado: f = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TEST_QUEUE_TEST_H_
