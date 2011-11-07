// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_BINARY_SEARCH_TREE_H_
#define SET_SRC_BINARY_SEARCH_TREE_H_

#include <stdlib.h>

#include "ordered_set/src/tree_node.h"

// Implementa um iterador para uma árvore binária de busca.
// NOTA: O cálculo da complexidade das funções assume que a árvore está
// balanceada, o que não é garantido nesta implentação. Ou seja, considera-se
// que a altura da arvore é O(log n), onde n é o número de elementos na árvore.
class TreeIterator {
 public:
  // Cria um iterador para o nó p da árvore em O(1).
  TreeIterator(TreeNode* p);

  // Retorna a chave do nó onde está posicionado o iterador em O(1).
  // PRECONDIÇÃO: O iterador está posicionado em um dos nós da árvore.
  type Key();

  // Retorna true se o operador aponta para um nó válido de um árvore em O(1),
  // ou false caso contrário.
  bool Nil();

  // Retorna um iterador para o menor elemento da árvore em O(log n).
  // PRECONDIÇÃO: O iterador está posicionado em um dos nós da árvore.
  TreeIterator Minimum();

  // Retorna um iterador para o maior elemento da árvore em O(log n).
  // PRECONDIÇÃO: O iterador está posicionado em um dos nós da árvore.
  TreeIterator Maximum();

  // Retorna um iterador para a subárvore cuja chave é k em O(log n),
  // ou um iterador inválido caso k não esteja na árvore.
  // PRECONDIÇÃO: O iterador está posicionado em um dos nós da árvore.
  TreeIterator Search(type k);

  // Retorna um iterador para a o nó da subárvore cuja chave é o menor número
  // maior que x na árvore em O(log n), ou um iterador para NULL caso x
  // seja o maior elemento da árvore árvore.
  // PRECONDIÇÃO: O iterador está posicionado em um dos nós da árvore.
  TreeIterator Succerssor(TreeIterator& x);

  // Retorna um iterador para a o nó da subárvore cuja chave é o maior número
  // menor que x na árvore em O(log n), ou um iterador para NULL caso x
  // seja o menor elemento da árvore árvore.
  // PRECONDIÇÃO: O iterador está posicionado em um dos nós da árvore.
  TreeIterator Predecerssor(TreeIterator& x);

 private:
  // Raiz da árvore binária de busca.
  TreeNode* ptr_;

};
#endif  // SET_SRC_BINARY_SEARCH_TREE_H_
