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

#include "funcoes/src/funcoes.h"

using namespace std;

// Retorna um numero inteiro indicando a opcao escolhida pelo usuario
int Menu() {
  int op;
  cout << "*****************************************************************";
  cout << "\n                        MENU PRINCIPAL\n";
  cout << "*****************************************************************";
  cout << "\n Opcoes:\n\n";
  cout << "1.  Media\n";
  cout << "2.  Media Ponderada\n";
  cout << "3.  Perimetro do Circulo\n";
  cout << "4.  Area do Circulo\n";
  cout << "5.  Area da Caixa\n";
  cout << "6.  Volume da Caixa\n";
  cout << "7.  Area do Cilindro\n";
  cout << "8.  Volume do Cilindro\n";
  cout << "9.  Hipotenusa\n";
  cout << "10. Raiz Positiva de uma Funcao do Segundo Grau\n\n";
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
  int k;
  int a, b, c;
  switch (op) {
    case 1:  // Media
      cout << "Digite o valor do primeiro numero: ";
      cin >> a;
      cout << "Digite o valor do segundo numero: ";
      cin >> b;
      cout << "Digite o valor do terceiro numero: ";
      cin >> c;
      cout << "\nResultado: " << Media(a, b, c) << endl;
      break;
    case 2:  // Media Ponderada
      cout << "Digite o valor do primeiro numero: ";
      cin >> a;
      cout << "Digite o valor do segundo numero: ";
      cin >> b;
      cout << "Digite o valor do terceiro numero: ";
      cin >> c;
      cout << "\nResultado: " << MediaPonderada(a, b, c) << endl;
      break;
    case 3:  // Perimetro do Circulo
      cout << "Digite o valor do raio do circulo: ";
      cin >> k;
      cout << "\nResultado: " << Perimetro(k) << endl;
      break;
    case 4:  // Area do Circulo
      cout << "Digite o valor do raio do circulo: ";
      cin >> k;
      cout << "\nResultado: " << AreaCirculo(k) << endl;
      break;
    case 5:  // Area da Caixa
      cout << "Digite o valor da altura da caixa: ";
      cin >> a;
      cout << "Digite o valor da largura da caixa: ";
      cin >> b;
      cout << "Digite o valor do comprimento da caixa: ";
      cin >> c;
      cout << "\nResultado: " << AreaCaixa(a, b, c) << endl;
      break;
    case 6:  // Volume da Caixa
      cout << "Digite o valor da altura da caixa: ";
      cin >> a;
      cout << "Digite o valor da largura da caixa: ";
      cin >> b;
      cout << "Digite o valor do comprimento da caixa: ";
      cin >> c;
      cout << "\nResultado: " << VolumeCaixa(a, b, c) << endl;
      break;
    case 7:  // Area do Cilindro
      cout << "Digite o valor do raio da base do cilindro: ";
      cin >> n;
      cout << "Digite o valor da altura do cilindro: ";
      cin >> k;
      cout << "\nResultado: " << AreaCilindro(n, k) << endl;
      break;
    case 8:  // Volume do Cilindro
      cout << "Digite o valor do raio da base do cilindro: ";
      cin >> n;
      cout << "Digite o valor da altura do cilindro: ";
      cin >> k;
      cout << "\nResultado: " << VolumeCilindro(n, k) << endl;
      break;
    case 9:  // Hipotenusa
      cout << "Digite o valor do primeiro cateto: ";
      cin >> b;
      cout << "Digite o valor do segundo cateto: ";
      cin >> c;
      cout << "\nResultado: " << Hipotenusa(b, c) << endl;
      break;
    case 10:  // Raiz positiva
      cout << "Sendo a funcao do segundo grau definida como ax2 + bx + c\n";
      cout << "Digite o coeficiente a: ";
      cin >> a;
      cout << "Digite o coeficiente b: ";
      cin >> b;
      cout << "Digite o coeficiente c: ";
      cin >> c;
      cout << "\nResultado: " << RaizPositiva(a, b, c) << endl;
      break;
  }
}

int main() {
  int op = Menu();
  Operacao(op);
  return 0;
}


