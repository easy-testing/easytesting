// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercício sobre estruturas de dados heterogêneas - Registros.
//
// QUESTÃO 1:
// Implemente em agenda.h struct Agenda que contém os campos
// {nome, telefone, aniversário (DD MM AAAA)}.
//
// QUESTÃO 2:
// Escreva um programa em C++ que gerencia uma agenda persistente, ou seja,
// cujos dados são armazenados em arquivo (agenda.txt) e podem ser acessados
// em várias execuções do programa. A agenda pode conter até 1000
// entradas. As funcionalidades desta agenda são apresentadas na função
// MostraMenu().

#include <fstream>
#include <iostream>

#include "agenda/src/agenda.h"

#define MAX 1000

using namespace std;

void MostrarMenu() {
  cout << "Digite a opcao desejada\n";
  cout << "1 - Inserir entrada: Insere mais uma entrada na agenda.\n";
  cout << "2 - Consultar por nome: Le um nome do teclado e imprime os dados "
       << "associados ao nome.\n";
  cout << "3 - Consultar por telefone: Le uma data do teclado e Imprime o nome "
       << "de todas as pessoas cujo aniversário é nesta data.\n";
  cout << "4 - Apagar entrada: Le um nome do teclado e remove os dados "
       << "associados a este nome da agenda.\n";
  cout << "5 - Listar agenda: Lista todas as entradas na agenda\n";
  cout << "6 - Salvar agenda: Salva em arquivo as alterações na agenda.\n";
  cout << "7 - Sair.\n";
}

int LerOpcao() {
  int x;
  do {
    cout << "> ";
    cin >> x;
  } while (x < 1 || x > 7);
  return x;
}

void Imprimir(Entrada e) {
  cout << "Nome: " << e.nome << endl;
  cout << "Telefone: " << e.telefone << endl;
  cout << "Aniversario: " << e.aniversario << endl;
}


int AbrirArquivo(string arquivo, Entrada v[]) {
  ifstream fin(arquivo.c_str());
  int n = 0;
  while (getline(fin, v[n].nome)) {
    getline(fin, v[n].telefone);
    getline(fin, v[n].aniversario);
    n++;
  }
  return n;
}

void ListarAgenda(int n, Entrada v[]) {
  for (int i = 0; i < n; i++) {
    Imprimir(v[i]);
    cout << endl;
  }
}

int main() {
  Entrada agenda[MAX];
  int n = AbrirArquivo("agenda.txt", agenda);
  int op;
  do {
    MostrarMenu();
    op = LerOpcao();
    switch (op) {
      case 5:
        ListarAgenda(n, agenda);
        break;
    }
  } while (op != 7);
}
