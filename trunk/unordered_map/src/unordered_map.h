// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_UNORDERED_map_WITH_SET_SRC_UNORDERED_map_H_
#define TRUNK_UNORDERED_map_WITH_SET_SRC_UNORDERED_map_H_

#include <cmath>
#include <cstdlib>
#include <string>

#include "ordered_map/src/map.h"

// Implementa um conjunto utilizando associativo com tabela hash.
// NOTA1: O cálculo da complexidade das funções assume que a função de hash
// utilizada é uniforme simples e que capacity_ >= size_. Entretanto,
// a primeira condição não é garantida nesta implentação.
// Denota-se n = size_ e m = capacity_.
// NOTA2: O tipo das chaves dos elementos contidos no conjunto é definido por
// SType. Já o tipo dos valores associados a cada chave é definido por VType.
// O valor de SType e o de VType é um #define declarado em tempo de compilação.
class unordered_map{
 public:
   // Cria um conjunto vazio em O(1).
  unordered_map();

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o primeiro elemento do conjunto em O(m).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para map::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(m).
  // Se x aponta para o último elemento do conjunto, retorna map::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x);

  // Retorna o elemento anterior ao indicado por x no conjunto em O(m).
  // Se x aponta para o primeiro elemento do conjunto, retorna map::end();
  // Precondição: x aponta para um dos elementos do cojunto, ou para map::end().
  Node* prev(Node* x);

  // Retorna uma referência ao valor associado a chave k em O(1).
  // Precondição: k pertence ao conjunto.
  VType& operator[](SType k);

  // Retorna a chave do nó x em O(1).
  SType key(Node* x);

  // Retorna o valor do nó x em O(1).
  VType value(Node* x);

  // Retorna um ponteiro para o elemento k em O(1),
  // ou um ponteiro para map::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(SType k);

  // Insere k no conjunto, associado ao valor v, em O(1).
  // Caso k já pertença ao conjunto, o valor associado a k é atualizado para v.
  void insert(SType k, VType v);

  // Remove o elemento cuja chave é k (caso exista) em O(1).
  void erase(SType k);

  // Remove todos os elementos do conjunto em O(n + m).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n + m + n' + m'), onde n' = s.size_ e m' = s.capacity_.
  void operator=(unordered_map& s);

  // Libera toda a memória alocada para o conjunto em O(n + m).
  ~unordered_map();
 private:

  // Função que altera o número de linhas da tabela e re-distribui os
  // elementos em O(c).
  void rehash(int c);

  // Número de elementos no cojunto.
  int size_;

  // Número de subconjuntos no vetor table_.
  int capacity_;

  // Vetor de subconjuntos que guarda os elementos do cojunto.
  map* table_;

  friend class Teste;
};

#endif  // TRUNK_UNORDERED_map_WITH_SET_SRC_UNORDERED_map_H_
