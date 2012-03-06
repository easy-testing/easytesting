// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_POLINOMIO_SRC_POLINOMIO_H_
#define TRUNK_POLINOMIO_SRC_POLINOMIO_H_

// Retorna verdadeiro se o polinomio v de grau g é nulo (g < 0), false c.c.
bool nulo(int g, float v[]);

// Retorna o valor do polinômio v de grau g no ponto x.
float Avaliar(int g, float v[], float x);

// Faz com que o polinômio u fique igual ao polinômio v de grau g.
void Atribuir(int g, float v[], float u[]);

// Faz com que o polinômio u fique igual a derivada do polinômio v de grau g.
// v não pode ser nulo.
void Derivar(int g, float v[], float u[]);

// Faz com que o polinômio u fique igual a integral do polinômio v de grau g.
// v não pode ser nulo.
void Integrar(int g, float v[], float u[]);

// Imprime o polinômio v de grau g no formato
// "v[0] + v[1]*x + v[2]*x^2 + ... + v[g]*^g", para todos os v[i] > 0.
// Por exemplo:
//   v={7} imprime "7".
//   v={4, -2.7, 3.8, -5, 1} imprime "4 - 2.7x + 3.8x^2 - 5x^3 + x^4".
//   v={0, -0.2, 0, 3, -1} imprime "-0.2x + 3x^3 - x^4".
//   v={0, 0, 3, -1} imprime "3x^2 - x^3".
//   v={-5, 0, 1} imprime "-5 + x^2"
//   v={0, -1, 1} imrpime "-x + x^2",
//   v={0, 1, -1} imprime "x - x^2",
void Imprimir(int g, float v[]);

#endif  // TRUNK_POLINOMIO_SRC_POLINOMIO_H_
