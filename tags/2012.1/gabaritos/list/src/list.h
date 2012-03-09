// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_LIST_SRC_LIST_H_
#define TRUNK_LIST_SRC_LIST_H_

#include <string>

// Defite como os elementos da lista serão organizados na memória.
// É declarado aqui, mas só é implementado em list.cc para não violar o
// encapsulamento
struct Node;

// Implementa uma lista de elementos utilizando Listas Encadeadas.
class list {
 public:
  // Cria uma lista vazia em O(1).
  list();

  // Cria a lista com os mesmos elementos de l em O(m), onde m = l.size().
  list(list& l);

  // Libera toda a memória alocada para a lista em O(n),
  // onde n é o número de elementos na lista.
  ~list();

  // Retorna o número de elementos na lista em O(1).
  int size();

  // Testa se a lista está vazia em O(1).
  bool empty();

  // Retorna um ponteiro para o primeiro elemento da lista em O(1).
  // Caso a lista esteja vazia, rentorna um ponteiro para list::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" da lista em O(1).
  // Nota: list::end() não é considerado um elemento válido da lista.
  Node* end();

  // Retorna o elemento seguinte ao indicado por i na lista em (1).
  // Retorna o valor do elemento indicado por i em (1).
  Node* next(Node* i);

  // Retorna o elemento anterior ao indicado por i na lista em (1).
  // Precondição: i aponta para um dos elementos da lista ou para list::end().
  Node* prev(Node* i);

  // Retorna o valor do elemento indicado por i em (1).
  LType& operator[](Node* i);

  // Faz a lista corrente ficar igual a l em O(m), onde m = l.size().
  void operator=(list& l);

  // Insere k antes do elemento indicado por i em O(1).
  void insert(Node* i, LType k);

  // Apaga o elemento indicado por i em O(1).
  // Precondição: i aponta para um dos elementos da lista.
  void erase(Node* i);

  // Remove todos os elementos da lista em O(n),
  // onde n é o número de elementos na lista.
  void clear();

  // Concatena os elementos de l no final da lista corrente em O(m),
  // onde m = l.size().
  void merge(list& l);

 private:
  // Número de elementos na lista.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  Node* end_;

  friend class Teste;
};

#endif  // TRUNK_LIST_SRC_LIST_H_
