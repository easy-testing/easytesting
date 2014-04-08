#include"tp.h"

int main(int argv, char* argc[]){
	char cenario[100];
	int jogadores[2];
	char* arquivo= "entrada/entrada.txt";
	lerCenario(arquivo, cenario, jogadores);
	imprimeCenario(cenario);
	double velocidade=0.0, angulo =0.0; 
	int dm = 0.0, alternador = 0, vitoria = 0;
	while(vitoria != 1){
		printf("Jogador %c\n", cenario[jogadores[alternador]]);
		printf("Velocidade Inicial: ");
		scanf("%lf", &velocidade);
		printf("\nAngulo: ");
		scanf("%lf", &angulo);
		printf("\n");
		
		dm = distanciaMaxima(velocidade, angulo);
		
        if(colisao(alternador, cenario, dm, jogadores)){
            vitoria = 1;
        }
		
		if(alternador) alternador = 0;
		else alternador = 1;
	}
	
	return 0;
}
