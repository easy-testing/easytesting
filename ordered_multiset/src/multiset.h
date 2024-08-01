// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_ORDERED_MULTISET_SRC_MULTISET_H_
#define TRUNK_ORDERED_MULTISET_SRC_MULTISET_H_

#include<string>

// Define como os elementos do multimulticonjunto serão organizados
// na memória. É declarado aqui, mas só é implementado em multiset.cpp para
// não violar o encapsulamento.
struct Node;

// Implementa um multiconjunto  (também conhecido com repetição) utilizando
// árvores binárias de busca. Num multiconjunto, podem ocorrer mais de uma
// ocorrência do mesmo elemento.
// NOTA1: O cálculo da complexidade das funções assume que a árvore está
// balanceada, ou seja, considera-se que a altura da arvore é O(log n), onde n
// é a cardinalidade do multiconjunto (i.e. n = size_). Entretanto, isto não é
// garantido nesta implentação.
// NOTA2: O tipo das chaves dos elementos contidos no multiconjunto é definido
// por SType. O valor de SType é um #define declarado em tempo de compilação.
class multiset {
 public:
  // Cria um multiconjunto vazio em O(1).
  multiset();

  // Testa se o cojunto está vazio em O(1).
  bool empty() const;

  // Retorna o número de elementos no multiconjunto em O(1).
  int size() const;

  // Retorna um ponteiro para o primeiro elemento do multiconjunto em O(log n).
  // Caso o multiconjunto esteja vazio, rentorna um ponteiro
  // para multiset::end().
  Node* begin() const;

  // Retorna um ponteiro para o "marcador de fim" do multiconjunto em O(1).
  Node* end() const;

  // Retorna o elemento seguinte (diferente) ao indicado por x no
  // multiconjunto em O(log n). Se x aponta para o último elemento do
  // multiconjunto, retorna multiset::end();
  // Precondição: x aponta para um dos elementos do multiconjunto.
  Node* next(Node* x) const;

  // Retorna o elemento anterior (diferente) ao indicado por x no
  // multiconjunto em O(log n).
  // Nota: x pode apontar para multiset::end().
  // Precondição: existe pelo menos um elemento do multiconjunto (diferente)
  // antes de x.
  Node* prev(Node* x) const;

  // Retorna o número de ocorrências do elemento k em O(log n).
  int count(SType k) const;

  // Retorna a chave do nó x em O(1).
  SType key(Node* x) const;

  // Retorna um ponteiro para o elemento k em O(log n),
  // ou um ponteiro para multiset::end() caso k não pertença ao multiconjunto.
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
  void operator=(const multiset& s);

  // Libera toda a memória alocada para o multiconjunto em O(n.log n).
  ~multiset();

 private:
  // Número de elementos no multiconjunto.
  int size_;

  // Ponteiro para a raiz da árvore.
  // "root_ == NULL" se o multiconjunto é vazio.
  Node* root_;

  friend Node* root(const multiset& s);

  friend int size(const multiset& s);

  // Retorna um ponteiro para o elemento seguinte ao último elemento
  // do multiconjunto.
  friend Node* end(const multiset& s);

  friend Node* insert(SType k, int count, multiset* s);

  friend std::string ToString(Node* x);

  // Retorna uma string contendo os elementos da árvore no formato
  // {k1, k2, ..., kn}.
  friend std::string TreeToString(Node* root);

  friend std::string ToString(const multiset& s);
};
#endif  // TRUNK_ORDERED_MULTISET_SRC_MULTISET_H_
