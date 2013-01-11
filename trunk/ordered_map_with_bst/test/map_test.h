// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_MAP_WITH_BST_TEST_MAP_TEST_H_
#define TRUNK_ORDERED_MAP_WITH_BST_TEST_MAP_TEST_H_

#include <cstdlib>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#include "ordered_map_with_bst/src/map.h"

using std::string;
using std::stringstream;

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  VType value; // Valor do nó
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna o valor da chave do elemento x de s;
  SType key(Node* x, map& s) {
    if (x == NULL) {
      return "NULL";
    } else if (x == end(s)) {
      return "map::end()";
    } else {
      return x->key;
    }
  }

  // Retorna o número de elementos no conjunto.
  int size(map& s) {
    return s.size_;
  }

  // Insere uma FOLHA z na árvore cujo nó raiz é 'root' de forma consistente.
  // NOTA: Esta função NÃO aloca a memória para z.
  void TreeInsert(Node*& root, Node* z) {
    // Procura qual vai ser o pai y de z na árvore.
    Node* y = NULL;
    Node* x = root;
    while (x != NULL) {
      y = x;
      if (z->key < x->key) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    // Insere z em baixo do nó y.
    z->parent = y;
    if (y == NULL) {
      root = z;  // z se torna a raiz da árvore.
    } else if (z->key < y->key) {
      y->left = z;
    } else  {
      y->right = z;
    }
  }

  void insert(SType k, VType v, map* s) {
    Node* z = new Node;
    z->key = k;
    z->value = v;
    z->left = z->right = z->parent = NULL;
    TreeInsert(s->root_, z);
    s->size_++;
  }

  // Retorna um ponteiro para o primeiro elemento do conjunto.
  Node* begin(const map& s) {
    Node* x = s.root_;
    if (x != NULL) {
      while (x->left != NULL) {
        x = x->left;
      }
    }
    return x;
  }

  // Retorna um ponteiro para o elemento seguinte ao último elemento
  // do conjunto.
  Node* end(const map& s) {
    return NULL;
  }

  // Dado o nó x, retorna o sucessor de x, ou seja, o nó cuja chave é o menor
  // elemento maior que a chave de x. Caso x seja o maior elemento da árvore,
  // retorna o nó sentinela.
  Node* next(Node* x, map& s) {
    if (x->right != NULL) {
      x = x->right;
      while (x->left != NULL) {
        x = x->left;
      }
      return x;
    } else {
      Node* y = x->parent;
      while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
      }
      return y;
    }
  }

  // Dado o nó x, retorna o antecessor de x, ou seja, o nó cuja chave é o menor
  // elemento maior que a chave de x. Caso x seja o menor elemento da árvore,
  // retorna o nó sentinela.
  Node* prev(Node* x, map& s) {
    if (x == end(s)) {
      x = s.root_;
      while (x->right != NULL) {
        x = x->right;
      }
      return x;
    } else if (x->left != NULL) {
      x = x->left;
      while (x->right != NULL) {
        x = x->right;
      }
      return x;
    } else {
      Node* y = x->parent;
      while (y != NULL && x == y->left) {
        x = y;
        y = y->parent;
      }
      return y;
    }
  }

  // Retorna um ponteiro para o elemento k de s.
  Node* find(SType k, map& s) {
    Node* x = s.root_;
    while (x != NULL && k != x->key) {
      if (k < x->key) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    return x;
  }

  // Retorna uma string contendo os elementos do conjunto
  // no formato { c1 c2 c3 c4 } e ordenados do maior para o menor.
  string ToString(map& s) {
    stringstream out;
    out << "{ ";
    for (Node* i = begin(s); i != end(s); i = next(i, s)) {
      out << key(i, s) << " ";
    }
    out << "}";
    return out.str();
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  map atual;
  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: map::map()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, size_ = 0\n"
    << "-------------------------------------------------------------------\n";
  ASSERT_EQ(begin(atual), end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: map::map()\n"
    << "-------------------------------------------------------------------\n"
    << " Em um conjunto vazio, map::begin() == map::end()\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_vazio) {
  map s;
  ASSERT_TRUE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool map::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_empty_em_conjunto_nao_vazio) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("3", 3, &s);
  ASSERT_FALSE(s.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool map::empty() \n"
      << "------------------------------------------------------------------\n"
      << " o conjunto tem pelo menos um elemento e a funcao retornou TRUE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_vazio) {
  map s;
  int esperado = 0;
  int atual = s.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int map::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_size_em_conjunto_nao_vazio) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("3", 3, &s);
  int atual = s.size();
  int esperado = 3;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int map::size()\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_conjunto_vazio) {
  map s;
  ASSERT_EQ(begin(s), s.begin())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.begin() nao retornou s.end().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_begin_em_conjunto_nao_vazio) {
  map s;
  insert("1", 1, &s);
  Node* atual = s.begin();
  Node* esperado = begin(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::begin() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.begin()\" retornou: ponteiro para " << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_conjunto_vazio) {
  map s;
  ASSERT_EQ(end(s), s.end())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " s.end() nao retornou s.begin().\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_end_em_conjunto_nao_vazio) {
  map s;
  insert("1", 1, &s);
  Node* atual = s.end();
  Node* esperado = end(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::end() \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.end()\" retornou: ponteiro para " << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_do_primeiro_de_dois_elementos) {
  map s;
  insert("1", 1, &s);
  insert("2", 2, &s);
  Node* atual = s.next(begin(s));
  Node* esperado = next(begin(s), s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.begin())\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testa_funcao_next_do_ultimo_elemento_do_conjunto) {
  map s;
  insert("1", 1, &s);
  Node* atual = s.next(begin(s));
  Node* esperado = s.next(begin(s));
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.next(s.begin())\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_com_o_proximo_acima) {
  map s;
  insert("3", 3, &s);
  insert("1", 1, &s);
  insert("4", 4, &s);
  insert("2", 2, &s);
  SType atual = key(next(find("2", s), s), s);
  SType esperado = "3";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"2\"))]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo esta acima de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_next_com_o_proximo_abaixo) {
  map s;
  insert("3", 3, &s);
  insert("1", 1, &s);
  insert("4", 4, &s);
  insert("2", 2, &s);
  SType atual = key(next(find("2", s), s), s);
  SType esperado = "3";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::next(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"2\"))]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_do_segundo_de_dois_elementos) {
  map s;
  insert("1", 1, &s);
  insert("2", 2, &s);
  Node* atual = s.prev(next(begin(s), s));
  Node* esperado = begin(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.find(2))\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_do_primeiro_elemento_do_conjunto) {
  map s;
  insert("1", 1, &s);
  Node* atual = s.prev(begin(s));
  Node* esperado = end(s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.begin())\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_do_end) {
  map s;
  insert("1", 1, &s);
  insert("2", 2, &s);
  Node* atual = s.prev(end(s));
  Node* esperado = prev(end(s), s);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s.prev(s.end())\" retornou: ponteiro para "
      << key(atual, s) << "\n"
      << " Valor esperado: ponteiro para " << key(esperado, s) << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_com_o_anterior_acima) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("4", 4, &s);
  insert("3", 3, &s);
  SType atual = key(prev(find("3", s), s), s);
  SType esperado = "2";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"3\"))]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo esta acima de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_prev_com_o_anterior_abaixo) {
  map s;
  insert("3", 3, &s);
  insert("1", 1, &s);
  insert("4", 4, &s);
  insert("2", 2, &s);
  SType atual = key(prev(find("3", s), s), s);
  SType esperado = "2";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* map::prev(Node* x) \n"
      << "------------------------------------------------------------------\n"
      << " s = " << ToString(s) << "\n"
      << " \"s[s.next(s.find(\"3\"))]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << " DICA: Verifique o caso onde o proximo esta abaixo de 'x'.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_at) {
  map s;
  insert("1", 1, &s);
  VType atual = s[key(begin(s), s)];
  VType esperado = 1;
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: SType& map::operator[](Node* x)\n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s[s.begin()]\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_em_conjunto_vazio) {
  map s;
  SType atual = key(s.find("3"), s);
  SType esperado = key(s.end(), s);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* map::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual << "\n"
    << " Valor esperado: ponteiro para " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_retornando_true) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("4", 4, &s);
  insert("3", 3, &s);
  SType atual = key(s.find("3"), s);
  SType esperado = "3";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* map::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual << "\n"
    << " Valor esperado: ponteiro para " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_find_retornando_false) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("5", 5, &s);
  insert("4", 4, &s);
  SType atual = key(s.find("3"), s);
  SType esperado = key(s.end(), s);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: Node* map::find(SType k) \n"
    << "-------------------------------------------------------------------\n"
    << " s = " << ToString(s) << "\n"
    << " \"s.find(3)\" retornou: um ponteiro para " << atual << "\n"
    << " Valor esperado: ponteiro para " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_incremento_do_size_na_funcao_insert) {
  map s;
  s.insert("9", 9);
  int atual = size(s);
  int esperado = 1;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(9)\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_vazio) {
  map s;
  s.insert("9", 9);
  string atual = ToString(s);
  string esperado = "{ 9 }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { } \n"
      << " \"s.insert(9)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_em_conjunto_nao_vazio) {
  map s;
  insert("4", 4, &s);
  insert("1", 1, &s);
  insert("3", 3, &s);
  s.insert("2", 2);
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 3 4 } \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_insert_com_elemento_repetido) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("3", 3, &s);
  s.insert("2", 2);
  string atual = ToString(s);
  string esperado("{ 1 2 3 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.insert(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_decremento_do_size_na_funcao_erase) {
  map s;
  insert("9", 9, &s);
  s.erase("9");
  int atual = size(s);
  int esperado = 0;
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::insert(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 9 } \n"
      << " \"s.erase(9)\" resultou em: s.size() == " << atual << "\n"
      << " Resultado esperado: s.size() == " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_conjunto_unitario) {
  map s;
  s.insert("9", 9);
  s.erase("9");
  string atual = ToString(s);
  string esperado = "{ }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 9 } \n"
      << " \"s.erase(9)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_conjunto_com_mais_de_um_elemento) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("4", 4, &s);
  insert("3", 3, &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 1 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4} \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_de_elemento_que_nao_pertence_ao_conjunto) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("4", 4, &s);
  insert("3", 3, &s);
  s.erase("5");
  string atual = ToString(s);
  string esperado("{ 1 2 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4 } \n"
      << " \"s.erase(5)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_no_sem_filhos) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("3", 3, &s);
  s.erase("3");
  string atual = ToString(s);
  string esperado("{ 1 2 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.erase(3)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
      << " um no sem filhos.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_no_sem_subarvore_direita) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 1 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 } \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
      << " um no que nao tem a subarvore direita.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_no_sem_subarvore_esquerda) {
  map s;
  insert("2", 2, &s);
  insert("3", 3, &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 3 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 } \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
         " um no que nao tem a subarvore esquerda.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_funcao_erase_em_no_com_os_dois_filhos) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("4", 4, &s);
  insert("3", 3, &s);
  s.erase("2");
  string atual = ToString(s);
  string esperado("{ 1 3 4 }");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::erase(SType k) *\n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 4} \n"
      << " \"s.erase(2)\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << " DICA: Verifique se voce esta removendo corretamente da arvore\n"
         " um no que tem as duas subarvores nao vazias.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Clear) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("3", 3, &s);
  s.clear();
  string atual = ToString(s);
  string esperado = "{ }";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void map::clear() \n"
      << "------------------------------------------------------------------\n"
      << " s = { 1 2 3 } \n"
      << " \"s.clear()\" resultou em: s = " << atual << "\n"
      << " Resultado esperado: s = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_vazio) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("3", 3, &s);
  map u;
  u = s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void map::operator=(map& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ }" << "\n"
    << " s = " << esperado << "\n"
    << " \"u = s\" resultou em: u = " << atual << "\n"
    << " Resultado esperado: u = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_de_atribuicao_a_conjunto_nao_vazio) {
  map s;
  insert("2", 2, &s);
  insert("1", 1, &s);
  insert("3", 3, &s);
  map u;
  insert("5", 5, &u);
  insert("4", 4, &u);
  insert("6", 6, &u);
  u = s;
  string atual = ToString(u);
  string esperado = "{ 1 2 3 }";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void map::operator=(map& s)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << "{ 4 5 6 }" << "\n"
    << " s = " << esperado << "\n"
    << " \"u = s\" resultou em: u = " << atual << "\n"
    << " Resultado esperado: u = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // TRUNK_ORDERED_MAP_WITH_BST_TEST_MAP_TEST_H_
