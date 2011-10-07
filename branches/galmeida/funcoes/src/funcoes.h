// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#ifndef FUNCOES_SRC_FUNCOES_H_
#define FUNCOES_SRC_FUNCOES_H_

// Calcula a media de a, b e c.
float Media(float a, float b, float c);

// Calcula a media ponderada de a, b e c onde a tem peso 3, b 4 e c 5.
float MediaPonderada(float a, float b, float c);

// Calcula o perimetro de um circulo de raio r.
float Perimetro(float r);

// Calcula a area de um circulo de raio r.
float AreaCirculo(float r);

// Calcula a area de um triangulo de base b e altura c.
float AreaTriangulo(float b, float c);

// Calcula a area de uma caixa de dimensoes a, b e c.
float AreaCaixa(float a, float b, float c);

// Calcula o volume de uma caixa de dimensoes a, b e c.
float VolumeCaixa(float a, float b, float c);

// Calcula a area de um cilindro de raio r e altura h.
float AreaCilindro(float r, float h);

// Calcula o volume de um cilindro de raio r e altura h.
float VolumeCilindro(float r, float h);

// Calcula a hipotenusa de um triangulo retangulo,
// cujos lados conhecidos sao b e c.
float Hipotenusa(float b, float c);

// Calcula a raiz positiva da equacao do segundo grau definida
// por a.x2 + b.x + c.
float RaizPositiva(float a, float b, float c);

#endif  // FUNCOES_SRC_FUNCOES_H_
