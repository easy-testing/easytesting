// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_SET_WITH_LINKED_LIST_SRC_SET_H_
#define TRUNK_ORDERED_SET_WITH_LINKED_LIST_SRC_SET_H_

#include <string>

// Define como os elementos da lista encadeada serão organizados na memória.
// É declarado aqui, mas só é implementado em list.cpp para não violar o
// encapsulamento.
struct Node;

// Implementa um conjunto de elementos utilizando listas encadeadas.
// NOTA1: Nesta implementão, os elementos do conjunto estão ordenados na lista
// encadeada do menor para o maior.
// NOTA2: O tipo dos elementos contidos no conjunto é definido por SType.
// O valor de SType é um #define declarado em tempo de compilação.
// NOTA3: Para simplificar as funções de complexidade, denota-se n = size_.
class set {
 public:
  // Cria um conjunto vazio em O(1).
  set();

  // Testa se o cojunto está vazio em O(1).
  bool empty() const;

  // Retorna o número de elementos no conjunto em O(1).
  int size() const;

  // Retorna um ponteiro para o primeiro (menor) elemento do conjunto em O(1).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  Node* begin() const;

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end() const;

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(1).
  // Se x aponta para o último elemento do conjunto, retorna set::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x) const;

  // Retorna o elemento anterior ao indicado por x no conjunto em O(1).
  // Se x aponta para o primeiro elemento do conjunto, retorna set::end();
  // Precondição: x aponta para um dos elementos do cojunto, ou para set::end().
  Node* prev(Node* x) const;

  // Retorna a chave do elemento indicado por x em (1).
  SType key(Node* x) const;

  // Retorna um ponteiro para o elemento k em O(n),
  // ou um ponteiro para set::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(SType k) const;

  // Insere k no conjunto em O(n).
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no
  // conjunto.
  void insert(SType k);

  // Remove k do conjunto (caso lá ele esteja) em O(n).
  void erase(SType k);

  // Remove todos os elementos do conjunto em O(n).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n + m), onde m = s.size().
  void operator=(const set& s);

  // Libera toda a memória alocada para o conjunto em O(n).
  ~set();

 private:
  // Número de elementos no conjunto.
  int size_;

  // Ponteiro para o nó sentinela da lista encadeada.
  Node* end_;

  // Retorna o valor da chave do elemento x de s;
  friend SType key(Node* x, const set& s);

  // Retorna o número de elementos no conjunto.
  friend int size(const set& s);

  // Insere k em s.
  // Precondição: k não está em s.
  friend void insert(SType k, set* s);

  // Retorna o primeiro elemento do conjunto.
  friend Node* begin(const set& s);

  // Retorna o "marcador de fim" do conjunto.
  friend Node* end(const set& s);

  // Retorna o elemento seguinte a 'x' no conjunto.
  friend Node* next(Node* x, const set& s);

  // Retorna o elemento anterior a 'x' no conjunto.
  friend Node* prev(Node* x, const set& s);

  // Retorna um ponteiro para o elemento k de s.
  friend Node* find(SType k, const set& s);

  // Retorna uma string contendo os elementos do conjunto
  // no formato { c1 c2 c3 c4 } e ordenados do maior para o menor.
  friend std::string ToString(const set& s);
};

#endif  // TRUNK_ORDERED_SET_WITH_LINKED_LIST_SRC_SET_H_
