// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_FUNCOES_SRC_FUNCOES_H_
#define TRUNK_FUNCOES_SRC_FUNCOES_H_

// Calcula a média de a, b e c.
float media(float a, float b, float c);

// Calcula a média ponderada de a, b e c onde a tem peso 3, b 4 e c 5.
float media_ponderada(float a, float b, float c);

// Calcula o perímetro de um círculo de raio r.
float perimetro(float r);

// Calcula a área de um círculo de raio r.
float area_circulo(float r);

// Calcula a área de um triângulo de base b e altura c.
float area_triangulo(float b, float c);

// Calcula a área de uma caixa de dimensões a, b e c.
float area_caixa(float a, float b, float c);

// Calcula o volume de uma caixa de dimensões a, b e c.
float volume_caixa(float a, float b, float c);

// Calcula a área de um cilindro de raio r e altura h.
float area_cilindro(float r, float h);

// Calcula o volume de um cilindro de raio r e altura h.
float volume_cilindro(float r, float h);

// Calcula a hipotenusa de um triângulo retângulo,
// cujos lados conhecidos são b e c.
float hipotenusa(float b, float c);

#endif  // TRUNK_FUNCOES_SRC_FUNCOES_H_
