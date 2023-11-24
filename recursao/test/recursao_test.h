// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)



#include "../doctest/doctest.h"
#include "./src/recursao.h"

using std::string;
using std::stringstream;

TEST_CASE("Teste_Fatorial") {
    int esperado[] = {1, 1, 720};
    int entrada[] = {1, 0, 6};
    int num_testes = 3;

    for (int i = 0; i < num_testes; i++) {
        CHECK_EQ(esperado[i], fat(entrada[i]));
        if (esperado[i] != fat(entrada[i])) {
            INFO("---------------------------------------------------");
            INFO("Erro na função: int fat(int)");
            INFO("---------------------------------------------------");
            INFO("Valor de entrada : " << entrada[i]);
            INFO("Resultado esperado : " << esperado[i]);
            INFO("Resultado retornado : " << fat(entrada[i]));
            INFO("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_Potenciacao") {
    int esperado[] = {1, 16, -1, 9};
    int entrada1[] = {5, -2, -1, 3};
    int entrada2[] = {0, 4, 3, 2};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK_EQ(esperado[i], pow(entrada1[i], std::ref(entrada2[i]));
        if (esperado[i], pow(entrada1[i], std::ref(entrada2[i])) {
            INFO("---------------------------------------------------");
            INFO("Erro na função: int pow(int, int)");
            INFO("---------------------------------------------------");
            INFO("Valores de entrada : " << entrada1[i] << " elevado a " << entrada2[i]);
            INFO("Resultado esperado : " << esperado[i]);
            INFO("Resultado retornado : " << pow(entrada1[i], entrada2[i]));
            INFO("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_MDC_entre_dois_numeros") {
    int esperado[] = {11, 9, 1, 4};
    int entrada1[] = {11, 9, 11, 28};
    int entrada2[] = {11, 27, 13, 20};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK_EQ(esperado[i], mdc(entrada1[i], entrada2[i]));
        if (esperado[i] != mdc(entrada1[i], entrada2[i])) {
            INFO("---------------------------------------------------");
            INFO("Erro na função: int mdc(int, int)");
            INFO("---------------------------------------------------");
            INFO("Valores de entrada : " << entrada1[i] << " e " << entrada2[i]);
            INFO("Resultado esperado : " << esperado[i]);
            INFO("Resultado retornado : " << mdc(entrada1[i], entrada2[i]));
            INFO("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_MDC_entre_tres_numeros") {
    int esperado[] = {10, 10, 1, 1, 3};
    int entrada1[] = {10, 10, 17, 23, 9};
    int entrada2[] = {10, 10, 41, 27, 6};
    int entrada3[] = {10, 50, 13, 45, 12};
    int num_testes = 5;
    for (int i = 0; i < num_testes; i++) {
        CHECK_EQ(esperado[i], mdc3(entrada1[i], entrada2[i], entrada3[i]));
        if (esperado[i] != mdc3(entrada1[i], entrada2[i], entrada3[i])) {
            INFO("---------------------------------------------------");
            INFO("Erro na função: int mdc3(int, int, int)");
            INFO("---------------------------------------------------");
            INFO("Valores de entrada : " << entrada1[i] << ", " << entrada2[i] << " e " << entrada3[i]);
            INFO("Resultado esperado : " << esperado[i]);
            INFO("Resultado retornado : " << mdc3(entrada1[i], entrada2[i], entrada3[i]));
            INFO("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_MMC") {
    int esperado[] = {10, 27, 21, 30};
    int entrada1[] = {10, 3, 1, 6};
    int entrada2[] = {10, 27, 21, 10};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK_EQ(esperado[i], mmc(entrada1[i], entrada2[i]));
        if (esperado[i] != mmc(entrada1[i], entrada2[i])) {
            INFO("---------------------------------------------------");
            INFO("Erro na função: int mmc(int, int)");
            INFO("---------------------------------------------------");
            INFO("Valores de entrada : " << entrada1[i] << " e " << entrada2[i]);
            INFO("Resultado esperado : " << esperado[i]);
            INFO("Resultado retornado : " << mmc(entrada1[i], entrada2[i]);
            INFO("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_sequencia_de_Fibonacci") {
    int esperado[] = {0, 1, 3};
    int entrada[] = {0, 1, 4};
    int num_testes = 3;
    for (int i = 0; i < num_testes; i++) {
        CHECK_EQ(esperado[i], fib(entrada[i]);
        if (esperado[i] != fib(entrada[i])) {
            INFO("---------------------------------------------------");
            INFO("Erro na função: int fib(int)");
            INFO("---------------------------------------------------");
            INFO("Valores de entrada : " << entrada[i]);
            INFO("Resultado esperado : " << esperado[i]);
            INFO("Resultado retornado : " << fib(entrada[i]));
            INFO("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_da_Resto") {
    int esperado[] = {3, 0, 0, 5};
    int entrada1[] = {3, 4, 9, 15};
    int entrada2[] = {4, 4, 3, 10};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK_EQ(esperado[i], resto(entrada1[i], entrada2[i]);
        if (esperado[i] != resto(entrada1[i], entrada2[i])) {
            INFO("---------------------------------------------------");
            INFO("Erro na função: int resto(int, int)");
            INFO("---------------------------------------------------");
            INFO("Valores de entrada : " << entrada1[i] << " dividido por " << entrada2[i]);
            INFO("Resultado esperado : " << esperado[i]);
            INFO("Resultado retornado : " << resto(entrada1[i], entrada2[i]);
            INFO("---------------------------------------------------");
        }
    }
}

TEST_CASE("Teste_da_Divisao_inteira") {
    int esperado[] = {0, 1, 3, 1};
    int entrada1[] = {3, 4, 9, 15};
    int entrada2[] = {4, 4, 3, 10};
    int num_testes = 4;
    for (int i = 0; i < num_testes; i++) {
        CHECK_EQ(esperado[i], div_(entrada1[i], entrada2[i]);
        if (esperado[i] != div_(entrada1[i], entrada2[i])) {
            INFO("---------------------------------------------------");
            INFO("Erro na função: int div_(int, int)");
            INFO("---------------------------------------------------");
            INFO("Valores de entrada : " << entrada1[i] << " dividido por " << entrada2[i]);
            INFO("Resultado esperado : " << esperado[i]);
            INFO("Resultado retornado : " << div_(entrada1[i], entrada2[i]);
            INFO("---------------------------------------------------");
        }
    }
}

