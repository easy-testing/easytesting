// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef LIST_H_
#define LIST_H_

#include "list/src/node.h"

class list {
 public:
  // Cria uma lista vazia em O(1).
  list();

  // Cria a lista com os mesmo elementos de l em O(n), onde n = l.size().
  list(list& l);

  // Remove todos os elementos da lista para liberar a memoria em O(n),
  // onde n é o numero de elementos na lista.
  ~list();

  // Retorna um iterador para o primeiro elemento da lista em O(1).
  Node* begin();

  // Retorna um iterador para "depois" do ultimo elemento da lista em O(1).
  Node* end();

   // Testa se a lista esta vazia em O(1).
  bool empty();

  // Retorna o valor do primeiro elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  ListType front();

  // Retorna o valor do último elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  ListType back();

  // Retorna o número de elementos da lista em O(1).
  int size();

  // Insere x no início da lista em O(1).
  void push_front(ListType x);

  // Remove o primeiro elemento da lista em O(1).
  void pop_front();

  // Insere x no final da lista em O(1).
  void push_back(ListType x);

  // Remove o último elemento da lista em O(1).
  void pop_back();

  // Retona um ponteiro para o primeiro nó da lista que contém x em O(n),
  // onde n é o numero de elementos na lista.
  // Se x não está na lista, retorna um ponteiro para end().
  Node* find(ListType x);

  // Insere x antes do elemento identificado por 'node' em O(1) e retorna
  // um ponteiro para o nó que foi criado para armazenar x.
  Node* insert(Node* node, ListType x);

  // Apaga o elemento indicado por 'node' em O(1).
  void erase(Node* node);


  // Remove todos os elementos da lista corrente em O(n),
  // onde n é o numero de elementos na lista.
  void clear();

  // Concatena os elementos de l no final da lista corrente em O(n),
  // onde n = l.size().
  void merge(list& l);

  // Faz a lista corrente ficar igual a l em O(n), onde n = l.size().
  void operator=(list& l);

private:
  // Numero de elementos na lista.
  int size_;

  // Ponteiro para o no sentinela da lista.
  Node* end_;

  friend class Teste;
};

#endif  // LIST_H_
