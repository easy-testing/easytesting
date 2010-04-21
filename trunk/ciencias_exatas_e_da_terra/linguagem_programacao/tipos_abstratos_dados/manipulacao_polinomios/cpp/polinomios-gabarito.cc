// Copyright 2010, Natã Goulart da Silva - Curso ARL UFLA
// Copyright 2010, Thiago Ferreira de Noronha - DCC UFMG
//
// This file is part of EasyTesting.
//
// EasyTesting is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License // as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// EasyTesting is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY; without even the implied warranty // of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with Foobar.  If not, see 

// <http://www.gnu.org/licenses/>.
//  Algoritmos e Estruturas de Dados II
//

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
  float soma = 0;
  for (int i = 0; i < n; i++) {
    soma += a[i] * pow(x, i);
  }
  return soma;
}

void Polinomio::Atribuir(Polinomio& q) {
  n = q.grau() + 1;
  for (int i = 0; i < n; i++) {
    a[i] = q.a[i];    
  }                
}

void Polinomio::Somar(Polinomio& p1, Polinomio &p2) {
   n = p1.grau() + 1;
   for (int i = 0; i < n; i++) {
      a[i] = p1.get(i) + p2.get(i);
   }
}

void Polinomio::Derivar(Polinomio& q) {
  n = q.grau();
  for (int i = 0; i < n; i++) {
    a[i] = q.get(i + 1) * (i + 1);
  }         
}

void Polinomio::Integrar(Polinomio& q) {
  n = q.grau() + 2;
  a[0] = 0.0;
  for (int i = 0; i < n; i++) {
    a[i + 1] = q.get(i) / (i + 1);
  }  
}
