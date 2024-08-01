// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_SET_WITH_LINKED_LIST_TEST_SET_TEST_H_
#define TRUNK_ORDERED_SET_WITH_LINKED_LIST_TEST_SET_TEST_H_

#include <cmath>
#include <cstdlib>
#include <queue>
#include <sstream>
#include <string>

#include "../doctest/doctest.h"
#include "src/set.h"

using std::priority_queue;
using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};


// Retorna o valor da chave do elemento x de s;
SType key(Node* x, const set& s) {
  if (x == NULL) {
    return "NULL";
  } else if (x == end(s)) {
    return "set::end()";
  } else {
    return x->key;
  }
}

// Retorna o número de elementos no conjunto.
int size(const set& s) {
  return s.size_;
}

// Insere k em s.
// Precondição: k não está em s.
void insert(SType k, set* s) {
  Node* x = s->end_->next;
  while (x != s->end_ && x->key < k) {
    x = x->next;
  }
  if (x == s->end_ || x->key != k) {
    Node* node = new Node;
    node->key = k;
    node->prev = x->prev;
    node->next = x;
    x->prev->next = node;
    x->prev = node;
    s->size_++;
  }
}

// Retorna o primeiro elemento do conjunto.
Node* begin(const set& s) {
  return s.end_->next;
}

// Retorna o "marcador de fim" do conjunto.
Node* end(const set& s) {
  return s.end_;
}

// Retorna o elemento seguinte a 'x' no conjunto.
Node* next(Node* x, const set& s) {
  return x->next;
}

// Retorna o elemento anterior a 'x' no conjunto.
Node* prev(Node* x, const set& s) {
  return x->prev;
}

// Retorna um ponteiro para o elemento k de s.
Node* find(SType k, const set& s) {
  for (Node* i = s.end_->next; i != s.end_; i = i->next) {
    if (i->key == k) {
      return i;
    }
  }
  return s.end_;
}

// Retorna uma string contendo os elementos do conjunto
// no formato { c1 c2 c3 c4 } e ordenados do maior para o menor.
string ToString(const set& s) {
  stringstream out;
  out << "{ ";
  for (Node* i = begin(s); i != end(s); i = next(i, s)) {
    out << key(i, s) << " ";
  }
  out << "}";
  return out.str();
}

TEST_CASE("Testa_construtor_vazio") {
  set atual;
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: set::set()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um conjunto vazio, size_ = 0\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(begin(atual), end(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: set::set()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um conjunto vazio, set::begin() == set::end()\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_conjunto_vazio") {
  set s;
  CHECK_UNARY(s.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool set::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" o conjunto esta vazio e a funcao retornou FALSE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_conjunto_nao_vazio") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  CHECK_UNARY_FALSE(s.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool set::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_conjunto_vazio") {
  set s;
  int esperado = 0;
  int atual = s.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int set::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_conjunto_nao_vazio") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  int atual = s.size();
  int esperado = 3;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int set::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_conjunto_vazio") {
  set s;
  CHECK_EQ(begin(s), s.begin());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::begin() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" s.begin() nao retornou s.end().\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_conjunto_nao_vazio") {
  set s;
  insert("1", &s);
  Node* atual = s.begin();
  Node* esperado = begin(s);
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::begin() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.begin()\" retornou: ponteiro para " << key(atual, s) << "\n");
  INFO(" Valor esperado: ponteiro para " << key(esperado, s) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_conjunto_vazio") {
  set s;
  CHECK_EQ(end(s), s.end());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::end() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" s.end() nao retornou s.begin().\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_conjunto_nao_vazio") {
  set s;
  insert("1", &s);
  Node* atual = s.end();
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::end() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.end()\" retornou: ponteiro para " << key(atual, s) << "\n");
  INFO(" Valor esperado: ponteiro para " << key(esperado, s) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_do_primeiro_de_dois_elementos") {
  set s;
  insert("1", &s);
  insert("2", &s);
  Node* atual = s.next(begin(s));
  Node* esperado = next(begin(s), s);
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
  INFO(key(atual, s) << "\n");
  INFO(" Valor esperado: ponteiro para " << key(esperado, s) << "\n");
  INFO("------------------------------------------------------------------\n");
}


TEST_CASE("Testa_funcao_next_do_ultimo_elemento_do_conjunto") {
  set s;
  insert("1", &s);
  Node* atual = s.next(begin(s));
  Node* esperado = s.next(begin(s));
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
  INFO(key(atual, s) << "\n");
  INFO(" Valor esperado: ponteiro para " << key(esperado, s) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_do_segundo_de_dois_elementos") {
  set s;
  insert("1", &s);
  insert("2", &s);
  Node* atual = s.prev(next(begin(s), s));
  Node* esperado = begin(s);
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::prev(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.prev(s.find(2))\" retornou: ponteiro para ");
  INFO(key(atual, s) << "\n");
  INFO(" Valor esperado: ponteiro para " << key(esperado, s) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_do_primeiro_elemento_do_conjunto") {
  set s;
  insert("1", &s);
  Node* atual = s.prev(begin(s));
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::prev(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.prev(s.begin())\" retornou: ponteiro para ");
  INFO(key(atual, s) << "\n");
  INFO(" Valor esperado: ponteiro para " << key(esperado, s) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_do_end") {
  set s;
  insert("1", &s);
  insert("2", &s);
  Node* atual = s.prev(end(s));
  Node* esperado = prev(end(s), s);
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::prev(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.prev(s.end())\" retornou: ponteiro para ");
  INFO(key(atual, s) << "\n");
  INFO(" Valor esperado: ponteiro para " << key(esperado, s) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_key") {
  set s;
  insert("1", &s);
  SType atual = s.key(begin(s));
  SType esperado = "1";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: SType& set::key(Node* x)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.key(s.begin())\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_em_conjunto_vazio") {
  set s;
  SType atual = key(s.find("3"), s);
  SType esperado = key(s.end(), s);
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.find(3)\" retornou: um ponteiro para " << atual << "\n");
  INFO(" Valor esperado: ponteiro para " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_retornando_true") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  SType atual = key(s.find("3"), s);
  SType esperado = "3";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.find(3)\" retornou: um ponteiro para " << atual << "\n");
  INFO(" Valor esperado: ponteiro para " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_retornando_false") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("5", &s);
  insert("4", &s);
  SType atual = key(s.find("3"), s);
  SType esperado = key(s.end(), s);
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* set::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.find(3)\" retornou: um ponteiro para " << atual << "\n");
  INFO(" Valor esperado: ponteiro para " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_incremento_do_size_na_funcao_insert") {
  set s;
  s.insert("9");
  int atual = size(s);
  int esperado = 1;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { } \n");
  INFO(" \"s.insert(9)\" resultou em: s.size() == " << atual << "\n");
  INFO(" Resultado esperado: s.size() == " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_conjunto_vazio") {
  set s;
  s.insert("9");
  string atual = ToString(s);
  string esperado = "{ 9 }";
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { } \n");
  INFO(" \"s.insert(9)\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_conjunto_nao_vazio") {
  set s;
  insert("4", &s);
  insert("1", &s);
  insert("3", &s);
  s.insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { 1 3 4 } \n");
  INFO(" \"s.insert(2)\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_com_elemento_repetido") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  s.insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 3 }");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { 1 2 3 } \n");
  INFO(" \"s.insert(2)\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_decremento_do_size_na_funcao_erase") {
  set s;
  insert("9", &s);
  s.erase("9");
  int atual = size(s);
  int esperado = 0;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { 9 } \n");
  INFO(" \"s.erase(9)\" resultou em: s.size() == " << atual << "\n");
  INFO(" Resultado esperado: s.size() == " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_conjunto_unitario") {
  set s;
  s.insert("9");
  s.erase("9");
  string atual = ToString(s);
  string esperado = "{ }";
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { 9 } \n");
  INFO(" \"s.erase(9)\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_conjunto_com_mais_de_um_elemento") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 1 3 4 }");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { 1 2 3 4} \n");
  INFO(" \"s.erase(2)\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_erase_de_elemento_que_nao_pertence_ao_conjunto") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  s.erase("5");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { 1 2 3 4 } \n");
  INFO(" \"s.erase(5)\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Clear") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  s.clear();
  string atual = ToString(s);
  string esperado = "{ }";
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::clear() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { 1 2 3 } \n");
  INFO(" \"s.clear()\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_conjunto_vazio") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  set u;
  u = s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::operator=(set& s)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ }" << "\n");
  INFO(" s = " << esperado << "\n");
  INFO(" \"u = s\" resultou em: u = " << atual << "\n");
  INFO(" Resultado esperado: u = " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_conjunto_nao_vazio") {
  set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  set u;
  insert("5", &u);
  insert("4", &u);
  insert("6", &u);
  u = s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void set::operator=(set& s)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ 4 5 6 }" << "\n");
  INFO(" s = " << esperado << "\n");
  INFO(" \"u = s\" resultou em: u = " << atual << "\n");
  INFO(" Resultado esperado: u = " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_ORDERED_SET_WITH_LINKED_LIST_TEST_SET_TEST_H_

