// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Filas.
//
// Questão 1.
// Implemente o TAD queue<Type> em queue.h.
//
// Questão 2.
// Escreva uma função "void Imprimir(queue<string> f)" que recebe
// como parâmetro uma fila f e retira os elementos de f imprimindo-os na tela.
//
// Questão 3.
// Escreva um programa que gerencia uma fila de banco. Ao entrar na fila,
// o cliente dá seu nome e sua idade. Os clientes são atendidos por ordem de
// chegada. Entretanto, os clientes com 60 anos ou mais tem prioridade sobre
// os outros clientes, ou seja, um cliente com menos de 60 anos só é atendido
// se não houver nenhum cliente com 60 anos ou mais esperando na fila. O sistema
// que você vai implementar deve apresentar duas opções: "(1) Entrar na fila" e
// "(2) Próximo da fila". Na Primeira, o sistema deve cadastrar o nome e a
// idade do cliente. Já na segunda opção, ele deve imprimir apenas o nome do
// próximo cliente que está esperando na fila do banco ou uma mensagem
// indicando que a fila está vazia.
// DICA: Use duas filas (queue<string>): uma para armazenar os nomes do clientes
// prioritários e outra para armazenar os nomes dos clientes não prioritários.

#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>

#include "queue/src/queue.h"

using namespace std;

// Retira os elementos da fila f imprimindo-os na tela.
void Imprimir(queue<string>* f) {
  while (!f->empty()) {
    cout << f->front() << endl;
    f->pop();
  }
}

// Insere um cliente na fila do banco.
void Enfileirar(string nome,
                int idade,
                queue<string>* prioritarios,
                queue<string>* nao_prioritarios) {
  if (idade >= 60) {
    prioritarios->push(nome);
  } else {
    nao_prioritarios->push(nome);
  }
}

// Retira o próximo cliente da fila do banco e retorna o seu nome.
string Desenfileirar(queue<string>* prioritarios,
                     queue<string>* nao_prioritarios) {
  string proximo;
  if (!prioritarios->empty()) {
    proximo = prioritarios->front();
    prioritarios->pop();
    return proximo;
  } else if (!nao_prioritarios->empty()) {
    proximo = nao_prioritarios->front();
    nao_prioritarios->pop();
    return proximo;
  } else {
    return "A fila esta fazia.";
  }
}

int main() {
  queue<string> prioritarios;
  queue<string> nao_prioritarios;
  int opcao;
  do {
    // Insiste até que o usuário digite uma opção correta.
    do {
      cout << "(1) Entrar na fila" << endl;
      cout << "(2) Proximo da fila"  << endl;
      cout << "(3) Imprimir Fila"  << endl;
      cout << "(0) Sair"  << endl;
      cout << ">> ";
      cin >> opcao;
    } while (opcao < 0 || opcao > 3);

    // Executa a solicitação do usuário.
    if (opcao == 1) {
      string nome;
      cout << "Nome: ";
      cin >> nome;
      int idade;
      cout << "Idade: ";
      cin >> idade;
      Enfileirar(nome, idade, &prioritarios, &nao_prioritarios);
    } else if (opcao == 2) {
      cout << "\n\n\nPróximo: "
           << Desenfileirar(&prioritarios, &nao_prioritarios) << "\n\n";
    } else if (opcao == 3) {
      cout << "\n\n\Lista de espera:" << endl;
      queue<string> aux = prioritarios;
      Imprimir(&aux);
      aux = nao_prioritarios;
      Imprimir(&aux);
    }
  } while(opcao != 0);
  return 0;
}
