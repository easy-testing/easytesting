// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef LIST_H_
#define LIST_H_

#include "list/src/node.h"

template<class Type>
class list {
 public:
  // Cria uma lista vazia em O(1).
  list() {
    end_ = new Node<Type>();
  }

  // Cria a lista com os mesmo elementos de l em O(n).
  list(list<Type>& l) {
    end_ = new Node<Type>();
    clear();
    merge(l);
  }

  // Remove todos os elementos da lista para liberar a memoria.
  ~list() {
    clear();
    delete end_;
  }

  // Retorna um iterador para o primeiro elemento da lista em O(1).
  Node<Type>* begin() {
    return end_->next;
  }

  // Retorna um iterador para "depois" do ultimo elemento da lista em O(1).
  Node<Type>* end() {
    return end_;
  }

   // Testa se a lista esta vazia em O(1).
  bool empty() {
    return end_->next == end_;
  }

  // Retorna o valor do primeiro elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  Type front() {
    return end_->next->key;
  }

  // Retorna o valor do último elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  Type back() {
    return end_->prev->key;
  }

  // Retorna o número de elementos da lista em O(n).
  int size() {
    int s = 0;
    for (Node<Type>* i = begin(); i != end(); i = i->next) {
      s++;
    }
    return s;
  }

  // Insere x no início da lista em O(1).
  void push_front(Type x) {
    insert(begin(), x);
  }

  // Remove o primeiro elemento da lista em O(1).
  void pop_front() {
    erase(begin());
  }

  // Insere x no final da lista em O(1).
  void push_back(Type x) {
    insert(end(), x);
  }

  // Remove o último elemento da lista em O(1).
  void pop_back() {
    erase(end_->prev);
  }

  // Retona um ponteiro para o primeiro nó da lista que contém x.
  // Se x não está na lista, retorna um ponteiro para end().
  Node<Type>* find(Type x) {
    Node<Type>* iter = begin();
    while (iter != end() && iter.key != x) {
      iter = iter->next;
    }
    return iter;
  }

  // Insere x antes do elemento identificado por 'node' em O(1) e retorna
  // um ponteiro para o nó que foi criado para armazenar x.
  Node<Type>* insert(Node<Type>* node, Type x) {
    node->prev = node->prev->next = new Node<Type>(x, node->prev, node);
    return node->prev;
  }

  // Apaga o elemento indicado por 'node' em O(1).
  void erase(Node<Type>* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
  }


  // Remove todos os elementos da lista corrente em O(n).
  void clear() {
    while (!empty()) {
      pop_back();
    }
  }

  // Concatena os elementos de l no final da lista corrente em O(n).
  void merge(list<Type>& l) {
    for (Node<Type>* i = l.begin(); i != l.end(); i = i->next) {
      push_back(i->key);
    }
  }

  // Faz a lista corrente ficar igual a l em O(n);
  void operator=(list<Type>& l) {
    clear();
    merge(l);
  }

private:
  // Ponteiro para o nó sentinela da lista.
  Node<Type>* end_;

  friend class Teste;
};

#endif  // LIST_H_
