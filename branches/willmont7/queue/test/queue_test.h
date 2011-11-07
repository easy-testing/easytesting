// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_QUEUE_TEST_QUEUE_TEST_H_
#define BRANCHES_GABARITOS_QUEUE_TEST_QUEUE_TEST_H_

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
  string PrintQueue(queue& f) {
    stringstream output;
    output << "{";
    for (node* i = f.end_->next; i != f.end_ ; i = i->next) {
      if (i == f.end_->next)
        output << i->key;
      else
        output << " " << i->key;
    }
    output << "}";
    return output.str();
  }

  // Preenche a queue passada como parametro com 1 numero.
  // 'f' deve ser uma queue vazia.
  void CriaQueue1(string x, queue& f) {
    f.end_->prev = f.end_->next = NewNode(x, f.end_, f.end_);
    f.size_ = 1;
  }

  // Preenche a queue passada como parametro com "3" numeros.
  // 'f' deve ser uma lista vazia.
  void CriaQueue3(string x1, string x2, string x3, queue& f) {
    f.end_->next = NewNode(x1, f.end_, NULL);
    f.end_->next->next = NewNode(x2, f.end_->next, NULL);
    f.end_->next->next->next = f.end_->prev =
        NewNode(x3, f.end_->next->next, f.end_);
    f.size_ = 3;
  }
};

TEST_F(Teste, Testar_metodo_empty) {
  queue f1;
  ASSERT_TRUE(f1.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool queue::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A queue esta vazia e a funcao retornou FALSE.\n"
    << "-------------------------------------------------------------------\n";

  queue f2;
  CriaQueue3("12", "14", "15", f2);
  ASSERT_FALSE(f2.empty())
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* bool queue::empty() *\n"
    << "-------------------------------------------------------------------\n"
    << "A queue tem pelo menos um elemento e a funcao retornou TRUE.\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_queue_com_um_elemento) {
  queue f;
  CriaQueue1("2", f);
  string esperado = "2";
  string atual = f.front();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* type queue::front() *\n"
  << "-------------------------------------------------------------------\n"
  << "fila = " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_front_em_queue_com_mais_de_um_elemento) {
  queue f;
  CriaQueue3("3", "7", "8", f);
  string esperado = "3";
  string atual = f.front();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* type queue::front() *\n"
  << "-------------------------------------------------------------------\n"
  << "fila = " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_queue_com_um_elemento) {
  queue f;
  CriaQueue1("-4", f);
  string esperado = "-4";
  string atual = f.back();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* type queue::back() *\n"
  << "-------------------------------------------------------------------\n"
  << "fila = " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_back_em_queue_com_mais_de_um_elemento) {
  queue f;
  CriaQueue3("8", "5", "1", f);
  string esperado = "1";
  string atual = f.back();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao:  "
  << "* type queue::back() *\n"
  << "-------------------------------------------------------------------\n"
  << "fila = " << PrintQueue(f) << "\n\n"
  << "Valor esperado  : " << esperado << "\n"
  << "Valor retornado : " << atual << "\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_queue_vazia) {
  queue f;
  int esperado = 0;
  int atual = f.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* string queue::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "fila = " << PrintQueue(f) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_queue_com_um_elemento) {
  queue f;
  CriaQueue1("2", f);
  int esperado = 1;
  int atual = f.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int queue::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "fila = " << PrintQueue(f) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_size_em_queue_com_varios_elementos) {
  queue f;
  CriaQueue3("10", "3", "0", f);
  int esperado = 3;
  int atual = f.size();
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* int queue::size() *\n"
    << "-------------------------------------------------------------------\n"
    << "fila = " << PrintQueue(f) << "\n\n"
    << "Valor esperado  : " << esperado << "\n"
    << "Valor retornado : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

// Para realizar a comparacao da queue esperada para a queue do aluno, foi
// necessario utilizar a comparacao da classe string (imprimir a queue do
// aluno em uma string).
TEST_F(Teste, Testar_metodo_push_em_queue_vazia) {
  queue f;
  f.push("10");
  string esperado("{10}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue::push(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_queue_com_um_elemento) {
  queue f;
  CriaQueue1("22", f);
  f.push("12");
  string esperado("{22 12}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue::push(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_push_em_queue_com_varios_elementos) {
  queue f;
  CriaQueue3("5", "13", "49", f);
  f.push("17");
  string esperado("{5 13 49 17}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue::push(type x) *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_queue_com_um_elemento) {
  queue f;
  CriaQueue1("8", f);
  f.pop();
  string esperado("{}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Testar_metodo_pop_em_queue_com_varios_elemento) {
  queue f;
  CriaQueue3("8", "0", "-3", f);
  f.pop();
  string esperado("{0 -3}");
  string atual = PrintQueue(f);
  ASSERT_EQ(esperado, atual)
    << "-------------------------------------------------------------------\n"
    << "Erro na funcao:  "
    << "* void queue::pop() *\n"
    << "-------------------------------------------------------------------\n"
    << "Fila esperada : " << esperado << "\n"
    << "Fila atual    : " << atual << "\n"
    << "-------------------------------------------------------------------\n";
}
#endif  // BRANCHES_GABARITOS_QUEUE_TEST_QUEUE_TEST_H_
