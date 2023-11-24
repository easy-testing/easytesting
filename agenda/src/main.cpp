// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercício sobre estruturas de dados heterogêneas - Registros.
//
// QUESTÃO 1:
// Implemente em agenda.h struct Agenda que contém os campos
// {nome, telefone, aniversário (DD MM AAAA)}.
//
// QUESTÃO 2:
// Escreva um programa em C++ que gerencia uma agenda persistente, ou seja,
// cujos dados são armazenados no arquivo 'agenda.txt' e podem ser acessados
// em várias execuções do programa. A agenda pode conter até 1000
// contatos. As funcionalidades desta agenda são apresentadas na função
// MostraMenu(), definida abaixo.

#include <fstream>
#include <iostream>
#include <string>

#include "./src/agenda.h"

#define MAX 1000

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;



int main() {
  Contato agenda[MAX];
  int n;
  LerAgendaDoArquivo(&n, agenda);
  int op;
  do {
    MostrarMenu();
    op = LerOpcao();
    switch (op) {
      case 1: {
        InserirContatoNaAgenda(LerContatoDoTeclado(), &n, agenda);
        cout << "Contato inserido com sucesso.\n";
        break;
      } case 2: {
        Contato c =ConsultarContatoPorNome(LerNomeDoTeclado(), n, agenda);
        if (c.nome == "") {
          cout << "Contato nao existe.\n";
        } else {
          Imprimir(c);
        }
        break;
      } case 3: {
        Contato d = ConsultarContatoPorNome(LerNomeDoTeclado(), n, agenda);
        if (d.nome == "") {
          cout << "Contato nao existe.\n";
        } else {
          ApagarContato(d.nome, &n, agenda);
          cout << "Contato apagado com sucesso! " << endl;
        }
        break;
      } case 4: {
        ListarAgenda(n, agenda);
        break;
      } case 5: {
          SalvarAgenda(n, agenda);
          cout << "Agenda Atualizada" << endl;
        break;
      }
    }
  } while (op < 6);
  return 0;
}
