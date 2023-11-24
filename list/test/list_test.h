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

// Classe base dos testes.
class Teste {
 protected:
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
    return l.end_->next;
  }

  // Retorna um ponteiro para o elemento seguinte ao último elemento da lista.
  Node* end(const list& l) {
    return l.end_;
  }

  // Retorna o número de elementos na lista.
  int size(const list& l) {
    return l.size_;
  }

  // Retorna uma string no formato [a b c d ... z ].
  string ToString(const list& l) {
    stringstream sout;
    sout << "[ ";
    for (Node* i = begin(l); i != end(l); i = i->next) {
      sout << i->key << " ";
    }
    sout << "]";
    return sout.str();
  }

  // Preenche a lista d com 3 elementos. 'd' deve ser uma pilha vazia.
  void CriaLista(LType x1, LType x2, LType x3, list* d) {
    d->end_->next = NewNode(x1, d->end_, NULL);
    d->end_->next->next = NewNode(x2, d->end_->next, NULL);
    d->end_->next->next->next = d->end_->prev =
        NewNode(x3, d->end_->next->next, d->end_);
    d->size_ = 3;
  }
};

TEST_CASE_FIXTURE(Teste, "Testa construtor vazio") {
  list atual;
  DOCTEST_CHECK_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: list::list()\n"
    << "-------------------------------------------------------------------\n"
    << " Número de elementos na lista maior que zero.\n"
    << "-------------------------------------------------------------------\n";
  DOCTEST_CHECK_EQ(end(atual)->next, end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: list::list()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista encadeada vazia, end_->next = end_.\n"
    << "-------------------------------------------------------------------\n";
  DOCTEST_CHECK_EQ(end(atual)->prev, end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: list::list()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista encadeada vazia, end_->prev_ = end_.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Size para lista vazia") {
  list l;
  int esperado = 0;
  int atual = l.size();
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "-------------------------------------------------------------------\n"
    << "Erro na função: int list::size()\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << ToString(l) << "\n"
    << " \"l.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Size para lista não vazia") {
  list l;
  CriaLista("a", "b", "c", &l);
  int esperado = 3;
  int atual = l.size();
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "-------------------------------------------------------------------\n"
    << "Erro na função: int list::size()\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << ToString(l) << "\n"
    << " \"l.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Empty com lista vazia") {
  list l;
  DOCTEST_CHECK(l.empty()) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: bool list::empty() \n"
    << "------------------------------------------------------------------\n"
    << " A lista está vazia e a função retornou FALSE.\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Empty com lista não vazia") {
  list l;
  CriaLista("12", "14", "15", &l);
  DOCTEST_CHECK_FALSE(l.empty()) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: bool list::empty() \n"
    << "------------------------------------------------------------------\n"
    << " A lista tem pelo menos um elemento e a função retornou TRUE.\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Begin com lista vazia") {
  list l;
  DOCTEST_CHECK_EQ(begin(l), l.begin()) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: Node* list::begin() \n"
    << "------------------------------------------------------------------\n"
    << " begin() não retorna end_ na lista vazia.\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Begin com lista não vazia") {
  list l;
  CriaLista("1", "2", "3", &l);
  LType atual = l.begin()->key;
  LType esperado = "1";
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: Node* list::begin() \n"
    << "------------------------------------------------------------------\n"
    << " l = " << ToString(l) << "\n"
    << " \"l[l.begin()]\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa End com lista vazia") {
  list l;
  DOCTEST_CHECK_EQ(end(l), l.end()) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: Node* list::end() \n"
    << "------------------------------------------------------------------\n"
    << " end() não retorna end_ na lista vazia.\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa End com lista não vazia") {
  list l;
  CriaLista("1", "2", "3", &l);
  DOCTEST_CHECK_EQ(end(l), l.end()) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: Node* list::end() \n"
    << "------------------------------------------------------------------\n"
    << " l = " << ToString(l) << "\n"
    << " \"l.end()\" não retornou o valor de \"l.end_\"\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Next") {
  list l;
  CriaLista("1", "2", "3", &l);
  LType atual = l.next(l.begin())->key;
  LType esperado = "2";
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: Node* list::next(Node* x) \n"
    << "------------------------------------------------------------------\n"
    << " l = " << ToString(l) << "\n"
    << " \"l[l.next(l.begin())]\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Prev") {
  list l;
  CriaLista("1", "2", "3", &l);
  LType atual = l.prev(l.end())->key;
  LType esperado = "3";
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: Node* list::prev() \n"
    << "------------------------------------------------------------------\n"
    << " l = " << ToString(l) << "\n"
    << " \"l[l.prev(l.end())]\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Key") {
  list l;
  CriaLista("12", "14", "15", &l);
  LType atual = l.key(l.begin());
  LType esperado = "12";
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "-------------------------------------------------------------------\n"
    << "Erro na função: LType& list::key(Node* x)\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << "[ 12 14 15 ]" << "\n"
    << " \"l[l.begin()]\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa operador de atribuição a lista vazia") {
  list esperado;
  CriaLista("12", "14", "15", &esperado);
  list atual;
  atual = esperado;
  DOCTEST_CHECK_NE(end(esperado), end(atual)) <<
    "-------------------------------------------------------------------\n"
    << "Erro na função: void list::operator=(list& l)\n"
    << "-------------------------------------------------------------------\n"
    << " Não basta apenas copiar o ponteiro para \"end_\". \n"
    << " Você tem que copiar todos os elementos de l para a lista corrente.\n"
    << "-------------------------------------------------------------------\n";
  DOCTEST_CHECK_EQ(ToString(esperado), ToString(atual)) <<
    "-------------------------------------------------------------------\n"
    << "Erro na função: void list::operator=(list& l)\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << ToString(esperado) << "\n"
    << " \"u = l\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa operador de atribuição a lista não vazia") {
  list esperado;
  CriaLista("1", "2", "3", &esperado);
  list atual;
  CriaLista("4", "5", "6", &atual);
  atual = esperado;
  DOCTEST_CHECK_EQ(ToString(esperado), ToString(atual)) <<
    "-------------------------------------------------------------------\n"
    << "Erro na função: void list::operator=(list& l)\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << ToString(esperado) << "\n"
    << " \"u = l\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Insert no início de lista vazia") {
  list l;
  l.insert(l.begin(), "10");
  string atual = ToString(l);
  string esperado("[ 10 ]");
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: void list::insert(Node* x, LType k) *\n"
    << "------------------------------------------------------------------\n"
    << "l = [ ] \n"
    << "\"l.insert(l.begin(), 10)\" resultou em: l = " << atual << "\n"
    << "Resultado esperado: l = " << esperado << "\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Insert no meio da lista não vazia") {
  list l;
  CriaLista("1", "3", "4", &l);
  l.insert(l.begin()->next, "2");
  string atual = ToString(l);
  string esperado("[ 1 2 3 4 ]");
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: void list::insert(Node* x, LType k) *\n"
    << "------------------------------------------------------------------\n"
    << "l = [ 1 3 4 ] \n"
    << "\"l.insert(<ponteiro para 3>, 2)\" resultou em: l = " << atual << "\n"
    << "Resultado esperado: l = " << esperado << "\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Erase em lista unitária") {
  list l;
  l.insert(l.begin(), "10");
  l.erase(l.begin());
  string atual = ToString(l);
  string esperado("[ ]");
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: void list::erase(Node* x) *\n"
    << "------------------------------------------------------------------\n"
    << "l = [ 10 ] \n"
    << "\"l.erase(l.begin(l))\" resultou em: l = " << atual << "\n"
    << "Resultado esperado: l = " << esperado << "\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Erase no meio da lista não vazia") {
  list l;
  CriaLista("1", "2", "3", &l);
  l.erase(l.begin()->next);
  string atual = ToString(l);
  string esperado("[ 1 3 ]");
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: void list::erase(Node* x) *\n"
    << "------------------------------------------------------------------\n"
    << "l = [ 1 2 3 ] \n"
    << "\"l.erase(<ponterio para 2>)\" resultou em: l = " << atual << "\n"
    << "Resultado esperado: l = " << esperado << "\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Merge") {
  list l1;
  CriaLista("1", "2", "3", &l1);
  list l2;
  CriaLista("4", "5", "6", &l2);
  l1.merge(l2);
  string atual = ToString(l1);
  string esperado("[ 1 2 3 4 5 6 ]");
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: void list::merge(list& l) \n"
    << "------------------------------------------------------------------\n"
    << "l1 = [ 1 2 3 ] \n"
    << "l2 = [ 4 5 6 ] \n"
    << "\"l1.merge(l2)\" resultou em: l1 = " << atual << "\n"
    << "Resultado esperado: l1 = " << esperado << "\n"
    << "------------------------------------------------------------------\n";
}

TEST_CASE_FIXTURE(Teste, "Testa Clear") {
  list l;
  CriaLista("1", "4", "7", &l);
  l.clear();
  string atual = ToString(l);
  string esperado("[ ]");
  DOCTEST_CHECK_EQ(esperado, atual) <<
    "------------------------------------------------------------------\n"
    << "Erro na função: void list::clear() \n"
    << "------------------------------------------------------------------\n"
    << "l = [ 1 4 7 ] \n"
    << "\"l.clear()\" resultou em: l = " << atual << "\n"
    << "Resultado esperado: l = " << esperado << "\n"
    << "------------------------------------------------------------------\n";
}
