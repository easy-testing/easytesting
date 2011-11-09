// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Conjuntos.
//
// Questão 1.
// Implemente em set.h e set.cc o TAD set, utilizando o TAD list.
//
// Questão 2.
// Escreva uma função "void Imprimir(set& s)" que recebe
// como parâmetro um conjunto s e imprime os elementos de s na tela.
// DICA: Utilize a função set<type>::ToList(list<type>* l).
//
// Questão 3.
// Escreva uma função
// "void Intersecao(set& a, set& b, set* inter)" que recebe dois conjuntos
// 'a' e 'b' e atribui a 'inter' o resultado da interseção de 'a' e 'b'.
//
// Questão 4.
// Escreva um programa que gerencia os fornecedores para compra de peças
// em uma montadora de carros. As peças são identificadas por números inteiros
// entre 1 e 100 e os fornecedores são identificados por uma string.
//
// O sistema deve ler de um arquivo o nome dos fornecedores de peças e a lista
// das peças que cada fornecedor vende. Assuma que cada fornecedor sempre
// oferece exatamente 10 peças diferentes para venda. Tome como EXEMPLO o
// arquivo "fornecedores.txt". A  primeira linha deste arquivo contém o número n
// de fornecedores. As n linhas seguintes contêm uma string com o nome do
// de um fornecedor seguida de 10 números inteiros que são as peças vendidas
// por este fornecedor.
//
// O seu programa deve inicialmente exibir o conjunto com todos os
// fornecedores, ,que são candidatos para fornecer um pedido com várias peças.
// A cada iteração, o usuário deve ser capaz de digitar o número
// de uma peça e o sistema deve eliminar do conjunto de fornecedores candidatos
// aqueles que não vendem a última peça digitada. O programa deve continuar
// pedindo o número de uma nova peça até que o usuário digite zero ou até
// que o conjunto de fornecedores candidatos seja vazio.
//
// DICA: crie um conjunto "set candidatos" que contém
// inicialmente o nome de todos os fornecedores e um vetor
// "set pecas[100]" com o conjunto de fornecedores para cada
// peça. A cada iteração em que uma peça 'p' for digitada, você deve fazer a
// interseção do conjunto 'candidatos' com o conjunto 'pecas[p - 1]'.

#include <fstream>
#include <iostream>
#include <string>

#include "linear_set/src/set.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;


void Imprimir(set& c) {
  cout << "{ ";
  for (Node* i = c.begin(); i != c.end(); i = c.next(i)) {
    cout << c.value(i) << " ";
  }
  cout << "} = " << c.size() << endl;
}

void Intersecao(set& a, set& b, set* inter) {
  // Percorre todos os elementos do cojunto 'a' e insere em 'inter' todos
  // aqueles que também estão no cojunto 'b'.
  inter->clear();
  for (Node* i = a.begin(); i != a.end(); i = a.next(i)) {
    if (b.find(a.value(i)) != b.end()) {
      inter->insert(a.value(i));
    }
  }
}

int main() {
  // pecas[i] contém os fornecedores da peça i + 1.
  set pecas[100];
  set candidatos;

  // Inicializa o cojunto de fornecedores candidatos e o vetor de fornecedores
  // de cada peça.
  ifstream fin("fornecedores.txt");
  int n;
  fin >> n;
  for (int i = 0; i < n; i++) {
    string nome_fornecedor;
    fin >> nome_fornecedor;
    candidatos.insert(nome_fornecedor);
    for (int j = 0; j < 10; j++) {
      int num_peca;
      fin >> num_peca;
      pecas[num_peca - 1].insert(nome_fornecedor);
    }
  }

  // Filtra iterativamente o cojunto de fornecedores candidatos.
  int num_peca = -1;
  while (!candidatos.empty() && num_peca != 0) {
    cout << "Candidatos: ";
    Imprimir(candidatos);
    cout << "Filtrar por peca [1, 100]: ";
    cin >> num_peca;
    if (num_peca >= 1 && num_peca <= 100) {
      set inter;
      Intersecao(pecas[num_peca - 1], candidatos, &inter);
      candidatos = inter;
    }
  }
  cout << "Resultado: ";
  Imprimir(candidatos);
  return 0;
}
