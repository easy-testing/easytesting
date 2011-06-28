// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef UNORDERED_SET_SRC_UNORDERED_SET_H_
#define UNORDERED_SET_SRC_UNORDERED_SET_H_

#include <algorithm>
#include "linear_set/src/linear_set.h"
#include "list/src/list.h"
#include "hash_set/src/hash_function.h"

using std::max;

// Implementa um conjunto desordenado usando tabelas de dispersão.
// No cáculo das complexidades assintóticas, 'n' é o número de elementos
// no conjunto e 'k' é número esperado de colisões.
template<class Type>
class hash_set {
 public:
  // Cria um conjunto vazio em O(1).
  hash_set() {
    size_ = 0;
    num_lines_ = 1000;
    table_ = new linear_set<Type>[num_lines_];
  }

  // Cria um conjunto vazio em O(1).
  // Cria a tabela com num_lines.
  hash_set(int num_lines) {
    size_ = 0;
    num_lines_ = num_lines;
    table_ = new linear_set<Type>[num_lines_];
  }

  // Cria um conjunto com os mesmos elementos de c em O(n).
  hash_set(hash_set& c) {
    size_ = c.size_;
    num_lines_ = c.num_lines_;
    table_ = new linear_set<Type>[c.num_lines_];
    for (int i = 0; i < num_lines_; i++) {
      table_[i] = c.table_[i];
    }
  }

  // Libera memória.
  ~hash_set() {
    delete [] table_;
  }

  // Testa se o conjunto está vazio em O(1).
  bool empty() {
    return size_ == 0;
  }

  // Retorna o número de elementos no conjunto em O(1).
  int size() {
    return size_;
  }

  // Retorna o menor elemento do conjunto em O(n).
  Type min() {
    Type min_set;
    bool first_line_not_empty = true;
    for (int i = 0; i < num_lines_; i++) {
      if (!table_[i].empty()) {
        if (first_line_not_empty || table_[i].min() < min_set) {
          min_set = table_[i].min();
          first_line_not_empty = false;
        }
      }
    }
    return min_set;
  }

  // Testa se x pertece ao conjunto em O(k).
  bool find(Type x) {
    return table_[hash(x, num_lines_)].find(x);
  }

  // Insere x no conjunto em O(k).
  // Retorna false se x já estava no conjunto e true caso contrário.
  bool insert(Type x) {
    if (table_[hash(x, num_lines_)].insert(x)) {
      size_++;
      return true;
    } else {
      return false;
    }
  }

  // Remove x do conjunto em O(k).
  // Retorna true se algum elemento foi removido ou falso caso contrário.
  bool erase(Type x) {
    if (table_[hash(x, num_lines_)].erase(x)) {
      size_--;
      return true;
    } else {
      return false;
    }
  }

  // Remove todos os elementos do conjunto em O(n).
  void clear() {
    for (int i = 0; i < num_lines_; i++) {
      table_[i].clear();
    }
    size_ = 0;
  }

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do conjunto c.
  void operator=(hash_set<Type>& c) {
    // Apaga a tabela corrente.
    delete [] table_;
    // Cria uma nova tabela igual a de 'c'.
    size_ = c.size_;
    num_lines_ = c.num_lines_;
    table_ = new linear_set<Type>[num_lines_];
    for (int i = 0; i < num_lines_; i++) {
      table_[i] = c.table_[i];
    }
  }

  // Insere todos os elementos do conjunto no final de 'l' em O(n).
  void ToList(list<Type>* l) {
    for (int i = 0; i < num_lines_; i++) {
      table_[i].ToList(l);
    }
  }

 private:
  // Número de elementos no conjunto.
  int size_;

  // Número de linhas na tabela.
  int num_lines_;

  // Vetor com as linhas da tabela.
  linear_set<Type>* table_;
};  // end class hash_set.

#endif  // UNORDERED_SET_SRC_UNORDERED_SET_H_
