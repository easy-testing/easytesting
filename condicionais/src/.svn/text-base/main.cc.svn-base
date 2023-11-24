// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Condicionais.
//
// QUESTÃO 1:
// Implemente em condicionais.cc as funções descritas em condicionais.h.
//
// QUESTÃO 2:
// Escreva um programa que (i) apresenta um menu com as funções que você
// implementou na questão anterior e após o usuário escolher uma das funções
// (ii) lê o valor dos parâmetros e (iii) exibe o resultado da função.
//
#include <iostream>

#include "src/condicionais.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    int dia, mes, op;
    int  a, b, c;
    float  x, y, z;

    cout << "*****************************************************************";
    cout << "\n                        MENU PRINCIPAL - \n";
    cout << "*****************************************************************";
    cout << "\n Opcoes:\n\n";
    cout << "1.  Menor valor entre dois numeros\n";
    cout << "2.  Maior valor entre tres numeros.\n";
    cout << "3.  Verifica se um numero e par ou impar\n";
    cout << "4.  Verifica triangulo.\n";
    cout << "5.  Verifica qual o signo de uma pessoa.\n";
    cout << "Escolha a operacao que deseja fazer: ";
    cin >> op;

    switch (op) {
    case 1:  // Menor valor entre dois números.";
        cout << "Digite o valor do primeiro numero: ";
        cin >> a;
        cout << "Digite o valor do segundo numero: ";
        cin >> b;
        cout << "\nMenor: " << menor(a, b) << ".\n"<< endl;
        break;
    case 2:  // Maior valor entre três números.
        cout << "Digite o valor do primeiro numero: ";
        cin >> a;
        cout << "Digite o valor do segundo numero: ";
        cin >> b;
        cout << "Digite o valor do terceiro numero: ";
        cin >> c;
        cout << "\nMaior: " << maior(a, b, c) << ".\n"<< endl;
        break;
    case 3:  // Verifica se um número é par ou impar.
        cout << "Digite o valor de um numero: ";
        cin >> a;
        if (par(a)) {
            cout << "\nO numero " << a << " eh par.\n" << endl;
        } else {
            cout << "\nO numero " << a << " eh impar.\n" << endl;
        }
        break;
    case 4:  // Informa qual o tipo do triângulo.;
        cout << "Digite o valor do primeiro numero: ";
        cin >> x;
        cout << "Digite o valor do segundo numero: ";
        cin >> y;
        cout << "Digite o valor do terceiro numero: ";
        cin >> z;

        if (equilatero(x, y, z)) {
            cout << "\nResultados: Triangulo equilatero.\n" << endl;
        } else  if (isosceles(x, y, z)) {
            cout << "\nResultados: Triangulo isosceles.\n" << endl;
        } else  if (escaleno(x, y, z)) {
            cout << "\nResultados: Triangulo escaleno.\n" << endl;
        } else {
            cout << "\nResultados: Nao e um Triangulo.\n" << endl;
        }
        break;
    case 5:  // Verifica qual o signo
        cout << "Digite o dia do nascimento: ";
        cin >> dia;
        cout << "Digite o mes de nascimento: ";
        cin >> mes;
        cout << "\nResultado: " << signo(dia, mes) << endl;
        break;
    }
    cout << "\nFim do programa!\n" << endl;
    return 0;
}

