// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_UNORDERED_SET_SRC_UNORDERED_SET_H_
#define TRUNK_UNORDERED_SET_SRC_UNORDERED_SET_H_

#include <string>

#include "ordered_set_with_linked_list/src/set.h"

// Função que calcula o hash dos elementos para uma tabela com m linhas.
// É declarado aqui, mas só é implementado em unordered_set.cc para
// não violar o encapsulamento.
int hash(SType k, int m);


// Implementa um conjunto utilizando tabela hash.
// NOTA1: O cálculo da complexidade das funções assume que a função de hash
// utilizada é uniforme simples e que capacity_ >= size_. Entretanto,
// a primeira condição não é garantida nesta implentação.
// Denota-se n = size_ e m = capacity_.
// NOTA2: O tipo dos elementos contidos no conjunto é definido por SType.
// O valor de SType é um #define declarado em tempo de compilação.
class unordered_set{
 public:
  // Cria um conjunto vazio em O(1).
  unordered_set();

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o primeiro elemento do conjunto em O(m).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para
  // unordered_set::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(m).
  // Se x aponta para o último elemento do conjunto,
  // retorna unordered_set::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x);

  // Retorna o elemento anterior ao indicado por x no conjunto em O(m).
  // Se x aponta para o primeiro elemento do conjunto,
  // retorna unordered_set::end();
  // Precondição: x aponta para um dos elementos do cojunto,
  // ou para unordered_set::end().
  Node* prev(Node* x);

  // Retorna a chave do nó x em (1).
  SType key(Node* x);

  // Retorna um ponteiro para o elemento k em O(1),
  // ou um ponteiro para unordered_set::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(SType k);

  // Insere k no conjunto em O(1).
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no
  // conjunto.
  void insert(SType k);

  // Remove k do conjunto (caso lá ele esteja) em O(1).
  void erase(SType k);

  // Remove todos os elementos do conjunto em O(n + m).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n + m + n' + m'), onde n' = s.size_ e m' = s.capacity_.
  void operator=(unordered_set& s);

  // Libera toda a memória alocada para o conjunto em O(n + m).
  ~unordered_set();

 private:
  // Função que altera o número de linhas da tabela para 'm' e re-distribui os
  // elementos em O(m + n).
  void rehash(int m);

  // Número de elementos no cojunto.
  int size_;

  // Número de subconjuntos no vetor table_.
  int capacity_;

  // Vetor de subconjuntos que guarda os elementos do cojunto.
  set* table_;

  friend class Teste;
};

#endif  // TRUNK_UNORDERED_SET_SRC_UNORDERED_SET_H_
