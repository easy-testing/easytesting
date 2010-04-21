// Copyright 2010, Nat� Goulart da Silva - Curso ARL UFLA
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
// Lista 2: Tipos Abstratos de Dados.
//
// Introdu��o: Um polin�mio de grau n � uma fun��o do tipo
// P(x) = a0 + a1x + a2x2 + ... + anxn, onde a0, a1, a2, ... , an pertencem ao
// conjunto dos n�meros reais. Qualquer polin�mio de grau n pode ser
// representado em um programa de computador por um vetor p com n + 1 posi��es,
// onde cada posi��o p[i] do vetor armazena o valor do coeficiente
// ai, i  {0, ..., n}. Por exemplo: o polin�mio de grau 4,
// Q(x) = 5 + 3x2 + 2x4 = 5x0 + 0x1 + 3x2 + 0x3 + 2x4,
// pode ser representado pelo vetor "float q[5] = {5, 0, 3, 0, 2};"

#ifndef POLINOMIOS_H_
#define POLINOMIOS_H_

#define GRAU_MAXIMO 1000

class Polinomio {
// Dados.
private:
  int n;
  float a[GRAU_MAXIMO + 1];

// M�todos.
public:
  // Cria um polin�mio igual a P(x)=0.
  Polinomio();
       
  // Cria um polin�mio a partir de um vetor q com m elementos.
  Polinomio(int m, float* q);

  // Retorna o grau do polin�mio.
  int grau();
  
  // Retorna o coeficiente a[i].
  float get(int i);
  
  // Atribui o valor 'b' ao coeficiente a[i]. 
  void set(int i, float b);
  
  // Retorna o valor do polin�mio corrente no ponto x.
  float Avaliar(float x);
      
  // Faz com que o polin�mio corrente fique igual ao polin�mio q 
  // passado como par�metro.
  void Atribuir(Polinomio& q);
    
  // Atribui ao polin�mio corrente a soma dos polin�mios p1 e p2 
  // de mesmo grau passados como par�metro. 
  void Somar(Polinomio& p1, Polinomio &p2);

  // Faz com que o polin�mio corrente fique igual a derivada do polin�mio q
  // passado como par�metro.    
  void Derivar(Polinomio& q);

  // Faz com que o polin�mio corrente fique igual a integral do polin�mio q 
  // passado como par�metro.    
  void Integrar(Polinomio& q);
 };

#endif  // POLINOMIOS_H_
