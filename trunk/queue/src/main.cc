// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)

#include <iostream>
#include <fstream>
#include "queue/src/queue.h"

using namespace std;

// TODO(tfn): Escrever enunciado.
int main() {
  // Lê os dados de um arquivo.
  ifstream fin("input.txt");
  queue<float> fila;
  float x;
  while (fin >> x) {
    fila.push(x);
  }

  // Imprime-os na mesma ordem em que no arquivo.
  while (!fila.empty()) {
    cout << fila.front() << endl;
    fila.pop();
  }
  return 0;
}
