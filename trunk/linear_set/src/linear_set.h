// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include "list/src/list.h"

// Implementa um conjunto. O calculo da complexidade das fun��es assume que a
// �rvore esta sempre balanceada, o que n�o � garantido nesta implenta��o.
// Ou seja, considera-se que a altura da arvore eh O(log n),
// onde n eh o numero de elementos no conjunto.
template<class Type>
class set {
 public:
  // Cria um conjunto vazio em O(1).
  set() {
  }

  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return false;
  }

  // Retorna o n�mero de elementos no cojunto em O(1).
  int size() {
    return 0;
  }

  // Testa se x pertece ao conjunto em O(log n).
  bool find(Type x) {
    return false;
  }

  // Insere x no conjunto em O(log n). Retorna false se x j� estava no conjunto
  // r true caso contr�rio.
  bool insert(Type x) {
    return false;
  }

  // Remove x do conjunto em O(log n). x deve pertencer ao conjunto.
  void erase(Type x) {
  }

  // Insere todos os elementos do conjunto no final de l em O(n)
  void ToList(list<Type>* l) {
  }

  // Remove todos os elementos do conjunto em O(n).
  void clear() {
  }

 private:
  // N�mero de elementos no conjunto.
  int size_;

  // �rvore bin�ria de busca que representa o conjunto.
  list<Type> list_;
};  // end class set.

#endif  // SET_SRC_SET_H_
