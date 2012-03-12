// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_LIST_SRC_LIST_H_
#define TRUNK_LIST_SRC_LIST_H_

#include <string>

// Define como os elementos da lista serão organizados na memória.
// É declarado aqui, mas só é implementado em list.cc para não violar o
// encapsulamento.
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
  // Nota: list::end() não é considerado um elemento da lista.
  Node* end();

  // Retorna o elemento seguinte ao indicado por x na lista em (1).
  // Precondição: x aponta para um dos elementos da lista.
  Node* next(Node* x);

  // Retorna o elemento anterior ao indicado por x na lista em (1).
  // Precondição: x aponta para um dos elementos da lista.
  Node* prev(Node* x);

  // Retorna o valor do elemento indicado por x em (1).
  LType& operator[](Node* x);

  // Faz a lista corrente ficar igual a l em O(n + m),
  // onde m = l.size() e n é o número de elementos na lista corrente.
  void operator=(list& l);

  // Insere k antes do elemento indicado por x em O(1).
  void insert(Node* x, LType k);

  // Apaga o elemento indicado por x em O(1).
  // Precondição: x aponta para um dos elementos da lista.
  // Pós-condição: x não é mais um ponteiro válido.
  void erase(Node* x);

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
