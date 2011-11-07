// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "linear_set/src/list.h"
#include "linear_set/src/node.h"


// Implementa um conjunto usando listas ligadas.
class linear_set {
 public:
  // Cria um conjunto vazio em O(1).
  linear_set();

  // Cria um conjunto com os mesmos elementos de s em O(m), onde m = s.size().
  linear_set(linear_set& s);

  // Testa se o cojunto esta vazio em O(1).
  bool empty();

  // Retorna o número de elementos no cojunto em O(1).
  int size();

  // Retorna o menor elemento do cojunto em O(n), onde n = size().
  // PRECONDIÇÃO: O conjunto tem pelo menos um elemento.
  type min();

  // Retorna verdadeiro se x está no conjunto e false caso contrário em O(n),
  // onde n = size().
  bool find(type x);

  // Insere x no conjunto em O(n), onde n = size().
  // Retorna false se x já estava no conjunto ou true caso contrário.
  bool insert(type x);

  // Remove x do conjunto em O(n), onde n = size().
  // Retorna true se algum elemento foi removido ou falso caso contrário.
  bool erase(type x);

  // Remove todos os elementos do conjunto em O(n), onde n = size().
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(m), onde m = s.size().
  void operator=(linear_set& s);

 private:

  // Lista que representa o cojunto.
  list list_;
};

#endif  // SET_SRC_SET_H_
