// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_QUEUE_WITH_LINKED_LIST_TEST_QUEUE_TEST_H_
#define TRUNK_QUEUE_WITH_LINKED_LIST_TEST_QUEUE_TEST_H_

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


TEST_CASE("Testa_construtor_vazio") {
  queue atual;
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: queue::queue()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Número de elementos na fila maior que zero.\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(end(atual)->next, end(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: queue::queue()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em uma lista encadeada vazia, end_->next = end_.\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(end(atual)->prev, end(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: queue::queue()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em uma lista encadeada vazia, end_->prev_ = end_.\n");
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

TEST_CASE("Testa_Size_para_fila_nao_vazia") {
  queue q;
  CriaFila("a", "b", "c", &q);
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
  CriaFila("12", "14", "15", &q);
  CHECK_UNARY_FALSE(q.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool queue::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" A fila tem pelo menos um elemento e a funcao retornou TRUE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Front") {
  queue q;
  CriaFila("12", "14", "15", &q);
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
  CriaFila("12", "14", "15", &q);
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
  CriaFila("1", "2", "3", &q);
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
  CriaFila("2", "3", "4", &q);
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

TEST_CASE("Testa_operador_de_atribuicao") {
  queue esperado;
  CriaFila("12", "14", "15", &esperado);
  queue atual;
  atual = esperado;
  CHECK_NE(end(esperado), end(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void queue::operator=(queue& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Não basta apenas copiar o ponteiro para \"end_\". \n");
  INFO(" Você tem que copiar todos os elementos de l para a fila corrente.\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void queue::operator=(queue& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" q = " << ToString(esperado) << "\n");
  INFO(" \"f = q\" resultou em: f = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: f = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_QUEUE_WITH_LINKED_LIST_TEST_QUEUE_TEST_H_
