// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_UNORDERED_MULTISET_TEST_UNORDERED_MULTISET_TEST_H_
#define TRUNK_UNORDERED_MULTISET_TEST_UNORDERED_MULTISET_TEST_H_

#include <cstdlib>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "unordered_multiset/src/unordered_multiset.h"

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

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  multiset* table(unordered_multiset& s) {
    return s.table_;
  }

  int size(unordered_multiset& s) {
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

  string ToString(unordered_multiset& s) {
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
};

TEST_F(Teste, Testa_construtor_vazio) {
  unordered_multiset atual;
  ASSERT_NE(static_cast<multiset*>(NULL), table(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: unordered_multiset::unordered_multiset()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um multiconjunto vazio, table != NULL\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: unordered_multiset::unordered_multiset()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um multiconjunto vazio, size_ = 0\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_multiconjunto_vazio) {
  unordered_multiset s;
  ASSERT_TRUE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool unordered_multiset::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o multiconjunto esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_multiconjunto_nao_vazio) {
  unordered_multiset s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  ASSERT_FALSE(s.empty())
    << "------------------------------------------------------------------\n"
    << "Erro na funcao: bool unordered_multiset::empty() \n"
    << "------------------------------------------------------------------\n"
    << " Para um multiconjunto nao vazio a funcao retornou TRUE.          \n"
    << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_multiconjunto_vazio) {
  unordered_multiset s;
  int esperado = 0;
  int atual = s.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int unordered_multiset::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_multiconjunto_nao_vazio) {
  unordered_multiset s;
  insert("B", 2, &s);
  insert("A", 1, &s);
  insert("C", 3, &s);
  int atual = s.size();
  int esperado = 6;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int unordered_multiset::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_multiconjunto_vazio) {
  unordered_multiset s;
  ASSERT_EQ(end(s), s.begin())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.begin() nao retornou s.end().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_multiconjunto_nao_vazio) {
  unordered_multiset s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.begin();
  Node* esperado = a;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.begin()\" retornou: ponteiro para " << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_multiconjunto_vazio) {
  unordered_multiset s;
  ASSERT_EQ(end(s), s.end())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.end() nao retornou s.begin().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_multiconjunto_nao_vazio) {
  unordered_multiset s;
  insert("A", 1, &s);
  Node* atual = s.end();
  Node* esperado = end(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.end()\" retornou: ponteiro para " << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_do_primeiro_elemento) {
  unordered_multiset s;
  Node* a = insert("A", 1, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.begin())\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_do_ultimo_elemento) {
  unordered_multiset s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.next(a);
  Node* esperado = NULL;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.begin())\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_com_o_proximo_abaixo) {
  unordered_multiset s;
  insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(a);
  Node* esperado = b;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.find('A'))\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_com_o_proximo_acima) {
  unordered_multiset s;
  Node* c = insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.next(b);
  Node* esperado = c;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.find('B'))\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_do_end) {
  unordered_multiset s;
  Node* a = insert("A", 1, &s);
  Node* atual = s.prev(end(s));
  Node* esperado = a;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.end())\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_com_o_anterior_abaixo) {
  unordered_multiset s;
  Node* c = insert("C", 3, &s);
  insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(c);
  Node* esperado = b;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.find('C'))\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_com_o_proximo_acima) {
  unordered_multiset s;
  insert("C", 3, &s);
  Node* a = insert("A", 1, &s);
  insert("D", 4, &s);
  Node* b = insert("B", 2, &s);
  Node* atual = s.prev(b);
  Node* esperado = a;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* unordered_multiset::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.find('B'))\" retornou: ponteiro para "
      << ToString(atual) << "\n"
      << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_de_elemento_no_multiconjunto) {
  unordered_multiset s;
  insert("C", 1, &s);
  insert("A", 1, &s);
  insert("D", 1, &s);
  Node* b = insert("B", 1, &s);
  Node* atual = s.find("B");
  Node* esperado = b;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* unordered_multiset::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " 's.find(\"B\")' retornou: ponteiro para " << ToString(atual) << "\n"
    << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_de_elemento_fora_do_multiconjunto) {
  unordered_multiset s;
  insert("C", 1, &s);
  insert("A", 1, &s);
  insert("D", 1, &s);
  insert("B", 1, &s);
  Node* atual = s.find("X");
  Node* esperado = end(s);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* unordered_multiset::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " 's.find(\"E\")' retornou: ponteiro para " << ToString(atual) << "\n"
    << " Valor esperado: ponteiro para " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_count_em_multiconjunto_vazio) {
  unordered_multiset s;
  int atual = s.count("4");
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int unordered_multiset::count(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = { }\n"
    << " \"s.count(4)\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_count_com_mais_de_um_elemento) {
  unordered_multiset s;
  insert("2", 1, &s);
  insert("1", 3, &s);
  insert("3", 2, &s);
  int atual = s.count("1");
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int unordered_multiset::count(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.count(1)\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_count_sem_o_elemento) {
  unordered_multiset s;
  insert("2", 1, &s);
  insert("4", 2, &s);
  insert("3", 1, &s);
  int atual = s.count("1");
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int unordered_multiset::count(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.count(1)\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_incremento_do_size_na_funcao_insert_sem_repeticao) {
  unordered_multiset s;
  s.insert("A");
  int atual = size(s);
  int esperado = 1;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " 's.insert(\"A\")' resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_incremento_do_size_na_funcao_insert_com_repeticao) {
  unordered_multiset s;
  insert("A", 2, &s);
  s.insert("A");
  int atual = size(s);
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = {A, A} \n"
      << " 's.insert(\"A\")' resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_multiconjunto_vazio) {
  unordered_multiset atual;
  atual.insert("A");
  unordered_multiset esperado;
  insert("A", 1, &esperado);
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " 's.insert(\"A\")' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_multiconjunto_nao_vazio) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << "\n"
      << " 's.insert(\"B\")' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_com_elemento_ja_dentro) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << "\n"
      << " 's.insert(\"B\")' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_decremento_do_size_na_funcao_erase) {
  unordered_multiset s;
  insert("A", 1, &s);
  s.erase("A");
  int atual = size(s);
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { A } \n"
      << " \"s.erase(\"A\")\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_multiconjunto_unitario) {
  unordered_multiset atual;
  insert("A", 1, &atual);
  unordered_multiset original;
  insert("A", 1, &original);
  unordered_multiset esperado;
  atual.erase("A");
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

//  TEST_F(Teste, Testa_funcao_erase_da_ultima_ocorrencia_de_um_elemento) {
//  unordered_multiset atual;
//  insert("A", 1, &atual);
//  atual.erase("A");
//  ASSERT_EQ("NULL", ToString(root(atual)))
//    << "------------------------------------------------------------------\n"
//    << "Erro na funcao: void unordered_multiset::erase(SType k) *\n"
//    << "------------------------------------------------------------------\n"
//    << " s = " << "{ A }" << " \n"
//    << " 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n"
//    << " DICA: Se o número de ocorrencias de um elemento e igual a zero,  \n"
//    << " voce tem que apagar o no onde ele esta.                          \n"
//    << "------------------------------------------------------------------\n";
//  }

TEST_F(Teste, Testa_funcao_erase_de_no_com_dois_filhos) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_funcao_erase_de_no_sem_subarvore_direita) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_no_sem_subarvore_esquerda) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"A\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_de_elemento_que_nao_pertence_ao_multiconjunto) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_de_elemento_repetido) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.erase(\"B\")\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Clear) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void unordered_multiset::clear() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(original) << " \n"
      << " 's.clear()\' resultou em: s = " << ToString(atual) << "\n"
      << " Resultado esperado: s = " << ToString(esperado) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_multiconjunto_vazio) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:"
    << " void unordered_multiset::operator=(unordered_multiset& s)         \n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ }" << " \n"
    << " s = " << ToString(original) << "\n"
    << " \"u = s\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_multiconjunto_nao_vazio) {
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
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:"
    << " void unordered_multiset::operator=(unordered_multiset& s)         \n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ D D }" << " \n"
    << " s = " << ToString(original) << "\n"
    << " \"u = s\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_UNORDERED_MULTISET_TEST_UNORDERED_MULTISET_TEST_H_
