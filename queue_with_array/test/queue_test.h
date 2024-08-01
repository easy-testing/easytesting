// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_QUEUE_WITH_ARRAY_TEST_QUEUE_TEST_H_
#define TRUNK_QUEUE_WITH_ARRAY_TEST_QUEUE_TEST_H_

#include <sstream>
#include <string>

#include "../doctest/doctest.h"
#include "src/queue.h"

using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  QType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

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

TEST_CASE("Testa_construtor_vazio") {
  queue atual;
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: queue::queue()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Numero de elementos na fila maior que zero.\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Size_para_fila_vazia") {
  queue q;
  int esperado = 0;
  int atual = q.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int queue::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" q = " << ToString(q) << "\n");
  INFO(" \"q.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Size_parad_fila_nao_vazia") {
  queue q;
  CriaFila("a", "b", "c", 1, &q);
  int esperado = 3;
  int atual = q.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int queue::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" q = " << ToString(q) << "\n");
  INFO(" \"q.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Empty_com_fila_vazia") {
  queue q;
  CHECK_UNARY(q.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool queue::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" A fila esta vazia e a funcao retornou FALSE.\n");
  INFO("------------------------------------------------------------------\n");
}
  
TEST_CASE("Testa_Empty_com_fila_nao_vazia") {
  queue q;
  CriaFila("12", "14", "15", 1, &q);
  CHECK_UNARY_FALSE(q.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool queue::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" A fila tem pelo menos um elemento e a funcao retornou TRUE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Front") {
  queue q;
  CriaFila("12", "14", "15", 1, &q);
  QType atual = q.front();
  QType esperado = "12";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: VType queue::front()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" q = " << "[ 12 14 15 ]" << "\n");
  INFO(" \"q.front()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Back") {
  queue q;
  CriaFila("12", "14", "15", 1, &q);
  QType atual = q.back();
  QType esperado = "15";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: VType queue::back()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" q = " << "[ 12 14 15 ]" << "\n");
  INFO(" \"q.back()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Push_em_fila_vazia") {
  queue q;
  q.push("10");
  string atual = ToString(q);
  string esperado("[ 10 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void queue::push(QType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO("q = [ ] \n");
  INFO("\"q.push(10)\" resultou em: q = " << atual << "\n");
  INFO("Resultado esperado: q = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Push_em_fila_nao_vazia") {
  queue q;
  CriaFila("1", "2", "3", 1, &q);
  q.push("4");
  string atual = ToString(q);
  string esperado("[ 1 2 3 4 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void queue::push(QType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO("q = [ 1 2 3 ] \n");
  INFO("\"q.push(4)\" resultou em: q = " << atual << "\n");
  INFO("Resultado esperado: q = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Pop_em_fila_unitaria") {
  queue q;
  q.push("10");
  q.pop();
  string atual = ToString(q);
  string esperado("[ ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void queue::pop() *\n");
  INFO("------------------------------------------------------------------\n");
  INFO("q = [ 10 ] \n");
  INFO("\"q.pop()\" resultou em: q = " << atual << "\n");
  INFO("Resultado esperado: q = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Pop_em_fila_nao_vazia") {
  queue q;
  CriaFila("2", "3", "4", 1, &q);
  q.pop();
  string atual = ToString(q);
  string esperado("[ 3 4 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void queue::pop() *\n");
  INFO("------------------------------------------------------------------\n");
  INFO("q = [ 2 3 4 ] \n");
  INFO("\"q.pop()\" resultou em: q = " << atual << "\n");
  INFO("Resultado esperado: q = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_Assign") {
  queue esperado;
  CriaFila("12", "14", "15", 1, &esperado);
  queue atual;
  atual = esperado;
  CHECK_NE(array(esperado), array(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void queue::operator=(queue& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Nao basta apenas copiar o ponteiro para \"array_\". \n");
  INFO(" Voce tem que copiar todos os elementos de p para a fila corrente.\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void queue::operator=(queue& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" p = " << ToString(esperado) << "\n");
  INFO(" \"u = p\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_QUEUE_WITH_ARRAY_TEST_QUEUE_TEST_H_
