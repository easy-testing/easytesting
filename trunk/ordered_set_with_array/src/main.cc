// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre Conjuntos.
//
// Questão 1.
// Implemente em set.h e set.cc o TAD set, utilizando arrays.
//
// Questão 2.
// Escreva um programa para testar o conjunto que você implementou nas questões
// anteriores. Note que SType está definido como string no projeto do
// Code::Blocks.

#include <iostream>
#include <string>

#include "src/set.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Questão 2.
int main() {
  set s;
  s.insert("1");
  s.insert("2");
  s.insert("3");
  s.erase("2");
  cout << s.size() << endl;
  cout << s.belongs("1") << endl;
  cout << s.belongs("2") << endl;
  cout << s.belongs("3") << endl;
  return 0;
}
