// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef POLINOMIO_SRC_POLINOMIO_H_

#define POLINOMIO_SRC_POLINOMIO_H_

class Polinomio {
 public:
  // Cria um polinômio nulo (P(x)=0).
  Polinomio();

  // Cria um polinômio igual a P(x)=x^m.
  Polinomio(int g);

  // Cria um polinômio idêntico a q.
  Polinomio(Polinomio& q);

  // Retorna verdadeiro se o polinomio é nulo, false c.c.
  bool nulo();

  // Retorna o grau do polinômio. O polinomio não pode ser nulo,
  // uma vez que um polinomio nulo nao tem grau.
  int grau();

  // Retorna uma referência ao coeficiente a[i].
  // NOTA: Retornamos uma referência para um coeficiente do polinômio para
  // podermos alterar o valor deste coeficiente fora da classe.
  float& at(int i);
  float& operator[](int i) {return at(i);}

  // Retorna o valor do polinômio corrente no ponto x.
  float Avaliar(float x);
  float operator()(float x) {return Avaliar(x);}

  // Faz com que o polinômio corrente fique igual ao polinômio q.
  void Atribuir(Polinomio& q);
  void operator=(Polinomio& q) {Atribuir(q);}

  // Faz com que o polinômio corrente fique igual a derivada do polinômio q.
  // q não pode ser nulo.
  void Derivar(Polinomio& q);

  // Faz com que o polinômio corrente fique igual a integral do polinômio q.
  // q não pode ser nulo.
  void Integrar(Polinomio& q);

  // Libera a memória alocada para o vetor 'a'.
  ~Polinomio();

 private:
  // Número de elementos no vetor 'a'. O grau do polinômio é n - 1.
  int n_;

  // Vetor com os coeficientes do polinômio.
  float* coeficientes_;

  // Realoca a memória alocada para o vetor 'a'.
  // O novo bloco de memória terá m elementos.
  // NOTA: Esta função é definida como "private:" porque é usada apenas
  // internamente na classe.
  void Realocar(int m);

  friend class Teste;
};

#endif  // POLINOMIO_SRC_POLINOMIO_H_
