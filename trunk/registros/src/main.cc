// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre estruturas de dados heterogêneas - Registros.
//
// QUESTÃO 1:
// Implemente em registros.cc o struct Ponto que está em registros.h.
//
// QUESTÃO 2:
// Implemente em registros.cc o struct Triangulo que está em registros.h.
//
// QUESTÃO 3:
// Implemente em registros.cc o struct Retangulo que está em registros.h.
//
// QUESTÃO 4:
// Implemente em registros.cc o struct Circunferencia que está em registros.h.
//
// QUESTÃO 5:
// Resolva o seguinte problema: imagine que você está no centro de BH e procura
// um restaurante para almoçar. Você gostaria de saber quais são todos os
// restaurantes que estão a menos de uma determinada distância de onde você
// está.
// Escreva um programa em C++ que lê de um arquivo o nome e as coordenadas x e y
// de todos os restaurantes da cidade. O programa deve iterativamente perguntar
// qual é a coordenada (x, y) em que você se encontra e a distância máxima que
// você está disposto a caminhar para chegar em algum restaurante. Para cada
// valor de x, y e d que o usuário digitar, o seu programa deve retornar a
// lista com o o nome e a distância entre você e todos os restaurantes que
// estão a menos de d Km da sua posição atual. Assuma que BH não tem mais do
// 4.000 bares.
// Por favor, use os structs Ponto e Circunferencia definidos acima.
//
// QUESTÃO 6:
// Resolva o mesmo problema da questão 6, mas imprima os bares ordenados,
// começando do mais próximo da posição em que o usuário está e terminando com o
// bar mais distante.

#include <iostream>
#include <fstream>

#include "easytesting/registros/src/registros.h"

using std::cout;
using std::endl;

int main() {
  ifstream input;
  Ponto bar[4000];
  string CNPJ;
  int num_bares = 0;
  float a, b, dist_max;
  Ponto centro;
  cout << "Digite as coordenadas x e y de onde voce se encontra: ";
  cin >> a >> b;
  centro.atribuir(a, b);
  cout << endl << "Digite a distancia maxima a caminhar: ";
  cin >> dist_max;
  input.open("input.txt");
  while (input >> CNPJ >> a >> b) {
    bar[num_bares].atribuir(a, b);
    if (dist_max >= bar[num_bares].distancia(centro)) {
      cout << "CNPJ: " << CNPJ << endl;
    }
    num_bares++;
  }
  input.close();
}
