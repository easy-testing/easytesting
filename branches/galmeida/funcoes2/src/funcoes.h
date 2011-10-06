// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#ifndef FUNCOES_SRC_FUNCOES_H_
#define FUNCOES_SRC_FUNCOES_H_

// 1: Calcula a posicao final da trajetoria de um projetil disparado do solo
// com um angulo a(graus) em relação ao eixo horizontal(sentido anti-horario),
// partindo da posicao xi(metros) do eixo x e com velocidade inicial igual a v metros/segundo (em modulo).
// Considere que a regiao e totalmente plana, g=10m/s2 e despreze a resistencia do ar 
float Destino_disparo(float xi, float a, float v);

// 2: Verifica se um valor x pertence ao intervalo fechado [a,b] com tolerancia* de 0.1m 
//   (o valor pode diferir em ate 0.1m dos limites e ainda ser considerado pertencente a ele).
//   *Essa tolerancia nao e apenas uma caracteristica da funcao, mas algo necessario
//    ao se comparar numeros flutuante( devido a imprecisoes inerentes a representacao 
//    de numeros reais nas maquinas ). Mas na pratica as tolerancias usadas sao bem menores. 
//    Detalhes em http://en.wikipedia.org/wiki/Floating_point#Accuracy_problems
//	
bool Pertence_intervalo(float x, float a, float b);


#endif  // FUNCOES_SRC_FUNCOES_H_
