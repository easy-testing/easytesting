// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Maps
//
// Questão 1.
// Leia um arquivo contendo apenas palavras, e imprima as palavras em ordem
// crescente de lexicografia, seguidas do número de ocorrências da palavra no
// texto.
//
// Exemplo de entrada:
// lar doce lar
//
// Exemplo de saída:
// doce 1
// lar 2

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "ordered_map_with_bst/src/map.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main() {
  map words;

  ifstream fin("input.txt");

  Node *word;
  string str;
  while (fin >> str) {
    word = words.find(str);
    if ( word == words.end() ) {
      words.insert(str, 1);
    } else {
      words.insert(str, words.value(word)+1);
    }
  }

  for (Node* i = words.begin(); i != words.end(); i = words.next(i)) {
    std::cout << words.key(i) << ' ' << words.value(i) << std::endl;
  }

  return 0;
}
