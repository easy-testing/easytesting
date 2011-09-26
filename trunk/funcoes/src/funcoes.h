// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef BRANCHES_GABARITOS_FUNCOES3_SRC_FUNCOES_H_
#define BRANCHES_GABARITOS_FUNCOES3_SRC_FUNCOES_H_

// Calcula a media de a, b e c.
float media(float a, float b, float c);

// Calcula a media ponderada de a, b e c onde a tem peso 3, b 4 e c 5.
float media_ponderada(float a, float b, float c);

// Calcula o perimetro de um circulo de raio r.
float perimetro(float r);

// Calcula a area de um circulo de raio r.
float area_circulo(float r);

// Calcula a area de um triangulo de base b e altura c.
float area_triangulo(float b, float c);

// Calcula a area de uma caixa de dimensoes a, b e c.
float area_caixa(float a, float b, float c);

// Calcula o volume de uma caixa de dimensoes a, b e c.
float volume_caixa(float a, float b, float c);

// Calcula a area de um cilindro de raio r e altura h.
float area_cilindro(float r, float h);

// Calcula o volume de um cilindro de raio r e altura h.
float volume_cilindro(float r, float h);

// Calcula a hipotenusa de um triangulo retangulo,
// cujos lados conhecidos sao b e c.
float hipotenusa(float b, float c);

// Calcula a raiz positiva da equacao do segundo grau definida
// por a.x2 + b.x + c.
float raiz_positiva(float a, float b, float c);

#endif  // BRANCHES_GABARITOS_FUNCOES3_SRC_FUNCOES_H_
