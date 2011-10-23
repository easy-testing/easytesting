// Copyright 2011 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Pilhas.
//
// Questão 1.
// Implemente o TAD stack<Type> em stack.h.
//
// Questão 2.
// Escreva uma função "void ResolverExpressaoDoTopo(stack<string>* exp)" que
// recebe como parâmetro uma pilha exp que representa uma expressão em notação
// pré-fixada e substitui a expressão que está no topo da pilha pelo seu
// respectivo valor.
//
// Questão 3.
// Escreva uma função "void ImprimirInfixado(stack<string> exp)" que recebe
// como parâmetro uma pilha exp que representa uma expressão em notação
// pré-fixada e retira os operadores e operandos de exp, imprimindo-os em
// notação infixada totalmente parametrizada.
//
// Questão 4.
// Escreva um programa que (i) lê de um arquivo uma expressão em notação
// pré-fixada, (ii) imprime na tela a mesma expressão em notação infixada
// e em seguida (iii) imprime o resultado da expressão.
// Por exemplo: para o arquivo contendo a expressão "- / + 4 * 3 4 2 1",
// O programa deve imprimir "( ( ( 4 + ( 3 * 4 ) ) / 2 ) - 1 ) = 7".

#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "stack/src/stack.h"

using namespace std;

// Converte uma string em um número real.
double String2Double(string s) {
  istringstream sin(s);
  double num;
  sin >> num;
  return num;
}

// Converte um número real em uma string .
string Double2String(double num) {
  ostringstream sout;
  sout << num;
  return sout.str();
}

// Retorna true se a string s é um operador e false se s é um número.
bool EhUmOperador(string s) {
  return s == "+" || s == "-" || s == "*" || s == "/";
}

// Realiza a operação definida pela string operador utiliando como operandos
// os números reais operando1 e operando2.
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

// Recebe como parâmetro uma pilha exp que representa uma expressão em notação
// pré-fixada e substitui a expressão que está no topo da pilha pelo seu
// respectivo valor.
void ResolverExpressaoDoTopo(stack<string>* exp) {
  string topo = exp->top();
  if (EhUmOperador(topo)) {
    exp->pop();

    ResolverExpressaoDoTopo(exp);
    double operando1 = String2Double(exp->top());
    exp->pop();

    ResolverExpressaoDoTopo(exp);
    double operando2 = String2Double(exp->top());
    exp->pop();

    double resultado = RealizarOperacao(topo, operando1, operando2);
    exp->push(Double2String(resultado));
  }
}

// Recebe como parâmetro uma pilha exp que representa uma expressão em notação
// pré-fixada e retira os operadores e operandos de exp, imprimindo-os em
// notação infixada totalmente parametrizada.
void ImprimirInfixado(stack<string>* exp) {
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

// Lê de um arquivo uma expressão em notação pré-fixada, imprime na tela a
// mesma expressão em notação infixada e em seguida imprime o resultado
// da expressão.
int main() {
  // Lê uma expressão em notação pré-fixada de um arquivo.
  ifstream fin("input.txt");
  stack<string> aux;
  string x;
  while (fin >> x) {
    aux.push(x);
  }

  // Inverte a ordem dos elementos da pilha.
  stack<string> expressao;
  while (!aux.empty()) {
    expressao.push(aux.top());
    aux.pop();
  }

  // Imprime a expressão em notação infixada seguida do resultado da expressão.
  aux = expressao;
  ImprimirInfixado(&aux);
  ResolverExpressaoDoTopo(&expressao);
  cout << "= " << expressao.top() << endl;
  return 0;
}
