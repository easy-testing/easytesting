// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef COMPLEXO_POLAR_SRC_COMPLEXO_H_
#define COMPLEXO_POLAR_SRC_COMPLEXO_H_

// Representa um número complexo.
struct Complexo {
 private:
  // Módulo do número compelxo.
  double mod_;

  // Argumento do número complexo em radianos.
  double arg_;

 public:
  // Cria o número complexo 0 + 0i.
  Complexo();

  // Cria o número complexo a + 0i.
  Complexo(double a);

  // Cria o número complexo a + bi.
  Complexo(double a, double b);

  // Retorna a parte real do número complexo corrente.
  double real();

  // Retorna a parte imaginária do número complexo corrente.
  double imag();

  // Testa se o número complexo corrente é igual a 'x'.
  bool operator==(Complexo x);

  // Atribui 'x' ao número complexo corrente.
  void operator=(Complexo x);

  // Retorna o módulo do número complexo corrente.
  double modulo();

  // Retorna o conjugado do número complexo corrente.
  Complexo conjugado();

  // Retorna o simétrico do número complexo corrente.
  Complexo simetrico();

  // Retorna o inverso multiplicativo do número complexo corrente.
  Complexo inverso();

  // Soma o número complexo corrente com 'y' e retorna o resultado.
  Complexo operator+(Complexo y);

  // Subtrai o número complexo corrente por 'y' e retorna o resultado.
  Complexo operator-(Complexo y);

  // Multiplica o número complexo corrente com 'y' e retorna o resultado.
  Complexo operator*(Complexo y);

  // Divide o número complexo corrente por 'y' e retorna o resultado.
  Complexo operator/(Complexo y);

  // Usado apenas pelo testador da lista de exercício.
  friend class Teste;
};

#endif  // COMPLEXO_POLAR_SRC_COMPLEXO_H_
