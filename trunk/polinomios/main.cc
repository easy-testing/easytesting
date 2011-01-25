#include "polinomios.h"

#include <iostream>
#include <fstream>

using namespace std;

// Le um polinomio P(x) de uma arquivo e indefinidamente le um numero x
// do teclado e exibe na tela o valor de P(x).
// O primeiro nUmero do arquivo 'n' representa o grau do polinomio e
// eh seguido por n + 1 numeros reais que representam os cooeficientes de P(x).
int main() {
  ifstream fin("input.txt");
  int n;
  fin >> n;
  float* v = new float[n + 1];
  for (int i = 0; i <= n; i++){
    fin >> v[i];
  }
  Polinomio p(n + 1, v);
  delete [] v;

  while(true) {
    float x;
    cin >> x;
    cout << "P(" << x << ") = " << p.Avaliar(x) << endl;
  }
  return 0;
}
