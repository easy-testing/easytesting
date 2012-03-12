// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_ORDERED_SET_SRC_SET_H_
#define BRANCHES_GABARITOS_ORDERED_SET_SRC_SET_H_

#include<string>

// Define como os elementos do conjunto ser�o organizados na mem�ria.
// � declarado aqui, mas s� � implementado em set.cc para n�o violar o
// encapsulamento.
struct Node;

// Implementa um conjunto utilizando �rvores bin�rias de busca.
// NOTA: O c�lculo da complexidade das fun��es assume que a �rvore est�
// balanceada, ou seja, considera-se que a altura da arvore � O(log n), onde n
// � a cardinalidade do conjunto. Entretanto, isto n�o � garantido nesta
// implenta��o.
class set {
 public:
  // Cria um conjunto vazio em O(1).
  set();

  // Cria um conjunto com os mesmos elementos de s em O(m*log m),
  // onde m = s.size().
  set(set& s);

  // Libera toda a mem�ria alocada para o conjunto em O(n*log n).
  ~set();

  // Retorna um ponteiro para o MENOR elemento do conjunto em O(log n).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  Node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  Node* end();

  // Retorna o elemento seguinte ao indicado por x no conjunto em (log n).
  // Precondi��o: x aponta para um dos elementos do conjunto.
  Node* next(Node* x);

  // Retorna o elemento anterior ao indicado por x no conjunto em (log n).
  // Precondi��o: x aponta para um dos elementos da lista ou para list::end().
  Node* prev(Node* x);

  // Retorna o valor do elemento indicado por x em (1).
  SType& operator[](Node* x);

  // Testa se o cojunto est� vazio em O(1).
  bool empty();

  // Retorna o n�mero de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o elemento k em O(log n),
  // ou um ponteiro para set::end() caso k n�o perten�a ao conjunto.
  // OBS: Note que esta fun��o N�O retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', voc� deve escrever "if (c.find(a) != c.end())".
  Node* find(SType k);

  // Insere k no conjunto em O(log n) e retorna um ponteiro para este elemento.
  // Caso k j� perten�a ao conjunto, um novo elemento N�O � inserido no conjunto
  // e a fun��o retorna um ponteiro o para o elemento k j� existente.
  Node* insert(SType k);

  // Remove k do conjunto (caso l� ele esteja) em O(log n).
  void erase(SType k);

  // Remove todos os elementos do conjunto em O(n*log n),
  // onde n � o n�mero de elementos no conjunto.
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(n*log n + m*log m), onde m = s.size() e n � o n�mero
  // de elementos no conjunto corrente..
  void operator=(set& s);

 private:
  // N�mero de elementos no conjunto.
  int size_;

  // Ponteiro para a raiz da �rvore.
  // "root_ == NULL" se o conjunto � vazio.
  Node* root_;

  friend class Teste;
};
#endif  // BRANCHES_GABARITOS_ORDERED_SET_SRC_SET_H_
