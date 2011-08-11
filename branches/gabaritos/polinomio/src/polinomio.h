// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef POLINOMIO_SRC_POLINOMIO_H_

#define POLINOMIO_SRC_POLINOMIO_H_

#define GRAU_MAXIMO 1000

class Polinomio {
  int n;  // Numero de elementos no vetor 'a'. O grau do polinomio eh n - 1.
  float a[GRAU_MAXIMO + 1];  // Vetor com os coeficientes do polinomio.

  public:
  // Cria um polin�mio igual a P(x)=0.
  Polinomio();

  // Cria um polin�mio a partir de um vetor q com m elementos.
  Polinomio(int m, float* q);

  // Retorna o grau do polin�mio.
  int grau();

  // Retorna o coeficiente a[i].
  float get(int i);

  // Atribui o valor 'b' ao coeficiente a[i].
  void set(int i, float b);

  // Retorna o valor do polin�mio corrente no ponto x.
  float Avaliar(float x);

  // Faz com que o polin�mio corrente fique igual ao polin�mio q
  // passado como par�metro.
  void Atribuir(Polinomio& q);

  // Atribui ao polin�mio corrente a soma dos polin�mios p1 e p2
  // de mesmo grau passados como par�metro.
  void Somar(Polinomio& p1, Polinomio &p2);

  // Faz com que o polin�mio corrente fique igual a derivada do polin�mio q
  // passado como par�metro.
  void Derivar(Polinomio& q);

  // Faz com que o polin�mio corrente fique igual a integral do polin�mio q
  // passado como par�metro.
  void Integrar(Polinomio& q);
};

#endif  // POLINOMIO_SRC_POLINOMIO_H_
