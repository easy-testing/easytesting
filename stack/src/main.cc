// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre listas encadeadas - pilha.
//
// Questão 1.
// Implemente em stack.h e stack.cc o TAD stack, utilizando listas encadeadas.
//
// Questão 2.
// Escreva uma função "void ImprimirInfixado(stack* exp)" que recebe
// como parâmetro uma pilha 'exp' que representa uma expressão em notação
// pré-fixada e remove os operadores e operandos de 'exp', imprimindo-os em
// notação infixada totalmente parametrizada.
// Por exemplo: para para a pilha contendo a expressão "- / + 4 * 3 4 2 1",
// A função deve imprimir "( ( ( 4 + ( 3 * 4 ) ) / 2 ) - 1 )".
//
// Questão 3.
// Escreva um programa que (i) lê de um arquivo uma expressão em notação
// pré-fixada, (ii) imprime na tela a mesma expressão em notação infixada
// totalmente parametrizada.
// Por exemplo: para o arquivo contendo a expressão "- / + 4 * 3 4 2 1",
// O programa deve imprimir "( ( ( 4 + ( 3 * 4 ) ) / 2 ) - 1 )".

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "stack/src/stack.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

// Retorna true se a string s é um operador e false se s é um número.
bool EhUmOperador(string s) {
  return s == "+" || s == "-" || s == "*" || s == "/";
}

// Questão 2.
void ImprimirInfixado(stack* exp) {
  string top = exp->top();
  exp->pop();
  if (EhUmOperador(top)) {
    cout << "( ";
    ImprimirInfixado(exp);
    cout << top << " ";
    ImprimirInfixado(exp);
    cout << ") ";
  } else {
    cout << top << " ";
  }
}

// Questão 3.
int main() {
  // Lê uma expressão em notação pré-fixada de um arquivo.
  // A ordem dos elementos do arquivo vai estar invertida na pilha 'aux'.
  ifstream fin("input.txt");
  stack aux;
  string x;
  while (fin >> x) {
    aux.push(x);
  }

  // Inverte a ordem dos elementos da pilha 'aux'.
  stack expressao;
  while (!aux.empty()) {
    expressao.push(aux.top());
    aux.pop();
  }

  // Imprime a expressão em notação infixada.
  ImprimirInfixado(&expressao);
  cout << endl;
  return 0;
}
