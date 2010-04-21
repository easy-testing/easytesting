#include "polinomios.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

Polinomio::Polinomio() {
  n = 1;
  a[0] = 0.0;
}

Polinomio::Polinomio(int m, float* q) {
  n = m;
  for (int i = 0; i < m; i++) {
    a[i] = q[i];    
  }    
}

int Polinomio::grau() {
  return n - 1;    
}

float Polinomio::get(int i) {
  return a[i];    
}

void Polinomio::set(int i, float b) {
  a[i] = b;    
}

float Polinomio::Avaliar(float x) {
  // Questao 2.
  return 0.0;
}

void Polinomio::Atribuir(Polinomio& q) {
  // Questao 3.               
}

void Polinomio::Somar(Polinomio& p1, Polinomio &p2) {
  // Questao 4.
}

void Polinomio::Derivar(Polinomio& q) {
  // Questao 5.        
}

void Polinomio::Integrar(Polinomio& q) {
  // Questao 6.
}
