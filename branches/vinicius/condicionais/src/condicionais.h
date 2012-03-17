// copyright 2012 Universidade Federal de Minas Gerais (UFMG)
#ifndef TRUNK_FUNCOES_SRC_CONDICIONAIS_H_
#define TRUNK_FUNCOES_SRC_CONDICIONAIS_H_

// Retorna o menor valor entre dois numeros.
int menor(int x, int y);

// Retorna o maior valor entre dois numeros.
int maior(int x, int y);

// Retorna o maior valor entre tres numeros.
int maior(int x, int y, int z);

// Retorna verdadeiro se o numero for positivo, falso do contrario.
bool verifica_sinal(int x);

// Retorna verdadeiro se o numero for par, falso do contrario.
bool verifica_par_impar(int x);

// Calcule a potencencia entre dois numeros, onde o maior numero
// sera a base e o menor o expoente.
int potenciacao(int x, int y);

// Divide 'a' por 'b' e retorna a resposta em 'r',
// em caso de divisao por zero a funcao retorna retornar falso.
bool divisao(int a, int b, int& r);

// Dado os tres lados de um triangulo, informa qual tipo de triangulo e.
// Retorna (1) se for Triangulo equilatero, (2) se for Triangulo isosceles
// e (3) se for Triangulo escaleno.
int tipo_triangulo(int a, int b, int c);

#endif  // TRUNK_FUNCOES_SRC_CONDICIONAIS_H_
