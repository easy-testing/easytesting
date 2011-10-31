// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Filas.
//
// Quest�o 1.
// Implemente em queue.h e queue.cc o TAD queue.
//
// Quest�o 2.
// Escreva uma fun��o "void Imprimir(queue& q)" que recebe
// como par�metro uma fila q e imprime os elemento de q na tela.
//
// Quest�o 3.
// Escreva um programa que gerencia uma fila de banco. Ao entrar na fila,
// o cliente d� seu nome e sua idade. Os clientes s�o atendidos por ordem de
// chegada. Entretanto, os clientes com 60 anos ou mais tem prioridade sobre
// os outros clientes, ou seja, um cliente com menos de 60 anos s� � atendido
// se n�o houver nenhum cliente com 60 anos ou mais esperando na fila. O sistema
// que voc� vai implementar deve apresentar duas op��es: "(1) Entrar na fila" e
// "(2) Pr�ximo da fila". Na Primeira, o sistema deve cadastrar o nome e a
// idade do cliente. J� na segunda op��o, ele deve imprimir o nome do
// pr�ximo cliente que est� esperando e retir�-lo da fila, ou imprimir uma
// mensagem indicando que a fila est� vazia.
// DICA: Use duas filas: uma para armazenar os nomes dos clientes
// priorit�rios e outra para armazenar os nomes dos clientes n�o priorit�rios.

#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>

#include "queue/src/queue.h"

using namespace std;

// Retira os elementos da fila q na tela.
void Imprimir(queue& q) {
  for (int i = 0; i < q.size(); i++) {
    type primeiro = q.front();
    q.pop();
    cout << primeiro << endl;
    q.push(primeiro);
  }
}

// Insere um cliente na fila do banco.
void Enfileirar(string nome,
                int idade,
                queue* prioritarios,
                queue* nao_prioritarios) {
  if (idade >= 60) {
    prioritarios->push(nome);
  } else {
    nao_prioritarios->push(nome);
  }
}

// Retira o pr�ximo cliente da fila do banco e retorna o seu nome.
string Desenfileirar(queue* prioritarios,
                     queue* nao_prioritarios) {
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
  queue prioritarios;
  queue nao_prioritarios;
  int opcao;
  do {
    // Insiste at� que o usu�rio digite uma op��o correta.
    do {
      cout << "(1) Entrar na fila" << endl;
      cout << "(2) Proximo da fila"  << endl;
      cout << "(3) Imprimir Fila"  << endl;
      cout << "(0) Sair"  << endl;
      cout << ">> ";
      cin >> opcao;
    } while (opcao < 0 || opcao > 3);

    // Executa a solicita��o do usu�rio.
    if (opcao == 1) {
      string nome;
      cout << "Nome: ";
      cin >> nome;
      int idade;
      cout << "Idade: ";
      cin >> idade;
      Enfileirar(nome, idade, &prioritarios, &nao_prioritarios);
    } else if (opcao == 2) {
      cout << "\n\n\nProximo: "
           << Desenfileirar(&prioritarios, &nao_prioritarios) << "\n\n";
    } else if (opcao == 3) {
      cout << "\n\nLista de espera:" << endl;
      Imprimir(prioritarios);
      Imprimir(nao_prioritarios);
      cout << endl;
    }
  } while(opcao != 0);
  return 0;
}
