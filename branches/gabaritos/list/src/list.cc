// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include "list/src/list.h"

#include "list/src/node.h"

 // Cria uma lista vazia em O(1).
 list::list() {
   size_ = 0;
   end_ = NewSentinel();
 }

 // Cria a lista com os mesmo elementos de l em O(n).
 list::list(list& l) {
   size_ = 0;
   end_ = NewSentinel();
   merge(l);
 }

 // Remove todos os elementos da lista para liberar a memoria.
 list::~list() {
   clear();
   delete end_;
 }

 // Retorna um iterador para o primeiro elemento da lista em O(1).
 Node* list::begin() {
   return end_->next;
 }

 // Retorna um iterador para "depois" do ultimo elemento da lista em O(1).
 Node* list::end() {
   return end_;
 }

  // Testa se a lista esta vazia em O(1).
 bool list::empty() {
   return size_ == 0;
 }

 // Retorna o valor do primeiro elemento da lista em O(1).
 // PRECONDIÇÃO: a lista não pode estar vazia.
 ListType list::front() {
   return end_->next->key;
 }

 // Retorna o valor do último elemento da lista em O(1).
 // PRECONDIÇÃO: a lista não pode estar vazia.
 ListType list::back() {
   return end_->prev->key;
 }

 // Retorna o número de elementos da lista em O(n).
 int list::size() {
   return size_;
 }

 // Insere x no início da lista em O(1).
 void list::push_front(ListType x) {
   insert(begin(), x);
 }

 // Remove o primeiro elemento da lista em O(1).
 void list::pop_front() {
   erase(begin());
 }

 // Insere x no final da lista em O(1).
 void list::push_back(ListType x) {
   insert(end(), x);
 }

 // Remove o último elemento da lista em O(1).
 void list::pop_back() {
   erase(end_->prev);
 }

 // Retona um ponteiro para o primeiro nó da lista que contém x.
 // Se x não está na lista, retorna um ponteiro para end().
 Node* list::find(ListType x) {
   Node* iter = begin();
   while (iter != end() && iter->key != x) {
    iter = iter->next;
   }
   return iter;
 }

 // Insere x antes do elemento identificado por 'node' em O(1) e retorna
 // um ponteiro para o nó que foi criado para armazenar x.
 Node* list::insert(Node* node, ListType x) {
   node->prev = node->prev->next = NewNode(x, node->prev, node);
   size_++;
   return node->prev;
 }

 // Apaga o elemento indicado por 'node' em O(1).
 void list::erase(Node* node) {
   node->prev->next = node->next;
   node->next->prev = node->prev;
   delete node;
   size_--;
 }


 // Remove todos os elementos da lista corrente em O(n).
 void list::clear() {
  while (!empty()) {
   pop_back();
  }
 }

 // Concatena os elementos de l no final da lista corrente em O(n).
 void list::merge(list& l) {
  for (Node* i = l.begin(); i != l.end(); i = i->next) {
   push_back(i->key);
  }
 }

 // Faz a lista corrente ficar igual a l em O(n);
 void list::operator=(list& l) {
  clear();
  merge(l);
 }
