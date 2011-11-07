// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_BINARY_SEARCH_TREE_H_
#define SET_SRC_BINARY_SEARCH_TREE_H_

#include <stdlib.h>

#include "ordered_set/src/tree_node.h"

// Implementa um iterador para uma �rvore bin�ria de busca.
// NOTA: O c�lculo da complexidade das fun��es assume que a �rvore est�
// balanceada, o que n�o � garantido nesta implenta��o. Ou seja, considera-se
// que a altura da arvore � O(log n), onde n � o n�mero de elementos na �rvore.
class TreeIterator {
 public:
  // Cria um iterador para o n� p da �rvore em O(1).
  TreeIterator(TreeNode* p);

  // Retorna a chave do n� onde est� posicionado o iterador em O(1).
  // PRECONDI��O: O iterador est� posicionado em um dos n�s da �rvore.
  type Key();

  // Retorna true se o operador aponta para um n� v�lido de um �rvore em O(1),
  // ou false caso contr�rio.
  bool Nil();

  // Retorna um iterador para o menor elemento da �rvore em O(log n).
  // PRECONDI��O: O iterador est� posicionado em um dos n�s da �rvore.
  TreeIterator Minimum();

  // Retorna um iterador para o maior elemento da �rvore em O(log n).
  // PRECONDI��O: O iterador est� posicionado em um dos n�s da �rvore.
  TreeIterator Maximum();

  // Retorna um iterador para a sub�rvore cuja chave � k em O(log n),
  // ou um iterador inv�lido caso k n�o esteja na �rvore.
  // PRECONDI��O: O iterador est� posicionado em um dos n�s da �rvore.
  TreeIterator Search(type k);

  // Retorna um iterador para a o n� da sub�rvore cuja chave � o menor n�mero
  // maior que x na �rvore em O(log n), ou um iterador para NULL caso x
  // seja o maior elemento da �rvore �rvore.
  // PRECONDI��O: O iterador est� posicionado em um dos n�s da �rvore.
  TreeIterator Succerssor(TreeIterator& x);

  // Retorna um iterador para a o n� da sub�rvore cuja chave � o maior n�mero
  // menor que x na �rvore em O(log n), ou um iterador para NULL caso x
  // seja o menor elemento da �rvore �rvore.
  // PRECONDI��O: O iterador est� posicionado em um dos n�s da �rvore.
  TreeIterator Predecerssor(TreeIterator& x);

 private:
  // Raiz da �rvore bin�ria de busca.
  TreeNode* ptr_;

};
#endif  // SET_SRC_BINARY_SEARCH_TREE_H_
