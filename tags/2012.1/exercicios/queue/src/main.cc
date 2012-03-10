// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Filas.
//
// Questão 1.
// Implemente em queue.h e queue.cc o TAD queue, utilizando listas encadeadas.
//
// Questão 2.
// Escreva uma função "void Imprimir(queue& q)" que recebe
// como parâmetro uma fila q e imprime os elemento de q na tela.
//
// Questão 3.
// Escreva um programa que gerencia uma fila de banco. Ao entrar na fila,
// o cliente dá seu nome e sua idade. Os clientes são atendidos por ordem de
// chegada. Entretanto, os clientes com 60 anos ou mais tem prioridade sobre
// os outros clientes, ou seja, um cliente com menos de 60 anos só é atendido
// se não houver nenhum cliente com 60 anos ou mais esperando na fila. O sistema
// que você vai implementar deve apresentar duas opções: "(1) Entrar na fila" e
// "(2) Próximo da fila". Na Primeira, o sistema deve cadastrar o nome e a
// idade do cliente. Já na segunda opção, ele deve imprimir o nome do
// próximo cliente que está esperando e retirá-lo da fila, ou imprimir uma
// mensagem indicando que a fila está vazia.
// DICA: Use duas filas: uma para armazenar os nomes dos clientes
// prioritários e outra para armazenar os nomes dos clientes não prioritários.

#include "queue/src/queue.h"

int main() {
  return 0;  // TODO.
}
