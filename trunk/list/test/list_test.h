// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
#ifndef LIST_TEST_LIST_TEST_H_
#define LIST_TEST_LIST_TEST_H_

#include <sstream>
#include <string>

#include "easytesting/list/src/list.h"
#include "easytesting/gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  typedef ListNode<int> Node;  // Tipo dos nós da lista.

  // Retorna uma string no formato {a b c d...}.
  string PrintList(list<int>& l) {
    stringstream output;
    output << "{";
    for (list<int>::iterator i = l.begin() ; i != l.end() ; ++i) {
      if (i == l.begin())
        output << *i;
      else
        output << " " << *i;
    }
    output << "}";
    return output.str();
  }

  // Preenche a lista passada como parametro com 1 numero.
  // 'l' deve ser uma lista vazia.
  void CriaList1(int x, list<int> *l) {
    l->end_->left = l->end_->right = new Node(x, l->end_, l->end_);
  }

  // Preenche a lista passada como parametro com 3 numeros.
  // 'l' deve ser uma lista vazia.
  void CriaList3(int x1, int x2, int x3, list<int>* l) {
    l->end_->right = new Node(x1, l->end_, NULL);
    l->end_->right->right = new Node(x2, l->end_->right, NULL);
    l->end_->right->right->right = l->end_->left =
        new Node(x3, l->end_->right->right, l->end_);
  }
};

TEST_F(Teste, Testar_metodo_empty) {
  list<int> l1;
  ASSERT_TRUE(l1.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool list<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A lista esta vazia e a funcao retornou FALSE."
    << "-------------------------------------------------------------------\n";

  list<int> l2;
  CriaList3(12, 14, 15, &l2);
  ASSERT_FALSE(l2.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool list<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "Erro na chamada da funcao : bool list::empty()\n"
    << "A lista tem pelo menos um elemento e a funcao retornou TRUE."
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_lista_com_um_elemento) {
  list<int> l;
  CriaList1(2, &l);
  int esperado = 2;
  int atual = l.front();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type list<Type>::front() *\n"
  << "-------------------------------------------------------------------\n"
  << "     " << PrintList(l) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_lista_com_mais_de_um_elemento) {
  list<int> l;
  CriaList3(3, 7, 8, &l);
  int esperado = 3;
  int atual = l.front();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type list<Type>::front() *\n"
  << "-------------------------------------------------------------------\n"
  << "     " << PrintList(l) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_lista_com_um_elemento) {
  list<int> l;
  CriaList1(3, &l);
  int esperado = 3;
  int atual = l.back();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Type list<Type>::back() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintList(l) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_lista_com_mais_de_um_elemento) {
  list<int> l;
  CriaList3(4, 5, 7, &l);
  int esperado = 7;
  int atual = l.back();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Type list<Type>::back() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintList(l) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_lista_vazia) {
  list<int> l;
  int esperado = 0;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int list<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintList(l) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_lista_com_um_elemento) {
  list<int> l;
  CriaList1(2, &l);
  int esperado = 1;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int list<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintList(l) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_lista_com_varios_elementos) {
  list<int> l;
  CriaList3(10, 3, 0, &l);
  int esperado = 3;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int list<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintList(l) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

// Para realizar a comparacao da lista esperada para a lista do aluno, foi
// necessario utilizar a comparacao da classe string (imprimir a lista do
// aluno em uma string).
TEST_F(Teste, Testar_metodo_insert_no_inicio_da_lista_vazia) {
  list<int> l;
  l.insert(l.begin(), 10);
  string esperado("{10}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* list<Type>::insert(Node* position, Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_inicio_da_lista_com_um_elemento) {
  list<int> l;
  CriaList1(22, &l);
  l.insert(l.begin(), 12);
  string esperado("{12 22}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* list<Type>::insert(Node* position, Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_inicio_da_lista_com_varios_elementos) {
  list<int> l;
  CriaList3(5, 13, 49, &l);
  l.insert(l.begin(), 17);
  string esperado("{17 5 13 49}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* list<Type>::insert(Node* position, Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_final_da_lista_vazia) {
  list<int> l;
  l.insert(l.end(), 10);
  string esperado("{10}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* list<Type>::insert(Node* position, Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_final_da_lista_com_um_elemento) {
  list<int> l;
  CriaList1(45, &l);
  l.insert(l.end(), -9);
  string esperado("{45 -9}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* list<Type>::insert(Node* position, Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_final_da_lista_com_varios_elementos) {
  list<int> l;
  CriaList3(8, 22, -7, &l);
  l.insert(l.end(), 1);
  string esperado("{8 22 -7 1}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* list<Type>::insert(Node* position, Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}
TEST_F(Teste, Testar_metodo_insert_antes_do_segundo_elemento) {
  list<int> l;
  CriaList3(12, 8, -1, &l);
  list<int>::iterator it = l.begin();
  ++it;
  l.insert(it, 22);
  string esperado("{12 22 8 -1}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* list<Type>::insert(Node* position, Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_antes_do_ultimo_elemento) {
  list<int> l;
  CriaList3(13, 9, 0, &l);
  list<int>::iterator it = l.begin();
  ++it;
  ++it;
  l.insert(it, 23);
  string esperado("{13 9 23 0}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* Node* list<Type>::insert(Node* position, Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Testar_metodo_erase_em_uma_lista_com_um_elemento) {
  list<int> l;
  CriaList1(8, &l);
  l.erase(l.begin());
  string esperado("{}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void list<Type>::erase(Node* position) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_uma_lista_com_varios_elemento) {
  list<int> l;
  CriaList3(8, 0, -3, &l);
  list<int>::iterator it = l.begin();
  ++it;
  l.erase(it);
  string esperado("{8 -3}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void list<Type>::erase(Node* position) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_merge_de_lista_vazia_com_lista_nao_vazia) {
  list<int> l1;
  CriaList3(15, 13, 2, &l1);
  list<int> l2;
  l2.merge(l1);
  string esperado("{15 13 2}");
  string atual = PrintList(l2);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void list<Type>::merge(list<Type>) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_merge_de_lista_nao_vazia_com_lista_vazia) {
  list<int> l1;
  list<int> l2;
  CriaList3(12, 125, 32, &l2);
  l2.merge(l1);
  string esperado("{12 125 32}");
  string atual = PrintList(l2);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void list<Type>::merge(list<Type>) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_merge_com_duas_listas_nao_vazias) {
  list<int> l1;
  list<int> l2;
  CriaList3(1, 2, 3, &l1);
  CriaList3(4, 5, 6, &l2);
  l2.merge(l1);
  string esperado("{4 5 6 1 2 3}");
  string atual = PrintList(l2);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void list<Type>::merge(list<Type>) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_com_lista_vazia) {
  list<int> l;
  l.clear();
  string esperado("{}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void list<Type>::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_lista_nao_vazia) {
  list<int> l;
  CriaList3(1, 4, 7, &l);
  l.clear();
  string esperado("{}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void list<Type>::clear() *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

#endif  // LIST_TEST_LIST_TEST_H_
