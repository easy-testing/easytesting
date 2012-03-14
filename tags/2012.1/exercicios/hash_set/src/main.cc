// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Conjuntos.
//
// Questão 1.
// Implemente em set.h e set.cc o TAD set, utilizando árvores binárias de busca.
//
// Questão 2.
// Escreva uma função "void Imprimir(set& s)" que recebe
// como parâmetro um conjunto s e imprime os elementos de s na tela.
//
// Questão 3.
// Escreva uma função
// "void Intersecao(set& a, set& b, set* inter)" que recebe dois conjuntos
// 'a' e 'b' e atribui a 'inter' o resultado da interseção de 'a' e 'b'.
//
// Questão 4.
// Escreva uma função
// "void Uniao(set& a, set& b, set* uniao)" que recebe dois conjuntos
// 'a' e 'b' e atribui a 'uniao' o resultado da união de 'a' e 'b'.
//
// Questão 5.
// Escreva um programa que gerencia os fornecedores para compra de peças
// em uma montadora de carros. As peças são identificadas por números inteiros
// entre 1 e 100 e os fornecedores são identificados por uma string.
//
// O sistema deve ler de um arquivo o nome dos fornecedores de peças e a lista
// das peças que cada fornecedor vende. Tome como EXEMPLO o
// arquivo "fornecedores.txt". A  primeira linha deste arquivo contém o número n
// de fornecedores. As n linhas seguintes contêm uma string com o nome de um
// fornecedor, seguida de um número 'm' (de peças que o fornecedor vende),
// que por sua vez é seguido de 'm' números naturais, cada um deles referente a
// uma das peças vendidas pelo fornecedor.
//
// O seu programa deve inicialmente exibir o conjunto com todos os
// fornecedores e o conjunto de todas as peças.
// A cada iteração, o usuário deve ser capaz de digitar o número
// de uma peça e o sistema deve eliminar do conjunto de fornecedores candidatos
// aqueles que não vendem a última peça digitada. O programa deve continuar
// pedindo o número de uma nova peça até que o usuário digite zero ou até
// que o conjunto de fornecedores candidatos seja vazio.
//
// DICA: crie um conjunto "set candidatos" que contém
// inicialmente o nome de todos os fornecedores e um vetor
// "set pecas[100]" com o conjunto de fornecedores para cada
// peça. A cada iteração em que uma peça 'p' for digitada, você deve fazer a
// interseção do conjunto 'candidatos' com o conjunto 'pecas[p - 1]'.

#include "hash_set/src/set.h"

int main() {
  return 0;  // TODO.
}
