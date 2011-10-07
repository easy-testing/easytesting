// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre funções em C++.
//
// QUESTÃO 1:
// Implemente em funcoes.cc as funções descritas em funcoes.h.
//
// QUESTÃO 2:
// Escreva um programa que simula um jogo cujo
// objetivo e atingir uma determinada area com
// um tiro de canhao.Para isso ele devera:
// (i) Ler de um arquivo chamado 'cenario.txt':
//    - o numero de jogadores n
//    - a posicao do canhao x
//    - os limites a e b de um intervalo fechado [a.b]
// (ii) Alternar a vez entre os jogadores(uma tentativa para cada um),
// retornando ao primeiro apos a vez do ultimo.
// (iii) Em sua vez, o jogador escolhe o angulo e a velocidade do disparo.
// Ele entao e informado da posicao final do projetil. Se a regiao alvo foi
// atingida, e declarado o fim do jogo e o programa termina.
// Obs: Os jogadores deverao ser informados do objetivo do jogo, bem
// como a posicao do canhao e da area alvo.

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "funcoes2/src/funcoes.h"

using namespace std;

void ImprimeInstrucoes() {
  cout << "------------------------------";
  cout << "------------------------------" << endl;
  cout << "                     TIRO AO ALVO" << endl;
  cout << "------------------------------";
  cout << "------------------------------" << endl;
  cout << "O objetivo do jogo e atingir a regiao alvo";
  cout << " com um tiro de canhao." << endl;
  cout << "Para isso voce deve especificar o angulo";
  cout << " do disparo e a velocidade" << endl;
  cout << "inicial do projetil." << endl;
}

float RecebeJogada(float xi) {
  cout << " -- Digite os parametros do disparo ";
  cout << "(casas decimais separadas por um ponto) -- \n";
  cout << " Angulo do disparo em graus(anti-horario em relacao ao solo):";
  float a;
  cin >> a;
  cout << " Velocidade do projetil em m/s:";
  float v;
  cin >> v;
  return DestinoDisparo(xi, a, v);
}

bool ResultadoJogada(float xf, float a, float b) {
  cout << "\n------>O disparo atingiu a posicao "<< xf << "m.";
  if ( PertenceIntervalo(xf, a, b) ) {
    cout << "Alvo atingido!!!\n";
    return true;
  } else {
    cout << "Errou o alvo...\n";
    return false;
  }
}

int main() {
  FILE * cenario;
  cenario = fopen("cenario.txt", "r");
  float xi = 0;
  float a = 0;
  float b = 0;
  int njogadores  = 0;
  if (cenario != NULL) {
    fscanf(cenario, "%d %f %f %f", &njogadores , &xi , &a , &b);
    fclose(cenario);
  } else {
    cout << "Erro ao abrir cenario. Saindo do programa" << endl;
    exit(1);
  }

  ImprimeInstrucoes();
  bool fim = false;
  int jogador = 1;
  while ( !fim ) {
    cout << "\n--------------------------------------\n";
    cout << "         Vez do jogador " << jogador;
    cout << "\n--------------------------------------\n";
    cout << "Posicao do canhao no eixo x: " << xi << "." << endl;
    cout << "Regiao alvo: [" << a << "," << b << "]." << endl << endl;
    float xf = RecebeJogada(xi);
    if (ResultadoJogada(xf, a , b )) {
      cout << endl << ">>>>>Fim de jogo.";
      cout << "Jogador " << jogador << " e o vencedor." << endl;
      fim = true;
    }
    jogador=(jogador%njogadores)+1;
  }
  return 0;
}
