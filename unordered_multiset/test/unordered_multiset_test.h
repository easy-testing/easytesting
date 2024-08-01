// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_UNORDERED_MULTISET_TEST_UNORDERED_MULTISET_TEST_H_
#define TRUNK_UNORDERED_MULTISET_TEST_UNORDERED_MULTISET_TEST_H_

#include <cstdlib>
#include <sstream>
#include <string>

#include "../doctest/doctest.h"
#include "src/unordered_multiset.h"

using std::string;
using std::stringstream;

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  int count;  // Número de ocorrências da chave.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};


multiset* table(const unordered_multiset& s) {
  return s.table_;
}

int size(const unordered_multiset& s) {
  return s.size_;
}

// Retorna um ponteiro para o elemento seguinte ao último elemento
// do multiconjunto.
Node* end(const unordered_multiset& s) {
  return NULL;
}

Node* insert(SType k, int count, unordered_multiset* s) {
  int j = hash(k, s->capacity_);
  for (int i = 0; i < count; i++) {
    s->table_[j].insert(k);
    s->size_++;
  }
  return s->table_[j].find(k);
}

string ToString(Node* x) {
  stringstream out;
  if (x == NULL) {
    out << "NULL";
  } else {
    out << x->key;
  }
  return out.str();
}

string ToString(const unordered_multiset& s) {
  stringstream out;
  out << "{ ";
  for (int i = 0; i < s.capacity_; i++) {
    for (Node* j = s.table_[i].begin();
          j != s.table_[i].end();
          j = s.table_[i].next(j)) {
      for (int k = 0; k < j->count; k++) {
        out << ToString(j) << " ";
      }
    }
  }
  out << "}";
  return out.str();
}

TEST_CASE("Testa_construtor_vazio") {
  unordered_multiset atual;
  CHECK_NE(static_cast<multiset*>(NULL), table(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: unordered_multiset::unordered_multiset()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um multiconjunto vazio, table != NULL\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: unordered_multiset::unordered_multiset()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um multiconjunto vazio, size_ = 0\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_multiconjunto_vazio") {
  unordered_multiset s;
  CHECK_UNARY(s.empty());
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: bool unordered_multiset::empty() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" o multiconjunto esta vazio e a funcao retornou FALSE.\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_multiconjunto_nao_vazio") {
  unordered_multiset s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  CHECK_UNARY_FALSE(s.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool unordered_multiset::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" Para um multiconjunto nao vazio a funcao retornou TRUE.          \n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_multiconjunto_vazio") {
  unordered_multiset s;
  int esperado = 0;
  int atual = s.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int unordered_multiset::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_multiconjunto_nao_vazio") {
  unordered_multiset s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  int atual = s.size();
  int esperado = 6;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int unordered_multiset::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_multiconjunto_vazio") {
  unordered_multiset s;
  CHECK_EQ(end(s), s.begin());
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::begin() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" s.begin() nao retornou s.end().\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_multiconjunto_nao_vazio") {
  unordered_multiset s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.begin();
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::begin() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.begin()\" retornou: ponteiro para " << ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_multiconjunto_vazio") {
  unordered_multiset s;
  CHECK_EQ(end(s), s.end());
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::end() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" s.end() nao retornou s.begin().\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_multiconjunto_nao_vazio") {
  unordered_multiset s;
  insert("A", 1, &s);
  Node* atual = s.end();
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::end() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.end()\" retornou: ponteiro para " << ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_do_primeiro_elemento") {
  unordered_multiset s;
  Node* a = insert("A", 1, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::next(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_do_ultimo_elemento") {
  unordered_multiset s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.next(a);
  Node* esperado = NULL;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::next(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_com_o_proximo_abaixo") {
  unordered_multiset s;
  insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::next(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.next(s.find('A'))\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_com_o_proximo_acima") {
  unordered_multiset s;
  Node* c = insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(b);
  Node* esperado = c;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::next(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.next(s.find('B'))\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_do_end") {
  unordered_multiset s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.prev(end(s));
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::prev(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.prev(s.end())\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_com_o_anterior_abaixo") {
  unordered_multiset s;
  Node* c = insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(c);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::prev(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.prev(s.find('C'))\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_com_o_proximo_acima") {
  unordered_multiset s;
  insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(b);
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: Node* unordered_multiset::prev(Node* x) \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(s) << "\n");
    INFO(" \"s.prev(s.find('B'))\" retornou: ponteiro para ");
    INFO(ToString(atual) << "\n");
    INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
    INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_de_elemento_no_multiconjunto") {
  unordered_multiset s;
  insert("C", 1, &s);
  insert("A", 1, &s);
  insert("D", 1, &s);
  Node* b = insert("B", 1, &s);
  Node* atual = s.find("B");
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* unordered_multiset::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" 's.find(\"B\")' retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_de_elemento_fora_do_multiconjunto") {
  unordered_multiset s;
  insert("C", 1, &s);
  insert("A", 1, &s);
  insert("D", 1, &s);
  insert("B", 1, &s);
  Node* atual = s.find("X");
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* unordered_multiset::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" 's.find(\"E\")' retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_count_em_multiconjunto_vazio") {
  unordered_multiset s;
  int atual = s.count("4");
  int esperado = 0;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int unordered_multiset::count(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = { }\n");
  INFO(" \"s.count(4)\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_count_com_mais_de_um_elemento") {
  unordered_multiset s;
  insert("2", 1, &s);
  insert("1", 3, &s);
  insert("3", 2, &s);
  int atual = s.count("1");
  int esperado = 3;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int unordered_multiset::count(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.count(1)\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_count_sem_o_elemento") {
  unordered_multiset s;
  insert("2", 1, &s);
  insert("4", 2, &s);
  insert("3", 1, &s);
  int atual = s.count("1");
  int esperado = 0;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int unordered_multiset::count(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.count(1)\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_incremento_do_size_na_funcao_insert_sem_repeticao") {
  unordered_multiset s;
  s.insert("A");
  int atual = size(s);
  int esperado = 1;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::insert(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = { } \n");
    INFO(" 's.insert(\"A\")' resultou em: s.size() == " << atual << "\n");
    INFO(" Resultado esperado: s.size() == " << esperado << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_incremento_do_size_na_funcao_insert_com_repeticao") {
  unordered_multiset s;
  insert("A", 2, &s);
  s.insert("A");
  int atual = size(s);
  int esperado = 3;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::insert(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = {A, A} \n");
    INFO(" 's.insert(\"A\")' resultou em: s.size() == " << atual << "\n");
    INFO(" Resultado esperado: s.size() == " << esperado << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_multiconjunto_vazio") {
  unordered_multiset atual;
  atual.insert("A");
  unordered_multiset esperado;
  insert("A", 1, &esperado);
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::insert(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = { } \n");
    INFO(" 's.insert(\"A\")' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_multiconjunto_nao_vazio") {
  unordered_multiset atual;
  insert("D", 1, &atual);
  insert("A", 1, &atual);
  insert("C", 1, &atual);
  unordered_multiset original;
  insert("D", 1, &original);
  insert("A", 1, &original);
  insert("C", 1, &original);
  unordered_multiset esperado;
  insert("D", 1, &esperado);
  insert("A", 1, &esperado);
  insert("C", 1, &esperado);
  insert("B", 1, &esperado);
  atual.insert("B");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::insert(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << "\n");
    INFO(" 's.insert(\"B\")' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_com_elemento_ja_dentro") {
  unordered_multiset atual;
  insert("D", 1, &atual);
  insert("A", 1, &atual);
  insert("C", 1, &atual);
  insert("B", 1, &atual);
  unordered_multiset original;
  insert("D", 1, &original);
  insert("A", 1, &original);
  insert("C", 1, &original);
  insert("B", 1, &original);
  unordered_multiset esperado;
  insert("D", 1, &esperado);
  insert("A", 1, &esperado);
  insert("C", 1, &esperado);
  insert("B", 2, &esperado);
  atual.insert("B");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::insert(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << "\n");
    INFO(" 's.insert(\"B\")' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_decremento_do_size_na_funcao_erase") {
  unordered_multiset s;
  insert("A", 1, &s);
  s.erase("A");
  int atual = size(s);
  int esperado = 0;
  CHECK_EQ(esperado, atual);
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::insert(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = { A } \n");
    INFO(" \"s.erase(\"A\")\" resultou em: s.size() == " << atual << "\n");
    INFO(" Resultado esperado: s.size() == " << esperado << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_multiconjunto_unitario") {
  unordered_multiset atual;
  insert("A", 1, &atual);
  unordered_multiset original;
  insert("A", 1, &original);
  unordered_multiset esperado;
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::erase(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

//  TEST_CASE("Testa_funcao_erase_da_ultima_ocorrencia_de_um_elemento") {
//  unordered_multiset atual;
//  insert("A", 1, &atual);
//  atual.erase("A");
//  CHECK_EQ("NULL", ToString(root(atual)));
//  INFO("------------------------------------------------------------------\n");
//  INFO("Erro na funcao: void unordered_multiset::erase(SType k) *\n");
//  INFO("------------------------------------------------------------------\n");
//  INFO(" s = " << "{ A }" << " \n");
//  INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
//  INFO(" DICA: Se o número de ocorrencias de um elemento e igual a zero,  \n");
//  INFO(" voce tem que apagar o no onde ele esta.                          \n");
//  INFO("------------------------------------------------------------------\n");
//  }

TEST_CASE("Testa_funcao_erase_de_no_com_dois_filhos") {
  unordered_multiset atual;
  insert("B", 1, &atual);
  insert("A", 1, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  unordered_multiset original;
  insert("B", 1, &original);
  insert("A", 1, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  unordered_multiset esperado;
  insert("A", 1, &esperado);
  insert("D", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("B");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::erase(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}


TEST_CASE("Testa_funcao_erase_de_no_sem_subarvore_direita") {
  unordered_multiset atual;
  insert("B", 1, &atual);
  insert("A", 1, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  unordered_multiset original;
  insert("B", 1, &original);
  insert("A", 1, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  unordered_multiset esperado;
  insert("B", 1, &esperado);
  insert("A", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("D");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::erase(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_no_sem_subarvore_esquerda") {
  unordered_multiset atual;
  insert("B", 1, &atual);
  insert("A", 1, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  unordered_multiset original;
  insert("B", 1, &original);
  insert("A", 1, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  unordered_multiset esperado;
  insert("B", 1, &esperado);
  insert("D", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::erase(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_erase_de_elemento_que_nao_pertence_ao_multiconjunto") {
  unordered_multiset atual;
  insert("B", 1, &atual);
  insert("A", 1, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  unordered_multiset original;
  insert("B", 1, &original);
  insert("A", 1, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  unordered_multiset esperado;
  insert("B", 1, &esperado);
  insert("A", 1, &esperado);
  insert("D", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("X");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::erase(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_erase_de_elemento_repetido") {
  unordered_multiset atual;
  insert("B", 1, &atual);
  insert("A", 3, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  unordered_multiset original;
  insert("B", 1, &original);
  insert("A", 3, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  unordered_multiset esperado;
  insert("B", 1, &esperado);
  insert("A", 2, &esperado);
  insert("D", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::erase(SType k) *\n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Clear") {
  unordered_multiset atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  unordered_multiset original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  unordered_multiset esperado;
  atual.clear();
  CHECK_EQ(ToString(esperado), ToString(atual));
    INFO("------------------------------------------------------------------\n");
    INFO("Erro na funcao: void unordered_multiset::clear() \n");
    INFO("------------------------------------------------------------------\n");
    INFO(" s = " << ToString(original) << " \n");
    INFO(" 's.clear()\' resultou em: s = " << ToString(atual) << "\n");
    INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
    INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_multiconjunto_vazio") {
  unordered_multiset original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  unordered_multiset esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  unordered_multiset atual;
  atual = original;
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:");
  INFO(" void unordered_multiset::operator=(unordered_multiset& s)         \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ }" << " \n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" \"u = s\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_multiconjunto_nao_vazio") {
  unordered_multiset original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  unordered_multiset esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  unordered_multiset atual;
  insert("D", 2, &atual);
  atual = original;
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao:");
  INFO(" void unordered_multiset::operator=(unordered_multiset& s)         \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ D D }" << " \n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" \"u = s\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_UNORDERED_MULTISET_TEST_UNORDERED_MULTISET_TEST_H_
