//
//  main.c
//  tp0
//
//  Created by Clodoveu Davis on 19/08/11.
//  Copyright 2011 UFMG. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "T3D.h"

#define INPUTFILE  "in5.txt"
#define OUTPUTFILE "saida5.txt"

int main (int argc, const char * argv[])
{
    TipoObjeto Obj;
    FILE *infile;
    double deltaX, deltaY, deltaZ, scaleX, scaleY, scaleZ, angulo;
    char TipoTransf, eixo;
    Mat4x4 M;

    if ((infile = fopen(INPUTFILE, "r")) == NULL) {
        printf("ERRO: nao foi possivel abrir o arquivo entrada.txt.\n");
        exit(1);
    }

    Cria(&Obj, infile);

    M = Um();

    while (!feof(infile)) {
        TipoTransf = fgetc(infile);
        if (TipoTransf == 'T') {
            fscanf(infile, "%lf %lf %lf\n", &deltaX, &deltaY, &deltaZ);
            M = MatComp(Trans(deltaX, deltaY, deltaZ), M);
        }
        else if (TipoTransf == 'R') {
            fgetc(infile); // espaço
            eixo = fgetc(infile) - 'X';
            fscanf(infile, "%lf\n", &angulo);
            M = MatComp(Rot((int)eixo, angulo), M);
        }
        else if (TipoTransf == 'E') {
            fscanf(infile, "%lf %lf %lf\n", &scaleX, &scaleY, &scaleZ);
            M = MatComp(Escala(scaleX, scaleY, scaleZ), M);
        }
    }

    Obj = MatTransf(M, Obj);

    Imprime(Obj, OUTPUTFILE);
    return 0;
}

