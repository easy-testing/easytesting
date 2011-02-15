#ifndef BINARY_SEARCH_TREE_SET_H_
#define BINARY_SEARCH_TREE_SET_H_

#include "easytesting/list/src/list.h"
#include "easytesting/unordered_set/src/hash_function.h"

// Implementa um conjunto desordenado usando tabelas de dispersão.
// O calculo da complexidade assume que não existe colisão entre
// chaves, o que não é garantido nesta implementação.
template<class Type>
class unordered_set {
 public:
  // Tipo do iterador da lista.
  typedef ListIterator<Type> iterator;

  typedef list<Type> List;

  // Cria um conjunto vazio em O(1).
  unordered_set() {
    size_ = 0;
    max_size_ = 16;
    table_ = new List[max_size_];
  }

  // Libera memória.
  ~unordered_set() {
    delete [] table_;
  }

  // Testa se o cojunto esta vazio em O(1).
  bool empty() {
    return size_ == 0;
  }

  // Retorna o número de elementos no cojunto em O(1).
  int size() {
    return size_;
  }

  // Testa se x pertece ao conjunto em O(1).
  bool find(Type x) {
    int i = hash(x, max_size_);
    for (iterator it = table_[i].begin(); it != table_[i].end(); ++it) {
      if (*it == x) {
        return true;
      }
    }
    return false;
  }

  // Insere x no conjunto em O(1). Retorna false se x já estava no conjunto e
  // true caso contrário.
  bool insert(Type x) {
    if (find(x)) {
      return false;
    } else {
      table_[hash(x, max_size_)].push_back(x);
      return true;
    }
  }

  // Remove x do conjunto em O(1).
  void erase(Type x) {
    int i = hash(x, max_size_);
    for (iterator it = table_[i].begin(); it != table_[i].end(); ++it) {
      if (*it == x) {
        table_[i].erase(it);
      }
    }
  }

  // Remove todos os elementos do conjunto corrente em O(n).
  void clear() {
    for (int i = 0; i < max_size_; ++i) {
      table_[i].clear();
    }
  }

  // Insere todos os elementos do conjunto no final de l em O(n)
  void ToList(list<Type>* l) {
    for (int i = 0; i < max_size_; ++i) {
      l->merge(table_[i]);
    }
  }

 private:
  // Número de elementos no conjunto.
  int size_;

  // Número de linhas na tabela.
  int max_size_;

  // Vetor com as linhas da tabela.
  List* table_;
};  // end class unordered_set.

#endif  // BINARY_SEARCH_TREE_SET_H_
