// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LIST_SRC_LIST_H_
#define BRANCHES_GABARITOS_LIST_SRC_LIST_H_


struct node;  // Definido depois da classe list.

// Implementa uma lista de elementos. O tipo dos elementos é
// definido por 'type'.
class list {
 public:
  // Tipo dos elementos contidos na lista.
  typedef float type;

  // Cria uma lista vazia em O(1).
  list();

  // Cria a lista com os mesmo elementos de l em O(m), onde m = l.size().
  list(list& l);

  // Remove todos os elementos da lista para liberar a memoria em O(n),
  // onde n eh o numero de elementos na lista.
  ~list();

  // Retorna um pontiero para o primeiro noh da lista em O(1).
  node* begin();

  // Retorna um pontiero para "depois" do ultimo noh da lista em O(1).
  node* end();

  // Testa se a lista esta vazia em O(1).
  bool empty();

  // Retorna o valor do primeiro elemento da lista em O(1).
  // PRECONDICAO: a lista nao pode estar vazia.
  type front();

  // Retorna o valor do ultimo elemento da lista em O(1).
  // PRECONDICAO: a lista não pode estar vazia.
  type back();

  // Retorna o numero de elementos da lista em O(1).
  int size();

  // Insere x no início da lista em O(1).
  void push_front(type x);

  // Remove o primeiro elemento da lista em O(1).
  void pop_front();

  // Insere x no final da lista em O(1).
  void push_back(type x);

  // Remove o último elemento da lista em O(1).
  void pop_back();

  // Retorna um pontiero para o primeiro noh da lista cuja chave eh x em O(n),
  // onde n eh o numero de elementos na lista.
  // Se x nao esta na lista, retorna um pontiero para end().
  node* find(type x);

  // Insere x antes do elemento identificado por 'node' em O(1) e retorna
  // um ponteiro para o noh que foi criado para armazenar x.
  node* insert(node* node, type x);

  // Apaga o elemento indicado por 'node' em O(1).
  void erase(node* node);


  // Remove todos os elementos da lista corrente em O(n),
  // onde n é o numero de elementos na lista.
  void clear();

  // Concatena os elementos de l no final da lista corrente em O(m),
  // onde m = l.size().
  void merge(list& l);

  // Faz a lista corrente ficar igual a l em O(m), onde m = l.size().
  void operator=(list& l);

 private:
  // Numero de elementos na lista.
  int size_;

  // Ponteiro para o noh sentinela da lista.
  node* end_;

  friend class Teste;
};

// Implementa um noh da lista ligada.
struct node {
  list::type key;  // Valor da chave do noh.
  node* prev;  // Ponteiro para o proximo noh da lista.
  node* next;  // Ponteiro para o noh anterior da lista.
};

// Cria o noh sentinela da lista ligada em O(1).
node* NewSentinel();

// Cria um novo noh da lista ligada em O(1).
node* NewNode(list::type k, node* l, node* r);

#endif  // BRANCHES_GABARITOS_LIST_SRC_LIST_H_
