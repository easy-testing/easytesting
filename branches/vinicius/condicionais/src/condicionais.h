// copyright 2012 Universidade Federal de Minas Gerais (UFMG)
#ifndef TRUNK_FUNCOES_SRC_CONDICIONAIS_H_
#define TRUNK_FUNCOES_SRC_CONDICIONAIS_H_

// Retorna o menor valor entre dois n�meros.
int menor(int x, int y);

// Retorna o maior valor entre dois n�meros.
int maior(int x, int y);

// Retorna o maior valor entre tr�s n�meros.
int maior(int x, int y, int z);

// Retorna verdadeiro se o n�mero for positivo, falso do contr�rio.
bool verifica_sinal(int x);

// Retorna verdadeiro se o n�mero for par, falso do contr�rio.
bool verifica_par_impar(int x);

// Calcule a potencencia entre dois n�meros, onde o maior n�mero
// ser� a base e o menor o expoente.
int potenciacao(int x, int y);

// Divide 'a' por 'b' e retorna a resposta em 'r',
// em caso de divis�o por zero a fun��o retorna retornar falso.
bool divisao(int a, int b, int &r);

// Dado os tr�s lados de um tri�ngulo, informa qual tipo de tri�ngulo �.
// Retorna (1) se for Triangulo equilatero, (2) se for Triangulo isosceles
// e (3) se for Triangulo escaleno.
int tipo_triangulo(int a, int b, int c);

#endif  // TRUNK_FUNCOES_SRC_CONDICIONAIS_H_
