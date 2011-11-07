// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_DEQUE_TEST_DEQUE_TEST_H_
#define BRANCHES_GABARITOS_DEQUE_TEST_DEQUE_TEST_H_

#include <sstream>
#include <string>

#include "deque/src/deque.h"
#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna uma string no formato {a b c d...}.
  string PrintDeque(deque& l) {
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

  // Retorna um ponteiro para o primeiro elemento do deque.
  node* Begin(deque& l) {
    return l.end_->next;
  }

  // Retorna um ponteiro para o elemento seguinte ao último elemento do deque.
  node* End(deque& l) {
    return l.end_;
  }

  // Preenche o deque passado como parâmetro com um único número.
  // 'q' deve ser um deque vazio.
  void CriaList1(int x, deque *q) {
    q->end_->prev = q->end_->next = NewNode(x, q->end_, q->end_);
    q->size_ = 1;
  }

  // Preenche o deque passado como parametro com 3 números.
  // 'd' deve ser umo deque vazio.
  void CriaList3(int x1, int x2, int x3, deque* d) {
    d->end_->next = NewNode(x1, d->end_, NULL);
    d->end_->next->next = NewNode(x2, d->end_->next, NULL);
    d->end_->next->next->next = d->end_->prev =
        NewNode(x3, d->end_->next->next, d->end_);
    d->size_ = 3;
  }
};

TEST_F(Teste, Testar_metodo_empty) {
  deque l1;
  ASSERT_TRUE(l1.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* bool deque::empty() *\n"
      << "------------------------------------------------------------------\n"
      << "A deque esta vazio e a funcao retornou FALSE.\n"
      << "------------------------------------------------------------------\n";

  deque l2;
  CriaList3(12, 14, 15, &l2);
  ASSERT_FALSE(l2.empty())
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* bool deque::empty() *\n"
      << "------------------------------------------------------------------\n"
      << "Erro na chamada da funcao : bool deque::empty()\n"
      << "A deque tem pelo menos um elemento e a funcao retornou TRUE."
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_deque_com_um_elemento) {
  deque l;
  CriaList1(2, &l);
  int esperado = 2;
  int atual = l.front();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* type deque::front() *\n"
      << "------------------------------------------------------------------\n"
      << "deque = " << PrintDeque(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_deque_com_mais_de_um_elemento) {
  deque l;
  CriaList3(3, 7, 8, &l);
  int esperado = 3;
  int atual = l.front();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* type deque::front() *\n"
      << "------------------------------------------------------------------\n"
      << "deque = " << PrintDeque(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_deque_com_um_elemento) {
  deque l;
  CriaList1(3, &l);
  int esperado = 3;
  int atual = l.back();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* type deque::back() *\n"
      << "------------------------------------------------------------------\n"
      << "deque = " << PrintDeque(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_deque_com_mais_de_um_elemento) {
  deque l;
  CriaList3(4, 5, 7, &l);
  int esperado = 7;
  int atual = l.back();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* type deque::back() *\n"
      << "------------------------------------------------------------------\n"
      << "deque = " << PrintDeque(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_deque_vazio) {
  deque l;
  int esperado = 0;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* int deque::size() *\n"
      << "------------------------------------------------------------------\n"
      << "deque = " << PrintDeque(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_deque_com_um_elemento) {
  deque l;
  CriaList1(2, &l);
  int esperado = 1;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* int deque::size() *\n"
      << "------------------------------------------------------------------\n"
      << "deque = " << PrintDeque(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_deque_com_varios_elementos) {
  deque l;
  CriaList3(10, 3, 0, &l);
  int esperado = 3;
  int atual = l.size();
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* int deque::size() *\n"
      << "------------------------------------------------------------------\n"
      << "deque = " << PrintDeque(l) << "\n\n"
      << "Valor esperado  : " << esperado << "\n"
      << "Valor retornado : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_back) {
  deque l;
  CriaList3(10, 3, 0, &l);
  l.push_back(2);
  string esperado = "{10 3 0 2}";
  string atual = PrintDeque(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void deque::push_back(type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada: " << esperado << "\n"
      << "Lista atual: " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_back) {
  deque l;
  CriaList3(10, 3, 0, &l);
  l.pop_back();
  string esperado = "{10 3}";
  string atual = PrintDeque(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void deque::pop_back(type x) *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada: " << esperado << "\n"
      << "Lista atual: " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_com_deque_vazio) {
  deque l;
  l.clear();
  string esperado("{}");
  string atual = PrintDeque(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void deque::clear() *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_clear_deque_nao_vazio) {
  deque l;
  CriaList3(1, 4, 7, &l);
  l.clear();
  string esperado("{}");
  string atual = PrintDeque(l);
  ASSERT_EQ(esperado, atual)
      << "------------------------------------------------------------------\n"
      << "Erro na funcao:  "
      << "* void deque::clear() *\n"
      << "------------------------------------------------------------------\n"
      << "Lista esperada : " << esperado << "\n"
      << "Lista atual    : " << atual << "\n"
      << "------------------------------------------------------------------\n";
}

#endif  // BRANCHES_GABARITOS_DEQUE_TEST_DEQUE_TEST_H_
