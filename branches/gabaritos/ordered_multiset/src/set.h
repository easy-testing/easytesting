// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_ORDERED_MULTISET_SRC_SET_H_
#define BRANCHES_GABARITOS_ORDERED_MULTISET_SRC_SET_H_

#include "type/type.h"

// Defite como os elementos do conjunto serão organizados na memória.
// É declarado aqui, mas só é implementado em multiset.cc para não violar o
// encapsulamento
struct Node;

// Implementa um conjunto com repetições utilizando árvores binárias de busca.
// Os elementos menores que o da raiz encontram-se a esquerda e aqueles maiores
// ou iguais ao elemento da raiz encontram-se a direita.
// NOTA: O cálculo da complexidade das funções assume que a árvore está
// balanceada, ou seja, considera-se que a altura da arvore é O(log n), onde n
// é a cardinalidade do conjunto. Entretanto, isto não é garantido nesta
// implentação.
class multiset {
 public:
  // Cria um conjunto vazio em O(1).
  multiset();

  // Cria um conjunto com os mesmos elementos de s em O(m*log m),
  // onde m = s.size().
  multiset(multiset& s);

  // Libera toda a memória alocada para o conjunto em O(n*log n).
  ~multiset();

  // Retorna um ponteiro para o MENOR elemento do conjunto em O(log n).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para multiset::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna um ponteiro para o sucessor do elemento indicado por x no conjunto,
  // ou seja, o menor elemento maior que aquele indicado por x em O(log n).
  Node* next(Node* x);

  // Retorna o valor do elemento indicado por x em (1).
  Type value(Node* x);

  // Testa se o cojunto está vazio em O(1).
  bool empty();

  // Retorna o número de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para uma das ocorrências do elemento k em O(log n),
  // ou um ponteiro para multiset::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(Type k);

  // Conta quantas ocorrências de k existem no conjunto em O(log n).
  int count(Type k);

  // Insere k no conjunto em O(log n) e retorna um ponteiro para este elemento.
  Node* insert(Type k);

  // Remove uma das ocorrências de k do conjunto (caso lá ele esteja)
  // em O(log n).
  void erase(Type k);

  // Remove todos os elementos do conjunto em O(n*log n).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(m*log m), onde m = s.size().
  void operator=(multiset& s);

 private:
  // Número de elementos no conjunto.
  int size_;

  // Nó sentinela da árvore binária de busca que representa o conjunto.
  Node* end_;

  friend class Teste;
};
#endif  // BRANCHES_GABARITOS_ORDERED_MULTISET_SRC_SET_H_
