// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)


#include "../doctest/doctest.h"
#include <sstream>
#include <string>
#include "src/list.h"

using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

// Cria uma nó cuja chave é k, o nó anterior é l, e o nó posterior é r.
Node* NewNode(LType k, Node* l, Node* r) {
  Node* aux = new Node;
  aux->key = k;
  aux->prev = l;
  aux->next = r;
  return aux;
}

// Retorna um ponteiro para o primeiro elemento da lista.
Node* begin(const list& l) {
  return l.begin();
}

// Retorna um ponteiro para o elemento seguinte ao último elemento da lista.
Node* end(const list& l) {
  return l.end();
}

// Retorna o número de elementos na lista.
int size(const list& l) {
  return l.size();
}

// Retorna uma string no formato [a b c d ... z ].
string ToString(const list& l) {
  stringstream sout;
  sout << "[ ";
  for (Node* i = begin(l); i != end(l); i = i->next) {
    sout << i->key << " ";
  }''
  sout << "]";
  return sout.str();
}

// Preenche a lista d com 3 elementos. 'd' deve ser uma pilha vazia.
void CriaLista(LType x1, LType x2, LType x3, list* d) {
  d->push(x3);
  d->push(x2);
  d->push(x1);
  
  // d->end_->next = NewNode(x1, d->end_, NULL);
  // d->end_->next->next = NewNode(x2, d->end_->next, NULL);
  // d->end_->next->next->next = d->end_->prev =
  //     NewNode(x3, d->end_->next->next, d->end_);
  // d->size_ = 3;
}

TEST_CASE_FIXTURE(Teste, "Testa construtor vazio") {
  list atual;
  DOCTEST_CHECK_EQ(0, size(atual))
  INFO( "-------------------------------------------------------------------\n");
  INFO( "Erro no construtor: list::list()\n");
  INFO( "-------------------------------------------------------------------\n");
  INFO( " Número de elementos na lista maior que zero.\n");
  INFO( "-------------------------------------------------------------------\n");
  DOCTEST_CHECK_EQ(end(atual)->next, end(atual))
  INFO( "-------------------------------------------------------------------\n");
  INFO( "Erro no construtor: list::list()\n");
  INFO( "-------------------------------------------------------------------\n");
  INFO( " Em uma lista encadeada vazia, end_->next = end_.\n");
  INFO( "-------------------------------------------------------------------\n");
  DOCTEST_CHECK_EQ(end(atual)->prev, end(atual))
  INFO( "-------------------------------------------------------------------\n");
  INFO( "Erro no construtor: list::list()\n");
  INFO( "-------------------------------------------------------------------\n");
  INFO( " Em uma lista encadeada vazia, end_->prev_ = end_.\n");
  INFO( "-------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Size para lista vazia") {
  list l;
  int esperado = 0;
  int atual = l.size();
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("-------------------------------------------------------------------\n");
  INFO( "Erro na função: int list::size()\n");
  INFO( "-------------------------------------------------------------------\n");
  INFO( " l = " << ToString(l) << "\n");
  INFO( " \"l.sise()\" retornou: " << atual << "\n");
  INFO( " Valor esperado: " << esperado << "\n");
  INFO( "-------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Size para lista não vazia") {
  list l;
  CriaLista("a", "b", "c", &l);
  int esperado = 3;
  int atual = l.size();
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("-------------------------------------------------------------------\n");
  INFO( "Erro na função: int list::size()\n");
  INFO( "-------------------------------------------------------------------\n");
  INFO( " l = " << ToString(l) << "\n");
  INFO( " \"l.sise()\" retornou: " << atual << "\n");
  INFO( " Valor esperado: " << esperado << "\n");
  INFO( "-------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Empty com lista vazia") {
  list l;
  DOCTEST_CHECK(l.empty()) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: bool list::empty() \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( " A lista está vazia e a função retornou FALSE.\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Empty com lista não vazia") {
  list l;
  CriaLista("12", "14", "15", &l);
  DOCTEST_CHECK_FALSE(l.empty()) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: bool list::empty() \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( " A lista tem pelo menos um elemento e a função retornou TRUE.\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Begin com lista vazia") {
  list l;
  DOCTEST_CHECK_EQ(begin(l), l.begin()) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: Node* list::begin() \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( " begin() não retorna end_ na lista vazia.\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Begin com lista não vazia") {
  list l;
  CriaLista("1", "2", "3", &l);
  LType atual = l.begin()->key;
  LType esperado = "1";
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: Node* list::begin() \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( " l = " << ToString(l) << "\n");
  INFO( " \"l[l.begin()]\" retornou: " << atual << "\n");
  INFO( " Valor esperado: " << esperado << "\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa End com lista vazia") {
  list l;
  DOCTEST_CHECK_EQ(end(l), l.end()) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: Node* list::end() \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( " end() não retorna end_ na lista vazia.\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa End com lista não vazia") {
  list l;
  CriaLista("1", "2", "3", &l);
  DOCTEST_CHECK_EQ(end(l), l.end()) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: Node* list::end() \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( " l = " << ToString(l) << "\n");
  INFO( " \"l.end()\" não retornou o valor de \"l.end_\"\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Next") {
  list l;
  CriaLista("1", "2", "3", &l);
  LType atual = l.next(l.begin())->key;
  LType esperado = "2";
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: Node* list::next(Node* x) \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( " l = " << ToString(l) << "\n");
  INFO( " \"l[l.next(l.begin())]\" retornou: " << atual << "\n");
  INFO( " Valor esperado: " << esperado << "\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Prev") {
  list l;
  CriaLista("1", "2", "3", &l);
  LType atual = l.prev(l.end())->key;
  LType esperado = "3";
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: Node* list::prev() \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( " l = " << ToString(l) << "\n");
  INFO( " \"l[l.prev(l.end())]\" retornou: " << atual << "\n");
  INFO( " Valor esperado: " << esperado << "\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Key") {
  list l;
  CriaLista("12", "14", "15", &l);
  LType atual = l.key(l.begin());
  LType esperado = "12";
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("-------------------------------------------------------------------\n");
  INFO( "Erro na função: LType& list::key(Node* x)\n");
  INFO( "-------------------------------------------------------------------\n");
  INFO( " l = " << "[ 12 14 15 ]" << "\n");
  INFO( " \"l[l.begin()]\" retornou: " << atual << "\n");
  INFO( " Valor esperado: " << esperado << "\n");
  INFO( "-------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa operador de atribuição a lista vazia") {
  list esperado;
  CriaLista("12", "14", "15", &esperado);
  list atual;
  atual = esperado;
  DOCTEST_CHECK_NE(end(esperado), end(atual)) 
  INFO("-------------------------------------------------------------------\n");
  INFO( "Erro na função: void list::operator=(list& l)\n");
  INFO( "-------------------------------------------------------------------\n");
  INFO( " Não basta apenas copiar o ponteiro para \"end_\". \n");
  INFO( " Você tem que copiar todos os elementos de l para a lista corrente.\n");
  INFO( "-------------------------------------------------------------------\n");
  DOCTEST_CHECK_EQ(ToString(esperado), ToString(atual)) 
  INFO("-------------------------------------------------------------------\n");
  INFO( "Erro na função: void list::operator=(list& l)\n");
  INFO( "-------------------------------------------------------------------\n");
  INFO( " l = " << ToString(esperado) << "\n");
  INFO( " \"u = l\" resultou em: u = " << ToString(atual) << "\n");
  INFO( " Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO( "-------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa operador de atribuição a lista não vazia") {
  list esperado;
  CriaLista("1", "2", "3", &esperado);
  list atual;
  CriaLista("4", "5", "6", &atual);
  atual = esperado;
  DOCTEST_CHECK_EQ(ToString(esperado), ToString(atual)) 
  INFO("-------------------------------------------------------------------\n");
  INFO( "Erro na função: void list::operator=(list& l)\n");
  INFO( "-------------------------------------------------------------------\n");
  INFO( " l = " << ToString(esperado) << "\n");
  INFO( " \"u = l\" resultou em: u = " << ToString(atual) << "\n");
  INFO( " Resultado esperado: u = " << ToString(esperado) << "\n");
  INFO( "-------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Insert no início de lista vazia") {
  list l;
  l.insert(l.begin(), "10");
  string atual = ToString(l);
  string esperado("[ 10 ]");
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: void list::insert(Node* x, LType k) *\n");
  INFO( "------------------------------------------------------------------\n");
  INFO( "l = [ ] \n");
  INFO( "\"l.insert(l.begin(), 10)\" resultou em: l = " << atual << "\n");
  INFO( "Resultado esperado: l = " << esperado << "\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Insert no meio da lista não vazia") {
  list l;
  CriaLista("1", "3", "4", &l);
  l.insert(l.begin()->next, "2");
  string atual = ToString(l);
  string esperado("[ 1 2 3 4 ]");
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: void list::insert(Node* x, LType k) *\n");
  INFO( "------------------------------------------------------------------\n");
  INFO( "l = [ 1 3 4 ] \n");
  INFO( "\"l.insert(<ponteiro para 3>, 2)\" resultou em: l = " << atual << "\n");
  INFO( "Resultado esperado: l = " << esperado << "\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Erase em lista unitária") {
  list l;
  l.insert(l.begin(), "10");
  l.erase(l.begin());
  string atual = ToString(l);
  string esperado("[ ]");
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: void list::erase(Node* x) *\n");
  INFO( "------------------------------------------------------------------\n");
  INFO( "l = [ 10 ] \n");
  INFO( "\"l.erase(l.begin(l))\" resultou em: l = " << atual << "\n");
  INFO( "Resultado esperado: l = " << esperado << "\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Erase no meio da lista não vazia") {
  list l;
  CriaLista("1", "2", "3", &l);
  l.erase(l.begin()->next);
  string atual = ToString(l);
  string esperado("[ 1 3 ]");
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: void list::erase(Node* x) *\n");
  INFO( "------------------------------------------------------------------\n");
  INFO( "l = [ 1 2 3 ] \n");
  INFO( "\"l.erase(<ponterio para 2>)\" resultou em: l = " << atual << "\n");
  INFO( "Resultado esperado: l = " << esperado << "\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Merge") {
  list l1;
  CriaLista("1", "2", "3", &l1);
  list l2;
  CriaLista("4", "5", "6", &l2);
  l1.merge(l2);
  string atual = ToString(l1);
  string esperado("[ 1 2 3 4 5 6 ]");
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: void list::merge(list& l) \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( "l1 = [ 1 2 3 ] \n");
  INFO( "l2 = [ 4 5 6 ] \n");
  INFO( "\"l1.merge(l2)\" resultou em: l1 = " << atual << "\n");
  INFO( "Resultado esperado: l1 = " << esperado << "\n");
  INFO( "------------------------------------------------------------------\n");
}

TEST_CASE_FIXTURE(Teste, "Testa Clear") {
  list l;
  CriaLista("1", "4", "7", &l);
  l.clear();
  string atual = ToString(l);
  string esperado("[ ]");
  DOCTEST_CHECK_EQ(esperado, atual) 
  INFO("------------------------------------------------------------------\n");
  INFO( "Erro na função: void list::clear() \n");
  INFO( "------------------------------------------------------------------\n");
  INFO( "l = [ 1 4 7 ] \n");
  INFO( "\"l.clear()\" resultou em: l = " << atual << "\n");
  INFO( "Resultado esperado: l = " << esperado << "\n");
  INFO( "------------------------------------------------------------------\n");
}
