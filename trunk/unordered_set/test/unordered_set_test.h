// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_UNORDERED_SET_TEST_UNORDERED_SET_TEST_H_
#define TRUNK_UNORDERED_SET_TEST_UNORDERED_SET_TEST_H_

#include <cmath>
#include <cstdlib>
#include <set>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "src/unordered_set.h"

using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  SType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna o valor da chave do elemento x de s;
  SType key(Node* x, unordered_set& s) {
    if (x == NULL) {
      return "NULL";
    } else if (x == end(s)) {
      return "unordered_set::end()";
    } else {
      return x->key;
    }
  }

  // Retorna o número de elementos no conjunto.
  int size(unordered_set& s) {
    return s.size_;
  }

  // Insere k em s.
  // Precondição: k não está em s.
  void insert(SType k, unordered_set* s) {
    int j = hash(k, s->capacity_);
    s->table_[j].insert(k);
    s->size_++;
  }

  // Retorna o primeiro elemento do conjunto.
  Node* begin(unordered_set& s) {
    for (int i = 0; i < s.capacity_; i++) {
      if (!s.table_[i].empty()) {
        return s.table_[i].begin();
      }
    }
    return end(s);
  }

  // Retorna o "marcador de fim" do conjunto.
  Node* end(unordered_set& s) {
    return s.table_[s.capacity_ - 1].end();
  }

  // Retorna o elemento seguinte a 'x' no conjunto.
  Node* next(Node* x, unordered_set& s) {
    int j = hash(x->key, s.capacity_);
    if (x->next != s.table_[j].end()) {
      return x->next;
    } else {
      for (int i = j + 1; i < s.capacity_; i++) {
        if (!s.table_[i].empty()) {
          return s.table_[i].begin();
        }
      }
      return end(s);
    }
  }

  // Retorna o elemento anterior a 'x' no conjunto.
  Node* prev(Node* x, unordered_set& s) {
    int j = hash(x->key, s.capacity_);
    if (x != s.table_[j].begin()) {
      return x->prev;
    } else {
      for (int i = j - 1; i >= 0; i--) {
        if (!s.table_[i].empty()) {
          return s.table_[i].end()->prev;
        }
      }
      return s.end();
    }
  }

  // Retorna um ponteiro para o elemento k de s.
  Node* find(SType k, unordered_set& s) {
    // Procura pelo elemento k na lista onde k pode estar.
    int j = hash(k, s.capacity_);
    for (Node* i = s.table_[j].begin();
          i != s.table_[j].end();
          i = s.table_[j].next(i)) {
      if (i->key == k) {
         return i;
      }
    }
    return s.end();
  }

  // Retorna uma string contendo os elementos do conjunto
  // no formato { c1 c2 c3 c4 } e ordenados do maior para o menor.
  string ToString(unordered_set& s) {
    std::set<string> ord_s;
    for (Node* i = begin(s); i != end(s); i = next(i, s)) {
      ord_s.insert(key(i, s));
    }
    stringstream out;
    out << "{ ";
    for (std::set<string>::iterator i = ord_s.begin(); i != ord_s.end(); i++) {
      out << *i << " ";
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  unordered_set atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: unordered_set::unordered_set()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, size_ = 0\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(begin(atual), end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: unordered_set::unordered_set()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, unordered_set::begin() == unordered_set::end()\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_vazio) {
  unordered_set s;
  ASSERT_TRUE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool unordered_set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_nao_vazio) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  ASSERT_FALSE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool unordered_set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_vazio) {
  unordered_set s;
  int esperado = 0;
  int atual = s.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int unordered_set::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_nao_vazio) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  int atual = s.size();
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int unordered_set::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_conjunto_vazio) {
  unordered_set s;
  ASSERT_EQ(begin(s), s.begin())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.begin() nao retornou s.end().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_conjunto_nao_vazio) {
  unordered_set s;
  insert("1", &s);
  Node* atual = s.begin();
  Node* esperado = begin(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.begin()\" retornou: ponteiro para " << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_conjunto_vazio) {
  unordered_set s;
  ASSERT_EQ(end(s), s.end())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.end() nao retornou s.begin().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_conjunto_nao_vazio) {
  unordered_set s;
  insert("1", &s);
  Node* atual = s.end();
  Node* esperado = end(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.end()\" retornou: ponteiro para " << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_do_primeiro_de_dois_elementos) {
  unordered_set s;
  insert("1", &s);
  insert("2", &s);
  Node* atual = s.next(begin(s));
  Node* esperado = next(begin(s), s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.begin())\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_funcao_next_do_ultimo_elemento_do_conjunto) {
  unordered_set s;
  insert("1", &s);
  Node* atual = s.next(begin(s));
  Node* esperado = s.next(begin(s));
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.begin())\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_com_proximo_na_mesma_lista) {
  unordered_set s;
  insert("21", &s);
  insert("12", &s);
  SType primeiro = begin(s)->key;
  SType esperado = next(begin(s), s)->key;
  SType atual = s.next(s.find(primeiro))->key;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"" << primeiro <<  "\"))]\" retornou: "
      << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo elemento esta na mesma\n"
      << " lista que 'x'.\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_funcao_next_com_proximo_em_outra_lista) {
  unordered_set s;
  insert("1", &s);
  insert("5", &s);
  SType primeiro = begin(s)->key;
  SType esperado = next(begin(s), s)->key;
  SType atual = s.next(s.find(primeiro))->key;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"" << primeiro <<  "\"))]\" retornou: "
      << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo elemento NÃO esta na mesma\n"
      << " lista que 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_do_segundo_de_dois_elementos) {
  unordered_set s;
  insert("1", &s);
  insert("2", &s);
  Node* atual = s.prev(next(begin(s), s));
  Node* esperado = begin(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.find(2))\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_do_primeiro_elemento_do_conjunto) {
  unordered_set s;
  insert("1", &s);
  Node* atual = s.prev(begin(s));
  Node* esperado = end(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.begin())\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_do_end) {
  unordered_set s;
  insert("1", &s);
  insert("2", &s);
  Node* atual = s.prev(end(s));
  Node* esperado = prev(end(s), s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.end())\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_com_anterior_na_mesma_lista) {
  unordered_set s;
  insert("21", &s);
  insert("12", &s);
  SType primeiro = begin(s)->key;
  SType segundo = next(begin(s), s)->key;
  SType atual = s.prev(s.find(segundo))->key;
  ASSERT_EQ(primeiro, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.prev(s.find(\"" << segundo <<  "\"))]\" retornou: "
      << atual << "\n"
      << " Valor esperado: " << primeiro << "\n"
      << " DICA: Verifique o caso onde o elemento anterior esta na mesma\n"
      << " lista que 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_com_anterior_em_outra_lista) {
  unordered_set s;
  insert("1", &s);
  insert("5", &s);
  SType primeiro = begin(s)->key;
  SType segundo = next(begin(s), s)->key;
  SType atual = s.prev(s.find(segundo))->key;
  ASSERT_EQ(primeiro, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_set::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.prev(s.find(\"" << segundo <<  "\"))]\" retornou: "
      << atual << "\n"
      << " Valor esperado: " << primeiro << "\n"
      << " DICA: Verifique o caso onde o elemento anterior NÃO esta na mesma\n"
      << " lista que 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_keys) {
  unordered_set s;
  insert("1", &s);
  SType atual = s.key(begin(s));
  SType esperado = "1";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: SType& unordered_set::key(Node* x)\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.key(s.begin())\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_em_conjunto_vazio) {
  unordered_set s;
  SType atual = key(s.find("3"), s);
  SType esperado = key(s.end(), s);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* unordered_set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual << "\n"
    << " Valor esperado: ponteiro para " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_retornando_true) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  SType atual = key(s.find("3"), s);
  SType esperado = "3";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* unordered_set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual << "\n"
    << " Valor esperado: ponteiro para " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_retornando_false) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("5", &s);
  insert("4", &s);
  SType atual = key(s.find("3"), s);
  SType esperado = key(s.end(), s);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* unordered_set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual << "\n"
    << " Valor esperado: ponteiro para " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_incremento_do_size_na_funcao_insert) {
  unordered_set s;
  s.insert("9");
  int atual = size(s);
  int esperado = 1;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(9)\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_vazio) {
  unordered_set s;
  s.insert("9");
  string atual = ToString(s);
  string esperado = "{ 9 }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(9)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_nao_vazio) {
  unordered_set s;
  insert("4", &s);
  insert("1", &s);
  insert("3", &s);
  s.insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 3 4 } \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_com_elemento_repetido) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  s.insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 3 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_decremento_do_size_na_funcao_erase) {
  unordered_set s;
  insert("9", &s);
  s.erase("9");
  int atual = size(s);
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 9 } \n"
      << " \"s.erase(9)\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_conjunto_unitario) {
  unordered_set s;
  s.insert("9");
  s.erase("9");
  string atual = ToString(s);
  string esperado = "{ }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 9 } \n"
      << " \"s.erase(9)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_conjunto_com_mais_de_um_elemento) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 1 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4} \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_de_elemento_que_nao_pertence_ao_conjunto) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("4", &s);
  insert("3", &s);
  s.erase("5");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4 } \n"
      << " \"s.erase(5)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Clear) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  s.clear();
  string atual = ToString(s);
  string esperado = "{ }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_set::clear() \n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.clear()\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_vazio) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  unordered_set u;
  u = s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void unordered_set::operator=(unordered_set& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ }" << "\n"
    << " s = " << esperado << "\n"
    << " \"u = s\" resultou em: u = " << atual << "\n"
    << " Resultado esperado: u = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_nao_vazio) {
  unordered_set s;
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  unordered_set u;
  insert("5", &u);
  insert("4", &u);
  insert("6", &u);
  u = s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void unordered_set::operator=(unordered_set& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ 4 5 6 }" << "\n"
    << " s = " << esperado << "\n"
    << " \"u = s\" resultou em: u = " << atual << "\n"
    << " Resultado esperado: u = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_UNORDERED_SET_TEST_UNORDERED_SET_TEST_H_
