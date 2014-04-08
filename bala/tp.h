#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>


int distanciaMaxima(double velocidade, double angulo);

void imprimeCenarioComObjeto(char* cenario, int pos_acerto);

void imprimeCenario(char* cenario);

int valida(char elemento);

void lerCenario(char* filename, char* cenario, int* jogadores);

int colisao(int alternador, char* cenario, int dm, int* jogadores);
