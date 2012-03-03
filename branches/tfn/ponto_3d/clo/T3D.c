//
//  T3D.c
//  tp0
//
//  Created by Clodoveu Davis on 19/08/11.
//  Copyright 2011 UFMG. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "T3D.h"

void Cria(TipoObjeto *Obj, FILE *infile)
// Le^o arquivo com nome fName e carrega o objeto a transformar para o vetor Obj
{
    int i, n;
    double x, y, z;
    
    fscanf(infile, "%d\n", &n);
    Obj->n = n;
    
    for (i = 0; i < n; i++) {
        fscanf(infile, "%lf %lf %lf\n", &x, &y, &z);
        Obj->vertice[i].M[X] = x;
        Obj->vertice[i].M[Y] = y;
        Obj->vertice[i].M[Z] = z;
        Obj->vertice[i].M[T] = 1;
    }
}

Mat4x4 Trans(double deltaX, double deltaY, double deltaZ)
// Constrói uma matriz de translacao
{    
    Mat4x4 M;
    
    M.M[0][0] = 1;
    M.M[0][1] = 0;
    M.M[0][2] = 0;
    M.M[0][3] = deltaX;
    M.M[1][0] = 0;
    M.M[1][1] = 1;
    M.M[1][2] = 0;
    M.M[1][3] = deltaY;
    M.M[2][0] = 0;
    M.M[2][1] = 0;
    M.M[2][2] = 1;
    M.M[2][3] = deltaZ;
    M.M[3][0] = 0;
    M.M[3][1] = 0;
    M.M[3][2] = 0;
    M.M[3][3] = 1;
    
    return M;
}

Mat4x4 Escala(double FX, double FY, double FZ)
// Constrói uma matriz de mudanca de escala
{    
    Mat4x4 M;
    
    M.M[0][0] = FX;
    M.M[0][1] = 0;
    M.M[0][2] = 0;
    M.M[0][3] = 0;
    M.M[1][0] = 0;
    M.M[1][1] = FY;
    M.M[1][2] = 0;
    M.M[1][3] = 0;
    M.M[2][0] = 0;
    M.M[2][1] = 0;
    M.M[2][2] = FZ;
    M.M[2][3] = 0;
    M.M[3][0] = 0;
    M.M[3][1] = 0;
    M.M[3][2] = 0;
    M.M[3][3] = 1;
    
    return M;
}

Mat4x4 Rot(int eixo, double angulo)
// Constrói uma matriz de rotação
// eixo: 0 = X, 1 = Y, 2 = Z
{   
    Mat4x4 M;
    double costeta = cos(angulo * PI / 180);
    double senteta = sin(angulo * PI / 180);
    
    M.M[0][0] = 1;
    M.M[0][1] = 0;
    M.M[0][2] = 0;
    M.M[0][3] = 0;
    M.M[1][0] = 0;
    M.M[1][1] = 1;
    M.M[1][2] = 0;
    M.M[1][3] = 0;
    M.M[2][0] = 0;
    M.M[2][1] = 0;
    M.M[2][2] = 1;
    M.M[2][3] = 0;
    M.M[3][0] = 0;
    M.M[3][1] = 0;
    M.M[3][2] = 0;
    M.M[3][3] = 1;
    switch(eixo) {
        case 0: // X
            M.M[1][1] = costeta;
            M.M[2][2] = costeta;
            M.M[1][2] = -senteta;
            M.M[2][1] = senteta;
            break;
        case 1: //Y
            M.M[0][0] = costeta;
            M.M[2][2] = costeta;
            M.M[0][2] = -senteta;
            M.M[2][0] = senteta;
            break;
        case 2: //Z
            M.M[0][0] = costeta;
            M.M[1][1] = costeta;
            M.M[1][0] = senteta;
            M.M[0][1] = -senteta;
            break;
    }
    
    return M;
}

Mat4x4 Zero(void)
// retorna uma matriz 4x4 zerada (inicializacao)
{
    Mat4x4 M;
    int i, j;
    for (i = 0; i < 4; i++) 
        for (j = 0; j < 4; j++) 
            M.M[i][j] = 0;
    return M;
}

Mat4x4 Um(void)
// retorna uma matriz identidade (inicializacao)
{
    Mat4x4 M;
    int i;
    
    M = Zero();
    for (i = 0; i < 4; i++) M.M[i][i] = 1;
    return M;
}

Mat4x4 MatComp(Mat4x4 M1, Mat4x4 M2)
// Composicao de matrizes 4x4 por multiplicacao
{
    int i, j, k;
    Mat4x4 M;
    
    M = Zero();
    for(i = 0; i < 4; i++) 
        for( j = 0; j < 4; j++)
            for( k = 0; k < 4; k++) 
                M.M[i][j] +=  M1.M[i][k] * M2.M[k][j];
    
    return M;
}

TipoObjeto MatTransf(Mat4x4 M, TipoObjeto P)
// Aplicação da transformação codificada na matriz M sobre o objeto P
{
    int i, j, k;
    TipoObjeto R;
    R.n = P.n;
    for (i = 0; i < R.n; i++)
        R.vertice[i].M[0] = R.vertice[i].M[1] = R.vertice[i].M[2] = R.vertice[i].M[3] = 0;
    
    for (k = 0; k < P.n; k++) {
        for( i = 0; i < 4; i++) {
            for( j = 0; j < 4; j++) {
                R.vertice[k].M[i] +=  M.M[i][j] * P.vertice[k].M[j];
            }
        }
    }            
    return R;
}

void Imprime(TipoObjeto Obj, char* fName)
// Imprime um objeto no arquivo fName
{
    int i;
    FILE *outfile;
    
    if ((outfile = fopen(fName, "w")) == NULL) {
        printf("Erro: nao foi possivel criar arquivo %s\n", fName);
        exit(1);
    }
    
    fprintf(outfile, "%d\n", Obj.n);
    for (i = 0; i < Obj.n; i++)
        fprintf(outfile, "%.3lf %.3lf %.3lf\n", Obj.vertice[i].M[X], Obj.vertice[i].M[Y], Obj.vertice[i].M[Z]);
    
    fclose(outfile);
}
