// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_FUNCOES3_SRC_FUNCOES_H_
#define BRANCHES_GABARITOS_FUNCOES3_SRC_FUNCOES_H_

// Calcula a area do trapezio de base maior B, base menor b e altura h
float area_trapezio(float B, float b, float h);

// Retorna o maior entre a, b e c
float maior(float a, float b, float c);

// Retorna true se a, b e c podem ser lados de
// um mesmo triangulo e false caso contrario
bool formam_triangulo(float a, float b, float c);

// Calcula a area do triangulo de lados a, b e c
float area_triangulo(float a, float b, float c);

// Calcula o valor de g(graus) em radianos
float graus_radianos(float g);

// Calcula o valor do angulo expresso em g graus
// m minutos e s segundos em graus.
float grauminutosegundo_grau(float g, float m, float s);

// Calcula a soma de todos os inteiros de 1 a n
float soma_progressao(int n);

// Calcula o x para o qual y e maximo da parabola definida
// por a.x2 + b.x + c., a < 0
float xy_maximo(float a, float b, float c);

// Calcula o y maximo da parabola definida
// por a.x2 + b.x + c., a < 0
float y_maximo(float a, float b, float c);

// Calcula a distancia entre os pontos (x1,y1) e (x2,y2) no plano cartesiano.
float distancia_pontos(float x1, float y1, float x2, float y2);

#endif  // BRANCHES_GABARITOS_FUNCOES3_SRC_FUNCOES_H_
