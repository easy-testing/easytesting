// Copyright 2013 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_SET_WITH_ARRAY_SRC_SET_H_
#define TRUNK_ORDERED_SET_WITH_ARRAY_SRC_SET_H_

#include <string>

// Implementa um conjunto de elementos utilizando vetores.
// Nesta implementão, os elementos do conjunto estão ordenados no vetor
// do menor para o maior.
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

  // Testa se k pertence ao conjunto em O(log n).
  bool belongs(SType k);

  // Insere k no conjunto em O(n).
  // Caso k já pertença ao conjunto, um novo elemento NÃO é inserido no
  // conjunto.
  void insert(SType k);

  // Remove k do conjunto (caso lá ele esteja) em O(n).
  void erase(SType k);

  // Remove todos os elementos do conjunto em O(1).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n + m), onde m = s.size().
  void operator=(set& s);

  // Libera toda a memória alocada para o conjunto em O(n).
  ~set();

 private:
  // Altera o tamanho do vetor para n elementos.
  // Se n <= size_, o conteúdo do vetor é reduzido para os seus n primeiros
  // elementos. Se n > size_, o conteúdo do vetor é expandido e "n - size_"
  // novos elementos são inseridos no final do vetor. O valor dos novos
  // elementos é indeterminado (ou seja, pode ser qualquer SType).
  void resize(int n);

  // Número de elementos no conjunto.
  int size_;

  // Ponteiro para o vetor que contém os elementos do conjunto.
  SType* array_;

  friend class Teste;
};

#endif  // TRUNK_ORDERED_SET_WITH_LINKED_ARRAY_SRC_SET_H_
