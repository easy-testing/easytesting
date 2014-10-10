// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_QUEUE_WITH_ARRAY_TEST_QUEUE_TEST_H_
#define TRUNK_QUEUE_WITH_ARRAY_TEST_QUEUE_TEST_H_

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
  // Retorna um ponteiro para o primeiro elemento da fila.
  QType* array(const queue& p) {
    return p.array_;
  }


  // Retorna o número de elementos na pilha.
  int size(const queue& p) {
    return p.size_;
  }

  // Retorna uma string no formato [a b c d ... ].
  string ToString(const queue& p) {
    stringstream sout;
    sout << "[ ";
    for (int i = 0; i < p.size_; i++) {
      sout << p.array_[(i + p.first_) % p.capacity_] << " ";
    }
    sout << "]";
    return sout.str();
  }

  // Preenche a fila d com 3 números. 'd' deve ser uma fila vazia.
  void CriaFila(QType x1, QType x2, QType x3, int first, queue* d) {
    d->size_ = 3;
    d->capacity_ = 3;
    d->first_ = first;
    d->array_ = new QType[d->capacity_];
    d->array_[(0 + first) % 3] = x1;
    d->array_[(1 + first) % 3] = x2;
    d->array_[(2 + first) % 3] = x3;
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  queue atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: queue::queue()\n"
    << "-------------------------------------------------------------------\n"
    << " Numero de elementos na fila maior que zero.\n"
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

TEST_F(Teste, Testa_Size_parad_fila_nao_vazia) {
  queue q;
  CriaFila("a", "b", "c", 1, &q);
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
  CriaFila("12", "14", "15", 1, &q);
  ASSERT_FALSE(q.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool queue::empty() \n"
      << "------------------------------------------------------------------\n"
      << " A fila tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Front) {
  queue q;
  CriaFila("12", "14", "15", 1, &q);
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
  CriaFila("12", "14", "15", 1, &q);
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
  CriaFila("1", "2", "3", 1, &q);
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
  CriaFila("2", "3", "4", 1, &q);
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
  CriaFila("12", "14", "15", 1, &esperado);
  queue atual;
  atual = esperado;
  ASSERT_NE(array(esperado), array(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void queue::operator=(queue& p)\n"
    << "-------------------------------------------------------------------\n"
    << " Nao basta apenas copiar o ponteiro para \"array_\". \n"
    << " Voce tem que copiar todos os elementos de p para a fila corrente.\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void queue::operator=(queue& p)\n"
    << "-------------------------------------------------------------------\n"
    << " p = " << ToString(esperado) << "\n"
    << " \"u = p\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_QUEUE_WITH_ARRAY_TEST_QUEUE_TEST_H_
