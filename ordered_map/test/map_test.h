// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_MAP_TEST_MAP_TEST_H_
#define TRUNK_ORDERED_MAP_TEST_MAP_TEST_H_

#include <cstdlib>
#include <sstream>
#include <string>

#include "../doctest/doctest.h"
#include "src/map.h"

using std::string;
using std::stringstream;

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  VType value;  // Valor do nó
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

Node* root(const map& s) {
  return s.root_;
}

int size(const map& s) {
  return s.size_;
}

// Retorna um ponteiro para o elemento seguinte ao último elemento
// do conjunto.
Node* end(const map& s) {
  return NULL;
}

Node* insert(SType k, VType v, map* s) {
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
  z->value = v;
  z->parent = y;
  z->left = z->right = NULL;
  if (y == NULL) {
    s->root_ = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else  {
    y->right = z;
  }
  s->size_++;
  return z;
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

// Retorna uma string contendo os elementos da árvore no formato
// { <k1,v1> <k2,v2> ... <kn,vn> }.
string TreeToString(Node* root) {
  if (root == NULL) {
    return "";
  } else {
    stringstream out;
    if (root->left != NULL) out << TreeToString(root->left);
    out << ToString(root) << " ";
    if (root->right != NULL) out << TreeToString(root->right);
    return out.str();
  }
}

string ToString(const map& s) {
  stringstream out;
  out << "{ ";
  out << TreeToString(s.root_);
  out << "}";
  return out.str();
}

TEST_CASE("Testa_construtor_vazio") {
  map atual;
  CHECK_EQ(end(atual), root(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: map::map()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um conjunto vazio, root_ = NULL\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: map::map()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um conjunto vazio, size_ = 0\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_conjunto_vazio") {
  map s;
  CHECK_UNARY(s.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool map::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" o conjunto esta vazio e a funcao retornou FALSE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_empty_em_conjunto_nao_vazio") {
  map s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  CHECK_UNARY_FALSE(s.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool map::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_conjunto_vazio") {
  map s;
  int esperado = 0;
  int atual = s.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int map::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_size_em_conjunto_nao_vazio") {
  map s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  int atual = s.size();
  int esperado = 3;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int map::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_conjunto_vazio") {
  map s;
  CHECK_EQ(end(s), s.begin());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::begin() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" s.begin() nao retornou s.end().\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_begin_em_conjunto_nao_vazio") {
  map s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.begin();
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::begin() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.begin()\" retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_conjunto_vazio") {
  map s;
  CHECK_EQ(end(s), s.end());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::end() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" s.end() nao retornou s.begin().\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_end_em_conjunto_nao_vazio") {
  map s;
  insert("A", 1, &s);
  Node* atual = s.end();
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::end() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.end()\" retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_do_primeiro_elemento") {
  map s;
  Node* a = insert("A", 1, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_do_ultimo_elemento") {
  map s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.next(a);
  Node* esperado = NULL;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.begin())\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_com_o_proximo_abaixo") {
  map s;
  insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.find('A'))\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_next_com_o_proximo_acima") {
  map s;
  Node* c = insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(b);
  Node* esperado = c;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::next(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.next(s.find('B'))\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_do_end") {
  map s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.prev(end(s));
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::prev(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.prev(s.end())\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_com_o_anterior_abaixo") {
  map s;
  Node* c = insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(c);
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::prev(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.prev(s.find('C'))\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_prev_com_o_proximo_acima") {
  map s;
  insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(b);
  Node* esperado = a;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::prev(Node* x) \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.prev(s.find('B'))\" retornou: ponteiro para ");
  INFO(ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO(" DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_de_elemento_no_conjunto") {
  map s;
  insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.find("B");
  Node* esperado = b;
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" 's.find(\"B\")' retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_find_de_elemento_fora_do_conjunto") {
  map s;
  insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  insert("B", 2, &s);
  Node* atual = s.find("X");
  Node* esperado = end(s);
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: Node* map::find(SType k) \n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" 's.find(\"E\")' retornou: ponteiro para " << ToString(atual) << "\n");
  INFO(" Valor esperado: ponteiro para " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_at") {
  map atual;
  insert("A", 1, &atual);
  insert("B", 2, &atual);
  insert("C", 3, &atual);
  atual["B"] = -2;
  map esperado;
  insert("A", 1, &esperado);
  insert("B", -2, &esperado);
  insert("C", 3, &esperado);
  CHECK_EQ(ToString(atual), ToString(esperado));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: SType& map::operator[](Node* x)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(atual) << "\n");
  INFO(" \"s[\"B\"] = -2\" resultou em: s = " << ToString(atual) << "\n");
  INFO(" Valor esperado: " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}


TEST_CASE("Testa_incremento_do_size_na_funcao_insert") {
  map s;
  s.insert("A", 1);
  int atual = size(s);
  int esperado = 1;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { } \n");
  INFO(" 's.insert(\"A\",1)' resultou em: s.size() == " << atual << "\n");
  INFO(" Resultado esperado: s.size() == " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_conjunto_vazio") {
  map atual;
  atual.insert("A", 1);
  map esperado;
  insert("A", 1, &esperado);
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { } \n");
  INFO(" 's.insert(\"A,1\")' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_em_conjunto_nao_vazio") {
  map atual;
  insert("D", 4, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  map original;
  insert("D", 4, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  map esperado;
  insert("D", 4, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  insert("B", 2, &esperado);
  atual.insert("B", 2);
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" 's.insert(\"B\",2)' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_insert_com_atualizacao_de_valor") {
  map atual;
  insert("D", 4, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  insert("B", 2, &atual);
  map original;
  insert("D", 4, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  insert("B", 2, &original);
  map esperado;
  insert("D", 4, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  insert("B", -2, &esperado);
  atual.insert("B", -2);
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" 's.insert(\"B\",-2)' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_decremento_do_size_na_funcao_erase") {
  map s;
  insert("A", 1, &s);
  s.erase("A");
  int atual = size(s);
  int esperado = 0;
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::insert(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = { <A,1> } \n");
  INFO(" \"s.erase(A)\" resultou em: s.size() == " << atual << "\n");
  INFO(" Resultado esperado: s.size() == " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_conjunto_unitario") {
  map atual;
  insert("A", 1, &atual);
  map original;
  insert("A", 1, &original);
  map esperado;
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_de_no_com_dois_filhos") {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  map esperado;
  insert("A", 1, &esperado);
  insert("D", 4, &esperado);
  insert("C", 3, &esperado);
  atual.erase("B");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}


TEST_CASE("Testa_funcao_erase_de_no_sem_subarvore_direita") {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  atual.erase("D");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_funcao_erase_em_no_sem_subarvore_esquerda") {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("D", 4, &esperado);
  insert("C", 3, &esperado);
  atual.erase("A");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_erase_de_elemento_que_nao_pertence_ao_conjunto") {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("D", 4, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("D", 4, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("D", 4, &esperado);
  insert("C", 3, &esperado);
  atual.erase("X");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::erase(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Clear") {
  map atual;
  insert("B", 2, &atual);
  insert("A", 1, &atual);
  insert("C", 3, &atual);
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  map esperado;
  atual.clear();
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::clear() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = " << ToString(original) << " \n");
  INFO(" 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: s = " << ToString(esperado) << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_conjunto_vazio") {
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  map atual;
  atual = original;
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::operator=(map& s)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ }" << " \n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" \"u = s\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao_a_conjunto_nao_vazio") {
  map original;
  insert("B", 2, &original);
  insert("A", 1, &original);
  insert("C", 3, &original);
  map esperado;
  insert("B", 2, &esperado);
  insert("A", 1, &esperado);
  insert("C", 3, &esperado);
  map atual;
  insert("D", 4, &atual);
  atual = original;
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void map::operator=(map& s)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" u = " << "{ <D,4> }" << " \n");
  INFO(" s = " << ToString(original) << "\n");
  INFO(" \"u = s\" resultou em: u = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_ORDERED_MAP_TEST_MAP_TEST_H_
