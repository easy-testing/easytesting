#include "tp.h"

int distanciaMaxima(double velocidade, double angulo){
	double g = 9.80665;
	double pi = 3.14159265;
	double radiano = pi / 180; //um radiano é equivalente a PI/180
	return (pow(velocidade, 2)*sin(2*(angulo*radiano)))/g; 
}

void imprimeCenarioComObjeto(char* cenario, int pos_acerto){
	int i;
	for(i = 0; i < 100; i++){
		if(i != pos_acerto){
		    printf("%c", cenario[i]);
		}
        else{
            printf("*");
        }
	}
	printf("\n");
}

void imprimeCenario(char* cenario){
	int i;
	for(i = 0; i < 100; i++){
		printf("%c", cenario[i]);
	}
	printf("\n");
}

int valida(char elemento){
	if(isalpha(elemento) || elemento == '_'){
		return 1;
	}
	return 0;
}

void lerCenario(char* filename, char* cenario, int* jogadores){
	int i, posJogador=0;
	char elemento;
	FILE *arq = fopen(filename, "r");
	if(arq == NULL){
		printf("Arquivo nao encontrado.\n");
		exit(0);
	}
	else{
		for(i = 0; i < 100; i++){
			fscanf(arq, "%c", &elemento);
			if(valida(elemento)){
				if(isalpha(elemento)){
					jogadores[posJogador] = i;
					posJogador ++;
				}
				cenario[i] = elemento;
			}
		}
		fclose(arq);	
	}
}

int colisao(int alternador, char* cenario, int dm, int* jogadores){
    int i;    
    if(alternador){
			dm = jogadores[alternador]*10 - dm;
		}
		else{
			dm = jogadores[alternador]*10 + dm;
		}
		if(dm > 0 && dm < 1000){
			for(i = 1; i < 100; i++){
				if(dm < i*10){
					if(isalpha(cenario[i-1]) && cenario[jogadores[alternador]] != isalpha(cenario[i-1])){
                        imprimeCenarioComObjeto(cenario, i-1);
						printf("Jogador %c venceu\n", cenario[jogadores[alternador]]);
                       return 1;
					}
					imprimeCenarioComObjeto(cenario, i-1);
                    return 0;
				}
			}
		}
		else{
			printf("Acertou fora do cenario\n");
            imprimeCenario(cenario);
            return 0;
		}
}


