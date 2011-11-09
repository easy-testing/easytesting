// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_LIST_TEST_LIST_TEST_H_
#define BRANCHES_GABARITOS_LIST_TEST_LIST_TEST_H_

#include <sstream>
#include <string>

#include "list/src/list.h"
#include "list/src/node.h"
#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Cria um nó sentinela.
  node* NewSentinel() {
    node* aux = new node();
    aux->prev = aux->next = aux;
    return aux;
  }

  // Cria uma nó cuja chave é k, o nó anterior é l, e o nó posterior é r.
  node* NewNode(type k, node* l, node* r) {
    node* aux = new node();
    aux->key = k;
    aux->prev = l;
    aux->next = r;
    return aux;
  }

  // Retorna um ponteiro para o primeiro elemento da lista.
  node* Begin(list& l) {
    return l.end_->next;
  }

  // Retorna um ponteiro para o elemento seguinte ao ultimo elemento da lista.
  node* End(list& l) {
    return l.end_;
  }

  // Retorna uma string no formato {a b c d...}.
  string PrintList(list& l) {
    stringstream output;
    output << "{";
    for (node* i = Begin(l) ; i != End(l) ; i = i->next) {
      if (i == Begin(l))
        output << i->key;
      else
        output << " " << i->key;
    }
    output << "}";
    return output.str();
  }

  // Preenche a lista passada como parametro com 1 numero.
  // 'l' deve ser uma lista vazia.
  void CriaList1(string x, list *l) {
    l->end_->prev = l->end_->next = NewNode(x, l->end_, l->end_);
    l->size_ = 1;
  }

  // Preenche a lista passada como parametro com 3 numeros.
  // 'l' deve ser uma lista vazia.
  void CriaList3(string x1, string x2, string x3, list* l) {
    l->end_->next = NewNode(x1, l->end_, NULL);
    l->end_->next->next = NewNode(x2, l->end_->next, NULL);
    l->end_->next->next->next = l->end_->prev =
        NewNode(x3, l->end_->next->next, l->end_);
    l->size_ = 3;
  }
};

TEST_F(Teste, Testar_metodo_empty) {
  list l1;
  ASSERT_TRUE(l1.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* bool list::empty() *\n"
      << "------------------------------------------------------------------\n"
      << "A lista esta vazia e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";

  list l2;
  CriaList3("12", "14", "15", &l2);
  ASSERT_FALSE(l2.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* bool list::empty() *\n"
      << "------------------------------------------------------------------\n"
      << "Erro na chamada da funcao : bool list::empty()\n"
      << "A lista tem pelo menos um elemento e a funcao retornou TRUE."
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_lista_com_um_elemento) {
  list l;
  CriaList1("2", &l);
  string esperado = "2";
  string atual = l.front();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* type list::front() *\n"
      << "------------------------------------------------------------------\n"
      << "lista = " << PrintList(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_lista_com_mais_de_um_elemento) {
  list l;
  CriaList3("3", "7", "8", &l);
  string esperado = "3";
  string atual = l.front();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* type list::front() *\n"
      << "------------------------------------------------------------------\n"
      << "lista = " << PrintList(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_lista_com_um_elemento) {
  list l;
  CriaList1("3", &l);
  string esperado = "3";
  string atual = l.back();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* type list::back() *\n"
      << "------------------------------------------------------------------\n"
      << "lista = " << PrintList(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_lista_com_mais_de_um_elemento) {
  list l;
  CriaList3("4", "5", "7", &l);
  string esperado = "7";
  string atual = l.back();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* type list::back() *\n"
      << "------------------------------------------------------------------\n"
      << "lista = " << PrintList(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_lista_vazia) {
  list l;
  int esperado = 0;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* int list::size() *\n"
      << "------------------------------------------------------------------\n"
      << "lista = " << PrintList(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_lista_com_um_elemento) {
  list l;
  CriaList1("2", &l);
  int esperado = 1;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* int list::size() *\n"
      << "------------------------------------------------------------------\n"
      << "lista = " << PrintList(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_lista_com_varios_elementos) {
  list l;
  CriaList3("10", "3", "0", &l);
  int esperado = 3;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* int list::size() *\n"
      << "------------------------------------------------------------------\n"
      << "lista = " << PrintList(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_back) {
  list l;
  CriaList3("10", "3", "0", &l);
  l.push_back("2");
  string esperado = "{10 3 0 2}";
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void list::push_back(type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada: " << esperado << "\n"
      << "Lista atual: " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_back) {
  list l;
  CriaList3("10", "3", "0", &l);
  l.pop_back();
  string esperado = "{10 3}";
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void list::pop_back(type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada: " << esperado << "\n"
      << "Lista atual: " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

// Para realizar a comparacao da lista esperada para a lista do aluno, foi
// necessario utilizar a comparacao da classe string (imprimir a lista do
// aluno em uma string).
TEST_F(Teste, Testar_metodo_insert_no_inicio_da_lista_vazia) {
  list l;
  l.insert(Begin(l), "10");
  string esperado("{10}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* node* list::insert(node* p, type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_inicio_da_lista_com_um_elemento) {
  list l;
  CriaList1("22", &l);
  l.insert(Begin(l), "12");
  string esperado("{12 22}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* node* list::insert(node* p, type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_inicio_da_lista_com_varios_elementos) {
  list l;
  CriaList3("5", "13", "49", &l);
  l.insert(Begin(l), "17");
  string esperado("{17 5 13 49}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* node* list::insert(node* p, type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_final_da_lista_vazia) {
  list l;
  l.insert(End(l), "10");
  string esperado("{10}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* node* list::insert(node* p, type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_final_da_lista_com_um_elemento) {
  list l;
  CriaList1("45", &l);
  l.insert(End(l), "-9");
  string esperado("{45 -9}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* node* list::insert(node* p, type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_no_final_da_lista_com_varios_elementos) {
  list l;
  CriaList3("8", "22", "-7", &l);
  l.insert(End(l), "1");
  string esperado("{8 22 -7 1}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* node* list::insert(node* p, type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}
TEST_F(Teste, Testar_metodo_insert_antes_do_segundo_elemento) {
  list l;
  CriaList3("12", "8", "-1", &l);
  node* it = Begin(l);
  it = it->next;
  l.insert(it, "22");
  string esperado("{12 22 8 -1}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* node* list::insert(node* p, type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_insert_antes_do_ultimo_elemento) {
  list l;
  CriaList3("13", "9", "0", &l);
  node* it = Begin(l);
  it = it->next;
  it = it->next;
  l.insert(it, "23");
  string esperado("{13 9 23 0}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* node* list::insert(node* p, type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}


TEST_F(Teste, Testar_metodo_erase_em_uma_lista_com_um_elemento) {
  list l;
  CriaList1("8", &l);
  l.erase(Begin(l));
  string esperado("{}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void list::erase(node* p) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_erase_em_uma_lista_com_varios_elemento) {
  list l;
  CriaList3("8", "0", "-3", &l);
  node* it = Begin(l);
  it = it->next;
  l.erase(it);
  string esperado("{8 -3}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void list::erase(node* p) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_merge_de_lista_vazia_com_lista_nao_vazia) {
  list l1;
  CriaList3("15", "13", "2", &l1);
  list l2;
  l2.merge(l1);
  string esperado("{15 13 2}");
  string atual = PrintList(l2);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void list::merge(list) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_merge_de_lista_nao_vazia_com_lista_vazia) {
  list l1;
  list l2;
  CriaList3("12", "125", "32", &l2);
  l2.merge(l1);
  string esperado("{12 125 32}");
  string atual = PrintList(l2);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void list::merge(list) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_merge_com_duas_listas_nao_vazias) {
  list l1;
  list l2;
  CriaList3("1", "2", "3", &l1);
  CriaList3("4", "5", "6", &l2);
  l2.merge(l1);
  string esperado("{4 5 6 1 2 3}");
  string atual = PrintList(l2);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void list::merge(list) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_com_lista_vazia) {
  list l;
  l.clear();
  string esperado("{}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void list::clear() *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_lista_nao_vazia) {
  list l;
  CriaList3("1", "4", "7", &l);
  l.clear();
  string esperado("{}");
  string atual = PrintList(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void list::clear() *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

#endif  // BRANCHES_GABARITOS_LIST_TEST_LIST_TEST_H_
