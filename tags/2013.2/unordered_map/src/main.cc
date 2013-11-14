// Copyright 2013 Universidade Federal de Minas Gerais (UFMG)
//
// Lista sobre conjuntos associativos
//
// Questão 1.
// Implemente em unordered_map.h e unordered_map.cc o TAD unordered_map,
// utilizando tabela hash.
//
// Questão 2.
// Leia um arquivo contendo apenas palavras, e imprima as palavras,
// seguidas do número de ocorrências da palavra no texto.
//
// Você pode assumir que os arquivos contém apenas caracteres que são letras
// (a-z e A-Z), números (0-9), e caracteres de pontuação (",", ".", "?", etc.).
// Você pode assumir que o texto não tem acentos nem "ç".
// Após ler cada palavra, você deve (i) transformar todas as letras maiúsculas em
// minúsculas e (ii) apagar todos os caracteres que não são letras ou números. Por
// exemplo, depois de ler "Guarda-Chuva?", você deve transformá-la em "guardachuva",
// antes de inseri-la no conjunto. Desta forma, a mesma palavra apresentada com
// letras minúsculas ou maiúsculas, ou que estão adjacentes a pontuação, não serão
// diferenciadas. Por exemplo, para o texto:
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

#include "unordered_map/src/unordered_map.h"

int main() {
  return 0;  //TODO.
}
