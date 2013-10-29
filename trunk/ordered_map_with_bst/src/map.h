// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_MAP_WITH_BST_SRC_MAP_H_
#define TRUNK_ORDERED_MAP_WITH_BST_SRC_MAP_H_

#include<string>

// Define como os elementos do conjunto associativo serão organizados na memória.
// É declarado aqui, mas só é implementado em map.cc para não violar o
// encapsulamento.
struct Node;

// Implementa um conjunto associativo (também conhecido como mapa) utilizando
// árvores binárias de busca. Num conjunto associativo, todas as chaves dos
// elementos estão associadas a um valor específico. As chaves não se repetem,
// mas os valores associados as chaves podem se repetir.
// NOTA1: O cálculo da complexidade das funções assume que a árvore está
// balanceada, ou seja, considera-se que a altura da arvore é O(log n), onde n
// é a cardinalidade do conjunto (i.e. n = size_). Entretanto, isto não é
// garantido nesta implentação.
// NOTA2: O tipo das chaves dos elementos contidos no conjunto é definido por
// KType. Já o tipo dos valores associados a cada chave é definido por VType.
// O valor de KType e o de VType é um #define declarado em tempo de compilação.
class map {
 public:
  // Cria um conjunto vazio em O(1).
  map();

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o primeiro elemento do conjunto em O(log n).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para map::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(log n).
  // Se x aponta para o último elemento do conjunto, retorna map::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x);

  // Retorna o elemento anterior ao indicado por x no conjunto em O(log n).
  // Se x aponta para o primeiro elemento do conjunto, retorna map::end();
  // Precondição: x aponta para um dos elementos do cojunto, ou para map::end().
  Node* prev(Node* x);

  // Retorna o valor associado a chave k em O(log n).
  // Precondição: k pertence ao conjunto.
  VType operator[](SType k);

  // Retorna a chave do nó x em O(1).
  SType key(Node* x);

  // Retorna o valor do nó x em O(1).
  VType value(Node* x);

  // Retorna um ponteiro para o elemento k em O(n),
  // ou um ponteiro para map::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(SType k);

  // Insere k no conjunto em O(log n).
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no
  // conjunto, e seu valor é atualizado para v.
  void insert(SType k, VType v);

  // Remove k do conjunto (caso lá ele esteja) em O(log n).
  void erase(SType k);

  // Remove todos os elementos do conjunto em O(n.log n).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n.log n + m.log m), onde m = s.size().
  void operator=(map& s);

  // Libera toda a memória alocada para o conjunto em O(n.log n).
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
