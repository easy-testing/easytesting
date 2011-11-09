// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Pilhas.
//
// Questão 1.
// Implemente em stack.h e stack.cc o TAD stack, utilizando listas ligadas.
//
// Questão 2.
// Escreva uma função "void ImprimirInfixado(stack* exp)" que recebe
// como parâmetro uma pilha 'exp' que representa uma expressão em notação
// pré-fixada e remove os operadores e operandos de 'exp', imprimindo-os em
// notação infixada totalmente parametrizada.
// Por exemplo: para para a pilha contendo a expressão "- / + 4 * 3 4 2 1",
// O programa deve imprimir "( ( ( 4 + ( 3 * 4 ) ) / 2 ) - 1 )".
//
// Questão 3.
// Escreva um programa que (i) lê de um arquivo uma expressão em notação
// pré-fixada, (ii) imprime na tela a mesma expressão em notação infixada
// totalmente parametrizada.
// Por exemplo: para o arquivo contendo a expressão "- / + 4 * 3 4 2 1",
// O programa deve imprimir "( ( ( 4 + ( 3 * 4 ) ) / 2 ) - 1 )".

// Questão 4 (DESAFIO!).
// Escreva um programa que (i) lê de um arquivo uma expressão em notação
// pré-fixada, (ii) imprime na tela somente o resultado da expressão.
// Por exemplo: para o arquivo contendo a expressão "- / + 4 * 3 4 2 1",
// O programa deve imprimir "7".
// DICA: Crie uma função "double ResolverExpressao(stack* exp)" que recebe como
// parâmetro uma pilha 'exp' que representa uma expressão em notação
// pré-fixada e (a) retira a expressão (operador e operandos) que está no topo
// da pilha e em seguida (b) retorna o resultado desta expressão.


#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "stack/src/stack.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

// Questão 2.
////////////////////////////////////////////////////////////////////////////////

// Retorna true se a string s é um operador e false se s é um número.
bool EhUmOperador(string s) {
  return s == "+" || s == "-" || s == "*" || s == "/";
}

// Remove os elementos da expressão 'exp' e imprime-os em
// notação infixada totalmente parametrizada.
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
////////////////////////////////////////////////////////////////////////////////

// Lê de um arquivo uma expressão em notação pré-fixada, imprime na tela a
// mesma expressão em notação infixada totalmente parametrizada.
int main_questao3() {
  // Lê uma expressão em notação pré-fixada de um arquivo.
  ifstream fin("input.txt");
  stack aux;
  string x;
  while (fin >> x) {
    aux.push(x);
  }

  // Inverte a ordem dos elementos da pilha.
  stack expressao;
  while (!aux.empty()) {
    expressao.push(aux.top());
    aux.pop();
  }

  // Imprime a expressão em notação infixada.
  ImprimirInfixado(&expressao);
  return 0;
}

// Questão 4.
////////////////////////////////////////////////////////////////////////////////

// Realiza a operação binária definida pela string 'operador' utiliando como
// operandos os números reais 'operando1' e 'operando2'.
double RealizarOperacao(string operador, double operando1, double operando2) {
  if (operador == "+") {
    return operando1 + operando2;
  } else if (operador == "-") {
    return operando1 - operando2;
  } else if (operador == "*") {
    return operando1 * operando2;
  } else {  // operacao == "/".
    return operando1 / operando2;
  }
}

// Recebe como parâmetro uma pilha 'exp' que representa uma expressão em notação
// pré-fixada e (i) retira a expressão (operador e operandos) que está no topo
// da pilha e em seguida (ii) retorna o resultado desta expressão.

double ResolverExpressao(stack* exp) {
  string topo = exp->top();
  exp->pop();
  if (!EhUmOperador(topo)) {
    return atoi(topo.c_str());
  } else {
    double operando1 = ResolverExpressao(exp);
    double operando2 = ResolverExpressao(exp);
    return RealizarOperacao(topo, operando1, operando2);
  }
}

int main_questao4() {
  // Lê uma expressão em notação pré-fixada de um arquivo.
  ifstream fin("input.txt");
  stack aux;
  string x;
  while (fin >> x) {
    aux.push(x);
  }

  // Inverte a ordem dos elementos da pilha.
  stack expressao;
  while (!aux.empty()) {
    expressao.push(aux.top());
    aux.pop();
  }

  // Imprime o resultado da expressao.
  cout << ResolverExpressao(&expressao) << endl;
  return 0;
}

int main() {
  return main_questao3();
}
