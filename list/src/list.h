// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_LIST_SRC_LIST_H_
#define TRUNK_LIST_SRC_LIST_H_

#include <string>

// Define como os elementos da lista encadeada serão organizados na memória.
// É declarado aqui, mas só é implementado em list.cc para não violar o
// encapsulamento.
struct Node;
typedef char LType;
// Implementa uma lista de elementos utilizando Listas Encadeadas.
// O tipo dos elementos contidos na lista é definido por LType.
// O valor de LType deve ser definido em tempo de compilação.
// Para simplificar as funções de complexidade, denota-se n = size_.
class list {
 public:
  // Cria uma lista vazia em O(1).
  list();

  // Retorna o número de elementos na lista em O(1).
  int size() const;

  // Testa se a lista está vazia em O(1).
  bool empty() const;

  // Retorna um ponteiro para o primeiro elemento da lista em O(1).
  // Caso a lista esteja vazia, rentorna um ponteiro para list::end().
  Node* begin() const;

  // Retorna um ponteiro para o "marcador de fim" da lista em O(1).
  // Nota: list::end() não é considerado um elemento da lista.
  Node* end() const;

  // Retorna o elemento seguinte ao indicado por x na lista em (1).
  // Precondição: x aponta para um dos elementos da lista.
  Node* next(Node* x) const;

  // Retorna o elemento anterior ao indicado por x na lista em (1).
  // Precondição: x aponta para um dos elementos da lista.
  Node* prev(Node* x) const;

  // Retorna o valor do elemento indicado por x em (1).
  LType key(Node* x) const;

  // Faz a lista corrente ficar igual a l em O(n + m), onde m = l.size().
  void operator=(const list& l);

  // Insere k antes do elemento indicado por x em O(1).
  void insert(Node* x, LType k);

  // Apaga o elemento indicado por x em O(1).
  // Precondição: x aponta para um dos elementos da lista.
  // Pós-condição: x não é mais um ponteiro válido.
  void erase(Node* x);

  // Remove todos os elementos da lista em O(n).
  void clear();

  // Concatena os elementos de l no final da lista corrente em O(m),
  // onde m = l.size().
  void merge(const list& l);

  // Libera toda a memória alocada para a lista em O(n).
  ~list();

 private:
  // Número de elementos na lista.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  Node* end_;

  friend class Teste;
};

#endif  // TRUNK_LIST_SRC_LIST_H_
