// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef POLINOMIO_SRC_POLINOMIO_H_

#define POLINOMIO_SRC_POLINOMIO_H_

#define GRAU_MAXIMO 1000

class Polinomio {
  int n;  // Numero de elementos no vetor 'a'. O grau do polinomio eh n - 1.
  float a[GRAU_MAXIMO + 1];  // Vetor com os coeficientes do polinomio.

  public:
  // Cria um polinômio igual a P(x)=0.
  Polinomio();

  // Cria um polinômio a partir de um vetor q com m elementos.
  Polinomio(int m, float* q);

  // Retorna o grau do polinômio.
  int grau();

  // Retorna o coeficiente a[i].
  float get(int i);

  // Atribui o valor 'b' ao coeficiente a[i].
  void set(int i, float b);

  // Retorna o valor do polinômio corrente no ponto x.
  float Avaliar(float x);

  // Faz com que o polinômio corrente fique igual ao polinômio q
  // passado como parâmetro.
  void Atribuir(Polinomio& q);

  // Atribui ao polinômio corrente a soma dos polinômios p1 e p2
  // de mesmo grau passados como parâmetro.
  void Somar(Polinomio& p1, Polinomio &p2);

  // Faz com que o polinômio corrente fique igual a derivada do polinômio q
  // passado como parâmetro.
  void Derivar(Polinomio& q);

  // Faz com que o polinômio corrente fique igual a integral do polinômio q
  // passado como parâmetro.
  void Integrar(Polinomio& q);
};

#endif  // POLINOMIO_SRC_POLINOMIO_H_
