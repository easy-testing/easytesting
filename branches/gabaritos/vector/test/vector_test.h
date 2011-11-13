// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef Type_VECTOR_TEST_Type_VECTOR_TEST_H_
#define Type_VECTOR_TEST_Type_VECTOR_TEST_H_
#include "vector/src/vector.h"
#include <string>
#include "gtest/gtest.h"

using std::string;
using std::stringstream;


// Classe base dos testes.


class Teste : public testing::Test {
  public:
  vector* Initvector0() {
    vector* v =
    reinterpret_cast<vector*>(malloc(sizeof(vector)));
    v->size_ = 0;
    v->array_ = new Type[v->size_];
    return v;
  }

  vector* Initvector1(Type e1) {
    vector* v =
    reinterpret_cast<vector*>(malloc(sizeof(vector)));
    v->size_ = 1;
    v->array_ =  reinterpret_cast<Type*>(malloc(1 * sizeof(Type)));
    v->array_[0] = e1;
    return v;
  }

  vector* Initvector2(Type e1, Type e2) {
    vector* v =
    reinterpret_cast<vector*>(malloc(sizeof(vector)));
    v->size_ = 2;
    v->array_ =  reinterpret_cast<Type*>(malloc(2 * sizeof(Type)));
    v->array_[0] = e1;
    v->array_[1] = e2;
    return v;
  }

  vector* Initvector3(Type e1, Type e2, Type e3) {
    vector* v =
    reinterpret_cast<vector*>(malloc(sizeof(vector)));
    v->size_ = 3;
    v->array_ = reinterpret_cast<Type*>(malloc(3 * sizeof(Type)));
    v->array_[0] = e1;
    v->array_[1] = e2;
    v->array_[2] = e3;
    return v;
  }

  vector* v0;
  vector* v1;
  vector* v2;
  vector* v3;

  Teste() {
    v0 = Initvector0();
    v1 = Initvector1(0);
    v2 = Initvector2(0, 1);
    v3 = Initvector3(0, 1, 2);
  }
  // Retorna uma string no formato {a, b, c, d, ..., z}.
  string MostrarVetor(Type v[], int n) {
    stringstream output;
    output << "{";
    for (int i = 0; i < n ; i++) {
      output << v[i];
      if (i < n - 1) {
        output << ", ";
      }
    }
    output << "}";
    return output.str();
  }
};

TEST_F(Teste, At_Alteracao_Elemento) {
  Type inesperado = v1->at(0);
  v1->at(0) = inesperado + 1;
  Type atual = v1->at(0);
  ASSERT_NE(atual, inesperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"Type& at(int)\".                                  \n"
  << "-------------------------------------------------------------------\n"
  << "Nao foi possivel alterar o elemento do vetor v = {1} para 2 .      \n"
  << "Esta funcao ira influenciar todos os outros testes.                \n"
  << "Corrija esta funcao antes de continuar.                            \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construtor_Copia_Valores) {
  vector v(*v3);
  int diferencas = 0;
  for (int i = 0; i < 3; i++) {
      if (v[i] != (*v3)[i]) {
           diferencas++;
      }
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"vector(vector&)\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "O vetor criado nao e igual ao vetor passado como parametro.        \n"
  << "Vetor 1: " << MostrarVetor(&(v[0]), v.size()) << "                 \n"
  << "Vetor 2: " << MostrarVetor(&(*v3)[0], v3->size()) << "             \n"
  << "O vetor 2 foi passado como parametro para o construtor do vetor 1. \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construtor_Copia_Apontadores) {
  vector v(*v3);
  v[0]++;
  int diferencas = 0;
  for (int i = 0; i < 3; i++) {
      if (v[i] != (*v3)[i]) {
           diferencas++;
      }
  }
  ASSERT_EQ(diferencas, 1)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"vector(vector&)\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "O novo vetor esta compartilhando o arranjo do vetor passado.       \n"
  << "como parametro. Deve se criar um novo vetor.                       \n"
  << "Vetor 1: "<< MostrarVetor(&(v[0]), v.size()) << "                  \n"
  << "Vetor 2: "<< MostrarVetor(&(*v3)[0], v3->size()) << "              \n"
  << "O vetor 2 foi passado como parametro para o construtor do vetor 1. \n"
  << "Depois disso o vetor 1 foi alterado. O vetor dois nao deveria ter  \n"
  << "sofrido alteracoes. Isso indica que abos os vetores compartilham o \n"
  << "mesmo arranjo.                                                     \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Vazio_Vazio) {
  vector v(0);
  v.assign(*v0);
  bool esperado = true;
  bool atual = (v.size() == v0->size());
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(vector&)\".                           \n"
  << "-------------------------------------------------------------------\n"
  << "Erro ao copiar um vetor vazio para outro vetor vazio.              \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Cheio_Para_Vazio) {
  vector v(0);
  v.assign(*v3);
  int diferencas = 0;
  if (v.size() != v3->size()) {
      diferencas++;
  }
  if (diferencas == 0) {
    for (int i = 0; i < 3; i++) {
      if (v[i] != (*v3)[i]) {
        diferencas++;
      }
    }
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(vector&)\".                           \n"
  << "-------------------------------------------------------------------\n"
  << "Os vetores estao diferentes ao final do processo.                  \n"
  << "vetor 1: {}                                                        \n"
  << "vetor 2: {0, 1, 2}                                                 \n"
  << "Operacao realizada: vetor1.assign(vetor2)                          \n"
  << "Resultado esperado para vetor 1: {0, 1, 2}                         \n"
  << "Resultado atual: " << MostrarVetor(&(v[0]), v.size()) << "         \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Vazio_Para_Cheio) {
  vector v(3);
  v.assign(*v0);
  bool esperado = true;
  bool atual = (v.size() == v0->size());
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(vector&)\".                           \n"
  << "-------------------------------------------------------------------\n"
  << "Os vetores estao diferentes ao final do processo.                  \n"
  << "vetor 1: (3 valores nao inicializados)                             \n"
  << "vetor 2: {}                                                        \n"
  << "Operacao realizada: vetor1.assign(vetor2)                          \n"
  << "Resultado esperado para vetor 1: {}                                \n"
  << "Resultado atual: " << MostrarVetor(&(v[0]), v.size()) << "         \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Cheio_Para_Cheio) {
  v2->assign(*v3);
  int diferencas = 0;
  if (v2->size() != v3->size()) {
      diferencas++;
  }
  if (diferencas == 0) {
    for (int i = 0; i < 3; i++) {
      if ((*v2)[i] != (*v3)[i]) {
        diferencas++;
      }
    }
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(vector&)\".                           \n"
  << "-------------------------------------------------------------------\n"
  << "vetor 1: {0, 1}                                                    \n"
  << "vetor 2: {0, 1, 2}                                                 \n"
  << "Operacao realizada: vetor1.assign(vetor2)                          \n"
  << "Resultado esperado para vetor 1: {0, 1, 2}                         \n"
  << "Resultado atual: " << MostrarVetor(&(*v2)[0], v2->size()) << "     \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Cheio_Para_Cheio_Ponteiros) {
  v2->assign(*v3);
  ASSERT_NE(&v2[0], &v3[0])
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(vector&)\".                           \n"
  << "-------------------------------------------------------------------\n"
  << "vetor 1: {0, 1}                                                    \n"
  << "vetor 2: {0, 1, 2}                                                 \n"
  << "Operacao realizada: vetor1.assign(vetor2)                          \n"
  << "Resultado esperado para vetor 1: {0, 1, 2}                         \n"
  << "Resultado atual: " << MostrarVetor(&(*v2)[0], v2->size()) << "     \n"
  << "Apesar de os elementos serem iguais, cada vetor deve possuir       \n"
  << "seu proprio arranjo.                                               \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Push_Back_Vazio) {
  v0->push_back(2);
  int diferencas = 0;
  if ( v0->size() != 1 ) {
    diferencas++;
  }
  if ( &(*v0)[0] == NULL || (&(*v0)[0] != NULL && (*v0)[0] != 2) ) {
    diferencas++;
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void push_back(Type)\".                          \n"
  << "-------------------------------------------------------------------\n"
  << "Erro ao adicionar um elemento a um vetor vazio.                    \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Push_Back_Cheio) {
  v1->push_back(2);
  int diferencas = 0;
  if ( v1->size() != 2 ) {
    diferencas++;
  }
  if ( (*v1)[0] != 0 ) {
    diferencas++;
  }
  if ( (*v1)[1] != 2 ) {
    diferencas++;
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void push_back(Type)\".                           \n"
  << "-------------------------------------------------------------------\n"
  << "Erro ao adicionar um elemento a um vetor com 1 elemento.           \n"
  << "Vetor original: {0}.                                               \n"
  << "Operacao realizada: push_back(2)                                   \n"
  << "Esperado: {0, 2}.                                                  \n"
  << "Resultado atual: " << MostrarVetor(&(*v1)[0], v1->size()) << "     \n"
  << "Valor de size_ apos insercao:" << v1->size() << "                  \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Push_Back_Verifica_Alocacao_Array) {
  Type* antes = &(*v0)[0];
  v0->push_back(3);
  Type* depois = &(*v0)[0];
  ASSERT_NE(antes, depois)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void push_back(Type)\".                           \n"
  << "-------------------------------------------------------------------\n"
  << "Para aumentar o tamanho do vetor, você deve alocar um novo array.  \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Pop_Back_2_Elementos) {
  v2->pop_back();
  int diferencas = 0;
  if ( v2->size() != 1 ) {
    diferencas++;
  }
  if ((*v2)[v2->size()-1] != 0) {
    diferencas++;
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void pop_back()\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "Erro ao remover o ultimo elemento de um vetor de 2 elementos.      \n"
  << "Vetor original: {0, 1}                                             \n"
  << "Operacao realizada: pop_back();                                    \n"
  << "Resultado esperado: {0}.                                           \n"
  << "Resultado atual: " << MostrarVetor(&(*v2)[0], v2->size()) << "     \n"
  << "Valor de size_ apos remocao:" << v1->size() << "                   \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Pop_Back_1_Elemento_verifica_size) {
  v1->pop_back();
  int esperado = 0;
  int atual = v1->size();
  ASSERT_EQ(esperado, atual)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void pop_back()\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "Erro ao remover o ultimo elemento de um vetor de 1 elemento.       \n"
  << "Vetor original: {0}                                                \n"
  << "Operacao realizada: pop_back();                                    \n"
  << "Resultado esperado: {}.                                            \n"
  << "Resultado atual: " << MostrarVetor(&(*v1)[0], v1->size()) << "     \n"
  << "O valor do campo size_ do vetor estava incorreto apos a remoção.   \n"
  << "Valor de size_ apos remocao:" << atual << "                        \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Insert_Elemento_0_Tamanho) {
  int erros = 0;
  int anterior = v1->size();
  v1->insert(0, 3);
  int atual = v1->size();
  if ( (*v1)[0] != 3 ) {
    erros++;
  }
  if ( (*v1)[1] != 0 ) {
    erros++;
  }
  if ( atual != 2 ) {
    erros++;
  }
  ASSERT_EQ(erros, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void insert(int, Type)\".                         \n"
  << "-------------------------------------------------------------------\n"
  << "Erro ao inserir um elemento num de 2 elementos.                    \n"
  << "Vetor original: {0}                                                \n"
  << "Operacao realizada: insert(0, 3.14);                               \n"
  << "Resultado esperado: {3.14, 0}.                                     \n"
  << "Resultado atual: " << MostrarVetor(&(*v1)[0], v1->size()) << "     \n"
  << "O valor do campo size_ do vetor estava incorreto apos a isercao.   \n"
  << "Valor de size_ apos insercao:" << atual << "                       \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Insert_Em_Vetor_Com_1_Elemento) {
  v1->insert(0, 2);
  int erros = 0;
  if ( (*v1)[0] != 2 ) {
    erros++;
  }
  if ( (*v1)[1] != 0 ) {
    erros++;
  }
  ASSERT_EQ(erros, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void insert(int, Type)\".                         \n"
  << "-------------------------------------------------------------------\n"
  << "O elemento nao foi inserido na posicao correta.                    \n"
  << "Vetor original: {0}.                                               \n"
  << "Chamada da funcao: insert(0, 2);                                   \n"
  << "Esperado: {2, 0}.                                                  \n"
  << "Atual: " << MostrarVetor(&(*v1)[0], v1->size()) << "               \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Insert_Em_Vetor_Com_2_Elementos_Meio) {
  v2->insert(1, 2);
  int erros = 0;
  if ( (*v2)[0] != 0 ) {
    erros++;
  }
  if ( (*v2)[1] != 2 ) {
    erros++;
  }
  if ( (*v2)[2] != 1 ) {
    erros++;
  }
  ASSERT_EQ(erros, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void insert(int, Type)\".                         \n"
  << "-------------------------------------------------------------------\n"
  << "O elemento nao foi inserido na posicao correta.                    \n"
  << "Vetor original: {0, 1}.                                            \n"
  << "Chamada da funcao: insert(1, 2);                                   \n"
  << "Esperado: {0, 2, 1}.                                               \n"
  << "Atual: " << MostrarVetor(&(*v2)[0], v2->size()) << "               \n"
  << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Insert_Elemento_Fim) {
  v1->insert(1, 2);
  int diferencas = 0;
  if ( (*v1)[1] != 2 ) {
    diferencas++;
  }
  if ( (*v1)[0] != 0 ) {
    diferencas++;
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void insert(int, Type)\".                         \n"
  << "-------------------------------------------------------------------\n"
  << "O elemento nao foi inserido na posicao correta.                    \n"
  << "Vetor original: {0}.                                               \n"
  << "Chamada da funcao: insert(1, 2);                                   \n"
  << "Esperado: {0, 2}.                                                  \n"
  << "Atual: " << MostrarVetor(&(*v1)[0], v1->size()) << "               \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Insert_verifica_nova_alocacao_vetor) {
  Type* antes = &(*v1)[0];
  v1->insert(0, 3.14);
  Type* depois = &(*v1)[0];
  ASSERT_NE(antes, depois)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void insert(int, Type)\".                         \n"
  << "-------------------------------------------------------------------\n"
  << "A sua funcao nao esta alocando um novo arranjo para comportar      \n"
  << "o elemento inserido e os elementos originais do vetor.             \n"
  << "Ela esta alterando o arranjo original.                             \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Erase_Tamanho) {
  int antes = v2->size();
  v2->erase(0);
  int depois = v2->size();
    ASSERT_EQ(antes-1, depois )
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void erase(int)\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "Erro ao remover o primeiro elemento de um vetor de 2 elementos.    \n"
  << "O valor do campo size_ do vetor estava incorreto apos a remoção.   \n"
  << "Valor de size_ apos remoção:" << depois
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Erase_Primeiro) {
  v2->erase(0);
  int diferencas = 0;
  if ( v2->size() != 1 ) {
    diferencas++;
  }
  if ( (*v2)[0] != 1 ) {
    diferencas++;
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void erase(int))\".                               \n"
  << "-------------------------------------------------------------------\n"
  << "O primeiro elemento nao foi removido corretamente.                 \n"
  << "Original: {0, 1}.                                                  \n"
  << "Apos remocao: " << MostrarVetor(&(*v2)[0], v2->size()) << "        \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Erase_Ultimo) {
  v2->erase(1);
  int diferencas = 0;
  if ( v2->size() != 1 ) {
    diferencas++;
  }
  if ( (*v2)[0] != 0 ) {
    diferencas++;
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void erase(int)\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "O ultimo elemento nao foi removido corretamente.                   \n"
  << "Original: {0, 1}.                                                  \n"
  << "Apos remocao: " << MostrarVetor(&(*v2)[0], v2->size()) << "        \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Erase_Meio) {
  v3->erase(1);
  int diferencas = 0;
  if ( v3->size() != 2 ) {
    diferencas++;
  }
  if ( (*v3)[0] != 0 ) {
    diferencas++;
  }
  if ( (*v3)[1] != 2 ) {
    diferencas++;
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void erase(int)\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "O segundo elemento nao foi removido corretamente.                  \n"
  << "Original: {0, 1, 2 }.                                              \n"
  << "Apos remocao: " << MostrarVetor(&(*v3)[0], v3->size()) << "        \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Empty_Vazio) {
  bool esperado = true;
  bool atual = v0->empty();
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"bool empty()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "Valor original: "<< esperado << "                                  \n"
  << "Valor retornado: " << atual  << "                                  \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Empty_Nao_Vazio) {
  bool esperado = false;
  bool atual = v1->empty();
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"bool empty()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "Valor esperado: "<< esperado << "                                  \n"
  << "Valor retornado: " << atual  << "                                  \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Empty_Posicoes_Nulas) {
  bool antes = v1->empty();
  (*v1)[0]=1;
  bool depois = v1->empty();
  ASSERT_EQ(antes, depois)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"bool empty()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "Um vetor de n > 0 posicoes, todas iguais a 0, nao e um vetor vazio.\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Size_vetor_3_elementos) {
  int esperado = 3;
  int atual = v3->size();
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"int size()\".                                     \n"
  << "-------------------------------------------------------------------\n"
  << "Valor esperado: "<< esperado << "                                  \n"
  << "Valor retornado: " << atual
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Size_vetor_0_elementos) {
  int esperado = 0;
  int atual = v0->size();
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"int size()\".                                     \n"
  << "-------------------------------------------------------------------\n"
  << "Vetor: " << MostrarVetor(&(*v0)[0], v0->size()) << ".              \n"
  << "Valor retornado: " << atual << "                                   \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Resize_3_Para_1) {
  int esperado = 1;
  v3->resize(1);
  int atual = v3->size();
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"int resize()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "Sua funcao nao esta alterando o campo size_ do vetor corretamente. \n"
  << "Vetor apos resize:"  << MostrarVetor(&(*v3)[0], v3->size()) << ".  \n"
  << "Campo size apos resize:" << atual << "                             \n"
  << "Valor de size_ esperado: "<< esperado << "                         \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Resize_1_Para_3) {
  int esperado = 3;
  v3->resize(3);
  int atual = v3->size();
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"int resize()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "Valor esperado: "<< esperado << "                                  \n"
  << "Valor retornado: " << atual
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Resize_2_Para_3_Verifica_Elementos) {
  int elemento1 = (*v2)[0];
  int elemento2 = (*v2)[1];
  v2->resize(3);
  bool esperado = true;
  bool atual = (elemento1 == (*v2)[0]) & (elemento2 == (*v2)[1]);
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"int resize()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "Todos os elementos do vetor que puderem ser mantidos apos a        \n"
  << "alteracao de tamanho devem ser mantidos em suas posições           \n"
  << "originais. Sua funcao alterou pelo menos um dos dois primeiros     \n"
  << "elementos de um vetor de 2 elementos quando a a funcao resize()    \n"
  << "foi chamada para reduzir seu tamanho para 3.                       \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Resize_3_Para_2_Verifica_Elementos) {
  int elemento1 = (*v3)[0];
  int elemento2 = (*v3)[1];
  v2->resize(2);
  bool esperado = true;
  int atual = (elemento1 == (*v3)[0]) & (elemento2 == (*v3)[1]);
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"int resize()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "Todos os elementos do vetor que puderem ser mantidos apos a        \n"
  << "alteracao de tamanho devem ser mantidos em suas posições           \n"
  << "originais. Sua funcao alterou pelo menos um dos dois primeiros     \n"
  << "elementos de um vetor de 3 elementos quando a a funcao resize()    \n"
  << "foi chamada para reduzir seu tamanho para 2.                       \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Clear_Size_3) {
  int inesperado = 3;
  v3->clear();
  int atual = v3->size();
  ASSERT_NE(atual, inesperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void clear()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "A chamada da funcao clear() deve alterar o campo size_ do vetor.   \n"
  << "para 0. Sua função esta mantendo o valor original."
  << "-------------------------------------------------------------------\n";
}


#endif  // Type_VECTOR_TEST_Type_VECTOR_TEST_H__

