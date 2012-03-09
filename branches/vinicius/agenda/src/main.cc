// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercício sobre estruturas de dados heterogêneas - Registros.
//
// QUESTÃO 1:
// Implemente em agenda.h struct Agenda que contém os campos
// {nome, telefone, aniversário (DD MM AAAA) e e-mail}.
//


// QUESTÃO 2:
// Escreva um programa em C++ que gerencia uma agenda persistente, ou seja,
// cujos dados são armazenados em arquivo (agenda.txt) e podem ser acessados
// em várias execuções do programa. A agenda pode conter até 1000
// Contatos. As funcionalidades desta agenda são apresentadas na função
// MostraMenu().

#include <string>
#include <fstream>
#include <iostream>

#include "agenda/src/agenda.h"

using namespace std;

void MostrarMenu(){
    cout << "Digite a opcao desejada\n";
    cout << "1 - Inserir Contato: Insere mais um Contato na agenda.\n";
    cout << "2 - Consultar por nome: Le um nome do teclado e imprime as informações do Contato.\n";
    cout << "3 - Consultar por Aniversario: Le uma data de aniversario do teclado e Imprime as informações dos contatos associados.\n";
    cout << "4 - Consultar por telefone: Le uma data do teclado e imprime as informações do contato.\n";
    cout << "5 - Consultar por e-mail: Le um e-mail do teclado e imprime as informações do contato.\n";
    cout << "6 - Apagar Contato: Le um nome do teclado e remove os dados do contato.\n";
    cout << "7 - Listar agenda: Lista todos os contatos na agenda\n";
    cout << "8 - Salvar agenda: Salva em arquivo as alterações na agenda.\n";
    cout << "9 - Sair.\n";
}

int LerOpcao() {
    int x;
    do{
        cout << "> ";
        cin >> x;
    }
    while (x < 1 || x > 9);
    return x;
}

void Imprimir(Contato contato){
    cout << "Nome: " << contato.nome << endl;
    cout << "Aniversario: " << contato.aniversario << endl;
    cout << "Telefone: " << contato.telefone << endl;
    cout << "E-mail: " << contato.email<< endl;

}


int AbrirArquivo(string arquivo)
{
    ifstream fin(arquivo.c_str());
    int num_contatos = 0;
    while (getline(fin, contatos[num_contatos].nome))
    {
        getline(fin, contatos[num_contatos].telefone);
        getline(fin, contatos[num_contatos].aniversario);
        getline(fin, contatos[num_contatos].email);
        num_contatos++;
    }
    return num_contatos;
}

int InserirContato(int num_contatos){
        if (num_contatos <  MAX){
        cout << "\nInserir os dados do contato." << endl;
        getchar();
        cout << "\nDigite o nome: ";
        getline(cin,contatos[num_contatos].nome);

        cout << "\nDigite o telefone:";
        getline(cin,contatos[num_contatos].telefone);

        cout << "\nDigite a data de aniversario:";
        getline(cin,contatos[num_contatos].aniversario);

        cout << "\nDigite o E-mail:";
        getline(cin,contatos[num_contatos].email);

        cout << "========================================" << endl;
        ++num_contatos;

    }else{
            cout << "\nA agenda NAO tem espaco suficiente!";
    }

    return num_contatos;
}

void ConsultarPorNome(int num_contatos){
    bool encontrou = false;
    string nome;
    getchar();
    cout << "\nDigite o nome: ";
    getline(cin,nome);

    for (int i =0; i < num_contatos; ++i){
        if (contatos[i].nome == nome){
            encontrou = true;
            Imprimir(contatos[i]);
            break;
        }
    }

    if (encontrou)    {
        cout << "Contato encontrado! " << endl;
    }else{
        cout << "Contato NAO encontrado! " << endl;
    }
    cout << "========================================" << endl;
}


void ConsultarPorAniversario(int num_contatos){
    bool encontrou = false;
    string data;
    getchar();
    cout << "\nDigite a data de aniversario: ";
    getline(cin,data);

    for (int i =0; i < num_contatos; ++i){
        if (contatos[i].aniversario == data){
            encontrou = true;
            Imprimir(contatos[i]);
        }
    }

    if (encontrou){
        cout << "Contato encontrado! " << endl;
    } else{
        cout << "Contato NAO encontrado! " << endl;
    }
    cout << "========================================" << endl;
}

void ConsultarPorTelefone(int num_contatos){
    bool encontrou = false;
    string telefone;
    getchar();
    cout << "\nDigite o telefone: ";
    getline(cin,telefone);

    for (int i =0; i < num_contatos; ++i){
        if (contatos[i].telefone == telefone){
            encontrou = true;
            Imprimir(contatos[i]);
            break;
        }
    }

    if (encontrou){
        cout << "Contato encontrado! " << endl;
    } else {
        cout << "Contato NAO encontrado! " << endl;
    }
    cout << "========================================" << endl;
}



void ConsultarPorEmail(int num_contatos){
    bool encontrou = false;
    string email;
    getchar();
    cout << "\nDigite o E-mail: ";
    getline(cin,email);

    for (int i =0; i < num_contatos; ++i){
        if (contatos[i].email == email){
            encontrou = true;
            Imprimir(contatos[i]);
            break;
        }
    }

    if (encontrou){
        cout << "Contato encontrado! " << endl;
    }else{
        cout << "Contato NAO encontrado! " << endl;
    }
    cout << "========================================" << endl;
}


int ApagarContato(int num_contatos){
    string nome;
    int posicao_remover;
    bool encontrou = false;

    getchar();
    cout << "\nDigite o nome do contato a remover: ";
    getline(cin,nome);

    for (int i =0; i < num_contatos; ++i){
        if (contatos[i].nome == nome){
            encontrou = true;
            posicao_remover = i;
            break;
        }
    }

    if (encontrou){
        // deleta a posicao do vetor de contatos e atualiza a sequencia na agenda.
        for (int i =posicao_remover; i < num_contatos; ++i){
            contatos[i].nome = contatos[i+1].nome;
            contatos[i].telefone = contatos[i+1].telefone ;
            contatos[i].aniversario = contatos[i+1].aniversario;
            contatos[i].email = contatos[i+1].email;
        }
        cout << "Contato apagado, salve sua modificacao na agenda! " << endl;
    }else {
        cout << "Contato NAO encontrado! " << endl;
    }


    cout << "========================================" << endl;
    // decrementa o numero de contatos
    num_contatos--;
    return num_contatos;

}

void ListarAgenda(int num_contatos){
    for (int i = 0; i < num_contatos; i++)    {
        Imprimir(contatos[i]);
        cout << endl;
    }

    cout << "========================================" << endl;
}

void SalvarAgenda(string nome_arquivo, int num_contatos){
    // abre o arquivo.
    std::ofstream arquivo_saida;
    arquivo_saida.open(nome_arquivo.c_str(), std::ios::in);

    // escreve no arquivo.
    for (int i = 0; i < num_contatos; ++i)    {
        arquivo_saida << contatos[i].nome << std::endl;
        arquivo_saida << contatos[i].telefone << std::endl;
        arquivo_saida << contatos[i].aniversario << std::endl;
        arquivo_saida << contatos[i].email<< std::endl;
    }
    arquivo_saida.close();
    // fecha o arquivo.
    cout << "Agenda Atualizada" << endl;
    cout << "========================================" << endl;

}

int main(){

    string nome_arquivo = "agenda.txt";

    int num_contatos = AbrirArquivo(nome_arquivo);
    int op;

    do{
        MostrarMenu();
        op = LerOpcao();
        switch (op) {
        case 1:
            num_contatos = InserirContato(num_contatos);
            break;
        case 2:
            ConsultarPorNome(num_contatos);
            break;
        case 3:
            ConsultarPorAniversario(num_contatos);
            break;
        case 4:
            ConsultarPorTelefone(num_contatos);
            break;
        case 5:
            ConsultarPorEmail(num_contatos);
            break;
        case 6:
            num_contatos = ApagarContato(num_contatos);
            break;
        case 7:
            ListarAgenda(num_contatos);
            break;
        case 8:
            SalvarAgenda(nome_arquivo,num_contatos);
            break;
        }
    }
    while (op < 9);

    return 0;
}
