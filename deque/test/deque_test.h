// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_DEQUE_TEST_DEQUE_TEST_H_
#define TRUNK_DEQUE_TEST_DEQUE_TEST_H_

#include <sstream>
#include <string>

#include "src/deque.h"
#include "../doctest/doctest.h"

using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  DType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};


// Cria uma nó cuja chave é k, o nó anterior é l, e o nó posterior é r.
Node* NewNode(DType k, Node* l, Node* r) {
  Node* aux = new Node;
  aux->key = k;
  aux->prev = l;
  aux->next = r;
  return aux;
}

// Retorna um ponteiro para o primeiro elemento do deque.
Node* begin(const deque& d) {
  return d.end_->next;
};

// Retorna um ponteiro para o elemento seguinte ao último elemento do deque.
Node* end(const deque& d) {
  return d.end_;
};

// Retorna o número de elementos no deque.
int size(const deque& d) {
  return d.size_;
};

// Retorna uma string no formato [a b c d ... ].
string ToString(const deque& d) {
  stringstream sout;
  sout << "[ ";
  for (Node* i = begin(d) ; i != end(d) ; i = i->next) {
    sout << i->key << " ";
  }
  sout << "]";
  return sout.str();
};

// Preenche o deque d com 3 números. 'd' deve ser umo deque vazio.
void Criadeque(DType x1, DType x2, DType x3, deque* d) {
  d->end_->next = NewNode(x1, d->end_, NULL);
  d->end_->next->next = NewNode(x2, d->end_->next, NULL);
  d->end_->next->next->next = d->end_->prev =
      NewNode(x3, d->end_->next->next, d->end_);
  d->size_ = 3;
};

TEST_CASE("Testa_construtor_vazio") {
  deque atual;
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: deque::deque()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Número de elementos no deque maior que zero.\n");
  INFO("-------------------------------------------------------------------\n";);
  CHECK_EQ(end(atual)->next, end(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: deque::deque()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em uma lista encadeada vazia, end_->next = end_.\n");
  INFO("-------------------------------------------------------------------\n";);
  CHECK_EQ(end(atual)->prev, end(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: deque::deque()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em uma lista encadeada vazia, end_->prev_ = end_.\n");
  INFO("-------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Size_para_deque_vazio") {
  deque d;
  int esperado = 0;
  int atual = d.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int deque::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" d = " << ToString(d) << "\n");
  INFO(" \"d.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Size_para_deque_nao_vazio") {
  deque d;
  Criadeque("a", "b", "c", &d);
  int esperado = 3;
  int atual = d.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int deque::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" d = " << ToString(d) << "\n");
  INFO(" \"d.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Empty_com_deque_vazio") {
  deque d;
  CHECK_UNARY(d.empty());
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: bool deque::empty() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" o deque esta vazio e a funcao retornou FALSE.\n");
    INFO("------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Empty_com_deque_nao_vazio") {
  deque d;
  Criadeque("12", "14", "15", &d);
  CHECK_UNARY_FALSE(d.empty());
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: bool deque::empty() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" o deque tem pelo menos um elemento e a funcao retornou TRUE.\n");
    INFO("------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Front") {
  deque d;
  Criadeque("12", "14", "15", &d);
  DType atual = d.front();
  DType esperado = "12";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: VType deque::front()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" d = " << "[ 12 14 15 ]" << "\n");
  INFO(" \"d.front()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Back") {
  deque d;
  Criadeque("12", "14", "15", &d);
  DType atual = d.back();
  DType esperado = "15";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: VType deque::back()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" d = " << "[ 12 14 15 ]" << "\n");
  INFO(" \"d.back()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Push_Front_em_deque_vazio") {
  deque d;
  d.push_front("10");
  string atual = ToString(d);
  string esperado("[ 10 ]");
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void deque::push_front(DType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO("d = [ ] \n");
    INFO("\"d.push(10)\" resultou em: d = " << atual << "\n");
    INFO("Resultado esperado: d = " << esperado << "\n");
    INFO("------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Push_Front_em_deque_nao_vazio") {
  deque d;
  Criadeque("1", "2", "3", &d);
  d.push_front("4");
  string atual = ToString(d);
  string esperado("[ 4 1 2 3 ]");
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void deque::push_front(DType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO("d = [ 1 2 3 ] \n");
    INFO("\"d.push(4)\" resultou em: d = " << atual << "\n");
    INFO("Resultado esperado: d = " << esperado << "\n");
    INFO("------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Push_Back_em_deque_vazio") {
  deque d;
  d.push_back("10");
  string atual = ToString(d);
  string esperado("[ 10 ]");
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void deque::push_back(DType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO("d = [ ] \n");
    INFO("\"d.push(10)\" resultou em: d = " << atual << "\n");
    INFO("Resultado esperado: d = " << esperado << "\n");
    INFO("------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Push_Back_em_deque_nao_vazio") {
  deque d;
  Criadeque("1", "2", "3", &d);
  d.push_back("4");
  string atual = ToString(d);
  string esperado("[ 1 2 3 4 ]");
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void deque::push_back(DType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO("d = [ 1 2 3 ] \n");
    INFO("\"d.push(4)\" resultou em: d = " << atual << "\n");
    INFO("Resultado esperado: d = " << esperado << "\n");
    INFO("------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Pop_Front_em_deque_unitario") {
  deque d;
  d.push_back("10");
  d.pop_front();
  string atual = ToString(d);
  string esperado("[ ]");
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void deque::pop_front() *\n");
    INFO("------------------------------------------------------------------\n");
    INFO("d = [ 10 ] \n");
    INFO("\"d.pop()\" resultou em: d = " << atual << "\n");
    INFO("Resultado esperado: d = " << esperado << "\n");
    INFO("------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Pop_Front_em_deque_nao_vazio") {
  deque d;
  Criadeque("2", "3", "4", &d);
  d.pop_front();
  string atual = ToString(d);
  string esperado("[ 3 4 ]");
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void deque::pop_front(DType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO("d = [ 2 3 4 ] \n");
    INFO("\"d.pop()\" resultou em: d = " << atual << "\n");
    INFO("Resultado esperado: d = " << esperado << "\n");
    INFO("------------------------------------------------------------------\n";);
}
TEST_CASE("Testa_Pop_Back_em_deque_unitario") {
  deque d;
  d.push_back("10");
  d.pop_back();
  string atual = ToString(d);
  string esperado("[ ]");
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void deque::pop_back() *\n");
    INFO("------------------------------------------------------------------\n");
    INFO("d = [ 10 ] \n");
    INFO("\"d.pop()\" resultou em: d = " << atual << "\n");
    INFO("Resultado esperado: d = " << esperado << "\n");
    INFO("------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_Pop_Back_em_deque_nao_vazio") {
  deque d;
  Criadeque("2", "3", "4", &d);
  d.pop_back();
  string atual = ToString(d);
  string esperado("[ 2 3 ]");
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void deque::pop_back(DType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO("d = [ 2 3 4 ] \n");
    INFO("\"d.pop()\" resultou em: d = " << atual << "\n");
    INFO("Resultado esperado: d = " << esperado << "\n");
    INFO("------------------------------------------------------------------\n";);
}

TEST_CASE("Testa_operador_Assign") {
  deque esperado;
  Criadeque("12", "14", "15", &esperado);
  deque atual;
  atual = esperado; 
  CHECK_NE(end(esperado), end(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void deque::operator=(deque& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Não basta apenas copiar o ponteiro para \"end_\". \n");
  INFO(" Você tem que copiar todos os elementos de l para o deque corrente.\n");
  INFO("-------------------------------------------------------------------\n";);
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void deque::operator=(deque& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" q = " << ToString(esperado) << "\n");
  INFO(" \"f = q\" resultou em: f = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: f = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n";);
}

#endif  // TRUNK_DEQUE_TEST_DEQUE_TEST_H_
