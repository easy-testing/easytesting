// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre listas encadeadas - deque.
//
// Questão 1.
// Vide main1.cc.
//
// Questão 2.
// Vide main1.cc.
//
// Questão 3.
// Vide main1.cc.
//
// Questão 4.
// Vide main1.cc.
//
// Questão 5.
// Escreva um programa que gerencia uma fila de eventos com duas prioridades.
// Eventos de alta prioridade (high) tem precedência sobre eventos de
// baixa prioridade (low), ou seja, um evento de baixa prioridade só é atendido
// se não existir nenhum evendo de alta prioridade na fila. Eventos de alta
// prioridade são atendidos de acordo com um protocolo LIFO (Last In
// First Out), ou seja, o último evento de alta prioridade que foi inserido na
// fila é o próximo a ser atendido. Já os eventos de baixa prioridade são
// atendidos de acordo com um protocolo FIFO (First In First Out), ou seja,
// os eventos de baixa prioridade são atendidos na ordem em que entraram na
// fila. O seu programa deve ler de um arquivo (ou do teclado) operações do tipo
// "in" e "out". No caso de um operação do tipo "in" seu programa deve solicitar
// o nome e a prioridade do evento e inserir o nome do evento na fila
// de eventos. No caso de operações "out", o seu programa deve retirar o nome
// no próximo evento que será atendido e imprimi-lo na tela.
// Tome o arquivo "input2.txt" como exemplo. A saída do seu programa para este
// arquivo deveria ser "e2 e5 e1 e3 e4 e6 e7".
// DICA: Use apenas um único deque com o nome dos eventos para gerenciar a fila
// de eventos.

#include "deque/src/deque.h"

int main() {
  return 0;  // TODO.
}
