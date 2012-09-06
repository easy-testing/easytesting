// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_VECTOR_SRC_VECTOR_H_
#define TRUNK_VECTOR_SRC_VECTOR_H_

// Implementa um vetor dinâmico de números reais.
// O tipo dos elementos contidos no vetor é definido por VType.
// O valor de VType deve ser definido em tempo de compilação.
class vector {
 public:
  // Cria um vetor vazio.
  vector();

  // Cria um vetor com n elementos. O valor dos n elementos é indeterminado
  // (ou seja, pode ser qualquer valor).
  vector(int n);

  // Cria um vetor idêntico a v.
  vector(vector& v);

  // Retorna o número de elementos no vetor.
  int size();

  // Altera o tamanho do vetor para n elementos.
  // Se n <= size_, o conteúdo do vetor é reduzido para os seus n primeiros
  // elementos. Se n > size_, o conteúdo do vetor é expandido e "n - size_"
  // novos elementos são inseridos no final do vetor. O valor dos novos
  // elementos é indeterminado (ou seja, pode ser qualquer número real).
  void resize(int n);

  // Retorna uma referência ao elemento de índice i no vetor.
  // Precondição: i deve ser um índice válido do vetor.
  VType& operator[](int i);

  // Faz com que o vetor corrente fique igual ao vetor v.
  void operator=(vector& v);

  // Insere o elemento x no final do vetor.
  // Esta operação aumenta o número de elementos do vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.push_back(-7.0)",
  // "v = {1.0, 3.0, 5.0, -7.0}".
  void push_back(VType x);

  // Remove o último elemento do vetor.
  // Esta operação diminui o número de elementos no vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.pop_back()",
  // "v = {1.0, 3.0}".
  // Precondição: O vetor deve ter pelo menos um elemento.
  void pop_back();

  // Insere o elemento x antes do elemento de índice 'index'.
  // Todos os elementos com índice igual ou maior que 'index' são deslocados
  // para a direita.
  // Esta operação aumenta o número de elementos no vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.insert(1, -7.0)",
  // "v = {1.0, -7.0, 3.0, 5.0}".
  // Precondição: 0 <= index <= size_.
  void insert(int index, VType x);

  // Remove o elemento de índice 'index' do vetor.
  // Todos os elementos com índice maior que 'index' são deslocados para
  // a esquerda.
  // Esta operação diminui o número de elementos no vetor em uma unidade.
  // Por exemplo: se "v = {1.0, 3.0, 5.0}", após "v.erase(1)",
  // "v = {1.0, 5.0}".
  // Precondição: 0 <= index < size_.
  void erase(int index);

  // Libera a memória alocada para array_.
  ~vector();

 private:
  // Número de elementos no vetor.
  int size_;

  // Vetor alocado dinamicamente.
  VType* array_;

  friend class Teste;
};  // end class vector.

#endif  // TRUNK_VECTOR_SRC_VECTOR_H_
