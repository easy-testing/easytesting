//
//  T3D.h
//  tp0
//
//  Created by Clodoveu Davis on 19/08/11.
//  Copyright 2011 UFMG. All rights reserved.
//

#ifndef tp0_T3D_h
#define tp0_T3D_h

#define X 0
#define Y 1
#define Z 2
#define T 3

#define PI 3.1415928

#define MAXVERT 1000

typedef struct {
    double M[4][4];
} Mat4x4;  // Matriz 4x4 para as transformacoes

typedef struct {
    double M[4];
} Mat4x1;  // Vertice 3D = matriz 4x1, coordenadas homogeneas

typedef struct {
    Mat4x1 vertice[MAXVERT];
    int n;
} TipoObjeto; // Objeto = vetor de vertices 3D


void Cria(TipoObjeto *Obj, FILE *infile);       // Le^o arquivo com nome fName e carrega o objeto a transformar para o vetor Obj
Mat4x4 Trans(double, double, double);           // Constrói uma matriz de translacao
Mat4x4 Escala(double, double, double);          // Constrói uma matriz de mudanca de escala
Mat4x4 Rot(int eixo, double angulo);            // Constrói uma matriz de rotação; eixo: 0 = X, 1 = Y, 2 = Z
Mat4x4 Zero(void);                              // Gera uma matriz 4x4 zerada
Mat4x4 Um(void);                                // Gera uma matriz 4x4 identidade
Mat4x4 MatComp(Mat4x4 M1, Mat4x4 M2);           // Composicao de matrizes 4x4 por multiplicacao
TipoObjeto MatTransf(Mat4x4 M, TipoObjeto Obj); // Aplicação da transformação codificada na matriz M sobre o objeto P
void Imprime(TipoObjeto Obj, char* fName);      // Imprime um objeto no arquivo fName


#endif

