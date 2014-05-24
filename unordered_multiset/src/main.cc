// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre multiconjuntos associativos
//
// Questão 1.
// Implemente em unordered_multiset.h e unordered_multiset.cc o TAD
// unordered_multiset, utilizando tabela de dispersão.
//
// Questão 2.
// Leia um arquivo contendo apenas palavras, e imprima as palavras em ordem
// crescente de lexicografia, seguidas do número de ocorrências da palavra no
// texto.
//
// Você pode assumir que os arquivos contém apenas caracteres que são letras
// (a-z e A-Z), números (0-9), e caracteres de pontuação (",", ".", "?", etc.).
// Você pode assumir que o texto não tem acentos nem "ç".
// Após ler cada palavra, você deve (i) transformar todas as letras maiúsculas
// em minúsculas e (ii) apagar todos os caracteres que não são letras ou
// números. Por exemplo, depois de ler "Guarda-Chuva?", você deve transformá-la
// em "guardachuva" antes de inseri-la no multiconjunto. Desta forma, a mesma
// palavra apresentada com letras minúsculas ou maiúsculas, ou que estão
// adjacentes a pontuação, não serão diferenciadas. Por exemplo, para o texto:
//
// -------------------------
// La vem o pato.
// Pata aqui, pata acola.
// La vem o pato,
// Para ver o que e que ha.
// -------------------------
//
// O seu programa deve imprimir:
//
// -------------------------
// acola 1
// aqui 1
// e 1
// ha 1
// la 2
// o 3
// para 1
// pata 2
// pato 2
// que 2
// vem 2
// ver 1
// -------------------------


#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "unordered_multiset/src/unordered_multiset.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

string CleanString(string s) {
  string result;
  for (int i = 0; i < s.length(); i++) {
    if (isalnum(s[i])) {
      result.push_back(tolower(s[i]));
    }
  }
  return result;
}

int main() {
  return 0;  // TODO.
}
