// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef FUNCOES3_SRC_FUNCOES_H_
#define FUNCOES3_SRC_FUNCOES_H_

// Calcula a area do trapezio de base maior B, base menor b e altura h
float AreaTrapezio(float B, float b, float h);

// Retorna o maior entre a, b e c
float Maior(float a, float b, float c);

// Retorna true se a, b e c podem ser lados de
// um mesmo triangulo e false caso contrario
bool FormamTriangulo(float a, float b, float c);

// Calcula a area do triangulo de lados a, b e c
float AreaTriangulo(float a, float b, float c);

// Calcula o valor de g(graus) em radianos
float GrausRadianos(float g);

// Calcula o valor do angulo expresso em g graus
// m minutos e s segundos em graus.
float SexagenalDecimal(float g, float m, float s);

// Calcula a soma de todos os inteiros de 1 a n
float SomaMenoresOuIguais(int n);

// Calcula o x para o qual y e maximo da parabola definida
// por a.x2 + b.x + c., a < 0
float XParaYMaximo(float a, float b, float c);

// Calcula o y maximo da parabola definida
// por a.x2 + b.x + c., a < 0
float YMaximo(float a, float b, float c);

// Calcula a distancia entre os pontos (x1,y1) e (x2,y2) no plano cartesiano.
float DistanciaPontos(float x1, float y1, float x2, float y2);

#endif  // FUNCOES3_SRC_FUNCOES_H_
