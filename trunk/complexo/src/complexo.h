// Copyright 2010 Thiago Noronha
#ifndef COMPLEXO_SRC_COMPLEXO_H_
#define COMPLEXO_SRC_COMPLEXO_H_

// Representa um numero complexo.
struct Complexo {
 private:
  float real_;  // Parte real;
  float imag_;  // Parte imaginaria.

 public:
  // Cria o numero complexo 0 + 0i.
  Complexo();

  // Cria o numero complexo a + 0i.
  Complexo(float a);

  // Cria o numero complexo a + bi.
  Complexo(float a, float b);

  // Retorna a parte real do numero complexo corrente.
  float real();

  // Retorna a parte imaginaria do numero complexo corrente.
  float imag();

  // Atribui 'a + bi' ao numero complexo corrente.
  void Atribuir(float a, float b);

  // Retorna o modulo do numero complexo corrente.
  float modulo();

  // Testa se o numero complexo corrente eh igual a 'x'.
  bool igual(Complexo x);

  // Atribui 'x' ao numero complexo corrente.
  void Igualar(Complexo x);

  // Atribui o conjugado de 'x' ao numero complexo corrente.
  void Conjugar(Complexo x);

  // Atribui o inverso multiplicativo de x ao numero complexo corrente.
  void Inverter(Complexo x);

  // Atribui a soma de 'x' e 'y' ao numero complexo corrente.
  void Somar(Complexo x, Complexo y);

  // Atribui a subtracao de 'x' e 'y' (x - y) ao numero complexo corrente.
  void Subtrair(Complexo x, Complexo y);

  // Atribui o produto de 'x' e 'y' ao numero complexo corrente.
  void Multiplicar(Complexo x, Complexo y);

  // Atribui a divisao de 'x' e 'y' (x / y) ao numero complexo corrente.
  void Dividir(Complexo x, Complexo y);
};

#endif  // COMPLEXO_SRC_COMPLEXO_H_
