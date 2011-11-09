// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "list/src/list.h"

// Defite como os elementos do conjunto ser�o organizados na mem�ria.
// � declarado aqui, mas s� � implementado em set.cc para n�o violar o
// encapsulamento
struct node;

// Implementa um conjunto usando listas ligadas.
class set {
 public:
    // Cria um conjunto vazio em O(1).
  set();

  // Cria um conjunto com os mesmos elementos de s em O(m), onde m = s.size().
  set(set& s);

  // Libera toda a mem�ria alocada para o conjunto em O(n).
  ~set();

  // Retorna um ponteiro para o MENOR elemento do conjunto em O(1).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  node* end();

  // Retorna um ponteiro para o sucessor do elemento indicado por x no conjunto,
  // ou seja, o menor elemento maior que aquele indicado por x em O(1).
  node* next(node* x);

  // Retorna o valor do elemento indicado por x em (1).
  type value(node* x);

  // Testa se o cojunto est� vazio em O(1).
  bool empty();

  // Retorna o n�mero de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o elemento k em O(n),
  // ou um ponteiro para set::end() caso k n�o perten�a ao conjunto.
  // OBS: Note que esta fun��o N�O retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', voc� deve escrever "if (c.find(a) != c.end())".
  node* find(type k);

  // Insere k no conjunto em O(n) e retorna um ponteiro para este elemento.
  // Caso k j� perten�a ao conjunto, um novo elemento N�O � inserido no conjunto
  // e a fun��o retorna um ponteiro o para o elemento k j� existente.
  node* insert(type k);

  // Remove k do conjunto (caso l� ele esteja) em O(n).
  void erase(type k);

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

#endif  // SET_SRC_SET_H_
