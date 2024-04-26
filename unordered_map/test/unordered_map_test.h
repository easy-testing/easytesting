// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_UNORDERED_MAP_TEST_UNORDERED_MAP_TEST_H_
#define TRUNK_UNORDERED_MAP_TEST_UNORDERED_MAP_TEST_H_

#include <cmath>
#include <cstdlib>
#include <set>
#include <sstream>
#include <string>

#include "../doctest/doctest.h"
#include "src/unordered_map.h"

using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  SType key;  // Chave do nó.
  VType value;  // Valor do nó
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

map* table(const unordered_map& s) {
  return s.table_;
}

int size(const unordered_map& s) {
  return s.size_;
}

// Retorna o "marcador de fim" do conjunto.
Node* end(const unordered_map& s) {
  return s.table_[s.capacity_ - 1].end();
}

Node* insert(SType k, VType v, unordered_map* s) {
  int j = hash(k, s->capacity_);
  s->table_[j].insert(k, v);
  s->size_++;
  return s->table_[j].find(k);
}

string ToString(Node* x) {
  stringstream out;
  if (x == NULL) {
    out << "NULL";
  } else {
    out << "<" << x->key << "," << x->value << ">";
  }
  return out.str();
}

string ToString(const unordered_map& s) {
  stringstream out;
  out << "{ ";
  for (int i = 0; i < s.capacity_; i++) {
    for (Node* j = s.table_[i].begin();
          j != s.table_[i].end();
          j = s.table_[i].next(j)) {
      out << ToString(j) << " ";
    }
  }
  out << "}";
  return out.str();
}

TEST_CASE("Testa_construtor_vazio") {
  unordered_map atual;
  map* esperado = NULL;
  CHECK_NE(esperado, table(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: unordered_map::unordered_map()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Mesmo em um conjunto vazio, table_ != NULL\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: unordered_map::unordered_map()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um conjunto vazio, size_ = 0\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_conjunto_vazio") {
  unordered_map s;
  CHECK_UNARY(s.empty());
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: bool unordered_map::empty() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" o conjunto esta vazio e a funcao retornou FALSE.\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_conjunto_nao_vazio") {
  unordered_map s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  CHECK_UNARY_FALSE(s.empty());
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: bool unordered_map::empty() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_conjunto_vazio") {
  unordered_map s;
  int esperado = 0;
  int atual = s.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int unordered_map::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_conjunto_nao_vazio") {
  unordered_map s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  int atual = s.size();
  int esperado = 3;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int unordered_map::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_conjunto_vazio") {
  unordered_map s;
  CHECK_EQ(end(s), s.begin());
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_map::begin() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" s.begin() nao retornou s.end().\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_conjunto_nao_vazio") {
  unordered_map s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.begin();
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_map::begin() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.begin()\" retornou: ponteiro para " << ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_conjunto_vazio") {
  unordered_map s;
  CHECK_EQ(end(s), s.end());
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_map::end() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" s.end() nao retornou s.begin().\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_conjunto_nao_vazio") {
  unordered_map s;
  insert("A", 1, &s);
  Node* atual = s.end();
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_map::end() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.end()\" retornou: ponteiro para " << ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_do_primeiro_elemento") {
  unordered_map s;
  Node* a = insert("A", 1, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_map::next(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_do_ultimo_elemento") {
  unordered_map s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.next(a);
  Node* esperado = NULL;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_map::next(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_do_endX") {
  unordered_map s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.prev(end(s));
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_map::prev(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.prev(s.end())\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_com_o_anterior_abaixo") {
  unordered_map s;
  Node* c = insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(c);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_map::prev(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.prev(s.find('C'))\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_com_o_proximo_acima") {
  unordered_map s;
  insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(b);
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_map::prev(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.prev(s.find('B'))\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_de_elemento_no_conjunto") {
  unordered_map s;
  insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.find("B");
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* unordered_map::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" 's.find(\"B\")' retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_de_elemento_fora_do_conjunto") {
  unordered_map s;
  insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  insert("B", 2, &s);
  Node* atual = s.find("X");
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* unordered_map::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" 's.find(\"E\")' retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_at") {
  unordered_map atual;
  insert("A", 1, &atual);
  insert("B", 2, &atual);
  insert("C", 3, &atual);
  atual["B"] = -2;
  unordered_map esperado;
  insert("A", 1, &esperado);
  insert("B", -2, &esperado);
  insert("C", 3, &esperado);
  CHECK_EQ(ToString(atual), ToString(esperado));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: SType& unordered_map::operator[](Node* x)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(atual) << "\n");
  INFO(" \"s[\"B\"] = -2\" resultou em: s = " << ToString(atual) << "\n");
  INFO(" Valor esperado: " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}


TEST_CASE("Testa_incremento_do_size_na_funcao_insert") {
  unordered_map s;
  s.insert("A", 1);
  int atual = size(s);
  int esperado = 1;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::insert(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = { } \n");
    INFO(" 's.insert(\"A\",1)' resultou em: s.size() == " << atual << "\n");
    INFO(" Resultado esperado: s.size() == " << esperado << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_conjunto_vazio") {
  unordered_map atual;
  atual.insert("A", 1);
  unordered_map esperado;
  insert("A", 1, &esperado);
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::insert(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = { } \n");
    INFO(" 's.insert(\"A,1\")' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_conjunto_nao_vazio") {
  unordered_map atual;
  insert("D", 4, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  unordered_map original;
  insert("D", 4, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  unordered_map esperado;
  insert("D", 4, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  insert("B", 2, &esperado);
  atual.insert("B", 2);
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::insert(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << "\n");
    INFO(" 's.insert(\"B\",2)' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_com_atualizacao_de_valor") {
  unordered_map atual;
  insert("D", 4, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  insert("B", 2, &atual);
  unordered_map original;
  insert("D", 4, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  insert("B", 2, &original);
  unordered_map esperado;
  insert("D", 4, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  insert("B", -2, &esperado);
  atual.insert("B", -2);
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::insert(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << "\n");
    INFO(" 's.insert(\"B\",-2)' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_decremento_do_size_na_funcao_erase") {
  unordered_map s;
  insert("A", 1, &s);
  s.erase("A");
  int atual = size(s);
  int esperado = 0;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::insert(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = { <A,1> } \n");
    INFO(" \"s.erase(A)\" resultou em: s.size() == " << atual << "\n");
    INFO(" Resultado esperado: s.size() == " << esperado << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_conjunto_unitario") {
  unordered_map atual;
  insert("A", 1, &atual);
  unordered_map original;
  insert("A", 1, &original);
  unordered_map esperado;
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::erase(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_de_no_com_dois_filhos") {
  unordered_map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  unordered_map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  unordered_map esperado;
  insert("A", 1, &esperado);
  insert("D", 4, &esperado);
  insert("C", 3, &esperado);
  atual.erase("B");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::erase(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}


TEST_CASE("Testa_funcao_erase_de_no_sem_subarvore_direita") {
  unordered_map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  unordered_map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  unordered_map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  atual.erase("D");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::erase(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_no_sem_subarvore_esquerda") {
  unordered_map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  unordered_map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  unordered_map esperado;
  insert("B", 2, &esperado);
  insert("D", 4, &esperado);
  insert("C", 3, &esperado);
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::erase(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_erase_de_elemento_que_nao_pertence_ao_conjunto") {
  unordered_map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  unordered_map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  unordered_map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("D", 4, &esperado);
  insert("C", 3, &esperado);
  atual.erase("X");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::erase(SType k) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Clear") {
  unordered_map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  unordered_map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  unordered_map esperado;
  atual.clear();
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_map::clear() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_conjunto_vazio") {
  unordered_map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  unordered_map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  unordered_map atual;
  atual = original;
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void unordered_map::operator=(map& s)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ }" << " \n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" \"u = s\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_conjunto_nao_vazio") {
  unordered_map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  unordered_map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  unordered_map atual;
  insert("D", 4, &atual);
  atual = original;
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void unordered_map::operator=(map& s)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ <D,4> }" << " \n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" \"u = s\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_UNORDERED_MAP_TEST_UNORDERED_MAP_TEST_H_
