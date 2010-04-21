#ifndef POLINOMIOS_H_

#define POLINOMIOS_H_

// Copyright 2010 Thiago Ferreira de Noronha.
//
//  Algoritmos e Estruturas de Dados II
//
// Lista 2: Tipos Abstratos de Dados.
//
// Introdução: Um polinômio de grau n é uma função do tipo
// P(x) = a0 + a1x + a2x2 + ... + anxn, onde a0, a1, a2, ... , an pertencem ao
// conjunto dos números reais. Qualquer polinômio de grau n pode ser
// representado em um programa de computador por um vetor p com n + 1 posições,
// onde cada posição p[i] do vetor armazena o valor do coeficiente
// ai, i  {0, ..., n}. Por exemplo: o polinômio de grau 4,
// Q(x) = 5 + 3x2 + 2x4 = 5x0 + 0x1 + 3x2 + 0x3 + 2x4,
// pode ser representado pelo vetor "float q[5] = {5, 0, 3, 0, 2};"

#define GRAU_MAXIMO 1000

class Polinomio {
// Dados.
private:
  int n;
  float a[GRAU_MAXIMO + 1];

// Métodos.
public:
  // Cria um polinômio igual a P(x)=0.
  Polinomio();
       
  // Cria um polinômio a partir de um vetor q com m elementos.
  Polinomio(int m, float* q);

  // Retorna o grau do polinômio.
  int grau();
  
  // Retorna o coeficiente a[i].
  float get(int i);
  
  // Atribui o valor 'b' ao coeficiente a[i]. 
  void set(int i, float b);
  
  // Retorna o valor do polinômio corrente no ponto x.
  float Avaliar(float x);
      
  // Faz com que o polinômio corrente fique igual ao polinômio q 
  // passado como parâmetro.
  void Atribuir(Polinomio& q);
    
  // Atribui ao polinômio corrente a soma dos polinômios p1 e p2 
  // de mesmo grau passados como parâmetro. 
  void Somar(Polinomio& p1, Polinomio &p2);

  // Faz com que o polinômio corrente fique igual a derivada do polinômio q
  // passado como parâmetro.    
  void Derivar(Polinomio& q);

  // Faz com que o polinômio corrente fique igual a integral do polinômio q 
  // passado como parâmetro.    
  void Integrar(Polinomio& q);
 };

#endif  // POLINOMIOS_H_
