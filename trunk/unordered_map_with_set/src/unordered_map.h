// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_UNORDERED_map_WITH_SET_SRC_UNORDERED_map_H_
#define TRUNK_UNORDERED_map_WITH_SET_SRC_UNORDERED_map_H_

#include <cmath>
#include <cstdlib>
#include <string>

#include "unordered_map_with_set/src/set.h"

// Implementa um conjunto utilizando tabela hash.
// NOTA: O cálculo da complexidade das funções assume que a função de hash
// utilizada é uniformemente simples e que capacity_ > size_. Entretanto,
// isto não é garantido nesta implentação.
// O tipo dos elementos contidos no conjunto é definido por VType.
// O valor de VType deve ser definido em tempo de compilação.
// Para simplificar as funções de complexidade,
// denota-se n = size_ e m = capacity_.
class unordered_map{
 public:
  // Cria um conjunto vazio em O(1).
  unordered_map();

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o primeiro elemento do conjunto em O(m).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para
  // unordered_map::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(m).
  // Se x aponta para o último elemento do conjunto,
  // retorna unordered_map::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x);

  // Retorna o elemento anterior ao indicado por x no conjunto em O(m).
  // Se x aponta para o primeiro elemento do conjunto,
  // retorna unordered_map::end();
  // Precondição: x aponta para um dos elementos do cojunto,
  // ou para unordered_map::end().
  Node* prev(Node* x);

  // Retorna o valor do elemento indicado por x em (1).
  SType operator[](KType key);

  KType key(Node *x);
  SType value(Node *x);

  // Retorna um ponteiro para o elemento k em O(1),
  // ou um ponteiro para unordered_map::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(KType k);

  // Insere k no conjunto em O(1).
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no
  // conjunto.
  void insert(KType k, SType v);

  // Remove k do conjunto (caso lá ele esteja) em O(1).
  void erase(KType k);

  // Remove todos os elementos do conjunto.
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(m).
  void operator=(unordered_map& s);

  // Libera toda a memória alocada para o conjunto em O(n).
  ~unordered_map();

 private:
  // Função que calcula o hash dos elementos.
  int hash(KType k);

  // Função que altera o número de linhas da tabela e re-distribui os
  // elementos em O(m).
  void rehash(int m);

  // Número de elementos no cojunto.
  int size_;

  // Número de subconjuntos no vetor table_.
  int capacity_;

  // Vetor de subconjuntos que guarda os elementos do cojunto.
  set* table_;

  friend class Teste;
};

#endif  // TRUNK_UNORDERED_map_WITH_SET_SRC_UNORDERED_map_H_
