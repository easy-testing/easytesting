// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_MAP_SRC_MAP_H_
#define TRUNK_ORDERED_MAP_SRC_MAP_H_

#include<string>

// Define como os elementos do conjunto associativo serão organizados na
// memória. É declarado aqui, mas só é implementado em map.cpp para não
// violar o encapsulamento.
struct Node;

// Implementa um conjunto associativo (também conhecido como mapa) utilizando
// árvores binárias de busca. Num conjunto associativo, todas as chaves dos
// elementos estão associadas a um valor específico. As chaves não se repetem,
// mas os valores associados as chaves podem se repetir.
// NOTA1: Nesta implementão, os elementos do conjunto estão ordenados na lista
// encadeada do menor para o maior.
// NOTA2: O tipo das chaves dos elementos contidos no conjunto é definido por
// SType. Já o tipo dos valores associados a cada chave é definido por VType.
// O valor de SType e o de VType é um #define declarado em tempo de compilação.
// Nota3: O cálculo das complexidades assume que a função de hasing
// é uniformemente simples, mas isto não é garantido nesta implementação.
// No entanto, esta implementação garante que o fator de carga é constante.
class map {
 public:
  // Cria um conjunto vazio em O(1).
  map();

  // Testa se o cojunto está vazio em O(1).
  bool empty() const;

  // Retorna o número de elementos no conjunto em O(1).
  int size() const;

  // Retorna um ponteiro para o primeiro elemento do conjunto em O(log n).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para map::end().
  Node* begin() const;

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end() const;

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(log n).
  // Se x aponta para o último elemento do conjunto, retorna map::end();
  // Precondição: x aponta para um dos elementos do conjunto.
  Node* next(Node* x) const;

  // Retorna o elemento anterior ao indicado por x no conjunto em O(log n).
  // Nota: x pode apontar para map::end().
  // Precondição: existe pelo menos um elemento do conjunto antes de x.
  Node* prev(Node* x) const;

  // Retorna uma referência ao valor associado a chave k em O(log n).
  // Precondição: k pertence ao conjunto.
  VType& operator[](SType k);

  // Retorna a chave do nó x em O(1).
  SType key(Node* x) const;

  // Retorna o valor do nó x em O(1).
  VType value(Node* x) const;

  // Retorna um ponteiro para o elemento k em O(log n),
  // ou um ponteiro para map::end() caso k não pertença ao conjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', você deve escrever "if (c.find(a) != c.end())".
  Node* find(SType k) const;

  // Insere k no conjunto, associado ao valor v, em O(log n).
  // Caso k já pertença ao conjunto, o valor associado a k é atualizado para v.
  void insert(SType k, VType v);

  // Remove o elemento cuja chave é k (caso exista) em O(log n).
  void erase(SType k);

  // Remove todos os elementos do conjunto em O(n.log n).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n.log n + m.log m), onde m = s.size().
  void operator=(const map& s);

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
#endif  // TRUNK_ORDERED_MAP_SRC_MAP_H_
