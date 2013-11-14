// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_SET_WITH_LINKED_LIST_SRC_SET_H_
#define TRUNK_ORDERED_SET_WITH_LINKED_LIST_SRC_SET_H_

#include <string>

// Define como os elementos da lista encadeada serão organizados na memória.
// É declarado aqui, mas só é implementado em list.cc para não violar o
// encapsulamento.
struct Node;

// Implementa um conjunto de elementos utilizando listas encadeadas.
// Nesta implementão, os elementos do conjunto são ordenados na lista
// encadeada do menor para o maior.
// O tipo dos elementos contidos no conjunto é definido por SType.
// O valor de SType é um #define declarado em tempo de compilação.
// Para simplificar as funções de complexidade, denota-se n = size_.
class set {
 public:
  // Cria um conjunto vazio em O(1).
  set();

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o primeiro (menor) elemento do conjunto em O(1).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(1).
  // Se x aponta para o último elemento do conjunto, retorna set::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x);

  // Retorna o elemento anterior ao indicado por x no conjunto em O(1).
  // Se x aponta para o primeiro elemento do conjunto, retorna set::end();
  // Precondição: x aponta para um dos elementos do cojunto, ou para set::end().
  Node* prev(Node* x);

  // Retorna o valor do elemento indicado por x em (1).
  KType operator[](Node* x);

  SType value(Node* x);


  // Retorna um ponteiro para o elemento k em O(n),
  // ou um ponteiro para set::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(KType k);

  // Insere k no conjunto em O(n).
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no
  // conjunto.
  void insert(KType k, SType v);

  // Remove k do conjunto (caso lá ele esteja) em O(n).
  void erase(KType k);

  // Remove todos os elementos do conjunto.
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n + m), onde m = s.size().
  void operator=(set& s);

  // Libera toda a memória alocada para o conjunto em O(n).
  ~set();

 private:
  // Número de elementos no conjunto.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  Node* end_;

  friend class Teste;
};

#endif  // TRUNK_ORDERED_SET_WITH_LINKED_LIST_SRC_SET_H_
