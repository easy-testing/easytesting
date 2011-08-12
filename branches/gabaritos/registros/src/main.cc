// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre estruturas de dados heterogêneas - Registros.
//
// QUESTÃO 1:
// Implemente em ponto.cc o struct Ponto que está em ponto.h.
//
// QUESTÃO 2:
// Implemente em triangulo.cc o struct Triangulo que está em Triangulo.h.
//
// QUESTÃO 3:
// Implemente em retangulo.cc o struct Retangulo que está em retangulo.h.
//
// QUESTÃO 4:
// Implemente em circunferencia.cc o struct Circunferencia que está
// em circunferencia.h.
//
// QUESTÃO 5:
// Resolva o seguinte problema: imagine que você está no centro de BH e procura
// um restaurante para almoçar. Você gostaria de saber quais são todos os
// restaurantes que estão a menos de uma determinada distância de onde você
// está.
// Escreva um programa em C++ que lê de um arquivo o nome e as coordenadas x e y
// de todos os restaurantes da cidade. O programa deve iterativamente perguntar
// qual é a coordenada (x, y) em que você se encontra e a distância máxima d que
// você está disposto a caminhar para chegar em algum restaurante. Para cada
// valor de x, y e d que o usuário digitar, o seu programa deve retornar a
// lista com o nome e a distância entre você e todos os restaurantes que
// estão a menos de d Km da sua posição atual. Assuma que BH tem no máximo
// 4.000 bares.
// Por favor, use os structs Ponto e Circunferencia definidos acima.
//
// QUESTÃO 6: DESAFIO!
// Resolva o mesmo problema da questão 6, mas imprima os bares ordenados,
// começando do mais próximo da posição em que o usuário está e terminando com o
// bar mais distante.

#include <iostream>
#include <fstream>
#include <string>

#include "registros/src/circunferencia.h"
#include "registros/src/ponto.h"

using namespace std;

// Gabarito da questão 5.
int main() {
  ifstream input;
  Ponto bar[4000];
  string nome;
  int num_bares = 0;
  float a, b, dist_max;
  cout << "Digite as coordenadas x e y de onde voce se encontra: ";
  cin >> a >> b;
  Ponto centro = {a, b};
  cout << endl << "Digite a distancia maxima a caminhar: ";
  cin >> dist_max;
  input.open("input.txt");
  while (input >> nome >> a >> b) {
    bar[num_bares].x = a;
    bar[num_bares].y = b;
    if (Distancia(centro, bar[num_bares]) <= dist_max) {
      cout << "Bar: " << nome << "\t\t"
           << "Distancia: " << Distancia(centro, bar[num_bares])<< endl;
    }
    num_bares++;
  }
  input.close();
}

