// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Conjuntos.
//
// Questão 1.
// Implemente o TAD set<Type> em set.h utilizando árvores binárias de busca.
//
// Questão 2.
// Escreva uma função "void Imprimir(set<string>& s)" que recebe
// como parâmetro um conjunto s e imprime os elementos de s na tela.
// DICA: Utilize a função set<Type>::ToList(list<Type>* l).
//
// Questão 3.
// Escreva uma função
// "void Intersecao(set<string>& a, set<string>& b, set<string>* inter)" que
// recebe dois conjuntos 'a' e 'b' e atribui a 'inter' o resultado da
// interseção de 'a' e 'b'.
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
// fornecedores, que são candidatos para fornecer um pedido com várias peças.
// A cada iteração, o usuário deve ser capaz de digitar o número
// de uma peça e o sistema deve eliminar do conjunto de fornecedores candidatos
// aqueles que não vendem a última peça digitada. O programa deve continuar
// pedindo o número de uma nova peça até que o usuário digite zero ou até
// que o conjunto de fornecedores candidatos seja vazio.
//
// DICA: crie um conjunto "set<string> candidatos" que contém inicialmente o
// nome de todos os fornecedores e um vetor "set<string> pecas[100]" com o
// conjunto de fornecedores para cada peça. A cada iteração em que uma peça
// x for digitada, você deve fazer a interseção do conjunto 'candidatos' com
// o conjunto 'pecas[x - 1]'.

#include <fstream>
#include <iostream>
#include "ordered_set/src/set.h"

using namespace std;

// Imprime os elementos da lista entre chaves.
void Imprimir(set<string>& s) {
  list<string> l;
  s.ToList(&l);
  cout << "{";
  for (Node<string>* i = l.begin(); i != l.end() ; i = i->next) {
    cout << i->key;
    if (i->next != l.end())
      cout << ", ";
  }
  cout << "}" << endl;
}

void Intersecao(set<string>& a, set<string>& b, set<string>* inter) {
  // Apaga todos os elementos de 'inter'.
  inter->clear();
  // Percorre todos os elementos do cojunto 'a' e insere em 'inter' todos
  // aqueles que também estão no cojunto 'b'.
  list<string> list_a;
  a.ToList(&list_a);
  for (Node<string>* i = list_a.begin(); i != list_a.end() ; i = i->next) {
    if (b.find(i->key)) {
      inter->insert(i->key);
    }
  }
}

int main() {
  set<string> pecas[100];  // pecas[i] contém os fornecedores da peça i + 1.
  set<string> candidatos;

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
    cout << "Filtrar por peça [1, 100]: ";
    cin >> num_peca;
    if (num_peca >= 1 && num_peca <= 100) {
      set<string> inter;
      Intersecao(pecas[num_peca - 1], candidatos, &inter);
      candidatos = inter;
      cout << "\n\nCandidatos: ";
      Imprimir(candidatos);
    }
  }
  return 0;
}
