// Copyright 2012 Universidade Federal de Minas Gerais (UFMG)
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

#include "agenda/src/agenda.h"

#define MAX 1000

using namespace std;

// Mosta as opções da agenda.
void MostrarMenu() {
    cout << "Digite a opcao desejada:\n";
    cout << "1 - Inserir Contato: Insere um contato na agenda.\n";
    cout << "2 - Consultar por nome: Le um nome do teclado "
            "e imprime as informações do contato.\n";
    cout << "3 - Apagar contato: Le um nome do "
         << "teclado e remove os dados do contato.\n";
    cout << "4 - Listar agenda: Lista todos os contatos da agenda\n";
    cout << "5 - Salvar agenda: Salva em arquivo as alterações na agenda.\n";
    cout << "6 - Sair.\n";
}

// Lê uma das 6 opções do teclado.
int LerOpcao() {
  int x;
  do {
    cout << "> ";
    cin >> x;
  } while (x < 1 || x > 6);
  return x;
}

// Imprime um contato.
void Imprimir(Contato contato) {
  cout << "Nome: " << contato.nome << endl;
  cout << "Aniversario: " << contato.aniversario << endl;
  cout << "Telefone: " << contato.telefone << endl;
}

// Abre o arquivo onde os dados da agenda são salvos e coloca os contatos em
// 'genda'.
void LerAgendaDoArquivo(int& n, Contato agenda[]) {
  ifstream fin("agenda.txt");
  n = 0;
  while (getline(fin, agenda[n].nome)) {
    getline(fin, agenda[n].telefone);
    getline(fin, agenda[n].aniversario);
    n++;
  }
}

// Lê um nome do teclado (incluindo os espaços).
string LerNomeDoTeclado() {
  string nome = "";
  cout << "\nDigite o nome: ";
  cin.ignore();
  getline(cin, nome, '\n');
  return nome;
}

// Lê um aniversário do teclado (incluindo os espaços).
string LerAniversarioDoTeclado() {
  string aniversario = "";
  cout << "\nDigite a data de aniversario: ";
  cin.ignore();
  getline(cin, aniversario, '\n');
  return aniversario;
}

// Lê um telefone do teclado (incluindo os espaços).
string LerTelefoneDoTeclado() {
  string telefone = "";
  cout << "\nDigite o telefone: ";
  cin.ignore();
  getline(cin, telefone, '\n');
  return telefone;
}

// Lê todos os dados de um contato do teclado.
Contato LerContatoDoTeclado() {
  Contato contato;
  contato.nome = LerNomeDoTeclado();
  contato.telefone = LerTelefoneDoTeclado();
  contato.aniversario = LerAniversarioDoTeclado();
  return contato;
}

// Dado um nome e uma agenda, retorna o contado daquele nome, caso este estaja
// na agenda. Caso contrário, retorna um contato d vazio (d.nome = "").
Contato ConsultarContatoPorNome(string nome, int n, Contato agenda[]) {
  for (int i = 0; i < n; ++i) {
    if (agenda[i].nome == nome) {
      return agenda[i];
    }
  }
  Contato vazio;
  vazio.nome = "";
  return vazio;
}

// Insere um contato na agenda.
void InserirContatoNaAgenda(Contato c, int& n, Contato agenda[]) {
  agenda[n].nome = c.nome;
  agenda[n].telefone = c.telefone;
  agenda[n].aniversario = c.aniversario;
  ++n;
}

// Remove um contato da agenda.
// Precondição: o contato a ser apagado está na agenda.
void ApagarContato(string nome, int& n, Contato agenda[]) {
  for (int i = 0; i < n; ++i) {
    if (agenda[i].nome == nome) {
      agenda[i] = agenda[n - 1];
      n--;
      return;
    }
  }
}


// Imprime na tela todos os contatos na agenda.
void ListarAgenda(int n, Contato agenda[]) {
  for (int i = 0; i < n; i++) {
    Imprimir(agenda[i]);
    cout << endl;
  }
}

void SalvarAgenda(int n, Contato agenda[]) {
  ofstream fout("agenda.txt");
  for (int i = 0; i < n; ++i) {
    fout << agenda[i].nome << endl;
    fout << agenda[i].telefone <<  endl;
    fout << agenda[i].aniversario <<  endl;
  }
}

int main() {
  Contato agenda[MAX];
  int n;
  LerAgendaDoArquivo(n, agenda);
  int op;
  do {
    MostrarMenu();
    op = LerOpcao();
    switch (op) {
      case 1: {
        InserirContatoNaAgenda(LerContatoDoTeclado(), n, agenda);
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
          ApagarContato(d.nome, n, agenda);
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
