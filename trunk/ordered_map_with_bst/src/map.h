// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_MAP_WITH_BST_SRC_MAP_H_
#define TRUNK_ORDERED_MAP_WITH_BST_SRC_MAP_H_

#include<string>

// Define como os elementos do conjunto serão organizados na memória.
// É declarado aqui, mas só é implementado em map.cc para não violar o
// encapsulamento.
struct Node;

// Implementa um conjunto utilizando árvores binárias de busca.
// NOTA: O cálculo da complexidade das funções assume que a árvore está
// balanceada, ou seja, considera-se que a altura da arvore é O(log n), onde n
// é a cardinalidade do conjunto. Entretanto, isto não é garantido nesta
// implentação.
// O tipo dos elementos contidos no conjunto é definido por SType.
// O valor de SType deve ser definido em tempo de compilação.
// Para simplificar as funções de complexidade, denota-se n = size_.
class map {
 public:
  // Cria um conjunto vazio em O(1).
  map();

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o primeiro elemento do conjunto em O(1).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para map::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(1).
  // Se x aponta para o último elemento do conjunto, retorna map::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x);

  // Retorna o elemento anterior ao indicado por x no conjunto em O(1).
  // Se x aponta para o primeiro elemento do conjunto, retorna map::end();
  // Precondição: x aponta para um dos elementos do cojunto, ou para map::end().
  Node* prev(Node* x);

  // Retorna o valor do elemento que tem a chave igual a x em O(logN).
  VType operator[](SType x);

  // Retorna o valor da chave do nó x
  SType key(Node* x);

  // Retorna o valor do nó x
  VType value(Node* x);

  // Retorna um ponteiro para o elemento k em O(n),
  // ou um ponteiro para map::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(SType k);

  // Insere k no conjunto em O(n).
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no
  // conjunto.
  void insert(SType k, VType v);

  // Remove k do conjunto (caso lá ele esteja) em O(n).
  void erase(SType k);

  // Remove todos os elementos do conjunto.
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n + m), onde m = s.size().
  void operator=(map& s);

  // Libera toda a memória alocada para o conjunto em O(n).
  ~map();

 private:
  // Número de elementos no conjunto.
  int size_;

  // Ponteiro para a raiz da árvore.
  // "root_ == NULL" se o conjunto é vazio.
  Node* root_;

  friend class Teste;
};
#endif  // TRUNK_ORDERED_map_WITH_BST_SRC_map_H_
