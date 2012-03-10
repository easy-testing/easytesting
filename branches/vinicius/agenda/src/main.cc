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
// Contatos. As funcionalidades desta agenda são apresentadas na função
// MostraMenu().

#include<fstream>
#include <iostream>
#include <string>

#include "agenda/src/agenda.h"

#define MAX 1000

using namespace std;

void MostrarMenu() {
    cout << "Digite a opcao desejada\n";
    cout << "1 - Inserir Contato: Insere mais um Contato na agenda.\n";
    cout << "2 - Consultar por nome: Le um nome do teclado "
                  << "e imprime as informações do Contato.\n";
    cout << "3 - Consultar por telefone: Le uma data do teclado"
                  << " e imprime as informações do contato.\n";
    cout << "4 - Apagar Contato: Le um nome do "
                  << "teclado e remove os dados do contato.\n";
    cout << "5 - Listar agenda: Lista todos os contatos na agenda\n";
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

void Imprimir(Contato contato) {
    cout << "Nome: " << contato.nome << endl;
    cout << "Aniversario: " << contato.aniversario << endl;
    cout << "Telefone: " << contato.telefone << endl;
}


int AbrirArquivo(string arquivo, Contato contatos[]) {
    ifstream fin(arquivo.c_str());
    int num_contatos = 0;
    while (getline(fin, contatos[num_contatos].nome)) {
        getline(fin, contatos[num_contatos].telefone);
        getline(fin, contatos[num_contatos].aniversario);
        num_contatos++;
    }
    return num_contatos;
}

string LerNomeDoTeclado() {
    string nome = "";
    cout << "\nDigite o nome: ";
    // Limpa o buffer.
    cin.ignore();
    // Ler do teclado até o ENTER.
    getline(cin, nome, '\n');
    return nome;
}

string LerAniversarioDoTeclado() {
    string aniversario = "";
    cout << "\nDigite a data de aniversario: ";
    cin.ignore();
    getline(cin, aniversario, '\n');
    return aniversario;
}


string LerTelefoneDoTeclado() {
    string telefone = "";
    cout << "\nDigite o telefone: ";
    cin.ignore();
    getline(cin, telefone, '\n');
    return telefone;
}


Contato LerContatoDoTeclado() {
    Contato contato;
    contato.nome = LerNomeDoTeclado();
    contato.telefone = LerTelefoneDoTeclado();
    contato.aniversario = LerAniversarioDoTeclado();
    return contato;
}


Contato ConsultarContatoPorNome(string nome,
                                int num_contatos, Contato contatos[]) {
    for (int i =0; i < num_contatos; ++i) {
        if (contatos[i].nome == nome) {
            cout << "Contato encontrado! " << endl;
            Imprimir(contatos[i]);
            return contatos[i];
        }
    }
    cout << "Contato NAO encontrado! " << endl;
    Contato contato;
    return contato;
}

void ConsultarPorTelefone(string telefone,
                             int num_contatos, Contato contatos[]) {
    bool contato_encontrado = false;

    for (int i =0; i < num_contatos; ++i) {
        if (contatos[i].telefone == telefone) {
            Imprimir(contatos[i]);
            contato_encontrado = true;
        }
    }

    if (!contato_encontrado)
        cout << "Nenhum contato encontrado! " << endl;
}

bool InserirContatoNaAgenda(Contato c,
                            int &num_contatos, Contato contatos[]) {
    if (num_contatos <  MAX) {
        contatos[num_contatos].nome = c.nome;
        contatos[num_contatos].telefone = c.telefone;
        contatos[num_contatos].aniversario = c.aniversario;
        ++num_contatos;
        cout << "\nO contato foi inserido com sucesso. "
             << "Salve a alteracao na agenda!";
        return true;
    } else {
        cout << "\nA agenda NAO tem espaco suficiente!";
        return false;
    }
}

void ApagarContato(string nome, int &num_contatos, Contato contatos[]) {
    int posicao_remover;
    bool encontrou = false;

    for (int i =0; i < num_contatos; ++i) {
        if (contatos[i].nome == nome) {
            encontrou = true;
            posicao_remover = i;
            break;
        }
    }
    if (encontrou) {
        // Deleta a posicao do vetor de contatos
        // e atualiza a sequencia na agenda.
        for (int i =posicao_remover; i < num_contatos; ++i) {
            contatos[i].nome = contatos[i+1].nome;
            contatos[i].telefone = contatos[i+1].telefone;
            contatos[i].aniversario = contatos[i+1].aniversario;
        }
        cout << "Contato apagado, salve sua modificacao na agenda! " << endl;
    } else {
        cout << "Contato NAO encontrado! " << endl;
    }


    cout << "========================================" << endl;
    // Decrementa o numero de contatos
    --num_contatos;
}

void ListarAgenda(int num_contatos, Contato contatos[]) {
    for (int i = 0; i < num_contatos; i++) {
        Imprimir(contatos[i]);
        cout << endl;
    }

    cout << "========================================" << endl;
}

void SalvarAgenda(string nome_arquivo, int num_contatos, Contato contatos[]) {
    // Abre o arquivo.
    std::ofstream arquivo_saida;
    arquivo_saida.open(nome_arquivo.c_str());

    // Escreve no arquivo.
    for (int i = 0; i < num_contatos; ++i) {
        arquivo_saida << contatos[i].nome << std::endl;
        arquivo_saida << contatos[i].telefone << std::endl;
        arquivo_saida << contatos[i].aniversario << std::endl;
    }
    arquivo_saida.close();
    // Fecha o arquivo.
    cout << "Agenda Atualizada" << endl;
    cout << "========================================" << endl;
}

int main() {
    string nome_arquivo = "agenda.txt";
    Contato contatos[MAX];
    int num_contatos = AbrirArquivo(nome_arquivo, contatos);
    int op;

    do {
        MostrarMenu();
        op = LerOpcao();
        switch (op) {
        case 1:
            InserirContatoNaAgenda(LerContatoDoTeclado(),
                                   num_contatos, contatos);
            break;
        case 2:
            ConsultarContatoPorNome(LerNomeDoTeclado(),
                                     num_contatos, contatos);
            break;
        case 3:
            ConsultarPorTelefone(LerTelefoneDoTeclado(),
                                 num_contatos, contatos);
            break;
        case 4:
            ApagarContato(LerNomeDoTeclado(),
                          num_contatos, contatos);
            break;
        case 5:
            ListarAgenda(num_contatos, contatos);
            break;
        case 6:
            SalvarAgenda(nome_arquivo, num_contatos, contatos);
            break;
        }
    } while (op < 7);

    return 0;
}
