// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_FLOAT_VECTOR_SRC_FLOAT_VECTOR_H_
#define BRANCHES_GABARITOS_FLOAT_VECTOR_SRC_FLOAT_VECTOR_H_

// Implementa um vetor dinâmico de números reais.
class FloatVector {
 public:
  // Cria um vetor vazio.
  FloatVector();

  // Cria um vetor com n elementos. O valor dos n elementos é indeterminado
  // (ou seja, pode ser qualquer número real).
  FloatVector(int n);

  // Cria um vetor idêntico a v.
  FloatVector(FloatVector& v);

  // Testa se o vetor está vazio.
  bool empty();

  // Retorna o número de elementos no vetor.
  int size();

  // Altera o tamanho do vetor para n elementos.
  // Se n <= size_, o conteúdo do vetor é reduzido para os seus n primeiros
  // elementos. Se n > size_, o conteúdo do vetor é expandido e "n - size_"
  // novos elementos são inseridos no final do vetor. O valor dos novos
  // elementos é indeterminado (ou seja, pode ser qualquer número real).
  void resize(int n);

  // Retorna uma referência ao elemento de índice i no vetor.
  float& at(int i);
  float& operator[](int i) {return at(i);}

  // Retorna uma referência ao primeiro elemento no vetor.
  float& front();

  // Retorna uma referência ao último elemento no vetor.
  float& back();

  // Faz com que o vetor corrente fique igual ao vetor v.
  void assign(FloatVector& v);
  void operator=(FloatVector& v) {assign(v);}

  // Insere o elemento x no final do vetor.
  // Esta operação aumenta o número de elementos do vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.push_back(-7.0)",
  // "v = {1.0, 3.0, 5.0, -7.0}".
  void push_back(float x);

  // Remove o último elemento do vetor.
  // Esta operação diminui o número de elementos no vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.pop_back()",
  // "v = {1.0, 3.0}".
  void pop_back();

  // Insere o elemento x antes do elemento de índice 'index'.
  // Os valores válidos para 'index' estão no intervalo [0, size_].
  // Todos os elementos com índice igual ou maior que 'index' são deslocados
  // para a direita.
  // Esta operação aumenta o número de elementos no vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.insert(1, -7.0)",
  // "v = {1.0, -7.0, 3.0, 5.0}".
  void insert(int index, float x);

  // Remove o elemento de índice 'index' do vetor.
  // Todos os elementos com índice maior que 'index' são deslocados para
  // a esquerda.
  // Esta operação diminui o número de elementos no vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.erase(1)",
  // "v = {1.0, 5.0}".
  void erase(int index);

  // Remove todos os elementos do vetor.
  // Ao final, o número de elementos no vetor é igual a zero.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.clear()",
  // "v = {}".
  void clear();

  // Libera a memória alocada para array_.
  ~FloatVector();

 private:
  // Número de elementos no vetor.
  int size_;

  // Vetor alocado dinamicamente.
  // Sempre que o tamanho do vetor for 0
  // o valor deste campo devera ser NULL
  float* array_;
};  // end class FloatVector.

#endif  // BRANCHES_GABARITOS_FLOAT_VECTOR_SRC_FLOAT_VECTOR_H_
