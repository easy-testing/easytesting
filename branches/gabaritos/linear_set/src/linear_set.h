// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "linear_set/src/list.h"
#include "linear_set/src/node.h"


// Implementa um conjunto usando listas ligadas.
class set {
 public:
  // Cria um conjunto vazio em O(1).
  set();

  // Cria um conjunto com os mesmos elementos de s em O(m), onde m = s.size().
  set(set& s);

  // Libera toda a memória alocada para o conjunto em O(n),
  // onde n é o número de elementos no conjunto.
  ~set();

  // Retorna um ponteiro para o nó com o MENOR elemento do conjunto em O(1).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  node* begin();

  // Retorna um ponteiro para o nó que marca o fim do conjunto em O(1).
  node* end();

  // Retorna o sucessor de x no conjunto, ou seja, o nó cuja chave é o menor
  // elemento maior que a chave de x em (1).
  node* next(node* x);

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o nó que contém k em O(n),
  // ou um ponteiro para set::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  node* find(type k);

  // Insere k no conjunto em O(n) e retorna um ponteiro para o nó que contém
  // k. Caso k já pertença ao conjunto, um novo elemento NÃO é criado e a função
  // retorna um ponteiro para o nó que contém a versão mais antiga de k;
  node* insert(type k);

  // Remove k do conjunto (caso lá ele esteja) em O(n).
  void erase(type k);

  // Remove todos os elementos do conjunto em O(n).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(m*log m), onde m = s.size().
  void operator=(set& s);

 private:

  // Lista que representa o cojunto.
  list list_;

  friend class Teste;
};

#endif  // SET_SRC_SET_H_
