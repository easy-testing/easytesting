// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
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
    return end_;  // TODO.
  }

  // Retorna um iterador para "depois" do ultimo elemento da lista em O(1).
  Node<Type>* end() {
    return end_;  // TODO.
  }

   // Testa se a lista esta vazia em O(1).
  bool empty() {
    return false;  // TODO.
  }

  // Retorna o valor do primeiro elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  Type front() {
    Type a;
    return a;  // TODO.
  }

  // Retorna o valor do último elemento da lista em O(1).
  // PRECONDIÇÃO: a lista não pode estar vazia.
  Type back() {
    Type a;
    return a;  // TODO.
  }

  // Retorna o número de elementos da lista em O(n).
  int size() {
    return 0;  // TODO.
  }

  // Insere x no início da lista em O(1).
  void push_front(Type x) {
    // TODO.
  }

  // Remove o primeiro elemento da lista em O(1).
  void pop_front() {
    // TODO.
  }

  // Insere x no final da lista em O(1).
  void push_back(Type x) {
    // TODO.
  }

  // Remove o último elemento da lista em O(1).
  void pop_back() {
    // TODO.
  }

  // Retona um ponteiro para o primeiro nó da lista que contém x.
  // Se x não está na lista, retorna um ponteiro para end().
  Node<Type>* find(Type x) {
    return end_;  // TODO.
  }

  // Insere x antes do elemento identificado por posision em O(1) e retorna
  // um ponteiro para o nó que foi criado para armazenar x.
  Node<Type>* insert(Node<Type>* node, Type x) {
    return end_;  // TODO.
  }

  // Apaga o elemento indicado por posision em O(1).
  void erase(Node<Type>* node) {
    // TODO.
  }


  // Remove todos os elementos da lista corrente em O(n).
  void clear() {
    // TODO.
  }

  // Concatena os elementos de l no final da lista corrente em O(n).
  void merge(list<Type>& l) {
    // TODO.
  }

  // Faz a lista corrente ficar igual a l em O(n);
  void operator=(list<Type>& l) {
    // TODO.
  }

private:
  // Ponteiro para o nó sentinela da lista.
  Node<Type>* end_;

  friend class Teste;
};

#endif  // LIST_H_
