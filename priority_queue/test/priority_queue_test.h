// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_PRIORITY_QUEUE_TEST_PRIORITY_QUEUE_TEST_H_
#define TRUNK_PRIORITY_QUEUE_TEST_PRIORITY_QUEUE_TEST_H_

#include <cstdlib>
#include <sstream>
#include <string>

#include "../doctest/doctest.h"
#include "src/priority_queue.h"

using std::string;
using std::stringstream;

// Define como os elementos da árvore serão organizados na memória.
struct Node {
  SType key;  // Valor da chave do nó.
  int copies;  // Número de cópia da chave na fila.
  Node* left;  // Ponteiro para o nó a esquerda.
  Node* right;  // Ponteiro para o nó a direita.
  Node* parent;  // Ponteiro para o nó acima.
};


// Retorna a raiz da árvore de s.
Node* root(const priority_queue& s) {
  return s.root_;
}

// Retorna um ponteiro para o primeiro elemento da fila de prioridades.
Node* begin(const priority_queue& s) {
  Node* x = s.root_;
  if (x != NULL) {
    while (x->left != NULL) {
      x = x->left;
    }
  }
  return x;
}

// Retorna um ponteiro para o elemento seguinte ao último elemento
// da fila de prioridades.
Node* end(const priority_queue& s) {
  return NULL;
}

// Retorna o número de elementos na fila de prioridades.
int size(const priority_queue& s) {
  return s.size_;
}

Node* Push(SType k, priority_queue* s) {
  Node* y = NULL;
  Node* x = s->root_;
  while (x != NULL) {
    y = x;
    if (k == x->key) {
      x->copies++;
      return x;
    } else if (k < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  Node* z = new Node;
  z->key = k;
  z->copies = 1;
  z->parent = y;
  z->left = z->right = NULL;
  if (y == NULL) {
    s->root_ = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else  {
    y->right = z;
  }
  s->size_++;
  return z;
}

// Cria uma fila de prioridades com três elementos.
void CriaFila(SType x1, SType x2, SType x3, priority_queue* s) {
  Push(x2, s);
  Push(x1, s);
  Push(x3, s);
}

// Retorna uma string contendo os elementos da árvore no formato
// { <k1,v1> <k2,v2> ... <kn,vn> }.
string TreeToString(Node* root) {
  if (root == NULL) {
    return "";
  } else {
    stringstream out;
    out << TreeToString(root->left);
    for (int i = 0; i < root->copies; ++i) {
      out << root->key << " ";
    }
    out << TreeToString(root->right);
    return out.str();
  }
}

string ToString(const priority_queue& s) {
  stringstream out;
  out << "[ ";
  out << TreeToString(s.root_);
  out << "]";
  return out.str();
}


TEST_CASE("Testa_construtor_vazio") {
  priority_queue atual;
  CHECK_EQ(0, size(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: priority_queue::priority_queue()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um fila de prioridades vazia, size_ = 0.\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_UNARY(root(atual) == NULL);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro no construtor: priority_queue::priority_queue()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Em um fila de prioridades vazia, root_ = NULL.\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Size_para_fila_de_prioridades_vazia") {
  priority_queue s;
  int esperado = 0;
  int atual = s.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int priority_queue::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Size_para_fila_de_prioridades_nao_vazia") {
  priority_queue s;
  CriaFila("1", "2", "3", &s);
  int esperado = 3;
  int atual = s.size();
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: int priority_queue::size()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << ToString(s) << "\n");
  INFO(" \"s.sise()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Empty_com_fila_de_prioridades_vazia") {
  priority_queue s;
  CHECK_UNARY(s.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool priority_queue::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" a fila de prioridades esta vazia e a funcao retornou FALSE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Empty_com_fila_de_prioridades_nao_vazio") {
  priority_queue s;
  CriaFila("1", "2", "3", &s);
  CHECK_UNARY_FALSE(s.empty());
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: bool priority_queue::empty() \n");
  INFO("------------------------------------------------------------------\n");
  INFO(" a fila de prioridades tem pelo menos um elemento\n");
  INFO(" e a funcao retornou TRUE.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Top_na_raiz") {
  priority_queue s;
  Push("10", &s);
  SType atual = s.top();
  SType esperado = "10";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: SType priority_queue::top()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << "[ 10 ]" << "\n");
  INFO(" \"s.top()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Top_nao_raiz") {
  priority_queue s;
  CriaFila("1", "2", "3", &s);
  SType atual = s.top();
  SType esperado = "1";
  CHECK_EQ(esperado, atual);
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: SType priority_queue::top()\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" s = " << "[ 1 2 3 ]" << "\n");
  INFO(" \"s.top()\" retornou: " << atual << "\n");
  INFO(" Valor esperado: " << esperado << "\n");
  INFO("-------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Push_em_fila_de_prioridades_vazia") {
  priority_queue s;
  s.push("10");
  string atual = ToString(s);
  string esperado("[ 10 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::push(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = [ ] \n");
  INFO(" \"s.push(10)\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Push_em_fila_de_prioridades_nao_vazia") {
  priority_queue s;
  CriaFila("1", "3", "4", &s);
  s.push("2");
  string atual = ToString(s);
  string esperado("[ 1 2 3 4 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::push(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = [ 1 3 4 ] \n");
  INFO(" \"s.push(2)\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Push_com_elemento_que_ja_esta_la") {
  priority_queue s;
  CriaFila("1", "2", "3", &s);
  s.push("2");
  string atual = ToString(s);
  string esperado("[ 1 2 2 3 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::push(SType k) *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = [ 1 2 3 ] \n");
  INFO(" \"s.push(2)\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Pop_em_fila_de_prioridades_unitaria") {
  priority_queue s;
  s.push("10");
  s.pop();
  string atual = ToString(s);
  string esperado("[ ]");
  CHECK_EQ(0, size(s));
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::pop() *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = [ 10 ] \n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO(" Ao apagar um elemento, você tem que decrementar size_");
  INFO("------------------------------------------------------------------\n");
  CHECK_UNARY(root(s) == NULL);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::pop() *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = [ 10 ] \n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO(" DICA: root_ deveria apontar para NULL num fila de prioridades vazia.\n");
  INFO("------------------------------------------------------------------\n");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::pop() *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = [ 10 ] \n");
  INFO(" \"s.pop()\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO(" DICA: Verifique se voce esta atualizando \"sroot_\".\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Pop_em_no_sem_a_subarvore_direita") {
  priority_queue s;
  Push("2", &s);
  Push("1", &s);
  Push("3", &s);
  s.pop();
  string atual = ToString(s);
  string esperado("[ 2 3 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::pop() *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = [ 1 2 3 ] \n");
  INFO(" \"s.pop()\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO(" DICA: Verifique se voce esta removendo corretamente da arvore\n");
  INFO(" um no sem filhos.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_Pop_em_no_com_subarvore_direita") {
  priority_queue s;
  Push("2", &s);
  Push("4", &s);
  Push("3", &s);
  s.pop();
  string atual = ToString(s);
  string esperado("[ 3 4 ]");
  CHECK_EQ(esperado, atual);
  INFO("------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::pop() *\n");
  INFO("------------------------------------------------------------------\n");
  INFO(" s = [ 2 3 4 ] \n");
  INFO(" \"s.pop()\" resultou em: s = " << atual << "\n");
  INFO(" Resultado esperado: s = " << esperado << "\n");
  INFO(" DICA: Verifique se voce esta removendo corretamente da arvore\n");
  INFO(" um no que tem as duas subarvores nao vazias.\n");
  INFO("------------------------------------------------------------------\n");
}

TEST_CASE("Testa_operador_de_atribuicao") {
  priority_queue esperado;
  Push("14", &esperado);
  Push("12", &esperado);
  Push("15", &esperado);
  priority_queue atual;
  atual = esperado;
  CHECK_NE(root(esperado), root(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::operator=(priority_queue& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" Não basta apenas copiar o ponteiro para \"root_\". \n");
  INFO(" Você tem que copiar todos os elementos de p para a fila corrente.\n");
  INFO("-------------------------------------------------------------------\n");
  CHECK_EQ(ToString(esperado), ToString(atual));
  INFO("-------------------------------------------------------------------\n");
  INFO("Erro na funcao: void priority_queue::operator=(priority_queue& p)\n");
  INFO("-------------------------------------------------------------------\n");
  INFO(" q = " << ToString(esperado) << "\n");
  INFO(" \"f = q\" resultou em: f = " << ToString(atual) << "\n");
  INFO(" Resultado esperado: f = " << ToString(esperado) << "\n");
  INFO("-------------------------------------------------------------------\n");
}

#endif  // TRUNK_PRIORITY_QUEUE_TEST_PRIORITY_QUEUE_TEST_H_
