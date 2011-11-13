// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_VECTOR_SRC_VECTOR_H_
#define BRANCHES_GABARITOS_VECTOR_SRC_VECTOR_H_
#include "type/type.h"

// Implementa um vetor dinâmico de numeros reais.
class vector {
 public:
  // Cria um vetor vazio em O(1).
  vector();

  // Cria um vetor com m elementos em O(m).
  // O valor dos m elementos é indeterminado.
  vector(int m);

  // Cria um vetor idêntico a v.
  vector(vector& v);

  // Testa se o vetor está vazio.
  bool empty();

  // Retorna o número de elementos no vetor.
  int size();

  // Altera o tamanho do vetor para m elementos em O(m).
  // Se m <= size_, o conteúdo do vetor é reduzido para os seus m primeiros
  // elementos. Se m > size_, o conteúdo do vetor é expandido e "m - size_"
  // novos elementos são inseridos no final do vetor. O valor dos novos
  // elementos é indeterminado.
  void resize(int m);

  // Retorna uma referência ao elemento de índice i no vetor.
  Type& at(int i);
  Type& operator[](int i) {return at(i);}

  // Faz com que o vetor corrente fique igual ao vetor v.
  void assign(vector& v);
  void operator=(vector& v) {assign(v);}

  // Insere o elemento x no final do vetor.
  // Esta operação aumenta o número de elementos do vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.push_back(-7.0)",
  // "v = {1.0, 3.0, 5.0, -7.0}".
  void push_back(Type x);

  // Remove o último elemento do vetor.
  // Esta operação diminui o número de elementos no vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.pop_back()",
  // "v = {1.0, 3.0}".
  void pop_back();

  // Insere o elemento x antes do elemento de índice 'i'.
  // Os valores válidos para 'i' estão no intervalo [0, size_].
  // Todos os elementos com índice igual ou maior que 'i' são deslocados
  // para a direita.
  // Esta operação aumenta o número de elementos no vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.insert(1, -7.0)",
  // "v = {1.0, -7.0, 3.0, 5.0}".
  void insert(int i, Type x);

  // Remove o elemento de índice 'i' do vetor.
  // Todos os elementos com índice maior que 'i' são deslocados para
  // a esquerda.
  // Esta operação diminui o número de elementos no vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.erase(1)",
  // "v = {1.0, 5.0}".
  void erase(int i);

  // Remove todos os elementos do vetor.
  // Ao final, o número de elementos no vetor é igual a zero.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.clear()",
  // "v = {}".
  void clear();

  // Libera a memória alocada para array_.
  ~vector();

 private:
  // Número de elementos no vetor.
  int size_;

  // Vetor alocado dinamicamente.
  Type* array_;

  friend class Teste;
};

#endif  // BRANCHES_GABARITOS_VECTOR_SRC_VECTOR_H_
