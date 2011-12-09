// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LIST_SRC_LIST_H_
#define BRANCHES_GABARITOS_LIST_SRC_LIST_H_

#include "type/type.h"

// Defite como os elementos do conjunto serão organizados na memória.
// É declarado aqui, mas só é implementado em list.cc para não violar o
// encapsulamento
struct Node;

// Implementa uma lista de elementos utilizando Listas Ligadas.
class list {
 public:
  // Cria uma lista vazia em O(1).
  list();

  // Cria a lista com os mesmos elementos de l em O(m), onde m = l.size().
  list(list& l);

  // Libera toda a memória alocada para a lista em O(n),
  // onde n é o número de elementos na lista.
  ~list();

  // Retorna um ponteiro para o primeiro elemento da lista em O(1).
  // Caso a lista esteja vazia, rentorna um ponteiro para list::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" da lista em O(1).
  Node* end();

  // Retorna o elemento seguinte ao indicado por i na lista em (1).
  Node* next(Node* i);

  // Retorna o elemento anterior ao indicado por i na lista em (1).
  Node* prev(Node* i);

  // Retorna o valor do indicado por i em (1).
  Type value(Node* i);

  // Testa se a lista esta vazia em O(1).
  bool empty();

  // Retorna o valor do primeiro elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  Type front();

  // Retorna o valor do último elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  Type back();

  // Retorna o número de elementos na lista em O(1).
  int size();

  // Insere k no início da lista em O(1).
  void push_front(Type k);

  // Remove o primeiro elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  void pop_front();

  // Insere k no final da lista em O(1).
  void push_back(Type k);

  // Remove o último elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  void pop_back();

  // Insere k antes do elemento indicado por i em O(1) e retorna um ponteiro
  // para o elemento k.
  Node* insert(Node* i, Type k);

  // Apaga o elemento indicado por i da lista em O(1).
  // PRECONDIÇÃO: i aponta para um dos elementos da lista.
  void erase(Node* i);

  // Remove todos os elementos da lista em O(n),
  // onde n é o número de elementos na lista.
  void clear();

  // Concatena os elementos de l no final da lista corrente em O(m),
  // onde m = l.size().
  void merge(list& l);

  // Faz a lista corrente ficar igual a l em O(m), onde m = l.size().
  void operator=(list& l);

 private:
  // Número de elementos na lista.
  int size_;

  // Ponteiro para o nó sentinela da lista ligada.
  Node* end_;

  friend class Teste;
};

#endif  // BRANCHES_GABARITOS_LIST_SRC_LIST_H_
