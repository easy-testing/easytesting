// copyright 2012 Universidade Federal de Minas Gerais (UFMG)
#ifndef TRUNK_FUNCOES_SRC_CONDICIONAIS_H_
#define TRUNK_FUNCOES_SRC_CONDICIONAIS_H_

#include <string>

// Retorna o menor valor entre dois números.
int menor(int x, int y);

// Retorna o maior valor entre dois números.
int maior(int x, int y);

// Retorna o maior valor entre três números.
int maior(int x, int y, int z);

// Retorna verdadeiro se o numero for par, falso do contrário.
bool par(int x);

// Calcule a potencencia entre dois numeros, onde o maior valor entre x e y
// será a base e o menor o expoente.
int potenciacao(int x, int y);

// Testa se abc formam um triângulo.
bool triangulo(float a, float b, float c);

// Retorna verdadeiro se abc for um triângulo equilátero.
// Precondição abc deve ser um triangulo.
bool equilatero(float a, float b, float c);

// Retorna verdadeiro se abc for um triângulo isósceles.
// Precondição abc deve ser um triangulo.
bool isosceles(float a, float b, float c);

// Retorna verdadeiro se abc for um triângulo escaleno.
// Precondição abc deve ser um triangulo.
bool escaleno(float a, float b, float c);

// Recebe o dia e o mês de nascimento e retorna o signo de uma pessoa.
std::string signo(int dia, int mes);

#endif  // TRUNK_FUNCOES_SRC_CONDICIONAIS_H_
