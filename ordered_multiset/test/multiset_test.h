// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_MULTISET_TEST_MULTISET_TEST_H_
#define TRUNK_ORDERED_MULTISET_TEST_MULTISET_TEST_H_

#include <cstdlib>
#include <sstream>
#include <string>

#include "../doctest/doctest.h"
#include "src/multiset.h"

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

Node* root(const multiset& s) {
  return s.root_;
}

int size(const multiset& s) {
  return s.size_;
}

// Retorna um ponteiro para o elemento seguinte ao último elemento
// do multiconjunto.
Node* end(const multiset& s) {
  return NULL;
}

Node* insert(SType k, int count, multiset* s) {
  Node* y = NULL;
  Node* x = s->root_;
  while (x != NULL) {
    y = x;
    if (k < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  Node* z = new Node;
  z->key = k;
  z->count = count;
  z->parent = y;
  z->left = z->right = NULL;
  if (y == NULL) {
    s->root_ = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else  {
    y->right = z;
  }
  s->size_ += count;
  return z;
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

// Retorna uma string contendo os elementos da árvore no formato
// {k1, k2, ..., kn}.
string TreeToString(Node* root) {
  if (root == NULL) {
    return "";
  } else {
    stringstream out;
    if (root->left != NULL) out << TreeToString(root->left);
    for (int i = 0; i < root->count; i++) {
      out << ToString(root) << " ";
    }
    if (root->right != NULL) out << TreeToString(root->right);
    return out.str();
  }
}

string ToString(const multiset& s) {
  stringstream out;
  out << "{ ";
  out << TreeToString(s.root_);
  out << "}";
  return out.str();
}

TEST_CASE("Testa_construtor_vazio") {
  multiset atual;
  CHECK_EQ(end(atual), root(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: multiset::multiset()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um multiconjunto vazio, root_ = NULL\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: multiset::multiset()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um multiconjunto vazio, size_ = 0\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_multiconjunto_vazio") {
  multiset s;
  CHECK_UNARY(s.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool multiset::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" o multiconjunto esta vazio e a funcao retornou FALSE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_multiconjunto_nao_vazio") {
  multiset s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  CHECK_UNARY_FALSE(s.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool multiset::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" Para um multiconjunto nao vazio a funcao retornou TRUE.          \n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_multiconjunto_vazio") {
  multiset s;
  int esperado = 0;
  int atual = s.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int multiset::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_multiconjunto_nao_vazio") {
  multiset s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  int atual = s.size();
  int esperado = 6;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int multiset::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_multiconjunto_vazio") {
  multiset s;
  CHECK_EQ(end(s), s.begin());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::begin() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" s.begin() nao retornou s.end().\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_multiconjunto_nao_vazio") {
  multiset s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.begin();
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::begin() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.begin()\" retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_multiconjunto_vazio") {
  multiset s;
  CHECK_EQ(end(s), s.end());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::end() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" s.end() nao retornou s.begin().\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_multiconjunto_nao_vazio") {
  multiset s;
  insert("A", 1, &s);
  Node* atual = s.end();
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::end() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.end()\" retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_do_primeiro_elemento") {
  multiset s;
  Node* a = insert("A", 1, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_do_ultimo_elemento") {
  multiset s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.next(a);
  Node* esperado = NULL;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_com_o_proximo_abaixo") {
  multiset s;
  insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.find('A'))\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_com_o_proximo_acima") {
  multiset s;
  Node* c = insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(b);
  Node* esperado = c;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.find('B'))\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_do_end") {
  multiset s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.prev(end(s));
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::prev(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.prev(s.end())\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_com_o_anterior_abaixo") {
  multiset s;
  Node* c = insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(c);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::prev(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.prev(s.find('C'))\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_com_o_proximo_acima") {
  multiset s;
  insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(b);
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::prev(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.prev(s.find('B'))\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_de_elemento_no_multiconjunto") {
  multiset s;
  insert("C", 1, &s);
  insert("A", 1, &s);
  insert("D", 1, &s);
  Node* b = insert("B", 1, &s);
  Node* atual = s.find("B");
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" 's.find(\"B\")' retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_de_elemento_fora_do_multiconjunto") {
  multiset s;
  insert("C", 1, &s);
  insert("A", 1, &s);
  insert("D", 1, &s);
  insert("B", 1, &s);
  Node* atual = s.find("X");
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* multiset::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" 's.find(\"E\")' retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_count_em_multiconjunto_vazio") {
  multiset s;
  int atual = s.count("4");
  int esperado = 0;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int multiset::count(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = { }\n");
  INFO(" \"s.count(4)\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_count_com_mais_de_um_elemento") {
  multiset s;
  insert("2", 1, &s);
  insert("1", 3, &s);
  insert("3", 2, &s);
  int atual = s.count("1");
  int esperado = 3;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int multiset::count(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.count(1)\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_count_sem_o_elemento") {
  multiset s;
  insert("2", 1, &s);
  insert("4", 2, &s);
  insert("3", 1, &s);
  int atual = s.count("1");
  int esperado = 0;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int multiset::count(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.count(1)\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_incremento_do_size_na_funcao_insert_sem_repeticao") {
  multiset s;
  s.insert("A");
  int atual = size(s);
  int esperado = 1;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { } \n");
  INFO(" 's.insert(\"A\")' resultou em: s.size() == " << atual << "\n");
  INFO(" Resultado esperado: s.size() == " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_incremento_do_size_na_funcao_insert_com_repeticao") {
  multiset s;
  insert("A", 2, &s);
  s.insert("A");
  int atual = size(s);
  int esperado = 3;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = {A, A} \n");
  INFO(" 's.insert(\"A\")' resultou em: s.size() == " << atual << "\n");
  INFO(" Resultado esperado: s.size() == " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_multiconjunto_vazio") {
  multiset atual;
  atual.insert("A");
  multiset esperado;
  insert("A", 1, &esperado);
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { } \n");
  INFO(" 's.insert(\"A\")' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_multiconjunto_nao_vazio") {
  multiset atual;
  insert("D", 1, &atual);
  insert("A", 1, &atual);
  insert("C", 1, &atual);
  multiset original;
  insert("D", 1, &original);
  insert("A", 1, &original);
  insert("C", 1, &original);
  multiset esperado;
  insert("D", 1, &esperado);
  insert("A", 1, &esperado);
  insert("C", 1, &esperado);
  insert("B", 1, &esperado);
  atual.insert("B");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" 's.insert(\"B\")' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_com_elemento_ja_dentro") {
  multiset atual;
  insert("D", 1, &atual);
  insert("A", 1, &atual);
  insert("C", 1, &atual);
  insert("B", 1, &atual);
  multiset original;
  insert("D", 1, &original);
  insert("A", 1, &original);
  insert("C", 1, &original);
  insert("B", 1, &original);
  multiset esperado;
  insert("D", 1, &esperado);
  insert("A", 1, &esperado);
  insert("C", 1, &esperado);
  insert("B", 2, &esperado);
  atual.insert("B");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" 's.insert(\"B\")' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_decremento_do_size_na_funcao_erase") {
  multiset s;
  insert("A", 1, &s);
  s.erase("A");
  int atual = size(s);
  int esperado = 0;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { A } \n");
  INFO(" \"s.erase(\"A\")\" resultou em: s.size() == " << atual << "\n");
  INFO(" Resultado esperado: s.size() == " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_multiconjunto_unitario") {
  multiset atual;
  insert("A", 1, &atual);
  multiset original;
  insert("A", 1, &original);
  multiset esperado;
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_da_ultima_ocorrencia_de_um_elemento") {
  multiset atual;
  insert("A", 1, &atual);
  atual.erase("A");
  CHECK_EQ("NULL", ToString(root(atual)));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << "{ A }" << " \n");
  INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" DICA: Se o número de ocorrencias de um elemento e igual a zero,  \n");
  INFO(" voce tem que apagar o no onde ele esta.                          \n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_de_no_com_dois_filhos") {
  multiset atual;
  insert("B", 1, &atual);
  insert("A", 1, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  multiset original;
  insert("B", 1, &original);
  insert("A", 1, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  multiset esperado;
  insert("A", 1, &esperado);
  insert("D", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("B");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}


TEST_CASE("Testa_funcao_erase_de_no_sem_subarvore_direita") {
  multiset atual;
  insert("B", 1, &atual);
  insert("A", 1, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  multiset original;
  insert("B", 1, &original);
  insert("A", 1, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  multiset esperado;
  insert("B", 1, &esperado);
  insert("A", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("D");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_no_sem_subarvore_esquerda") {
  multiset atual;
  insert("B", 1, &atual);
  insert("A", 1, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  multiset original;
  insert("B", 1, &original);
  insert("A", 1, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  multiset esperado;
  insert("B", 1, &esperado);
  insert("D", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_erase_de_elemento_que_nao_pertence_ao_multiconjunto") {
  multiset atual;
  insert("B", 1, &atual);
  insert("A", 1, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  multiset original;
  insert("B", 1, &original);
  insert("A", 1, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  multiset esperado;
  insert("B", 1, &esperado);
  insert("A", 1, &esperado);
  insert("D", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("X");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_erase_de_elemento_repetido") {
  multiset atual;
  insert("B", 1, &atual);
  insert("A", 3, &atual);
  insert("D", 1, &atual);
  insert("C", 1, &atual);
  multiset original;
  insert("B", 1, &original);
  insert("A", 3, &original);
  insert("D", 1, &original);
  insert("C", 1, &original);
  multiset esperado;
  insert("B", 1, &esperado);
  insert("A", 2, &esperado);
  insert("D", 1, &esperado);
  insert("C", 1, &esperado);
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Clear") {
  multiset atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  multiset original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  multiset esperado;
  atual.clear();
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::clear() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.clear()\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_multiconjunto_vazio") {
  multiset original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  multiset esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  multiset atual;
  atual = original;
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::operator=(multiset& s)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ }" << " \n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" \"u = s\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_multiconjunto_nao_vazio") {
  multiset original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  multiset esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  multiset atual;
  insert("D", 2, &atual);
  atual = original;
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void multiset::operator=(multiset& s)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ D D }" << " \n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" \"u = s\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_ORDERED_MULTISET_TEST_MULTISET_TEST_H_
