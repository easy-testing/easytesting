// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_DEQUE_SRC_DEQUE_H_
#define BRANCHES_GABARITOS_DEQUE_SRC_DEQUE_H_

#include <string>

// Tipo dos elementos contidos no deque.
typedef std::string  type;

// Defite como os elementos do deque serão organizados na memória.
// É declarado aqui, mas só é implementado em deque.cc para não violar o
// encapsulamento
struct node;

// Implementa um deque de elementos utilizando listas encadeadas.
class deque {
 public:
  // Cria um deque vazio em O(1).
  deque();

  // Libera a memória alocada para o deque em O(n),
  // onde n é o número de elementos no deque.
  ~deque();

  // Testa se o deque esta vazio em O(1).
  bool empty();

  // Retorna o número de elementos no deque em O(1).
  int size();

  // Retorna o valor da chave do primeiro elemento do deque em O(1).
  // PRECONDIÇÃO: o deque não pode estar vazio.
  type front();

  // Retorna o valor da chave do último elemento do deque em O(1).
  // PRECONDIÇÃO: o deque não pode estar vazio.
  type back();

  // Insere k no início do deque em O(1).
  void push_front(type k);

  // Remove o primeiro elemento do deque em O(1).
  // PRECONDIÇÃO: o deque não pode estar vazio.
  void pop_front();

  // Insere k no final do deque em O(1).
  void push_back(type k);

  // Remove o último elemento do deque em O(1).
  // PRECONDIÇÃO: o deque não pode estar vazio.
  void pop_back();

  // Remove todos os elementos do deque em O(n),
  // onde n é o número de elementos no deque.
  void clear();

 private:
  // Número de elementos no deque.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  node* end_;

  friend class Teste;
};

#endif  // BRANCHES_GABARITOS_DEQUE_SRC_DEQUE_H_
