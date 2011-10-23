// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef POLINOMIO_SRC_POLINOMIO_H_

#define POLINOMIO_SRC_POLINOMIO_H_

class Polinomio {
 public:
  // Cria um polin�mio nulo (P(x)=0).
  Polinomio();

  // Cria um polin�mio igual a P(x)=x^m.
  Polinomio(int g);

  // Cria um polin�mio id�ntico a q.
  Polinomio(Polinomio& q);

  // Retorna verdadeiro se o polinomio � nulo, false c.c.
  bool nulo();

  // Retorna o grau do polin�mio. O polinomio n�o pode ser nulo,
  // uma vez que um polinomio nulo nao tem grau.
  int grau();

  // Retorna uma refer�ncia ao coeficiente a[i].
  // NOTA: Retornamos uma refer�ncia para um coeficiente do polin�mio para
  // podermos alterar o valor deste coeficiente fora da classe.
  float& at(int i);
  float& operator[](int i) {return at(i);}

  // Retorna o valor do polin�mio corrente no ponto x.
  float Avaliar(float x);
  float operator()(float x) {return Avaliar(x);}

  // Faz com que o polin�mio corrente fique igual ao polin�mio q.
  void Atribuir(Polinomio& q);
  void operator=(Polinomio& q) {Atribuir(q);}

  // Faz com que o polin�mio corrente fique igual a derivada do polin�mio q.
  // q n�o pode ser nulo.
  void Derivar(Polinomio& q);

  // Faz com que o polin�mio corrente fique igual a integral do polin�mio q.
  // q n�o pode ser nulo.
  void Integrar(Polinomio& q);

  // Libera a mem�ria alocada para o vetor 'a'.
  ~Polinomio();

 private:
  // N�mero de elementos no vetor 'a'. O grau do polin�mio � n - 1.
  int n_;

  // Vetor com os coeficientes do polin�mio.
  float* coeficientes_;

  // Realoca a mem�ria alocada para o vetor 'a'.
  // O novo bloco de mem�ria ter� m elementos.
  // NOTA: Esta fun��o � definida como "private:" porque � usada apenas
  // internamente na classe.
  void Realocar(int m);

  friend class Teste;
};

#endif  // POLINOMIO_SRC_POLINOMIO_H_
