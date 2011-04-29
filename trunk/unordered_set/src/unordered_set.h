// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef UNORDERED_SET_SRC_UNORDERED_SET_H_
#define UNORDERED_SET_SRC_UNORDERED_SET_H_

#include "list/src/list.h"
#include "unordered_set/src/hash_function.h"

// Implementa um conjunto desordenado usando tabelas de dispersão.
// O cálculo da complexidade assume que não existe colisão entre
// chaves, o que não é garantido nesta implementação.
template<class Type>
class unordered_set {
 public:
  // Cria um conjunto vazio em O(1).
  unordered_set() {
    size_ = 0;
    table_size_ = 16;
    table_ = new list<Type>[table_size_];
  }

  unordered_set(unordered_set& c) {
    size_ = c.size_;
    table_size_ = c.table_size_;
    table_ = new list<Type>[table_size_];
    for (int i = 0; i < table_size_; i++) {
      table_[i].merge(c.table_[i]);
    }
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

  // Retorna o menor elemento do cojunto em O(n).
  Type min() {
    Type min = -1000; // TODO(tfn) implementar corretamente.
    for (int i = 0; i < table_size_; i++) {
      for (Node<Type>* j = table_[i].begin()->next;
           j != table_[i].end();
           j = j->next) {
        if (j->key < min) {
          min = j->key;
        }
      }
    }
    return min;
  }

  // Testa se x pertece ao conjunto em O(1).
  bool find(Type x) {
    int i = hash(x, table_size_);
    for (Node<Type>* in = table_[i].begin();
         in != table_[i].end();
         in = in->next) {
      if (in->key == x) {
        return true;
      }
    }
    return false;
  }

  // Insere x no conjunto em O(1).
  // Retorna false se x já estava no conjunto e true caso contrário.
  bool insert(Type x) {
    if (find(x)) {
      return false;
    } else {
      table_[hash(x, table_size_)].push_back(x);
      size_++;
      if (size_ > table_size_) {
        resize(2 * table_size_);
      }
      return true;
    }
  }

  // Remove x do conjunto em O(1).
  // Retorna true se algum elemento foi removido ou falso caso contrário.
  bool erase(Type x) {
    int i = hash(x, table_size_);
    for (Node<Type>* in = table_[i].begin();
         in != table_[i].end();
         in = in->next) {
      if (in->key == x) {
        table_[i].erase(in);
        size_--;
        return true;
      }
    }
    return false;
  }

  // Remove todos os elementos do conjunto em O(n).
  void clear() {
    for (int i = 0; i < table_size_; ++i) {
      table_[i].clear();
      size_ = 0;
    }
  }

  // Insere todos os elementos do conjunto no final de l em O(n).
  void ToList(list<Type>* l) {
    for (int i = 0; i < table_size_; ++i) {
      l->merge(table_[i]);
    }
  }

  // Define o número de linhas na tabela em O(n).
  void resize(int new_size) {
    // Salva os elementos no conjunto em l.
    list<Type> l;
    ToList(&l);

    // Realoca a tabela.
    delete [] table_;
    table_size_ = new_size;
    table_ = new list<Type>[table_size_];

    // Reinsere novamente os elementos do conjunto.
    for (Node<Type>* i = l.begin(); i != l.end(); i = i->next) {
      table_[hash(i->key, table_size_)].push_back(i->key);
    }
  }

 private:
  // Número de elementos no conjunto.
  int size_;

  // Número de linhas na tabela.
  int table_size_;

  // Vetor com as linhas da tabela.
  list<Type>* table_;
};  // end class unordered_set.

#endif  // UNORDERED_SET_SRC_UNORDERED_SET_H_
