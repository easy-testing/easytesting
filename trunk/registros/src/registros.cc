#include "easytesting/registros/src/registros.h"

#include <math.h>

float Ponto::distancia(Ponto& p) {
  return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

void Ponto::atribuir(float a, float b) {
  x = a;
  y = b;
}

float Triangulo::perimetro() {
  return p1.distancia(p2) +
         p2.distancia(p3) +
         p3.distancia(p1);
}

// Calcula a area em funcao do semi-perimetro s.
// Area = sqrt(s * (s - a) * (s - b) * (s - c)).
float Triangulo::area() {
  float a = p1.distancia(p2);
  float b = p2.distancia(p3);
  float c = p3.distancia(p1);
  float s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool Triangulo::equilatero() {
  return p1.distancia(p2) == p2.distancia(p3) &&
         p2.distancia(p3) == p3.distancia(p1);
}

float Maior(float a, float b){
  return a > b ? a : b;
}

float Menor(float a, float b){
  return a < b ? a : b;
}

// Dois triangulos sao semelhantes s.s.s. a razao entre o maior e o menor
// lado de cada triangulo eh igual.
bool Triangulo::semelhante(Triangulo& t) {
    // 'a', 'b', e 'c' armazenam o comprimento os lados do triangulo corrente.
    float a = p1.distancia(p2);
    float b = p2.distancia(p3);
    float c = p3.distancia(p1);

    // 'ta', 'tb', e 'tc' armazenam o comprimento dos lados do triangulo 't'.
    float ta = t.p1.distancia(t.p2);
    float tb = t.p2.distancia(t.p3);
    float tc = t.p3.distancia(t.p1);

    // Seleciona o maior lado de cada triangulo.
    float maiorLado = Maior(Maior(a, b),  c);
    float MaiorLadoDeT = Maior(Maior(ta, tb), tc);

    // Seleciona o menor lado de cada triangulo.
    float menorLado = Menor(Menor(a, b),  c);
    float MenorLadoDeT = Menor(Menor(ta, tb), tc);

    return maiorLado/MaiorLadoDeT == menorLado/MenorLadoDeT;
}

float Retangulo::perimetro() {
  float d1 = se.y - id.y;
  float d2 = id.x - se.x;
  return 2 * d1 +
         2 * d2;
}

float Retangulo::area() {
  float d1 = se.y - id.y;
  float d2 = id.x - se.x;
  return d1 * d2;
}

bool Retangulo::quadrado() {
  float d1 = se.y - id.y;
  float d2 = id.x - se.x;
  return d1 == d2;
}

bool Retangulo::contem(Ponto& p) {
  return p.x >= se.x &&
         p.y <= se.y &&
         p.y >= id.y &&
         p.x <= id.x;
}

bool Retangulo::contem(Triangulo& t) {
  return contem(t.p1) && contem(t.p2) && contem(t.p3);
}



float Circunferencia::perimetro() {
  return 2 * raio * kPi;
}

float Circunferencia::area() {
  return raio * raio * kPi;
}

bool Circunferencia::contem(Ponto& p) {
  return p.distancia(centro) <= raio;
}

bool Circunferencia::contem(Triangulo& t) {
  return contem(t.p1) && contem(t.p2) && contem(t.p3);
}

bool Circunferencia::contem(Retangulo& r) {
  return contem(r.se) && contem(r.id);
}

bool Circunferencia::pertence(Ponto& p) {
  return p.distancia(centro) == raio;
}

bool Circunferencia::circunscrita(Triangulo& t) {
  return pertence(t.p1) && pertence(t.p2) && pertence(t.p3);
}

bool Circunferencia::circunscrita(Retangulo& r) {
  return pertence(r.se) && pertence(r.id);
}
