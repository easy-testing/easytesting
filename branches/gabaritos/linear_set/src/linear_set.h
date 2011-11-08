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

  // Libera toda a mem�ria alocada para o conjunto em O(n),
  // onde n � o n�mero de elementos no conjunto.
  ~set();

  // Retorna um ponteiro para o n� com o MENOR elemento do conjunto em O(1).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  node* begin();

  // Retorna um ponteiro para o n� que marca o fim do conjunto em O(1).
  node* end();

  // Retorna o sucessor de x no conjunto, ou seja, o n� cuja chave � o menor
  // elemento maior que a chave de x em (1).
  node* next(node* x);

  // Testa se o cojunto est� vazio em O(1).
  bool empty();

  // Retorna o n�mero de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o n� que cont�m k em O(n),
  // ou um ponteiro para set::end() caso k n�o perten�a ao conjunto.
  // OBS: Note que esta fun��o N�O retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', voc� deve escrever "if (c.find(a) != c.end())".
  node* find(type k);

  // Insere k no conjunto em O(n) e retorna um ponteiro para o n� que cont�m
  // k. Caso k j� perten�a ao conjunto, um novo elemento N�O � criado e a fun��o
  // retorna um ponteiro para o n� que cont�m a vers�o mais antiga de k;
  node* insert(type k);

  // Remove k do conjunto (caso l� ele esteja) em O(n).
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
