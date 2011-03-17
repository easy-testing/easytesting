// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
#ifndef TESTE_H_
#define TESTE_H_

#include "easytesting/list/src/list.h"

#include <sstream>
#include <string>

#include "easytesting/gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
// protected:
//  // Retorna uma string no formato {a, b, c, d...}.
//  string PrintList(List& l) {
//    stringstream output;
//    output << "{";
//    for (Node* iter = l.begin() ; iter != l.end() ; iter = iter->next()) {
//      output << iter->value();
//      if(iter->next() != l.end()) {
//        output << ", ";
//      }
//    }
//    output << "}";
//    return output.str();
//  }
//
//  // Preenche a lista passada como parametro com 1 numero.
//  // 'l' deve ser uma lista vazia.
//  void CriaList1 (Type x, List *l) {
//    l->first_ = new Node(x, l->end());
//  }
//
//  //Preenche a lista passada como parametro com 3 numeros.
//  // 'l' deve ser uma lista vazia.
//  void CriaList3(Type n1, Type n2, Type n3, List* l) {
//    l->first_ = new Node(n1, new Node(n2, new Node(n3, l->end())));
//  }
};

//TEST_F(Teste, Testar_metodo_empty) {
//  List l1;
//  ASSERT_TRUE(l1.empty())
//    << "-------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : bool List::empty()\n"
//    << "A lista esta vazia e a funcao retornou FALSE."
//    << "-------------------------------------------------------------------\n";
//
//  List l2;
//  CriaList1(131, &l2);
//  ASSERT_FALSE(l2.empty())
//    << "-------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : bool List::empty()\n"
//    << "A lista tem pelo menos um elemento e a funcao retornou TRUE."
//    << "-------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_front_em_lista_com_um_elemento) {
//  List l;
//  CriaList1(2, &l);
//  Type esperado = 2;
//  ASSERT_FLOAT_EQ(esperado, l.front())
//  << "-----------------------------------------------\n"
//  << "Erro na chamada da funcao : Type List::front()\n"
//  << "Valor esperado  : " << esperado << "\n"
//  << "Valor retornado : " << l.front() << "\n"
//  << "-----------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_front_em_lista_com_mais_de_um_elemento) {
//  List l;
//  CriaList3(3, 7, 8, &l);
//  Type esperado = 3;
//  Type atual = l.front();
//  ASSERT_FLOAT_EQ(esperado, atual)
//  << "-----------------------------------------------\n"
//  << "Erro na chamada da funcao : Type List::front()\n"
//  << "Valor esperado  : " << esperado << "\n"
//  << "Valor retornado : " << atual << "\n"
//  << "-----------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_back_em_lista_com_um_elemento) {
//  List l;
//  CriaList1(3, &l);
//  Type esperado = 3;
//  Type atual = l.back();
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-----------------------------------------------\n"
//    << "Erro na chamada da funcao : Type List::back()\n"
//    << "Valor esperado  : " << esperado << "\n"
//    << "Valor retornado : " << atual << "\n"
//    << "-----------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_back_em_lista_com_mais_de_um_elemento) {
//  List l;
//  CriaList3(4, 5, 7, &l);
//  Type esperado = 7;
//  Type atual = l.back();
//  ASSERT_FLOAT_EQ(esperado, atual)
//    << "-----------------------------------------------\n"
//    << "Erro na chamada da funcao : Type List::back()\n"
//    << "Valor esperado  : " << esperado << "\n"
//    << "Valor retornado : " << atual << "\n"
//    << "-----------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_size_em_lista_vazia) {
//  List l;
//  Type esperado = 0;
//  Type atual = l.size();
//  ASSERT_EQ(esperado, atual)
//    << "-----------------------------------------------\n"
//    << "Erro na chamada da funcao : int List::size()\n"
//    << "Valor esperado  : " << esperado << "\n"
//    << "Valor retornado : " << atual << "\n"
//    << "-----------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_size_em_lista_com_um_elemento) {
//  List l;
//  CriaList1(2, &l);
//  Type esperado = 1;
//  Type atual = l.size();
//  ASSERT_EQ(esperado, atual)
//    << "-----------------------------------------------\n"
//    << "Erro na chamada da funcao : int List::size()\n"
//    << "Valor esperado  : " << esperado << "\n"
//    << "Valor retornado : " << atual << "\n"
//    << "-----------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_size_em_lista_com_varios_elementos) {
//  List l;
//  CriaList3(10, 3, 0, &l);
//  Type esperado = 3;
//  Type atual = l.size();
//  ASSERT_EQ(esperado, atual)
//    << "-----------------------------------------------\n"
//    << "Erro na chamada da funcao : int List::size()\n"
//    << "Valor esperado  : " << esperado << "\n"
//    << "Valor retornado : " << atual << "\n"
//    << "-----------------------------------------------\n";
//}
//
//// Para realizar a comparacao da lista esperada para a lista do aluno, utilizei a
//// comparacao da classe string (imprimir a lista do aluno em uma string).
//TEST_F(Teste, Testar_metodo_insert_no_inicio_da_lista_vazia) {
//  List l;
//  l.insert(l.begin(), 10);
//  string esperado("{10}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::insert(Node* position, Type x)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_insert_no_inicio_da_lista_com_um_elemento) {
//  List l;
//  CriaList1(22, &l);
//  l.insert(l.begin(), 12);
//  string esperado("{12, 22}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::insert(Node* position, Type x)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_insert_no_inicio_da_lista_com_varios_elementos) {
//  List l;
//  CriaList3(5, 13, 49, &l);
//  l.insert(l.begin(), 17);
//  string esperado("{17, 5, 13, 49}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::insert(Node* position, Type x)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_insert_no_final_da_lista_vazia) {
//  List l;
//  l.insert(l.end(), 10);
//  string esperado("{10}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::insert(Node* position, Type x)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_insert_no_final_da_lista_com_um_elemento) {
//  List l;
//  CriaList1(45, &l);
//  l.insert(l.end(), -9);
//  string esperado("{45, -9}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::insert(Node* position, Type x)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_insert_no_final_da_lista_com_varios_elementos) {
//  List l;
//  CriaList3(8, 22, -7, &l);
//  l.insert(l.end(), 1);
//  string esperado("{8, 22, -7, 1}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::insert(Node* position, Type x)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//TEST_F(Teste, Testar_metodo_insert_antes_do_segundo_elemento) {
//  List l;
//  CriaList3(12, 8, -1, &l);
//  l.insert(l.begin()->next(), 22);
//  string esperado("{12, 22, 8, -1}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::insert(Node* position, Type x)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_insert_antes_do_ultimo_elemento) {
//  List l;
//  CriaList3(13, 9, 0, &l);
//  l.insert(l.begin()->next()->next(), 23);
//  string esperado("{13, 9, 23, 0}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::insert(Node* position, Type x)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//
//TEST_F(Teste, Testar_metodo_erase_em_uma_lista_com_um_elemento) {
//  List l;
//  CriaList1(8, &l);
//  string esperado("{}");
//  l.erase(l.begin());
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::erase(Node* position)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_erase_em_uma_lista_com_varios_elemento) {
//  List l;
//  CriaList3(8, 0, -3, &l);
//  string esperado("{8, -3}");
//  l.erase(l.begin()->next());
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::erase(Node* position)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_assign_com_lista_vazia) {
//  List l1;
//  List l2;
//  CriaList3(8, 12, 4, &l2);
//  l2.assign(l1);
//  string esperado("{}");
//  ASSERT_EQ(esperado, PrintList(l2))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::assign(List& l)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l2) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_assign_com_lista_nao_vazia) {
//  List l1;
//  CriaList3(15, 2, -1, &l1);
//  List l2;
//  CriaList1(10, &l2);
//  string esperado("{15, 2, -1}");
//  l2.assign(l1);
//  ASSERT_EQ(esperado, PrintList(l2))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::assign(List& l)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l2) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_merge_de_lista_vazia_com_lista_nao_vazia) {
//  List l1;
//  CriaList3(15, 13, 2, &l1);
//  List l2;
//  l2.merge(l1);
//  string esperado("{15, 13, 2}");
//  ASSERT_EQ(esperado, PrintList(l2))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::merge(List& l)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l2) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_merge_de_lista_nao_vazia_com_lista_vazia) {
//  List l1;
//  List l2;
//  CriaList3(12, 125, 32, &l2);
//  l2.merge(l1);
//  string esperado("{12, 125, 32}");
//  ASSERT_EQ(esperado, PrintList(l2))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::merge(List& l)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l2) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_merge_com_duas_listas_nao_vazias) {
//  List l1;
//  List l2;
//  CriaList3(1, 2, 3, &l1);
//  CriaList3(4, 5, 6, &l2);
//  l2.merge(l1);
//  string esperado("{4, 5, 6, 1, 2, 3}");
//  ASSERT_EQ(esperado, PrintList(l2))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::merge(List& l)\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l2) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_clear_com_lista_vazia) {
//  List l;
//  l.clear();
//  string esperado("{}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::clear()\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}
//
//TEST_F(Teste, Testar_metodo_clear_lista_nao_vazia) {
//  List l;
//  CriaList3(1, 4, 7, &l);
//  l.clear();
//  string esperado("{}");
//  ASSERT_EQ(esperado, PrintList(l))
//    << "----------------------------------------------------------------------\n"
//    << "Erro na chamada da funcao : void List::clear()\n"
//    << "Lista esperada : " << esperado << "\n"
//    << "Lista atual    : " << PrintList(l) << "\n"
//    << "----------------------------------------------------------------------\n";
//}

#endif  // TESTE_H_
