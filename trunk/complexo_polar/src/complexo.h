// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef COMPLEXO_SRC_COMPLEXO_H_
#define COMPLEXO_SRC_COMPLEXO_H_

// Representa um número complexo.
struct Complexo {
 private:
  float arg_;  // Argumento do número complexo.
  float mod_;  // Módulo do número compelxo.

 public:
  // Cria o número complexo 0 + 0i.
  Complexo();

  // Cria o número complexo a + 0i.
  Complexo(float a);

  // Cria o número complexo a + bi.
  Complexo(float a, float b);

  // Retorna a parte real do número complexo corrente.
  float real();

  // Retorna a parte imaginária do número complexo corrente.
  float imag();

  // Testa se o número complexo corrente é igual a 'x'.
  bool operator==(Complexo x);

  // Atribui 'x' ao número complexo corrente.
  void operator=(Complexo x);

  // Retorna o módulo do número complexo corrente.
  float modulo();

  // Retorna o conjugado do número complexo corrente.
  Complexo conjugado();

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
};

#endif  // COMPLEXO_SRC_COMPLEXO_H_
