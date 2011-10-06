// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercício sobre estruturas de dados homogêneas - Vetores.
//
// QUESTÃO 1:
// Implemente em vetores.cc as funções descritas em vetores.h.
//
// QUESTÃO 2:
// Escreva um programa em C++ que lê uma sequência de números de um arquivo
// e armazena em um vetor. Assuma que a quantidade de numeros no arquivo
// não ultrapassa o limite máximo de elementos do vetor (e.g. 1000).
// Use este programa para testar as funções que você implementou na questão 1.
/*

// QUESTÃO 2:
// Escreva um programa em C++ que
1) lê um arquivo vocabulatio.txt uma lista de palavras
separados por espacow e qs armazene em um mapa( estrutura 'map' da STL) associando a cada uma
um número único no intervalo 0 a n-1, onde n é o número total de palaavras no arquivo.
// e armazena em um vetor. Assuma que a quantidade de numeros no arquivo
2) Para tres arquivos de texto A.txt, B.txt e C.txt, que contem apenas palaavras pertencentes ao vocabulario,
crie um vetor com n posicoes. A i-esima posicao deste vetor deve conter
o numero de ocorrencias da palavra associada ao numero i no mapa descrito no item 1.
5) Calcule o valor do cosseno do angulo entre todas as combinacoes 2 a 2 de vetores e imprima
na tela os nomes dos arquivos cuja combinaacao resultou no maior cosseno.
(Este e um metodo para determinar o quao 'parecidos' sao dois conjuntos de palavras. Detalhes
em http://en.wikipedia.org/wiki/Vector_space_model . Neste caso, quanto maior o cosseno
mais parecidos sao os textos )


*/



#include<fstream>
#include<map>
#include<iostream>
#include "vetores2/src/vetores.h"

using namespace std;

int main() {
  map<string, int> mapa;
  ifstream entrada;
  char palavra[50];
  int tamvocabulario = 0;
  entrada.open("vocabulario.txt");
  entrada >> palavra;
  int count = 0;
  while ( !entrada.eof() ) {
      mapa.insert(pair< string, int >(palavra, tamvocabulario++));
      entrada >> palavra;
  }
  entrada.close();
  int vA[tamvocabulario];
  for (int i = 0;i < tamvocabulario;i++) {
      vA[i] = 0;
  }
  entrada.open("A.txt");
  entrada >> palavra;
  while ( !entrada.eof() ) {
     vA[ mapa.find(palavra)->second ]++;
     entrada >> palavra;
  }
  entrada.close();
  int vB[tamvocabulario];
  for (int i = 0;i < tamvocabulario;i++) {
      vB[i] = 0;
  }
  entrada.open("B.txt");
  entrada >> palavra;
  while ( !entrada.eof() ) {
      vB[ mapa.find(palavra)->second ]++;
      entrada >> palavra;
  }
  entrada.close();
  int vC[tamvocabulario];
  for (int i = 0;i < tamvocabulario;i++) {
       vC[i] = 0;
  }
  entrada.open("C.txt");
  entrada >> palavra;
  while ( !entrada.eof() ) {
      vC[ mapa.find(palavra)->second ]++;
      entrada >> palavra;
  }
  entrada.close();
  float cos_A_B = Cosseno_Vetores(vA, vB, tamvocabulario);
  float cos_A_C = Cosseno_Vetores(vA, vC, tamvocabulario);
  float cos_B_C = Cosseno_Vetores(vB, vC, tamvocabulario);
  float Max = (cos_A_B >= cos_A_C ? cos_A_B : cos_A_C);
  if ( cos_B_C > Max ) {
        Max = cos_B_C;
  }
  if ( Max == cos_A_B ) {
        cout << "A e B resultam em cosseno maximo." << endl;
  }
  if ( Max == cos_A_C ) {
        cout << "A e C resultam em cosseno maximo." << endl;
  }
  if ( Max == cos_B_C ) {
        cout << "B e C resultam em cosseno maximo." << endl;
  }

  return 1;
}
