// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_COMPLEXO_POLAR_SRC_COMPLEXO_H_
#define TRUNK_COMPLEXO_POLAR_SRC_COMPLEXO_H_

// Representa um número complexo.
class Complexo {
 private:
  // Módulo do número complexo.
  double mod_;

  // Argumento do número complexo em radianos.
  double arg_;

 public:
  // Cria o número complexo 0 + 0i.
  Complexo();

  // Cria o número complexo a + 0i.
  Complexo(double a);  // NOLINT

  // Cria o número complexo a + bi.
  Complexo(double a, double b);

  // Retorna a parte real do número complexo corrente.
  double real() const;

  // Retorna a parte imaginária do número complexo corrente.
  double imag() const;

  // Testa se o número complexo corrente é igual a 'x'.
  bool operator==(Complexo x) const;

  // Atribui 'x' ao número complexo corrente.
  void operator=(Complexo x);

  // Retorna o módulo do número complexo corrente.
  double modulo() const;

  // Retorna o módulo do número complexo corrente.
  double argumento() const;

  // Retorna o conjugado do número complexo corrente.
  Complexo conjugado() const;

  // Retorna o simétrico do número complexo corrente.
  Complexo simetrico() const;

  // Retorna o inverso multiplicativo do número complexo corrente.
  Complexo inverso() const;

  // Soma o número complexo corrente com 'y' e retorna o resultado.
  Complexo operator+(Complexo y);

  // Subtrai o número complexo corrente por 'y' e retorna o resultado.
  Complexo operator-(Complexo y);

  // Multiplica o número complexo corrente com 'y' e retorna o resultado.
  Complexo operator*(Complexo y);

  // Divide o número complexo corrente por 'y' e retorna o resultado.
  Complexo operator/(Complexo y);

  // Funções do tipo friend para serem usadas nos testes
  friend double realTest(const Complexo& x);

  friend double imagTest(const Complexo& x);

  double moduloTest(const Complexo& x);

  double argumentoTest(const Complexo& x);

  friend bool igual(const Complexo& x, const Complexo& y);
};

#endif  // TRUNK_COMPLEXO_POLAR_SRC_COMPLEXO_H_
