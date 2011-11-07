// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LIST_SRC_LIST_H_
#define BRANCHES_GABARITOS_LIST_SRC_LIST_H_

#include "list/src/node.h"

// Implementa uma lista de elementos utilizando Listas Ligadas.
// O tipo dos elementos é definido por 'type'.
class list {
 public:
  // Cria uma lista vazia em O(1).
  list();

  // Cria a lista com os mesmos elementos de l em O(m), onde m = l.size().
  list(list& l);

  // Libera toda a memória alocada para a lista em O(n),
  // onde n é o número de elementos na lista.
  ~list();

  // Retorna um ponteiro para o primeiro nó da lista em O(1).
  // Caso a lista esteja vazia, rentorna um ponteiro para list::end().
  node* begin();

  // Retorna um ponteiro para "depois" do ultimo nó da lista em O(1).
  node* end();

  // Testa se a lista esta vazia em O(1).
  bool empty();

  // Retorna o valor da chave do primeiro elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  type front();

  // Retorna o valor da chave do último elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  type back();

  // Retorna o número de elementos na lista em O(1).
  int size();

  // Insere x no início da lista em O(1).
  void push_front(type x);

  // Remove o primeiro elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  void pop_front();

  // Insere x no final da lista em O(1).
  void push_back(type x);

  // Remove o último elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  void pop_back();

  // Insere x antes do nó p em O(1) e retorna um ponteiro para o nó que foi
  // criado para armazenar x.
  node* insert(node* p, type x);

  // Apaga o nó p da lista em O(1).
  // PRECONDIÇÃO: p é um nó da lista.
  void erase(node* p);

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
  node* end_;

  friend class Teste;
};

#endif  // BRANCHES_GABARITOS_LIST_SRC_LIST_H_
