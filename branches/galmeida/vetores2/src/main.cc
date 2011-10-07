// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercício sobre estruturas de dados homogêneas - Vetores.
//
// QUESTÃO 1:
// Implemente em vetores.cc as funções descritas em vetores.h.
//
// QUESTÃO 2:
// Escreva um programa em C++ que:
// 1) Le de um arquivo chamado vocabulario.txt uma lista de palavras,
// separadas por espaco. A cada uma delas deve sar associado um número
// único no intervalo 0 a n-1, onde n é o número total de palavras no
// arquivo.
// 2) Receba do teclado o nome de dois arquivos de texto formados
// apenas de palavras existentes no arquivo vocabulario
// 3) Para cada um dos arquivos do item 2, criar um vetor de
// n posicoes. A i-esima posicao do vetor deve ser igual ao numero de
// ocorrencias da palavra associada ao numero i(no item 1) no
// arquivo de texto correspondente aquele vetor
// 4) Imprima na tela o cosseno entre os vetores.

#include<fstream>
#include<map>
#include<iostream>
#include "vetores2/src/vetores.h"

using namespace std;

int main() {
  map<string, int> mapa;
  ifstream entrada;
  char palavra[50];
  int tam_vocabulario = 0;
  entrada.open("vocabulario.txt");
  entrada >> palavra;
  int count = 0;
  while ( !entrada.eof() ) {
    mapa.insert(pair< string, int >(palavra, tam_vocabulario++));
    entrada >> palavra;
  }
  entrada.close();
  int vA[tam_vocabulario];
  for (int i = 0; i < tam_vocabulario; i++) {
    vA[i] = 0;
  }
  char nome_arquivo[50];
  cout << "Digite o nome do primeiro arquivo:";
  cin >> nome_arquivo;
  entrada.open(nome_arquivo);
  entrada >> palavra;
  while ( !entrada.eof() ) {
    vA[ mapa.find(palavra)->second ]++;
    entrada >> palavra;
  }
  entrada.close();
  int vB[tam_vocabulario];
  for (int i = 0; i < tam_vocabulario; i++) {
    vB[i] = 0;
  }
  cout << "Digite o nome do segundo arquivo:";
  cin >> nome_arquivo;
  entrada.open(nome_arquivo);
  entrada >> palavra;
  while ( !entrada.eof() ) {
    vB[ mapa.find(palavra)->second ]++;
    entrada >> palavra;
  }
  entrada.close();
  float cos_A_B = CossenoVetores(vA, vB, tam_vocabulario);
  cout << "O cosseno entre os vetores e " <<  cos_A_B << "\n";
  return 1;
}
