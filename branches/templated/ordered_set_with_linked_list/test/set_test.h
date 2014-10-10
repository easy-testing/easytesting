// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_TEMPLATED_ORDERED_SET_WITH_LINKED_LIST_TEST_SET_TEST_H_
#define BRANCHES_TEMPLATED_ORDERED_SET_WITH_LINKED_LIST_TEST_SET_TEST_H_

#include <cmath>
#include <cstdlib>
#include <queue>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "src/set.h"

using std::priority_queue;
using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna o valor da chave do elemento x de s;
  SType key(Node<string>* x, const set<string>& s) {
    if (x == NULL) {
      return "NULL";
    } else if (x == end(s)) {
      return "set::end()";
    } else {
      return x->key;
    }
  }

  // Retorna o número de elementos no conjunto.
  int size(const set<string>& s) {
    return s.size_;
  }

  // Insere k em s.
  // Precondição: k não está em s.
  void insert(string k, set<string>* s) {
    Node<string>* x = s->end_->next;
    while (x != s->end_ && x->key < k) {
      x = x->next;
    }
    if (x == s->end_ || x->key != k) {
      Node<string>* node = new Node<string>;
      node->key = k;
      node->prev = x->prev;
      node->next = x;
      x->prev->next = node;
      x->prev = node;
      s->size_++;
    }
  }

  // Retorna o primeiro elemento do conjunto.
  Node<string>* node(const set<string>::iterator& it) {
    return it.node_;
  }

  // Retorna o primeiro elemento do conjunto.
  Node<string>* begin(const set<string>& s) {
    return s.end_->next;
  }

  // Retorna o "marcador de fim" do conjunto.
  Node<string>* end(const set<string>& s) {
    return s.end_;
  }

  // Retorna o elemento seguinte a 'x' no conjunto.
  Node<string>* next(Node<string>* x, const set<string>& s) {
    return x->next;
  }

  // Retorna o elemento anterior a 'x' no conjunto.
  Node<string>* prev(Node<string>* x, const set<string>& s) {
    return x->prev;
  }

  // Retorna um ponteiro para o elemento k de s.
  Node<string>* find(string k, const set<string>& s) {
    for (Node<string>* i = s.end_->next; i != s.end_; i = i->next) {
      if (i->key == k) {
        return i;
      }
    }
    return s.end_;
  }

  // Retorna uma string contendo os elementos do conjunto
  // no formato { c1 c2 c3 c4 } e ordenados do maior para o menor.
  string ToString(const set<string>& s) {
    stringstream out;
    out << "{ ";
    for (Node<string>* i = begin(s); i != end(s); i = next(i, s)) {
      out << key(i, s) << " ";
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  set<string> atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, size_ = 0\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(begin(atual), end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, set::begin() == set::end()\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_vazio) {
  set<string> s;
  ASSERT_TRUE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_nao_vazio) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  ASSERT_FALSE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_vazio) {
  set<string> s;
  int esperado = 0;
  int atual = s.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int set::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_nao_vazio) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  int atual = s.size();
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int set::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_conjunto_vazio) {
  set<string> s;
  ASSERT_EQ(begin(s), node(s.begin()))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.begin() nao retornou s.end().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_conjunto_nao_vazio) {
  set<string> s;
  insert("1", &s);
  Node<string>* atual = node(s.begin());
  Node<string>* esperado = begin(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.begin()\" retornou: ponteiro para " << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_conjunto_vazio) {
  set<string> s;
  ASSERT_EQ(end(s), node(s.end()))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.end() nao retornou s.begin().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_conjunto_nao_vazio) {
  set<string> s;
  insert("1", &s);
  Node<string>* atual = node(s.end());
  Node<string>* esperado = end(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.end()\" retornou: ponteiro para " << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_em_conjunto_vazio) {
  set<string> s;
  SType atual = key(node(s.find("3")), s);
  SType esperado = key(node(s.end()), s);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual << "\n"
    << " Valor esperado: ponteiro para " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_retornando_true) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  SType atual = key(node(s.find("3")), s);
  SType esperado = "3";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual << "\n"
    << " Valor esperado: ponteiro para " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_retornando_false) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("5", &s);
  insert("4", &s);
  SType atual = key(node(s.find("3")), s);
  SType esperado = key(node(s.end()), s);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual << "\n"
    << " Valor esperado: ponteiro para " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_incremento_do_size_na_funcao_insert) {
  set<string> s;
  s.insert("9");
  int atual = size(s);
  int esperado = 1;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(9)\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_vazio) {
  set<string> s;
  s.insert("9");
  string atual = ToString(s);
  string esperado = "{ 9 }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(9)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_nao_vazio) {
  set<string> s;
  insert("4", &s);
  insert("1", &s);
  insert("3", &s);
  s.insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 3 4 } \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_com_elemento_repetido) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  s.insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 3 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_decremento_do_size_na_funcao_erase) {
  set<string> s;
  insert("9", &s);
  s.erase("9");
  int atual = size(s);
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 9 } \n"
      << " \"s.erase(9)\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_conjunto_unitario) {
  set<string> s;
  s.insert("9");
  s.erase("9");
  string atual = ToString(s);
  string esperado = "{ }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 9 } \n"
      << " \"s.erase(9)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_conjunto_com_mais_de_um_elemento) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 1 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4} \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_de_elemento_que_nao_pertence_ao_conjunto) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  s.erase("5");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4 } \n"
      << " \"s.erase(5)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Clear) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  s.clear();
  string atual = ToString(s);
  string esperado = "{ }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::clear() \n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.clear()\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_vazio) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  set<string> u;
  u = s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void set::operator=(set& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ }" << "\n"
    << " s = " << esperado << "\n"
    << " \"u = s\" resultou em: u = " << atual << "\n"
    << " Resultado esperado: u = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_nao_vazio) {
  set<string> s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  set<string> u;  // NOLINT
  insert("5", &u);
  insert("4", &u);
  insert("6", &u);
  u = s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void set::operator=(set& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ 4 5 6 }" << "\n"
    << " s = " << esperado << "\n"
    << " \"u = s\" resultou em: u = " << atual << "\n"
    << " Resultado esperado: u = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // BRANCHES_TEMPLATED_ORDERED_SET_WITH_LINKED_LIST_TEST_SET_TEST_H_

