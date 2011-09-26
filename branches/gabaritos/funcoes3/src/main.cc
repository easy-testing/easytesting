// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre funções em C++.
//
// QUESTÃO 1:
// Implemente em funcoes.cc as funções descritas em funcoes.h.
//
// QUESTÃO 2:
// Escreva um programa que (i) apresenta um menu com as funções que você
// programaou na questão anterior e após o usuário escolher uma das funções
// (ii) lê o valor dos parâmetros e (iii) exibe o resultado da função.

#include <iostream>

#include "funcoes3/src/funcoes.h"

using namespace std;

// Retorna um numero inteiro indicando a opcao escolhida pelo usuario
int Menu() {
  int op;
  cout << "*****************************************************************";
  cout << "\n                        MENU PRINCIPAL\n";
  cout << "*****************************************************************";
  cout << "\n Opcoes:\n\n";
  cout << "1.  Area do trapezio\n";
  cout << "2.  Maior de 3 valores\n";
  cout << "3.  Verifica se 3 numeros podem ser as medidas de um triangulo\n";
  cout << "4.  Area do triangulo\n";
  cout << "5.  Converte graus em radianos\n";
  cout << "6.  Converte um angulo de graus minutos e segundos para graus\n";
  cout << "7.  Soma dos numeros de 1 a n\n";
  cout << "8.  Calcula x para o qual y e maximo numa parabola\n";
  cout << "9.  Calcula o y maximo de parabola com a concavidade para baixo\n";
  cout << "10. Calcula distancia entre dois pontos no plano cartesiano\n\n";
  cout << "Escolha a operacao que deseja fazer: ";
  cin >> op;
  while (op < 1 || op > 10) {
    cout << "Opcao invalida. Escolha uma das opcoes acima: ";
    cin >> op;
  }
  return op;
}

// Recebe como parametro a opcao escolhida pelo usuario e
// apos entrada de valores, imprime o resultado desejado
void Operacao(int op) {
  int n;
  float a, b, c, d;
  switch (op) {
    case 1:  // Area trapezio
      cout << "Digite o valor da base maior: ";
      cin >> a;
      cout << "Digite o valor da base menor: ";
      cin >> b;
      cout << "Digite o valor da altura: ";
      cin >> c;
      cout << "\nResultado: " << area_trapezio(a, b, c) << endl;
      break;
    case 2:  // Maior de 3 valores
      cout << "Digite o valor do primeiro numero: ";
      cin >> a;
      cout << "Digite o valor do segundo numero: ";
      cin >> b;
      cout << "Digite o valor do terceiro numero: ";
      cin >> c;
      cout << "\nResultado: "  << maior(a, b, c) << endl;
    case 3:  // Formam triangulo
      cout << "Digite o valor do primeiro numero: ";
      cin >> a;
      cout << "Digite o valor do segundo numero: ";
      cin >> b;
      cout << "Digite o valor do terceiro numero: ";
      cin >> c;
      cout << "\nResultado: ";
      if ( formam_triangulo(a, b, c) ) {
           cout << "Sim." << endl;
      } else {
          cout << "Nao." << endl;
      }
      break;
    case 4:  // Area triangulo
      cout << "Digite a medida do primeiro lado: ";
      cin >> a;
      cout << "Digite a medida do segundo lado: ";
      cin >> b;
      cout << "Digite a medida do terceiro lado: ";
      cin >> c;
      cout << "\nResultado: "  << area_triangulo(a, b, c) << endl;
      break;
    case 5:  // graus para radianos
      cout << "Digite o angulo en graus: ";
      cin >> a;
      cout << "\nResultado: " << graus_radianos(a) << endl;
      break;
    case 6:  // graus,minutos,segundos para grau
      cout << "Digite o numero de graus: ";
      cin >> a;
      cout << "Digite o numero de minutois: ";
      cin >> b;
      cout << "Digite o numero de segundos: ";
      cin >> c;
      cout << "\nResultado: "  << grauminutosegundo_grau(a, b, c) << endl;
      break;
    case 7:  // Soma de 1 a n
      cout << "Digite o valor de n: ";
      cin >> a;
      cout << "\nResultado: " << soma_progressao(a) << endl;
      break;
    case 8:  // x de y maximo
      cout << "Digite o valor de a: ";
      cin >> a;
      cout << "Digite o valor de b: ";
      cin >> b;
      cout << "Digite o valor de c: ";
      cin >> c;
      cout << "\nResultado: "  << xy_maximo(a, b, c) << endl;
      break;
    case 9:  // y maximo
      cout << "Digite o valor de a: ";
      cin >> a;
      cout << "Digite o valor de b: ";
      cin >> b;
      cout << "Digite o valor de c: ";
      cin >> c;
      cout << "\nResultado: "  << y_maximo(a, b, c) << endl;
      break;
    case 10:  // Distancia pontos
      cout << "Digite a coordenada x do primeiro ponto: ";
      cin >> a;
      cout << "Digite a coordenada y do primeiro ponto: ";
      cin >> b;
      cout << "Digite a coordenada x do segundo ponto: ";
      cin >> c;
      cout << "Digite a coordenada y do segundo ponto: ";
      cin >> d;
      cout << "\nResultado: " << distancia_pontos(a, b, c, d) << endl;
      break;
  }
}

int main() {
  int op = Menu();
  Operacao(op);
  return 0;
}


