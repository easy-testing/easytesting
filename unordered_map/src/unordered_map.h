// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_UNORDERED_map_WITH_SET_SRC_UNORDERED_map_H_
#define TRUNK_UNORDERED_map_WITH_SET_SRC_UNORDERED_map_H_

#include <cmath>
#include <cstdlib>
#include <string>

#include "src/map.h"

// Fun��o que calcula o hash dos elementos para uma tabela com m linhas.
// � declarado aqui, mas s� � implementado em unordered_map.cpp para
// n�o violar o encapsulamento.
int hash(SType k, int m);

// Implementa um conjunto utilizando associativo com tabela hash.
// NOTA1: O c�lculo da complexidade das fun��es assume que a fun��o de hash
// utilizada � uniforme simples e que capacity_ >= size_. Entretanto,
// a primeira condi��o n�o � garantida nesta implenta��o.
// Denota-se n = size_ e m = capacity_.
// NOTA2: O tipo das chaves dos elementos contidos no conjunto � definido por
// SType. J� o tipo dos valores associados a cada chave � definido por VType.
// O valor de SType e o de VType � um #define declarado em tempo de compila��o.
class unordered_map {
 public:
   // Cria um conjunto vazio em O(1).
  unordered_map();

  // Testa se o cojunto est� vazio em O(1).
  bool empty() const;

  // Retorna o n�mero de elementos no conjunto em O(1).
  int size() const;

  // Retorna um ponteiro para o primeiro elemento do conjunto em O(m).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para map::end().
  Node* begin() const;

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end() const;

  // Retorna o elemento seguinte ao indicado por x no conjunto em O(m).
  // Se x aponta para o �ltimo elemento do conjunto, retorna map::end();
  // Precondi��o: x aponta para um dos elementos do conjunto.
  Node* next(Node* x) const;

  // Retorna o elemento anterior ao indicado por x no conjunto em O(m).
  // Nota: x pode apontar para unordered_map::end().
  // Precondi��o: existe pelo menos um elemento do conjunto antes de x.
  Node* prev(Node* x) const;

  // Retorna uma refer�ncia ao valor associado a chave k em O(1).
  // Precondi��o: k pertence ao conjunto.
  VType& operator[](SType k);

  // Retorna a chave do n� x em O(1).
  SType key(Node* x) const;

  // Retorna o valor do n� x em O(1).
  VType value(Node* x) const;

  // Retorna um ponteiro para o elemento k em O(1),
  // ou um ponteiro para map::end() caso k n�o perten�a ao conjunto.
  // OBS: Note que esta fun��o N�O retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', voc� deve escrever "if (c.find(a) != c.end())".
  Node* find(SType k) const;

  // Insere k no conjunto, associado ao valor v, em O(1).
  // Caso k j� perten�a ao conjunto, o valor associado a k � atualizado para v.
  void insert(SType k, VType v);

  // Remove o elemento cuja chave � k (caso exista) em O(1).
  void erase(SType k);

  // Remove todos os elementos do conjunto em O(n + m).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n + m + n' + m'), onde n' = s.size_ e m' = s.capacity_.
  void operator=(const unordered_map& s);

  // Libera toda a mem�ria alocada para o conjunto em O(n + m).
  ~unordered_map();
 private:

  // Fun��o que altera o n�mero de linhas da tabela e re-distribui os
  // elementos em O(c).
  void rehash(int c);

  // N�mero de elementos no cojunto.
  int size_;

  // N�mero de subconjuntos no vetor table_.
  int capacity_;

  // Vetor de subconjuntos que guarda os elementos do cojunto.
  map* table_;

  // Funções do tipo friend para serem usadas nos testes
  friend map* table(const unordered_map& s);

  friend int size(const unordered_map& s);

// Retorna o "marcador de fim" do conjunto.
  friend Node* end(const unordered_map& s);

  friend Node* insert(SType k, VType v, unordered_map* s);

  friend std::string ToString(Node* x);

  friend std::string ToString(const unordered_map& s);
};

#endif  // TRUNK_UNORDERED_map_WITH_SET_SRC_UNORDERED_map_H_
