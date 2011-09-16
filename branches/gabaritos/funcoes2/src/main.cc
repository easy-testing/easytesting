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

// Exibe na dela o objetivo do jogo
void Instrucoes() {
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


// Recebe a posicao xi de disparo(metros),
// le do teclado os parametros
// a e v da funcao 1( orientando o usuario
// com mensagens na tela), chama  a funcao 1
// utilizando esses parametros
// e retorna seu resultado
float RecebeJogada(float xi) {
     cout << " -- Digite os parametros do disparo ";
     cout << "(casas decimais separadas por um ponto) -- \n";

     float a;
     float v;

     cout << " Angulo do disparo em graus(anti-horario em relacao ao solo):";
     cin >> a;
     cout << " Velocidade do projetil em m/s:";
     cin >> v;

     return Destino_disparo(xi, a, v);
}

// Avalia se o disparo atingiu o alvo, recebendo
// a posicao final do projetil xf e o intervalo do alvo [a,b].
// Exibe na tela uma mensagem descrevendo
// a posicao final do projetil e indicando se o tiro atingiu ou nao o alvo.
// Retorna true se o alvo foi atingido e false caso contrario.
bool ResultadoJogada(float xf, float a, float b) {
     printf("\n------>O disparo atingiu a posicao %.2f m.", xf);


     if ( Pertence_intervalo(xf, a, b) ) {
          cout << "Alvo atingido!!!\n";
          return true;

     } else {
          cout << "Errou o alvo...\n";
          return false;
     }
}


void DeclaraVez(int jogador) {
     cout << "\n--------------------------------------\n";
     cout << "         Vez do jogador " << jogador;
     cout << "\n--------------------------------------\n";
}

void ExibeCenario(float xi, float a, float b) {
     cout << "Posicao do canhao no eixo x: " << xi << "." << endl;
     cout << "Regiao alvo: [" << a << "," << b << "]." << endl << endl;
}


int main() {
       int njogadores  = 0;
       float        xi = 0.;
       float         a = 0.;
       float         b = 0.;


       FILE * cenario;
       cenario = fopen("cenario.txt", "r");
       if (cenario != NULL) {
           fscanf(cenario, "%d %f %f %f", &njogadores , &xi , &a , &b);
               fclose(cenario);
       } else {
          cout << "Erro ao abrir cenario. Saindo do programa" << endl;
          exit(1);
       }


     Instrucoes();
     bool    fim = false;
     int jogador = 1;

     while ( !fim ) {
          DeclaraVez(jogador);
          ExibeCenario(xi , a , b);
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
