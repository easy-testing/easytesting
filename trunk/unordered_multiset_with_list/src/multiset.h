// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_HASH_MULTISET_SRC_MULTISET_H_
#define TRUNK_HASH_MULTISET_SRC_MULTISET_H_

#include <cmath>
#include <cstdlib>
#include <string>

#include "unordered_multiset_with_list/src/hash.h"

#include "list/src/list.h"

#define SType LType

// Implementa um conjunto com repetições utilizando tabela hash.
// NOTA: O cálculo da complexidade das funções assume que a função de hash
// utilizada é uniformemente simples e que capacity_ > size_. Entretanto,
// isto não é garantido nesta implentação. Para simplificar as funções de
// complexidade, denota-se n = size_ e m = capacity_.
class set {
 public:
  // Cria um conjunto vazio em O(1).
  set();

  // Cria um conjunto com os mesmos elementos de s em O(n + m).
  set(set& s);

  // Libera toda a memória alocada para o conjunto em O(n + m).
  ~set();

  // Retorna um ponteiro para o PRIMEIRO elemento do conjunto em O(m).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  //
  Node* end();

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(m).
  // Se x aponta para o último elemento do conjunto, retorna set::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x);

  // Retorna o elemento anterior ao indicado por x no conjunto em O(m).
  // Se x aponta para o primeiro elemento do conjunto, retorna set::end();
  // Precondição: x aponta para um dos elementos da lista.
  Node* prev(Node* x);

  // Retorna o valor do elemento indicado por x em (1).
  SType operator[](Node* x);

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna verdadeiro se k está no conjunto e false caso contrário em O(1).
  bool find(SType k);

  // Retorna quantas ocorrências de k existem no conjunto em O(d),
  // onde d é o número de ocorrências de k.
  int count(SType k);

  // Insere k no conjunto em O(1) e retorna um ponteiro para este elemento.
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no conjunto
  // e a função retorna um ponteiro o para o elemento k já existente.
  void insert(SType k);

  // Remove k do conjunto (caso lá ele esteja) em O(1).
  void erase(SType k);

  // Remove todos os elementos do conjunto.
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s.
  void operator=(set& s);

 private:
  // Número de elementos no cojunto.
  int size_;

  // Número de listas no vetor table_.
  static const int kCapacity_ = 10000;

  // Vetor de listas que guarda os elementos do cojunto.
  list table_[kCapacity_];

  friend class Teste;
};

#endif  // TRUNK_HASH_MULTISET_SRC_MULTISET_H_
