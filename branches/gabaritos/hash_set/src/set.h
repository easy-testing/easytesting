// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_HASH_SET_SRC_SET_H_
#define BRANCHES_GABARITOS_HASH_SET_SRC_SET_H_

#include "type/type.h"

// Defite como os elementos do conjunto serão organizados na memória.
// É declarado aqui, mas só é implementado em set.cc para não violar o
// encapsulamento
struct Node;
class list;

// Implementa um conjunto usando tabela hash.
// NOTA: O cálculo da complexidade das funções assume que (i) o número de linhas
// da tabela hash é sempre maior que o número de elementos no conjunto e que
// (ii) não existem colisões entre os elementos do cojunto, ou seja,
// considera-se que a função de hash não retorna o mesmo valor para dois
// elementos diferentes no cojunto. Entretanto, por questões de simplicidade,
// estas condições não são garantidas nesta implentação.
class set {
 public:
    // Cria um conjunto vazio em O(1).
  set();

  // Cria um conjunto com os mesmos elementos de s em O(m), onde m = s.size().
  set(set& s);

  // Libera toda a memória alocada para o conjunto em O(n).
  ~set();

  // Retorna um ponteiro para o primeiro elemento do conjunto em O(n).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna um ponteiro para o elemento seguinte x no cojunto em O(n).
  Node* next(Node* x);

  // Retorna o valor do elemento indicado por x em (1).
  Type value(Node* x);

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o elemento k em O(1),
  // ou um ponteiro para set::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(Type k);

  // Insere k no conjunto em O(1) e retorna um ponteiro para este elemento.
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
  // Número de elementos no cojunto.
  int size_;

  // Vetor de listas (Tabela hash) que guarda os elementos do cojunto.
  list* table_;

  // Número de entradas na tabela hash, ou seja,
  // número de listas no vetor table_.
  static const int capacity_ = 100000;

  friend class Teste;
};

#endif  // BRANCHES_GABARITOS_HASH_SET_SRC_SET_H_
