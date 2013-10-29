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
//
// Você pode assumir que os arquivos contém apenas caracteres que são letras
// (a-z e A-Z), números (0-9), e caracteres de pontuação (",", ".", "?", etc.).
// Você pode assumir que o texto não tem acentos nem "ç".
// Após ler cada palavra, você deve (i) transformar todas as letras maiúsculas em
// minúsculas e (ii) apagar todos os caracteres que não são letras ou números. Por
// exemplo, depois de ler "Guarda-Chuva?", você deve transformá-la em "guardachuva",
// antes de inseri-la no índice invertido. Desta forma, a mesma palavra apresentada com
// letras minúsculas ou maiúsculas, ou que estão adjacentes a pontuação, não serão
// diferenciadas.


#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>

#include "ordered_map/src/map.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

string CleanString(string s) {
  string result;
  for ( int i=0;i<(int)s.length();i++ ) {
    if ( isalnum(s[i]) ) {
      result.push_back(tolower(s[i]));
    }
  }
  return result;
}
int main() {
  map words;

  ifstream fin("input.txt");

  Node *word;
  string str;
  while (fin >> str) {
    str = CleanString(str);
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
