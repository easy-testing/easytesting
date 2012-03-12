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
// cujos dados são armazenados em arquivo 'agenda.txt' e podem ser acessados
// em várias execuções do programa. A agenda pode conter até 1000
// agenda. As funcionalidades desta agenda são apresentadas na função
// MostraMenu(), definida abaixo.
#include<fstream>
#include <iostream>
#include <string>

#include "agenda/src/agenda.h"

#define MAX 1000

using namespace std;

void MostrarMenu(){
    cout << "Digite a opcao desejada\n";
    cout << "1 - Inserir Contato: Insere um contato na agenda.\n";
    cout << "2 - Consultar por nome: Le um nome do teclado "
         << "e imprime as informações do Contato.\n";
    cout << "3 - Apagar Contato: Le um nome do "
         << "teclado e remove os dados do contato.\n";
    cout << "4 - Listar agenda: Lista todos os contatos da agenda\n";
    cout << "5 - Salvar agenda: Salva em arquivo as alterações na agenda.\n";
    cout << "6 - Sair.\n";
}

int LerOpcao(){
    int x;
    do{
        cout << "> ";
        cin >> x;
    }
    while (x < 1 || x > 6);
    return x;
}

void Imprimir(Contato contato){
    cout << "Nome: " << contato.nome << endl;
    cout << "Aniversario: " << contato.aniversario << endl;
    cout << "Telefone: " << contato.telefone << endl;
}

int AbrirArquivo(string arquivo, Contato agenda[]){
    ifstream fin(arquivo.c_str());
    int num_agenda = 0;
    while (getline(fin, agenda[num_agenda].nome))
    {
        getline(fin, agenda[num_agenda].telefone);
        getline(fin, agenda[num_agenda].aniversario);
        num_agenda++;
    }
    return num_agenda;
}

string LerNomeDoTeclado(){
    string nome = "";
    cout << "\nDigite o nome: ";
    // Limpa o buffer.
    cin.ignore();
    // Lê um nome do teclado (incluindo os espaços)
    // até a tecla ENTER ser precionada.
    getline(cin, nome, '\n');
    return nome;
}

string LerAniversarioDoTeclado(){
    string aniversario = "";
    cout << "\nDigite a data de aniversario: ";
    cin.ignore();
    getline(cin, aniversario, '\n');
    return aniversario;
}

string LerTelefoneDoTeclado(){
    string telefone = "";
    cout << "\nDigite o telefone: ";
    cin.ignore();
    getline(cin, telefone, '\n');
    return telefone;
}

Contato LerContatoDoTeclado(){
    Contato contato;
    contato.nome = LerNomeDoTeclado();
    contato.telefone = LerTelefoneDoTeclado();
    contato.aniversario = LerAniversarioDoTeclado();
    return contato;
}

Contato ConsultarContatoPorNome(string nome,
                                int num_agenda, Contato agenda[]){
    for (int i = 0; i < num_agenda; ++i) {
        if (agenda[i].nome == nome) {
            Imprimir(agenda[i]);
            return agenda[i];
        }
    }
    Contato contato;
    return contato;
}

void InserirContatoNaAgenda(Contato c,
                            int& num_agenda, Contato agenda[]){
    agenda[num_agenda].nome = c.nome;
    agenda[num_agenda].telefone = c.telefone;
    agenda[num_agenda].aniversario = c.aniversario;
    ++num_agenda;
}

void ApagarContato(string nome, int& num_agenda, Contato agenda[]){
    int posicao_remover;
    bool encontrou = false;
    for (int i =0; i < num_agenda; ++i){
        if (agenda[i].nome == nome){
            encontrou = true;
            posicao_remover = i;
            break;
        }
    }if (encontrou){
        // Deleta a posicao do vetor agenda
        // e atualiza a sequência na agenda.
        for (int i =posicao_remover; i < num_agenda; ++i) {
            agenda[i].nome = agenda[i+1].nome;
            agenda[i].telefone = agenda[i+1].telefone;
            agenda[i].aniversario = agenda[i+1].aniversario;
        }
    }
    // Decrementa o número de contatos da agenda.
    --num_agenda;
}

void ListarAgenda(int num_agenda, Contato agenda[]){
    for (int i = 0; i < num_agenda; i++){
        Imprimir(agenda[i]);
        cout << endl;
    }
}

void SalvarAgenda(string nome_arquivo, int num_agenda, Contato agenda[]){
    ofstream arquivo_saida;
    arquivo_saida.open(nome_arquivo.c_str());
    for (int i = 0; i < num_agenda; ++i){
        arquivo_saida << agenda[i].nome << endl;
        arquivo_saida << agenda[i].telefone <<  endl;
        arquivo_saida << agenda[i].aniversario <<  endl;
    }
    arquivo_saida.close();
}

int main() {
    string nome_arquivo = "agenda.txt";
    Contato agenda[MAX];
    int num_agenda = AbrirArquivo(nome_arquivo, agenda);
    int op;

    do {
        MostrarMenu();
        op = LerOpcao();
        switch (op) {
        case 1:
            InserirContatoNaAgenda(LerContatoDoTeclado(),
                                   num_agenda, agenda);
             cout << "\nO contato foi inserido com sucesso. "
                  << "Salve a alteracao na agenda!";
            break;
        case 2:
            ConsultarContatoPorNome(LerNomeDoTeclado(),
                                    num_agenda, agenda);
            break;
        case 3:
            ApagarContato(LerNomeDoTeclado(),
                          num_agenda, agenda);
            cout << "Contato apagado, salve sua modificacao na agenda! " << endl;
            break;
        case 4:
            ListarAgenda(num_agenda, agenda);
            break;
        case 5:
            SalvarAgenda(nome_arquivo, num_agenda, agenda);
             cout << "Agenda Atualizada" << endl;
            break;
        }
    }
    while (op < 6);

    return 0;
}
