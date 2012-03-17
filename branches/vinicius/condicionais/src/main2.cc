// Copyright 2012 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre condicionais em C++.
//
// QUESTÃO 1:
// main.cc
//
// QUESTÃO 2:
// main.cc
//
// QUESTÃO 3:
// Desenvolva um programa que recebe o sexo ('f' ou 'm'), a idade,
// dia e mês de nascimento e salário de um funcionário e informa de
// forma literal seu sexo ("femino" ou "masculino"), se este é maior de idade,
// seu signo e o novo salário reajustado. O funcionário terá seu salário
// reajustado em 10% caso seu salário seja superior ou igual a R$ 2.500,
// 15% se o o salário for inferior a R$ 2500,00 ou 20% caso seu salário
// seja menor que R$ 1500,00.

#include <iostream>
#include <string>

using namespace std;

// Recebe a idade de uma pessoa e
// retorna verdadeiro se ela for maior de idade ou falso caso contrário.
bool verifica_maioridade(int idade) {
    if(idade >= 18) {
        return true;
    }else {
        return false;
    }
}

// Recebe o dia e o mês de nascimento e informa o signo da pessoa.
void signo(int dia, int mes) {
    if (mes == 3) {
        if (dia <= 22) {
            cout << "Peixes" << endl;
        } else if (dia >= 23) {
            cout << "Ares"  << endl;
        }
    }
    if (mes == 4) {
        if (dia <= 20) {
            cout << "Ares"  << endl;
        } else if (dia >= 21) {
            cout << "Touro"  << endl;
        }
    }
    if (mes == 5) {
        if (dia <= 21) {
            cout << "Touro"  << endl;
        } else if (dia >= 22) {
            cout << "Gemeos"  << endl;
        }
    }
    if (mes == 6) {
        if (dia <= 21) {
            cout << "Gemeos"  << endl;
        } else if (dia <= 22) {
            cout << "Cancer"  << endl;
        }
    }
    if (mes == 7) {
        if (dia <= 22) {
            cout << "Cancer"  << endl;
        } else if (dia >= 23) {
            cout << "Leão"  << endl;
        }
    }
    if (mes == 8) {
        if (dia <= 23) {
            cout << "Leão"  << endl;
        } else if (dia >= 24) {
            cout << "Virgem"  << endl;
        }
    }
    if (mes == 9) {
        if (dia <= 22) {
            cout << "Virgem"  << endl;
        } else if (dia >= 23) {
            cout << "Libra"  << endl;
        }
    }
    if (mes == 10) {
        if (dia <= 23) {
            cout << "Libra"  << endl;
        } else if (dia >= 24) {
            cout << "Escorpião"  << endl;
        }
    }
    if (mes == 11) {
        if(dia <= 22) {
            cout << "Escorpião"  << endl;
        } else if (dia >= 23) {
            cout << "Sargitario"  << endl;
        }
    }
    if (mes == 12) {
        if (dia <= 21) {
            cout << "Sargitario"  << endl;
        } else if (dia >= 22) {
            cout << "Capricornio"  << endl;
        }
    }
    if (mes == 1) {
        if (dia <= 20) {
            cout << "Capricornio"  << endl;
        } else if (dia >= 21) {
            cout << "Aquario"  << endl;
        }
    }
    if (mes == 2) {
        if (dia <= 18) {
            cout << "Aquario"  << endl;
        } else if (dia >= 19) {
            cout << "Peixes"  << endl;
        }
    }
}

double reajuste(double salario) {
    double novo_salario = salario;
    // Superior ou igual a R$ 2.500
    if (salario >= 2500.00) {
        novo_salario += (salario*0.10);
    } else // Inferior a R$ 2500,00 a superior ou igual a R$ 1500,00
        if(salario >= 1500.00) {
            // Menor que R$ 1500,00.
            novo_salario += (salario*0.15);
        } else {
            novo_salario += (salario*0.20);
        }
    return novo_salario;
}

int main() {
    string sexo;
    int dia, mes;
    double salario;
    cout << "=====================================================" << endl;
    cout << "Informacoes do funcionario" << endl;
    cout << "=====================================================" << endl;
    cout << "Sexo: (f) para feminino ou (m) para masculino: " << endl;
    cin >> sexo;
    cout << "Dia de nascimento:" << endl;
    cin >> dia;
    cout << "Mes de nascimento:" << endl;
    cin >> mes;
    cout << "Salario:" << endl;
    cin>> salario;
    cout << "Informacoes atualizadas: " << endl;
    if (sexo == "f") {
        cout << "Sexo: Femino: " << endl;
    } else if (sexo == "m") {
        cout << "Sexo: Masculino: " << endl;
    }

    cout << "Signo: ";
    signo(dia,mes);
    cout << "Novo salario: " << reajuste(salario);
    return 0;
}

