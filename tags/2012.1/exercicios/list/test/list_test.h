// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_LIST_TEST_LIST_TEST_H_
#define TRUNK_LIST_TEST_LIST_TEST_H_

#include <sstream>
#include <string>

#include "list/src/list.h"
#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Implementa um nó da lista encadeada.
struct Node {
  LType key;  // Valor da chave do nó.
  Node* prev;  // Ponteiro para o nó anterior.
  Node* next;  // Ponteiro para o próximo nó.
};

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Cria uma nó cuja chave é k, o nó anterior é l, e o nó posterior é r.
  Node* NewNode(LType k, Node* l, Node* r) {
    Node* aux = new Node();
    aux->key = k;
    aux->prev = l;
    aux->next = r;
    return aux;
  }

  // Retorna um ponteiro para o primeiro elemento da lista.
  Node* begin(const list& l) {
    return l.end_->next;
  }

  // Retorna um ponteiro para o elemento seguinte ao ultimo elemento da lista.
  Node* end(const list& l) {
    return l.end_;
  }

  // Retorna o número de elementos na lista.
  int size(const list& l) {
    return l.size_;
  }

  // Retorna uma string no formato {a b c d...}.
  string ToString(const list& l) {
    stringstream sout;
    sout << "[ ";
    for (Node* i = begin(l) ; i != end(l) ; i = i->next) {
      sout << i->key << " ";
    }
    sout << "]";
    return sout.str();
  }

  // Preenche a lista com 3 elementos.
  // 'd' deve ter sido criada com construtor vazio.
  void CriaList3(LType x1, LType x2, LType x3, list* d) {
    d->end_->next = NewNode(x1, d->end_, NULL);
    d->end_->next->next = NewNode(x2, d->end_->next, NULL);
    d->end_->next->next->next = d->end_->prev =
        NewNode(x3, d->end_->next->next, d->end_);
    d->size_ = 3;
  }
};

TEST_F(Teste, Testa_construtor_vazio) {
  list atual;

  ASSERT_EQ(0, size(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: list::list()\n"
    << "-------------------------------------------------------------------\n"
    << " Número de elementos na lista maior que zero.\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_EQ(begin(atual), end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: list::list()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista vazia, l.begin() = l.end() = ao no sentinela.\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_EQ(end(atual)->prev, end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: list::list()\n"
    << "-------------------------------------------------------------------\n"
    << " Em uma lista vazia, end_->prev_ = end_.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_construtor_por_copia) {
  list esperado;
  CriaList3("a", "b", "c", &esperado);
  list atual(esperado);
  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro no construtor: list::list(list& v)\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << ToString(esperado) << "\n"
    << " lista esperada = " << ToString(esperado) << "\n"
    << " lista criado = " << ToString(atual) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_lista_vazia) {
  list l;
  int esperado = 0;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int list::size()\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << ToString(l) << "\n"
    << " l.sise() retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Size_para_lista_nao_vazia) {
  list l;
  CriaList3("a", "b", "c", &l);
  int esperado = 3;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: int list::size()\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << ToString(l) << "\n"
    << " \"l.sise()\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_lista_vazia) {
  list l;
  ASSERT_TRUE(l.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool list::empty() \n"
      << "------------------------------------------------------------------\n"
      << " A lista esta vazia e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Empty_com_lista_nao_vazia) {
  list l;
  CriaList3("12", "14", "15", &l);
  ASSERT_FALSE(l.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: bool list::empty() \n"
      << "------------------------------------------------------------------\n"
      << " Erro na chamada da funcao : bool list::empty()\n"
      << " A lista tem pelo menos um elemento e a funcao retornou TRUE."
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Begin_com_lista_vazia) {
  list l;
  ASSERT_EQ(begin(l), l.begin())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* list::begin() \n"
      << "------------------------------------------------------------------\n"
      << " begin() nao retorna end_ na lista vazia.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Begin_com_lista_nao_vazia) {
  list l;
  CriaList3("1", "2", "3", &l);
  LType atual = l.begin()->key;
  LType esperado = "1";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* list::begin() \n"
      << "------------------------------------------------------------------\n"
      << " l = " << ToString(l) << "\n"
      << " \"l[l.begin()]\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_End_com_lista_vazia) {
  list l;
  ASSERT_EQ(end(l), l.end())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* list::end() \n"
      << "------------------------------------------------------------------\n"
      << " end() nao retorna end_ na lista vazia.\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_End_com_lista_nao_vazia) {
  list l;
  CriaList3("1", "2", "3", &l);
  ASSERT_EQ(end(l), l.end())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* list::begin() \n"
      << "------------------------------------------------------------------\n"
      << " l = " << ToString(l) << "\n"
      << " \"l.end()\" nao retornou o valor de \"l.end_\"\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Next) {
  list l;
  CriaList3("1", "2", "3", &l);
  LType atual = l.next(l.begin())->key;
  LType esperado = "2";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* list::begin() \n"
      << "------------------------------------------------------------------\n"
      << " l = " << ToString(l) << "\n"
      << " \"*l.next(l.begin())\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Prev) {
  list l;
  CriaList3("1", "2", "3", &l);
  LType atual = l.prev(l.end())->key;
  LType esperado = "3";
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: Node* list::begin() \n"
      << "------------------------------------------------------------------\n"
      << " l = " << ToString(l) << "\n"
      << " \"*l.next(l.end())\" retornou: " << atual << "\n"
      << " Valor esperado: " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_At_para_acesso) {
  list l;
  CriaList3("12", "14", "15", &l);
  LType atual = l[l.begin()];
  LType esperado = "12";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: VType& list::operator[](int i)\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << "[ 12 14 15 ]" << "\n"
    << " \"l[l.begin()]\" retornou: " << atual << "\n"
    << " Valor esperado: " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_At_para_atribuicao) {
  list l;
  CriaList3("12", "14", "15", &l);
  l[l.begin()] = "-1";
  string atual = ToString(l);
  string esperado = "[ -1 14 15 ]";
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: VType& list::operator[](int i)\n"
    << "-------------------------------------------------------------------\n"
    << " l = " << "[ 12 14 15 ]" << "\n"
    << " \"l[l.begin()] = -1\" resultou em: l = " << atual << "\n"
    << " Resultado esperado: l = " << esperado << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_operador_Assign) {
  list esperado;
  CriaList3("12", "14", "15", &esperado);
  list atual;
  atual = esperado;

  ASSERT_NE(end(esperado), end(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void list::operator=(list& l)\n"
    << "-------------------------------------------------------------------\n"
    << " Não basta apenas copiar o ponteiro para \"end_\". \n"
    << " Você tem que copiar todos os elementos de l para a lista corrente.\n"
    << "-------------------------------------------------------------------\n";

  ASSERT_EQ(ToString(esperado), ToString(atual))
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao: void list::operator=(list& l)\n"
    << "-------------------------------------------------------------------\n"
    << " u = " << ToString(esperado) << "\n"
    << " \"u = l\" resultou em: u = " << ToString(atual) << "\n"
    << " Resultado esperado: u = " << ToString(esperado) << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Insert_no_inicio_de_lista_vazia) {
  list l;
  l.insert(l.begin(), "10");
  string atual = ToString(l);
  string esperado("[ 10 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void list::insert(Node* i, LType k) *\n"
      << "------------------------------------------------------------------\n"
      << "l = [] \n"
      << "\"l.insert(l.begin(l), 10)\" resultou em: l = " << atual << "\n"
      << "Resultado esperado: l = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Insert_no_meio_da_lista_nao_vazia) {
  list l;
  CriaList3("1", "3", "4", &l);
  l.insert(l.begin()->next, "2");
  string atual = ToString(l);
  string esperado("[ 1 2 3 4 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void list::insert(Node* i, LType k) *\n"
      << "------------------------------------------------------------------\n"
      << "l = [ 1 3 4 ] \n"
      << "\"l.insert(<ponteiro para 3>, \"2\")\" resultou em: "
      << "l = " << atual << "\n"
      << "Resultado esperado: l = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Erase_em_lista_unitaria) {
  list l;
  l.insert(l.begin(), "10");
  l.erase(l.begin());
  string atual = ToString(l);
  string esperado("[ ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void list::erase(Node* i, LType k) *\n"
      << "------------------------------------------------------------------\n"
      << "l = [ 10 ] \n"
      << "\"l.erase(l.begin(l))\" resultou em: l = " << atual << "\n"
      << "Resultado esperado: l = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_erase_no_meio_da_lista_nao_vazia) {
  list l;
  CriaList3("1", "2", "3", &l);
  l.erase(l.begin()->next);
  string atual = ToString(l);
  string esperado("[ 1 3 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void list::erase(Node* i) *\n"
      << "------------------------------------------------------------------\n"
      << "l = [ 1 2 3 ] \n"
      << "\"l.erase(<ponterio para 2>)\" resultou em: l = " << atual << "\n"
      << "Resultado esperado: l = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Merge) {
  list l1;
  CriaList3("1", "2", "3", &l1);
  list l2;
  CriaList3("4", "5", "6", &l2);
  l1.merge(l2);
  string atual = ToString(l1);
  string esperado("[ 1 2 3 4 5 6 ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void list::merge(list& l) \n"
      << "------------------------------------------------------------------\n"
      << "l1 = [ 1 2 3 ] \n"
      << "l2 = [ 4 5 6 ] \n"
      << "\"l1.merge(l2)\" resultou em: l1 = " << atual << "\n"
      << "Resultado esperado: l1 = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testa_Clear) {
  list l;
  CriaList3("1", "4", "7", &l);
  l.clear();
  string atual = ToString(l);
  string esperado("[ ]");
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao: void list::clear() \n"
      << "------------------------------------------------------------------\n"
      << "l = [ 1 4 7 ] \n"
      << "\"l.clear()\" resultou em: l = " << atual << "\n"
      << "Resultado esperado: l = " << esperado << "\n"
      << "------------------------------------------------------------------\n";
}

#endif  // TRUNK_LIST_TEST_LIST_TEST_H_