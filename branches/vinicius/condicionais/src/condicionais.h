// copyright 2012 Universidade Federal de Minas Gerais (UFMG)
#ifndef TRUNK_FUNCOES_SRC_CONDICIONAIS_H_
#define TRUNK_FUNCOES_SRC_CONDICIONAIS_H_

// Retorna o menor valor entre dois números.
int menor(int x, int y);

// Retorna o maior valor entre dois números.
int maior(int x, int y);

// Retorna o maior valor entre três números.
int maior(int x, int y, int z);

// Retorna verdadeiro se o número for positivo, falso do contrário.
bool verifica_sinal(int x);

// Retorna verdadeiro se o número for par, falso do contrário.
bool verifica_par_impar(int x);

// Calcule a potencencia entre dois números, onde o maior número
// será a base e o menor o expoente.
int potenciacao(int x, int y);

// Divide 'a' por 'b' e retorna a resposta em 'r',
// em caso de divisão por zero a função retorna retornar falso.
bool divisao(int a, int b, int &r);

// Dado os três lados de um triângulo, informa qual tipo de triângulo é.
// Retorna (1) se for Triangulo equilatero, (2) se for Triangulo isosceles
// e (3) se for Triangulo escaleno.
int tipo_triangulo(int a, int b, int c);

#endif  // TRUNK_FUNCOES_SRC_CONDICIONAIS_H_
