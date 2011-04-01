// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef QUEUE_TEST_QUEUE_TEST_H_
#define QUEUE_TEST_QUEUE_TEST_H_

#include "queue/src/queue.h"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

using std::string;
using std::stringstream;

// Classe base dos testes.
class Teste : public testing::Test {
 protected:
  // Retorna uma string no formato {a b c d...}.
  string PrintQueue(queue<int>& f) {
    stringstream output;
    output << "{";
    for (Node<int>* i = f.list_.begin() ; i != f.list_.end() ; i = i->next) {
      if (i == f.list_.begin())
        output << i->key;
      else
        output << " " << i->key;
    }
    output << "}";
    return output.str();
  }

  // Preenche a queue passada como parametro com 1 numero.
  // 'f' deve ser uma queue vazia.
  void CriaQueue1(int x, queue<int>& f) {
    //l->end_->prev = l->end_->next = new Node<int>(x, l->end_, l->end_);
    f.list_.end_->prev = f.list_.end_->next = new Node<int>(x, f.list_.end_, f.list_.end_);
  }

  // Preenche a queue passada como parametro com 3 numeros.
  // 'f' deve ser uma lista vazia.
  void CriaQueue3(int x1, int x2, int x3, queue<int>& f) {
    f.list_.end_->next = new Node<int>(x1, f.list_.end_, NULL);
    f.list_.end_->next->next = new Node<int>(x2, f.list_.end_->next, NULL);
    f.list_.end_->next->next->next = f.list_.end_->prev =
        new Node<int>(x3, f.list_.end_->next->next, f.list_.end_);
  }
};

TEST_F(Teste, Testar_metodo_empty) {
  queue<int> f1;
  ASSERT_TRUE(f1.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool queue<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A queue esta vazia e a funcao retornou FALSE."
    << "-------------------------------------------------------------------\n";

  queue<int> f2;
  CriaQueue3(12, 14, 15, f2);
  ASSERT_FALSE(f2.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool queue<Type>::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A queue tem pelo menos um elemento e a funcao retornou TRUE."
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_queue_com_um_elemento) {
  queue<int> f;
  CriaQueue1(2, f);
  int esperado = 2;
  int atual = f.front();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type queue<Type>::front() *\n"
  << "-------------------------------------------------------------------\n"
  << "     " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_queue_com_mais_de_um_elemento) {
  queue<int> f;
  CriaQueue3(3, 7, 8, f);
  int esperado = 3;
  int atual = f.front();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type queue<Type>::front() *\n"
  << "-------------------------------------------------------------------\n"
  << "     " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_queue_com_um_elemento) {
  queue<int> f;
  CriaQueue1(-4, f);
  int esperado = -4;
  int atual = f.back();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type queue<Type>::back() *\n"
  << "-------------------------------------------------------------------\n"
  << "     " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_queue_com_mais_de_um_elemento) {
  queue<int> f;
  CriaQueue3(8, 5, 1, f);
  int esperado = 1;
  int atual = f.back();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* Type queue<Type>::back() *\n"
  << "-------------------------------------------------------------------\n"
  << "     " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_queue_vazia) {
  queue<int> f;
  int esperado = 0;
  int atual = f.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int queue<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintQueue(f) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_queue_com_um_elemento) {
  queue<int> f;
  CriaQueue1(2, f);
  int esperado = 1;
  int atual = f.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int queue<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintQueue(f) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_queue_com_varios_elementos) {
  queue<int> f;
  CriaQueue3(10, 3, 0, f);
  int esperado = 3;
  int atual = f.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int queue<Type>::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "     " << PrintQueue(f) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

// Para realizar a comparacao da queue esperada para a queue do aluno, foi
// necessario utilizar a comparacao da classe string (imprimir a queue do
// aluno em uma string).
TEST_F(Teste, Testar_metodo_push_em_queue_vazia) {
  queue<int> f;
  f.push(10);
  string esperado("{10}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue<Type>::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_queue_com_um_elemento) {
  queue<int> f;
  CriaQueue1(22, f);
  f.push(12);
  string esperado("{22 12}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue<Type>::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_queue_com_varios_elementos) {
  queue<int> f;
  CriaQueue3(5, 13, 49, f);
  f.push(17);
  string esperado("{5 13 49 17}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue<Type>::push(Type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_queue_com_um_elemento) {
  queue<int> f;
  CriaQueue1(8, f);
  f.pop();
  string esperado("{}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue<Type>::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_queue_com_varios_elemento) {
  queue<int> f;
  CriaQueue3(8, 0, -3, f);
  f.pop();
  string esperado("{0 -3}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue<Type>::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Lista esperada : " << esperado << "\n"
    << "Lista atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}
#endif  // QUEUE_TEST_QUEUE_TEST_H_
