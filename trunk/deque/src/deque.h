// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_DEQUE_SRC_DEQUE_H_
#define TRUNK_DEQUE_SRC_DEQUE_H_

#include <string>

// Defite como os elementos do deque serão organizados na memória.
// É declarado aqui, mas só é implementado em deque.cc para não violar o
// encapsulamento.
struct Node;

// Implementa um deque de elementos utilizando listas encadeadas.
class deque {
 public:
  // Cria um deque vazio em O(1).
  deque();

  // Libera a memória alocada para o deque em O(n),
  // onde n é o número de elementos no deque.
  ~deque();

  // Testa se o deque esta vazio em O(1).
  bool empty() const;

  // Retorna o número de elementos no deque em O(1).
  int size() const;

  // Retorna o valor da chave do primeiro elemento do deque em O(1).
  // Precondição: o deque não pode estar vazio.
  LType front() const;

  // Retorna o valor da chave do último elemento do deque em O(1).
  // Precondição: o deque não pode estar vazio.
  LType back() const;

  // Insere k no início do deque em O(1).
  void push_front(LType k);

  // Remove o primeiro elemento do deque em O(1).
  // Precondição: o deque não pode estar vazio.
  void pop_front();

  // Insere k no final do deque em O(1).
  void push_back(LType k);

  // Remove o último elemento do deque em O(1).
  // Precondição: o deque não pode estar vazio.
  void pop_back();

  // Faz o deque corrente ficar igual a d em O(n + m),
  // onde m = d.size() e n é o número de elementos no deque corrente.
  void operator=(const deque& d);

 private:
  // Número de elementos no deque.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  Node* end_;

  friend class Teste;
};

#endif  // TRUNK_DEQUE_SRC_DEQUE_H_

