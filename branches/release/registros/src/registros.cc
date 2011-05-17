// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "registros/src/registros.h"

#include <math.h>

float Ponto::distancia(Ponto& p) {
  return 0;  // TODO.
}

void Ponto::atribuir(float a, float b) {
  // TODO.
}

float Triangulo::perimetro() {
  return 0;  // TODO.
}

// Calcula a área em função do semi-perímetro s.
// Área = sqrt(s * (s - a) * (s - b) * (s - c)).
float Triangulo::area() {
  return 0;  // TODO.
}

bool Triangulo::equilatero() {
  return false;  // TODO.
}

float Maior(float a, float b) {
  return a > b ? a : b;
}

float Menor(float a, float b) {
  return a < b ? a : b;
}

// Dois triângulos são semelhantes s.s.s. a razão entre o maior e o menor
// lado de cada triângulo é igual.
bool Triangulo::semelhante(Triangulo& t) {
  return false;  // TODO.
}

float Retangulo::perimetro() {
  return 0;  // TODO.
}

float Retangulo::area() {
  return 0;  // TODO.
}

bool Retangulo::quadrado() {
  return false;  // TODO.
}

bool Retangulo::contem(Ponto& p) {
  return false;  // TODO.
}

bool Retangulo::contem(Triangulo& t) {
  return false;  // TODO.
}



float Circunferencia::perimetro() {
  return 0;  // TODO.
}

float Circunferencia::area() {
  return 0;  // TODO.
}

bool Circunferencia::contem(Ponto& p) {
  return false;  // TODO.
}

bool Circunferencia::contem(Triangulo& t) {
  return false;  // TODO.
}

bool Circunferencia::contem(Retangulo& r) {
  return false;  // TODO.
}

bool Circunferencia::pertence(Ponto& p) {
  return false;  // TODO.
}

bool Circunferencia::circunscrita(Triangulo& t) {
  return false;  // TODO.
}

bool Circunferencia::circunscrita(Retangulo& r) {
  return pertence(r.se) && pertence(r.id);
}
