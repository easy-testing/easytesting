// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_UNORDERED_MULTISET_SRC_UNORDERED_MULTISET_H_
#define TRUNK_UNORDERED_MULTISET_SRC_UNORDERED_MULTISET_H_

#include <string>

#include "src/multiset.h"

// Função que calcula o hash dos elementos para uma tabela com m linhas.
// É declarado aqui, mas só é implementado em unordered_set.cc para
// não violar o encapsulamento.
int hash(SType k, int m);

// Implementa um multiconjunto  (também conhecido com repetição) utilizando
// tabelas de dispersão. Num multiconjunto, podem ocorrer mais de uma
// ocorrência do mesmo elemento.
// NOTA1: Nesta implementão, os elementos do conjunto estão ordenados na lista
// encadeada do menor para o maior.
// NOTA2: O tipo das chaves dos elementos contidos no conjunto é definido por
// SType. Já o tipo dos valores associados a cada chave é definido por VType.
// O valor de SType e o de VType é um #define declarado em tempo de compilação.
// Nota3: O cálculo das complexidades assume que a função de hasing
// é uniformemente simples, mas isto não é garantido nesta implementação.
// No entanto, esta implementação garante que o fator de carga é constante.
class unordered_multiset {
 public:
  // Cria um multiconjunto vazio em O(1).
  unordered_multiset();

  // Testa se o cojunto está vazio em O(1).
  bool empty() const;

  // Retorna o número de elementos no multiconjunto em O(1).
  int size() const;

  // Retorna um ponteiro para o primeiro elemento do multiconjunto em O(log n).
  // Caso o multiconjunto esteja vazio, rentorna um ponteiro
  // para unordered_multiset::end().
  Node* begin() const;

  // Retorna um ponteiro para o "marcador de fim" do multiconjunto em O(1).
  Node* end() const;

  // Retorna o elemento seguinte (diferente) ao indicado por x no
  // multiconjunto em O(log n). Se x aponta para o último elemento do
  // multiconjunto, retorna unordered_multiset::end();
  // Precondição: x aponta para um dos elementos do multiconjunto.
  Node* next(Node* x) const;

  // Retorna o elemento anterior (diferente) ao indicado por x no
  // multiconjunto em O(log n).
  // Nota: x pode apontar para unordered_multiset::end().
  // Precondição: existe pelo menos um elemento do multiconjunto (diferente)
  // antes de x.
  Node* prev(Node* x) const;

  // Retorna o número de ocorrências do elemento k em O(log n).
  int count(SType k) const;

  // Retorna a chave do nó x em O(1).
  SType key(Node* x) const;

  // Retorna um ponteiro para o elemento k em O(log n),
  // ou um ponteiro para unordered_multiset::end() caso k não pertença ao
  // multiconjunto.
  // OBS: Note que esta função NÃO retorna bool. Para testar se um elemento 'a'
  // pertence a um multiconjunto 'c', você deve escrever
  // "if (c.find(a) != c.end())".
  Node* find(SType k) const;

  // Insere k no multiconjunto em O(log n).
  void insert(SType k);

  // Remove uma ocorrência de k do multiconjunto (caso lá ele esteja)
  // em O(log n).
  void erase(SType k);

  // Remove todos os elementos do multiconjunto em O(n.log n).
  void clear();

  // Faz com que o multiconjunto corrente contenha exatamente os mesmos
  // elementos do cojunto s em O(n.log n + m.log m), onde m = s.size().
  void operator=(const unordered_multiset& s);

  // Libera toda a memória alocada para o multiconjunto em O(n.log n).
  ~unordered_multiset();

 private:
  // Função que altera o número de linhas da tabela para 'm' e re-distribui os
  // elementos em O(m + n).
  void rehash(int m);

  // Número de elementos no multicojunto.
  int size_;

  // Número de subconjuntos no vetor table_.
  int capacity_;

  // Vetor de subconjuntos que guarda os elementos do multicojunto.
  multiset* table_;

  friend class Teste;
};
#endif  // TRUNK_UNORDERED_MULTISET_SRC_UNORDERED_MULTISET_H_
