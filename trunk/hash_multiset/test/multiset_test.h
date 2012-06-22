// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_HASH_MULTISET_TEST_MULTISET_TEST_H_
#define TRUNK_HASH_MULTISET_TEST_MULTISET_TEST_H_

#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "hash_multiset/src/multiset.h"
#include "list/src/list.h"

using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Insere k em c.
  // Precondição: k não está em c.
  void insert(SType k, set* c) {
    int j = hash(k, c->kCapacity_);
    c->table_[j].insert(c->table_[j].begin(), k);
    c->size_++;
  }

  // Retorna o primeiro elemento da primeira lista não vazia.
  Node* begin(set& s) {
    for (int i = 0; i < s.kCapacity_; i++) {
      if (!s.table_[i].empty()) {
        return s.table_[i].begin();
      }
    }
    return end(s);
  }

  // Retorna o "marcador de fim" do conjunto, ou seja,
  // O sentinela da última lista da tabela.
  Node* end(set& s) {
    return s.table_[s.kCapacity_ - 1].end();
  }

  // Se x não é o último elemento da lista que o contém, retorna o elemento
  // seguinte a x nesta lista. Caso contrário, retorna o primeiro elemento da
  // próxima lista não vazia da tabela.
  Node* next(Node* x, set& s) {
    int j = hash(x->key, s.kCapacity_);
    if (x->next != s.table_[j].end()) {
      return x->next;
    } else {
      for (int i = j + 1; i < s.kCapacity_; i++) {
        if (!s.table_[i].empty()) {
          return s.table_[i].begin();
        }
      }
      return end(s);
    }
  }

  int size(set& c) {
    return c.size_;
  }

  // Insere em um conjunto c, n elementos contidos no vetor v
  void CriaConjunto(SType x1, SType x2, SType x3, set* s) {
    insert(x2, s);
    insert(x1, s);
    insert(x3, s);
  }

  // Retorna uma string no formato "a b c d ... z ".
  string ToString(list& l) {
    stringstream sout;
    for (Node* i = l.begin() ; i != l.end() ; i = l.next(i)) {
      sout << i->key << " ";
    }
    return sout.str();
  }

  // Retorna uma string contendo os elementos do conjunto c
  // no formato { c1 c2 c3 c4 }
  string ToString(set& c) {
    stringstream out;
    out << "{ ";
    for (int i = 0; i < c.kCapacity_; i++) {
      if (!c.table_[i].empty()) {
        out << ToString(c.table_[i]);
      }
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  set atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, size_ = 0.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Construtor_por_copia_vazio) {
  set c;
  set s(c);
  string atual = ToString(s);
  string esperado = ToString(c);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set(set& s) \n"
    << "-------------------------------------------------------------------\n"
    << " s = { }\n"
    << " Conjunto criado: " << atual << "\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_Construtor_por_copia_com_varios_elementos) {
  set c;
  CriaConjunto("1", "2", "3", &c);
  set s(c);
  string atual = ToString(s);
  string esperado = ToString(c);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: set::set(set& s) \n"
    << "-------------------------------------------------------------------\n"
    << " s = { }\n"
    << " Conjunto criado: " << atual << "\n"
    << " Conjunto esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Find_em_conjunto_vazio) {
  set s;
  bool atual = s.find("4");
  bool esperado = false;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: bool set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = { }\n"
    << " \"s.find(4)\" retornou: " << "true" << "\n"
    << " Valor esperado: " << "false" << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Find_retorna_true) {
  set s;
  insert("2", &s);
  insert("3", &s);
  insert("1", &s);
  insert("3", &s);
  bool atual = s.find("3");
  bool esperado = true;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: bool set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: " << "false" << "\n"
    << " Valor esperado: true\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Find_retorna_false) {
  set s;
  insert("2", &s);
  insert("3", &s);
  insert("1", &s);
  insert("3", &s);
  bool atual = s.find("4");
  bool esperado = false;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: bool set::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(4)\" retornou: " << "true" << "\n"
    << " Valor esperado: " << "false" << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_count_em_conjunto_vazio) {
  set s;
  int atual = s.count("4");
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int set::count(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = { }\n"
    << " \"s.count(4)\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_count_com_elemento) {
  set s;
  insert("1", &s);
  insert("2", &s);
  insert("1", &s);
  insert("3", &s);
  insert("1", &s);
  int atual = s.count("1");
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int set::count(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.count(1)\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_count_sem_o_elemento) {
  set s;
  insert("2", &s);
  insert("4", &s);
  insert("4", &s);
  insert("3", &s);
  int atual = s.count("1");
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int set::count(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.count(1)\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_conjunto_vazio) {
  set s;
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

TEST_F(Teste, Testa_Size_para_conjunto_nao_vazio) {
  set s;
  CriaConjunto("1", "2", "1", &s);
  int esperado = 3;
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

TEST_F(Teste, Testa_Empty_com_conjunto_vazio) {
  set s;
  ASSERT_TRUE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_conjunto_nao_vazio) {
  set s;
  CriaConjunto("1", "2", "1", &s);
  ASSERT_FALSE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool set::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Next_na_mesma_lista) {
  set s;
  insert("21", &s);
  insert("12", &s);
  SType primeiro = "12";
  SType esperado = "21";
  SType atual = s.next(begin(s))->key;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"" << primeiro <<  "\"))]\" retornou: "
      << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo elemento esta na mesma\n"
      << " lista que 'x'.\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_Next_em_outra_lista) {
  set s;
  insert("1", &s);
  insert("5", &s);
  SType primeiro = begin(s)->key;
  SType esperado = next(begin(s), s)->key;
  SType atual = s.next(begin(s))->key;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"" << primeiro <<  "\"))]\" retornou: "
      << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo elemento NÃO esta na mesma\n"
      << " lista que 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Pred_na_mesma_lista) {
  set s;
  insert("21", &s);
  insert("12", &s);
  SType primeiro = begin(s)->key;
  SType segundo = next(begin(s), s)->key;
  SType atual = s.prev(next(begin(s), s))->key;
  ASSERT_EQ(primeiro, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.prev(s.find(\"" << segundo <<  "\"))]\" retornou: "
      << atual << "\n"
      << " Valor esperado: " << primeiro << "\n"
      << " DICA: Verifique o caso onde o elemento anterior esta na mesma\n"
      << " lista que 'x'.\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_Pred_em_outra_lista) {
  set s;
  insert("1", &s);
  insert("5", &s);
  SType primeiro = begin(s)->key;
  SType segundo = next(begin(s), s)->key;
  SType atual = s.prev(next(begin(s), s))->key;
  ASSERT_EQ(primeiro, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* set::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.prev(s.find(\"" << segundo <<  "\"))]\" retornou: "
      << atual << "\n"
      << " Valor esperado: " << primeiro << "\n"
      << " DICA: Verifique o caso onde o elemento anterior NÃO esta na mesma\n"
      << " lista que 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_At) {
  set s;
  CriaConjunto("1", "2", "1", &s);
  SType atual = s[s.begin()];
  SType esperado = begin(s)->key;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: SType& set::operator[](Node* x)\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s[s.begin()]\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Insert_em_conjunto_vazio) {
  set s;
  s.insert("10");
  string atual = ToString(s);
  string esperado("{ 10 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(10)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Insert_com_elemento_que_nao_esta_no_conjunto) {
  set s;
  CriaConjunto("1", "3", "1", &s);
  s.insert("2");
  string atual = ToString(s);
  string esperado("{ 1 1 2 3 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << "{ 1 1 3 }" << " \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Insert_com_elemento_que_ja_esta_no_conjunto) {
  set s;
  CriaConjunto("1", "2", "3", &s);
  s.insert("2");
  string atual = ToString(s);
  string esperado("{ 1 2 2 3 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << "{ 1 2 3 }" << " \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Erase_em_conjunto_unitario) {
  set s;
  s.insert("10");
  s.erase("10");
  string atual = ToString(s);
  string esperado("{ }");
  ASSERT_EQ(0, size(s))
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 10 } \n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " Ao apagar um elemento, você tem que decrementar size_"
      << "------------------------------------------------------------------\n";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 10 } \n"
      << " \"s.erase(10)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_em_conjunto_nao_vazio) {
  set s;
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
      << " s = " << "{ 1 2 3 4}" << " \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_de_elemento_que_nao_esta_no_conjunto) {
  set s;
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
      << " s = " << "{ 1 2 3 4 }" << " \n"
      << " \"s.erase(5)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_de_elemento_repetido) {
  set s;
  insert("1", &s);
  insert("2", &s);
  insert("1", &s);
  insert("2", &s);
  insert("1", &s);
  s.erase("1");
  string atual = ToString(s);
  string esperado("{ 1 1 2 2 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = " << "{ 1 1 1 2 2 }" << " \n"
      << " \"s.erase(1)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Clear) {
  set s;
  CriaConjunto("1", "2", "3", &s);
  s.clear();
  string atual = ToString(s);
  string esperado("{ }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void set::clear() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << "{ 1 2 3 }" << " \n"
      << " \"s.clear()\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_Assign) {
  set esperado;
  CriaConjunto("1", "2", "3", &esperado);
  set atual;
  atual = esperado;
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void set::operator=(set& s)\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(esperado) << "\n"
    << " \"u = s\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_HASH_MULTISET_TEST_MULTISET_TEST_H_
