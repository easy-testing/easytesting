// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef FLOAT_VECTOR_TEST_FLOAT_VECTOR_TEST_H_
#define FLOAT_VECTOR_TEST_FLOAT_VECTOR_TEST_H_

#include "float_vector/src/float_vector.h"
#include <string>
#include "gtest/gtest.h"

using std::string;
using std::stringstream;
  using namespace std;

// Classe base dos testes.


class Teste : public testing::Test {
  public:
  FloatVector* InitFloatvector0() {
    FloatVector* v =
    reinterpret_cast<FloatVector*>(malloc(sizeof(FloatVector)));
    v->size_ = 0;
    v->array_ = NULL;
    return v;
  }

  FloatVector* InitFloatvector1(float e1) {
    FloatVector* v =
    reinterpret_cast<FloatVector*>(malloc(sizeof(FloatVector)));
    v->size_ = 1;
    v->array_ =  reinterpret_cast<float*>(malloc(1 * sizeof(float)));
    v->array_[0] = e1;
    return v;
  }

  FloatVector* InitFloatvector2(float e1, float e2) {
    FloatVector* v =
    reinterpret_cast<FloatVector*>(malloc(sizeof(FloatVector)));
    v->size_ = 2;
    v->array_ =  reinterpret_cast<float*>(malloc(2 * sizeof(float)));
    v->array_[0] = e1;
    v->array_[1] = e2;
    return v;
  }

  FloatVector* InitFloatvector3(float e1, float e2, float e3) {
    FloatVector* v =
    reinterpret_cast<FloatVector*>(malloc(sizeof(FloatVector)));
    v->size_ = 3;
    v->array_ = reinterpret_cast<float*>(malloc(3 * sizeof(float)));
    v->array_[0] = e1;
    v->array_[1] = e2;
    v->array_[2] = e3;
    return v;
  }

  FloatVector* v0;
  FloatVector* v1;
  FloatVector* v2;
  FloatVector* v3;

  Teste() {
    v0 = InitFloatvector0();
    v1 = InitFloatvector1(0);
    v2 = InitFloatvector2(0, 1);
    v3 = InitFloatvector3(0, 1, 2);
  }
  // Retorna uma string no formato {a, b, c, d, ..., z}.
  string MostrarVetor(float v[], int n) {
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
  float inesperado = v1->at(0);
  v1->at(0) = inesperado + 1;
  float atual = v1->at(0);
  ASSERT_NE(atual, inesperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"float& at(int)\".                                 \n"
  << "-------------------------------------------------------------------\n"
  << "Nao foi possivel alterar um elemento do vetor.                     \n"
  << "Esta funcao ira influenciar todos os outros testes.                \n"
  << "Corrija esta funcao antes de continuar.                            \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construtor_Copia_Valores) {
  FloatVector v(*v3);
  int diferencas = 0;
  for (int i = 0; i < 3; i++) {
      if (v[i] != (*v3)[i]) {
           diferencas++;
      }
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"FloatVector(FloatVector&)\".                      \n"
  << "-------------------------------------------------------------------\n"
  << "O vetor criado nao e igual ao vetor passado como parametro.        \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construtor_Copia_Apontadores) {
  FloatVector v(*v3);
  v[0]++;
  int diferencas = 0;
  for (int i = 0; i < 3; i++) {
      if (v[i] != (*v3)[i]) {
           diferencas++;
      }
  }
  ASSERT_EQ(diferencas, 1)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"FloatVector(FloatVector&)\".                      \n"
  << "-------------------------------------------------------------------\n"
  << "O novo vetor esta compartilhando o arranjo do vetor passado.       \n"
  << "como parametro. Deve se criar um novo vetor.                       \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Construtor_Copia_NULL) {
  FloatVector v(*v0);
  ASSERT_EQ(&v[0], reinterpret_cast<float*>(NULL))
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"FloatVector(FloatVector&)\".                      \n"
  << "-------------------------------------------------------------------\n"
  << "Falha ao criar vetor vazio. array_ deve aponter para NULL.         \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Front_Alteracao_Elemento) {
  float inesperado = v2->front();
  v2->at(0) = inesperado + 1;
  float atual = v2->at(0);
  ASSERT_NE(atual, inesperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"float& front(int)\".                              \n"
  << "-------------------------------------------------------------------\n"
  << "A funcao esta devolvendo o elemento errado do vetor.               \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Back_Alteracao_Elemento) {
  float inesperado = v2->back();
  v2->at(1) = inesperado + 1;
  float atual = v2->at(1);
  ASSERT_NE(atual, inesperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"float& back(int)\".                               \n"
  << "-------------------------------------------------------------------\n"
  << "A funcao esta devolvendo o elemento errado do vetor.               \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Vazio_Vazio) {
  FloatVector v(0);
  v.assign(*v0);
  bool esperado = true;
  bool atual = (v.size() == v0->size()) && (&v[0] == &(*v0)[0] );
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(FloatVector&)\".                      \n"
  << "-------------------------------------------------------------------\n"
  << "Erro ao copiar um vetor vazio para outro vetor vazio.              \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Cheio_Para_Vazio) {
  FloatVector v(0);
  v.assign(*v3);
  int diferencas = 0;
  if (v.size() != v3->size()) {
    diferencas++;
  }
  for (int i = 0; i < 3; i++) {
    if (v[i] != (*v3)[i]) {
      diferencas++;
    }
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(FloatVector&)\".                      \n"
  << "-------------------------------------------------------------------\n"
  << "Os vetores estao diferentes ao final do processo.\n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Vazio_Para_Cheio) {
  FloatVector v(3);
  v.assign(*v0);
  bool esperado = true;
  bool atual = (v.size() == v0->size()) && (&v[0] == &(*v0)[0]);
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(FloatVector&)\".                      \n"
  << "-------------------------------------------------------------------\n"
  << "Os vetores estao diferentes ao final do processo.                  \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Cheio_Para_Cheio) {
  v2->assign(*v3);
  int diferencas = 0;
  if (v2->size() != v3->size()) {
      diferencas++;
  }
  for (int i = 0; i < 3; i++) {
    if ((*v2)[i] != (*v3)[i]) {
      diferencas++;
    }
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(FloatVector&)\".                      \n"
  << "-------------------------------------------------------------------\n"
  << "Os vetores estao diferentes ao final do processo.                  \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Assign_Cheio_Para_Cheio_Ponteiros) {
  v2->assign(*v3);
  ASSERT_NE(&v2[0], &v3[0])
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void assign(FloatVector&)\".                      \n"
  << "-------------------------------------------------------------------\n"
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
  << "Erro na funcao \"void push_back(float)\".                          \n"
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
  << "Erro na funcao \"void push_back(float)\".                          \n"
  << "-------------------------------------------------------------------\n"
  << "Erro ao adicionar um elemento a um vetor com 1 elemento.           \n"
  << "Esperado: {0, 2}.                                                  \n"
  << "Atual: {" << (*v1)[0] << ", " << (*v1)[1] << "}.                   \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Push_Back_Ponteiro) {
  float* antes = &(*v0)[0];
  v0->push_back(3.14);
  float* depois = &(*v0)[0];
  ASSERT_NE(antes, depois)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void push_back(float)\".                          \n"
  << "-------------------------------------------------------------------\n"
  << "Ao aumentar o vetor deve se criar um novo array.                   \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Pop_Back_2_Elementos) {
  v2->pop_back();
  int diferencas = 0;
  if ( v2->size() != 1 ) {
    diferencas++;
  }
  if ( v2->back() != (*v2)[0] ) {
    diferencas++;
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void pop_back()\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "O tamanho do vetor deve ser reduzido em 1 e o penultimo valor      \n"
  << "passa a ser o ultimo.                                              \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Pop_Back_1_Elemento) {
  v1->pop_back();
  int diferencas = 0;
  if ( v1->size() != 0 ) {
    diferencas++;
  }
  if ( &(*v1)[0] != NULL ) {
    diferencas++;
  }
  ASSERT_EQ(diferencas, 0)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void pop_back()\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "O tamanho do vetor deve ser reduzido em 1 e o arranjo              \n"
  << "de vetores vazios deve apontar para NULL.                          \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Insert_Elemento_0_Tamanho) {
  int anterior = v1->size();
  v1->insert(0, 3.14);
  int atual = v1->size();
  ASSERT_EQ(atual, anterior + 1)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void insert(int, float)\".                        \n"
  << "-------------------------------------------------------------------\n"
  << "O tamanho do vetor deve ser aumentado em 1.                        \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Insert_Em_Vetor_Vom_1_Elemento) {
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
  << "Erro na funcao \"void insert(int, float)\".                        \n"
  << "-------------------------------------------------------------------\n"
  << "O elemento nao foi inserido na posicao correta.                    \n"
  << "Esperado: {2, 0}.                                                  \n"
  << "Atual: {" << (*v1)[0] << ", " << (*v1)[1] << "}.                   \n"
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
  << "Erro na funcao \"void insert(int, float)\".                        \n"
  << "-------------------------------------------------------------------\n"
  << "O elemento nao foi inserido na posicao correta.                    \n"
  << "Esperado: {0, 2, 1}.                                               \n"
  << "Atual: {" << (*v1)[0] << ", " << (*v1)[1] << ", "
  << (*v1)[2] << "}                                             .        \n"
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
  << "Erro na funcao \"void insert(int, float)\".                        \n"
  << "-------------------------------------------------------------------\n"
  << "O elemento nao foi inserido na posicao correta.                    \n"
  << "Esperado: {0, 2}.                                                  \n"
  << "Atual: {" << (*v1)[0] << ", " << (*v1)[1] << "}.                   \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Insert_Apontador) {
  float* antes = &(*v1)[0];
  v1->insert(0, 3.14);
  float* depois = &(*v1)[0];
  ASSERT_NE(antes, depois)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void insert(int, float)\".                        \n"
  << "-------------------------------------------------------------------\n"
  << "Deve ser criado um novo arranjo para a insercao.                   \n"
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
  << "O tamanho do vetor deve ser diminuido em 1.                        \n"
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
  << "O elemento nao foi removido corretamente.                          \n"
  << "Esperado: { 1 }.                                                   \n"
  << "Atual: " << MostrarVetor(&(*v2)[0], v2->size()) << ".                  \n"
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
  << "O elemento nao foi removido corretamente.                          \n"
  << "Esperado: { 0 }.                                                   \n"
  << "Atual: " << MostrarVetor(&(*v2)[0], v2->size()) << "                   \n"
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
  << "O elemento nao foi removido corretamente.                          \n"
  << "Esperado: { 0, 2 }.                                                \n"
  << "Atual: " << MostrarVetor(&(*v3)[0], v3->size()) << "                   \n"
  << "-------------------------------------------------------------------\n";
}


TEST_F(Teste, Erase_Apontador) {
  float* antes = &(*v1)[0];
  v1->erase(0);
  float* depois = &(*v1)[0];
  ASSERT_NE(antes, depois)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void erase(int)\".                                \n"
  << "-------------------------------------------------------------------\n"
  << "Deve ser criado um novo arranjo para a remocao.                    \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Empty_Vazio) {
  bool esperado = true;
  bool atual = v0->empty();
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"bool empty()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "Valor esperado: "<< esperado << "                                  \n"
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
  << " Um vetor de n>0 posicoes, todas iguais a 0, nao e um vetor vazio. \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Size_3) {
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

TEST_F(Teste, Size_0) {
  int esperado = 0;
  int atual = v0->size();
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"int size()\".                                     \n"
  << "-------------------------------------------------------------------\n"
  << "Valor esperado: "<< esperado << "                                  \n"
  << "Valor retornado: " << atual
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Resize_3_Para_1) {
  int esperado = 1;
  v3->resize(1);
  int atual = v3->size();
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"int size()\".                                     \n"
  << "-------------------------------------------------------------------\n"
  << "Valor esperado: "<< esperado << "                                  \n"
  << "Valor retornado: " << atual
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
  << "Os valores dos velhos elementos e suas posicoes devem ser mantidos.\n"
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
  << "Os valores dos velhos elementos e suas posicoes devem ser mantidos.\n"
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
  << "A funcao nao esta alterando o tamanho do vetor.                    \n"
  << "-------------------------------------------------------------------\n";
}

TEST_F(Teste, Clear_Size_3_Array) {
  float* esperado = NULL;
  v3->clear();
  float* atual = &(*v3)[0];
  ASSERT_EQ(atual, esperado)
  << "-------------------------------------------------------------------\n"
  << "Erro na funcao \"void clear()\".                                   \n"
  << "-------------------------------------------------------------------\n"
  << "O arranjo do vetor deve passar a ser NULL.                         \n"
  << "-------------------------------------------------------------------\n";
}

#endif  // FLOAT_VECTOR_TEST_FLOAT_VECTOR_TEST_H__

