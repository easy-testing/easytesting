// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_SET_WITH_BST_SRC_SET_H_
#define TRUNK_ORDERED_SET_WITH_BST_SRC_SET_H_

#include<string>

// Define como os elementos do conjunto serão organizados na memória.
// É declarado aqui, mas só é implementado em set.cc para não violar o
// encapsulamento.
struct Node;

// Implementa um conjunto utilizando árvores binárias de busca.
// NOTA1: O cálculo da complexidade das funções assume que a árvore está
// balanceada, ou seja, considera-se que a altura da arvore é O(log n), onde n
// é a cardinalidade do conjunto (i.e. n = size_). Entretanto, isto não é
// garantido nesta implentação.
// NOTA2: O tipo dos elementos contidos no conjunto é definido por SType.
// O valor de SType é um #define declarado em tempo de compilação.
class set {
 public:
  // Cria um conjunto vazio em O(1).
  set();

  // Testa se o cojunto está vazio em O(1).
  bool empty() const;

  // Retorna o número de elementos no conjunto em O(1).
  int size() const;

  // Retorna um ponteiro para o primeiro elemento do conjunto em O(log n).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  Node* begin() const;

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end() const;

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(log n).
  // Se x aponta para o último elemento do conjunto, retorna set::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x) const;

  // Retorna o elemento anterior ao indicado por x no conjunto em O(log n).
  // Se x aponta para o primeiro elemento do conjunto, retorna set::end();
  // Precondição: x aponta para um dos elementos do cojunto, ou para set::end().
  Node* prev(Node* x) const;

  // Retorna a chave do elemento indicado por x em (1).
  SType key(Node* x) const;

  // Retorna um ponteiro para o elemento k em O(log n),
  // ou um ponteiro para set::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(SType k) const;

  // Insere k no conjunto em O(log n).
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no
  // conjunto.
  void insert(SType k);

  // Remove k do conjunto (caso lá ele esteja) em O(log n).
  void erase(SType k);

  // Remove todos os elementos do conjunto em O(n.log n).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n.log n + m.log m), onde m = s.size().
  void operator=(const set& s);

  // Libera toda a memória alocada para o conjunto em O(n.log n).
  ~set();

 private:
  // Número de elementos no conjunto.
  int size_;

  // Ponteiro para a raiz da árvore.
  // "root_ == NULL" se o conjunto é vazio.
  Node* root_;

  friend class Teste;
};
#endif  // TRUNK_ORDERED_SET_WITH_BST_SRC_SET_H_
