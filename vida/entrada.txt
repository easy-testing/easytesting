#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

const int MAX_LIN = 100;
const int MAX_COL = 100;
int matriz[MAX_LIN][MAX_COL];
int matrizAux[MAX_LIN][MAX_COL];
int n;
int m;

void lerMatriz(const char *nomeEnt) {
  ifstream fEntrada;
  fEntrada.open(nomeEnt);
  if (! fEntrada.is_open()) {
    cout << "Arquivo "<<nomeEnt<< " nao encontrado";
    return;
  }

  fEntrada >> n;
  fEntrada >> m;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      fEntrada >> matriz[i][j];
    }
  }
  fEntrada.close();
}

void imprimirMatriz() {
  for (int i = 0; i < m + 2; i++) {
    cout << "_";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << "|";
    for(int j = 0; j < m; j++) {
       if (matriz[i][j]) {
         cout << "*";
       } else {
         cout << " ";
       }
     }
     cout << "|" << endl;
  }
  for (int i = 0; i < m + 2; i++) {
    cout << "_";
  }
  cout << endl;
}

int numeroVizinhos(int l, int c) {
  int vizinhos = 0;
  if (l > 0) {
    if (c > 0) {
      vizinhos = vizinhos + matrizAux[l - 1][c - 1];
    }
    vizinhos = vizinhos + matrizAux[l - 1][c];
    if (c < MAX_COL - 1) {
      vizinhos = vizinhos + matrizAux[l - 1][c + 1];
    }
  }
  if (c > 0) {
    vizinhos = vizinhos + matrizAux[l][c - 1];
  }
  if (c < MAX_COL - 1) {
    vizinhos = vizinhos + matrizAux[l][c + 1];
  }
  if (l < MAX_LIN - 1) {
    if (c > 0) {
      vizinhos = vizinhos + matrizAux[l + 1][c - 1];
    }
    vizinhos = vizinhos + matrizAux[l + 1][c];
    if (c < MAX_COL - 1) {
      vizinhos = vizinhos + matrizAux[l + 1][c + 1];
    }
  }
  return vizinhos;
}

  // 1.Any live cell with fewer than two live neighbours dies, as if caused by under-population.
  // 2.Any live cell with two or three live neighbours lives on to the next generation.
  // 3.Any live cell with more than three live neighbours dies, as if by overcrowding.
  // 4.Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
int proximoEstado(int l, int c) {
  int vizinhos = numeroVizinhos(l, c);
  if (matrizAux[l][c] == 1) {
    if (vizinhos < 2 || vizinhos > 3) {
      return 0;
    } else {
      return 1;
    }
  } else {
    if (vizinhos == 3) {
      return 1;
    } else {
      return 0;
    }
  }
}
void calcularProximaGeracao() {
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      matrizAux[i][j] = matriz[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      matriz[i][j] = proximoEstado(i, j);
    }
  }
}

void gravarMatriz(const char *nomeSai) {
  ofstream fSaida(nomeSai);
  if (! fSaida.is_open()) {
    cout << "Erro abrindo arquivo "<<nomeSai<< " para escrita";
    return;
  }
 fSaida << n << " " << m << endl;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      fSaida <<  matriz[i][j] << " ";
    }
    fSaida << endl;
  }
  fSaida.close();
}

int main() {
  cout << "Digite o nome arquivo de entrada: ";
  char nome[128];
  cin >> nome;
  lerMatriz(nome);
  imprimirMatriz();
  char op;
  cout << "s/n: ";
  cin >> op;
  while (op != 'n') {
    calcularProximaGeracao();
    imprimirMatriz();
    cout << "s/n: ";
    cin >> op;
  }
  cout << "Digite o nome arquivo de saida: ";
  cin >> nome;

  gravarMatriz(nome);
  return 0;
}
