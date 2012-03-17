// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre condicionais em C++.
//
// QUESTÃO 1:
// Implemente em condicionais.cc as funções descritas em condicionais.h.
//
// QUESTÃO 2:
// Escreva um programa que (i) apresenta um menu com as funções que você
// programaou na questão anterior e após o usuário escolher uma das funções
// (ii) lê o valor dos parâmetros e (iii) exibe o resultado da função.
//
// QUESTÃO 3:
// arquivo: main2.cc
#include <iostream>
#include "condicionais/src/condicionais.h"

using namespace std;

// Retorna um numero inteiro indicando a opcao escolhida pelo usuario
int Menu() {
    int op;
    cout << "*****************************************************************";
    cout << "\n                        MENU PRINCIPAL\n";
    cout << "*****************************************************************";
    cout << "\n Opcoes:\n\n";
    cout << "1.  Menor valor entre dois numeros\n";
    cout << "2.  Maior valor entre dois numeros\n";
    cout << "3.  Maior valor entre tres numeros.\n";
    cout << "4.  Verifica se um numero e positivo ou negativo\n";
    cout << "5.  Verifica se um numero e par ou impar\n";
    cout << "6.  Realiza potenciacao\n";
    cout << "7.  Divisao\n";
    cout << "8.  Informa qual o tipo do triangulo \n";
    cout << "9.  Sair\n";
    cout << "Escolha a operacao que deseja fazer: ";
    cin >> op;
    while (op < 1 || op > 9) {
        cout << "Opcao invalida. Escolha uma das opcoes acima: ";
        cin >> op;
    }
    return op;
}

// Recebe como parametro a opcao escolhida pelo usuario e
// apos entrada de valores, imprime o resultado desejado
void Operacao(int op) {
    int a, b, c,r;
    switch (op) {
    case 1:  // Menor valor entre dois numeros.";
        cout << "Digite o valor do primeiro numero: ";
        cin >> a;
        cout << "Digite o valor do segundo numero: ";
        cin >> b;
        cout << "\nMenor: " << menor(a, b) << ".\n"<< endl;
        break;
    case 2: // Maior valor entre dois numeros
        cout << "Digite o valor do primeiro numero: ";
        cin >> a;
        cout << "Digite o valor do segundo numero: ";
        cin >> b;
        cout << "\nMaior: " << maior(a, b) << ".\n"<< endl;
        break;
    case 3:  // Maior valor entre tres numeros.
        cout << "Digite o valor do primeiro numero: ";
        cin >> a;
        cout << "Digite o valor do segundo numero: ";
        cin >> b;
        cout << "Digite o valor do terceiro numero: ";
        cin >> c;
        cout << "\nMaior: " << maior(a, b, c) << ".\n"<< endl;
        break;
    case 4:  // Verifica se um numero e positivo ou negativo.
        cout << "Digite o valor de um numero: ";
        cin >> a;
        if (verifica_sinal(a)) {
            cout << "\nO numero " << a << " eh positivo.\n" << endl;
        } else {
            cout << "\nO numero " << a << " eh negativo.\n" << endl;
        }
        break;
    case 5:  // Verifica se um numero e par ou impar.
        cout << "Digite o valor de um numero: ";
        cin >> a;
        if (verifica_par_impar(a)) {
            cout << "\nO numero " << a << " eh par.\n" << endl;
        } else {
            cout << "\nO numero " << a << " eh impar.\n" << endl;
        }
        break;
    case 6:  // Realiza potenciacao.
        cout << "Digite o valor do primeiro numero: ";
        cin >> a;
        cout << "Digite o valor do segundo numero: ";
        cin >> b;
        cout << "\nResultado: " << potenciacao(a, b) << endl;
        break;
    case 7:  // Divisao";
        cout << "Digite o valor do primeiro numero: ";
        cin >> a;
        cout << "Digite o valor do segundo numero: ";
        cin >> b;
        int r;
        if (divisao(a, b, r)){
             cout << "\nResultado: " << r << endl;
        }else{
            cout << "\nErro: Divisao por zero.\n"<< endl;
        }
        break;
    case 8:  // Informa qual o tipo do triangulo.;
        cout << "Digite o valor do primeiro numero: ";
        cin >> a;
        cout << "Digite o valor do segundo numero: ";
        cin >> b;
        cout << "Digite o valor do terceiro numero: ";
        cin >> c;
        int retorno = tipo_triangulo(a, b, c);
        if(retorno == 1) {
            cout << "\nResultados: Triangulo equilatero.\n" << endl;
        } else if (retorno == 2) {
            cout << "\nResultados: Triangulo isosceles.\n" << endl;
        } else {
            cout << "\nResultados: Triangulo escaleno.\n" << endl;
        }
        break;
    }
}

int main() {
    while(true){
        int op = Menu();
        if (op == 9){
            cout << '\a';
            break;
        }else{
            Operacao(op);
        }
    }
    return 0;
}


