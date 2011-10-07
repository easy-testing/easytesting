// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef FUNCOES2_SRC_FUNCOES_H_
#define FUNCOES2_SRC_FUNCOES_H_

// Calcula a posicao final da trajetoria de um projetil
// disparado do solo com um angulo a(graus) em relação ao
// eixo horizontal(sentido anti-horario), partindo da
// posicao xi(metros) do eixo x e com velocidade inicial
// igual a v metros/segundo.Considere que a regiao e
// totalmente plana, g=10m/s2 e despreze a resistencia
// do ar
float DestinoDisparo(float xi, float a, float v);

//  Verifica se um valor x pertence ao intervalo fechado
//  [a,b] com tolerancia de 0.001
bool PertenceIntervalo(float x, float a, float b);

#endif  // FUNCOES2_SRC_FUNCOES_H_
