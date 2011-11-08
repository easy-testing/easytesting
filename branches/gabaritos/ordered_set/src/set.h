// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef SET_SRC_SET_H_
#define SET_SRC_SET_H_

#include <string>

// Tipo dos elementos contidos no conjunto.
#ifdef EASY_TESTING
// Os testes s�o sempre realizados sobre conjuntos de string.
typedef std::string type;
#else
typedef std::string type;
#endif

// Defite como os elementos do conjunto ser�o organizados na mem�ria.
// � declarado aqui, mas s� � implementado em set.cc para n�o violar o
// encapsulamento
struct node;

// Implementa um conjunto utilizando �rvores bin�rias de busca.
// NOTA: O c�lculo da complexidade das fun��es assume que a �rvore est�
// balanceada, ou seja, considera-se que a altura da arvore � O(log n), onde n
// � a cardinalidade do conjunto. Entretanto, isto n�o � garantido nesta
// implenta��o.
class set {
 public:
  // Cria um conjunto vazio em O(1).
  set();

  // Cria um conjunto com os mesmos elementos de s em O(m), onde m = s.size().
  set(set& s);

  // Libera toda a mem�ria alocada para o conjunto em O(n*log n),
  // onde n � o n�mero de elementos no conjunto.
  ~set();

  // Retorna um ponteiro para o MENOR elemento do conjunto em O(log n).
  // Caso o conjunto esteja vazio, rentorna um ponteiro para set::end().
  node* begin();

  // Retorna um ponteiro para o "marcador de fim" do conjunto em O(1).
  node* end();

  // Retorna um ponteiro para o sucessor de x no conjunto, ou seja, o menor
  // elemento maior que x em O(log n).
  node* next(node* x);

  // Retorna o valor do elemento apontado por x em (1).
  type value(node* x);

  // Testa se o cojunto est� vazio em O(1).
  bool empty();

  // Retorna o n�mero de elementos no conjunto em O(1).
  int size();

  // Retorna um ponteiro para o elemento cuja chave � k em O(log n),
  // ou um ponteiro para set::end() caso k n�o perten�a ao conjunto.
  // OBS: Note que esta fun��o N�O retorna bool. Para testar se um elemento 'a'
  // pertence a um conjunto 'c', voc� deve escrever "if (c.find(a) != c.end())".
  node* find(type k);

  // Insere k no conjunto em O(log n) e retorna um ponteiro para este elemento.
  // Caso k j� perten�a ao conjunto, um novo elemento N�O � criado e a fun��o
  // retorna um ponteiro para k;
  node* insert(type k);

  // Remove k do conjunto (caso l� ele esteja) em O(log n).
  void erase(type k);

  // Remove todos os elementos do conjunto em O(n*log n).
  void clear();

  // Faz com que o conjunto corrente contenha exatamente os mesmos elementos
  // do cojunto s em O(m*log m), onde m = s.size().
  void operator=(set& s);

 private:
  // N�mero de elementos no conjunto.
  int size_;

  // Raiz da �rvore bin�ria de busca que representa o conjunto.
  node* end_;

  friend class Teste;
};
#endif  // SET_SRC_SET_H_
