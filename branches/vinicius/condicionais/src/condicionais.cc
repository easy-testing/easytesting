// Copyright 2012 Universidade Federal de Minas Gerais (UFMG)
#include "condicionais/src/condicionais.h"
#include <cmath>

int menor(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int maior(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int maior(int x, int y, int z) {
    if ((x > y) && (x > z)) {
        // Verifica se x é maior
        return x;
    } else if (y > z) {
        // Verifica se y é maior.
        return y;
    } else {
        // Se z é maior.
        return z;
    }
}

bool verifica_sinal(int x) {
    if (x < 0) {
        return false;
    } else {
        return true;
    }
}

bool verifica_par_impar(int x) {
    if (x%2==0) {
        return true;
    } else {
        return false;
    }
}

int potenciacao(int x, int y) {
    int base = maior(x, y);
    int expoente = menor(x,y);
    return pow(base,expoente);
}

bool divisao(int a, int b, int &r) {
    if(b > 0) {
        r = (a/b);
        return true;
    } else {
        return false;
    }
}

int tipo_triangulo(int a, int b, int c) {
    if ((a < b + c) && (b < a + b) && (b < a +b)) {
        if ((a == b) && (a == c)) {
            return 1;
        } else if((a == b) || (a == c) || (b == c)) {
            return 2;
        } else {
            return 3;
        }
    }
}
