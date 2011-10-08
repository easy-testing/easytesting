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

// Calcula a area de uma caixa de dimensoes a, b e c.
float AreaCaixa(float a, float b, float c);

// Calcula o volume de uma caixa de dimensoes a, b e c.
float VolumeCaixa(float a, float b, float c);

// Calcula a area de um cilindro de raio r e altura h.
float AreaCilindro(float r, float h);

// Calcula o volume de um cilindro de raio r e altura h.
float VolumeCilindro(float r, float h);

// Calcula a area de um triangulo de base b e altura c.
float AreaTriangulo(float b, float c);

// Calcula a area do triangulo de lados a, b e c
float AreaTrianguloLados(float a, float b, float c);

// Calcula o valor de g(graus) em radianos
float GrausRadianos(float g);

// Calcula o valor do angulo expresso em g graus
// m minutos e s segundos em graus.
float SexagenalDecimal(float g, float m, float s);

// Calcula o x para o qual y e maximo da parabola definida
// por a.x2 + b.x + c., a < 0
float XParaYMaximo(float a, float b, float c);

// Calcula o y maximo da parabola definida
// por a.x2 + b.x + c., a < 0
float YMaximo(float a, float b, float c);

// Calcula a distancia entre os pontos (x1,y1) e (x2,y2) no plano cartesiano.
float DistanciaPontos(float x1, float y1, float x2, float y2);

// Calcula a hipotenusa de um triangulo retangulo,
// cujos lados conhecidos sao b e c.
float Hipotenusa(float b, float c);

// Calcula a raiz positiva da equacao do segundo grau definida
// por a.x2 + b.x + c.
float RaizPositiva(float a, float b, float c);

#endif  // FUNCOES_SRC_FUNCOES_H_
