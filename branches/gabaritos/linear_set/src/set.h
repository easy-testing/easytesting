// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LINEAR_SET_SRC_SET_H_
#define BRANCHES_GABARITOS_LINEAR_SET_SRC_SET_H_

#include "list/src/list.h"

// Defite como os elementos do conjunto serão organizados na memória.
// É declarado aqui, mas só é implementado em set.cc para não violar o
// encapsulamento
struct Node;

// Implementa um conjunto usando listas ligadas.
class set {
 public:
    // Cria um conjunto vazio em O(1).
  set();

  // Cria um conjunto com os mesmos elementos de s em O(m), onde m = s.size().
  set(set& s);

  // Libera toda a memória alocada para o conjunto em O(n).
  ~set();

  // Retorna um ponteiro para o MENOR elemento do conjunto em O(1).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna um ponteiro para o sucessor do elemento indicado por x no conjunto,
  // ou seja, o menor elemento maior que aquele indicado por x em O(1).
  Node* next(Node* x);

  // Retorna o valor do elemento indicado por x em (1).
  Type value(Node* x);

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o elemento k em O(n),
  // ou um ponteiro para set::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(Type k);

  // Insere k no conjunto em O(n) e retorna um ponteiro para este elemento.
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no conjunto
  // e a função retorna um ponteiro o para o elemento k já existente.
  Node* insert(Type k);

  // Remove k do conjunto (caso lá ele esteja) em O(n).
  void erase(Type k);

  // Remove todos os elementos do conjunto em O(n).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(m), onde m = s.size().
  void operator=(set& s);

 private:

  // Lista que representa o cojunto.
  list list_;

  friend class Teste;
};

#endif  // BRANCHES_GABARITOS_LINEAR_SET_SRC_SET_H_
