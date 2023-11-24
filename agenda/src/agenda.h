// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#ifndef TRUNK_AGENDA_SRC_AGENDA_H_
#define TRUNK_AGENDA_SRC_AGENDA_H_

#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

struct Contato {
    std::string nome;
    std::string telefone;
    std::string aniversario;
    
    bool operator==(const Contato& other) const {
      return nome == other.nome &&
              telefone == other.telefone &&
              aniversario == other.aniversario;
    }
};

void MostrarMenu();
int LerOpcao();
void Imprimir(Contato contato);
void LerAgendaDoArquivo(int* n, Contato agenda[]);
string LerNomeDoTeclado();
string LerAniversarioDoTeclado();
string LerTelefoneDoTeclado();
Contato LerContatoDoTeclado();
Contato ConsultarContatoPorNome(string nome, int n, Contato agenda[]);
void InserirContatoNaAgenda(Contato c, int* n, Contato agenda[]);
void ApagarContato(string nome, int* n, Contato agenda[]);
void ListarAgenda(int n, Contato agenda[]);
void SalvarAgenda(int n, Contato agenda[]);


#endif  // TRUNK_AGENDA_SRC_AGENDA_H_
