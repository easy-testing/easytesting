// Copyright 2014 Universidade Federal de Minas Gerais (UFMG)

#include <../doctest/doctest.h>
#include "./src/agenda.h"

const int MAX = 50;

TEST_CASE("Testa_LerNomeDoTeclado") {
  // Print dos resultados do teste
  INFO("-------------------------------------------------------------------");
  INFO("Teste: Testa_LerNomeDoTeclado");
  INFO("-------------------------------------------------------------------");
  INFO("Valores de entrada: ");
  INFO("   esperado: João da Silva");
  INFO("   obtido: " << LerNomeDoTeclado());
  INFO("-------------------------------------------------------------------");

  string esperado = "João da Silva";
  string obtido = LerNomeDoTeclado();
  CHECK_EQ(obtido, esperado);
}

TEST_CASE("Testa_LerAniversarioDoTeclado") {
  // Print dos resultados do teste
  INFO("-------------------------------------------------------------------");
  INFO("Teste: Testa_LerAniversarioDoTeclado");
  INFO("-------------------------------------------------------------------");
  INFO("Valores de entrada: ");
  INFO("   esperado: 20/07/1990");
  INFO("   obtido: " << LerAniversarioDoTeclado());
  INFO("-------------------------------------------------------------------");

  string esperado = "20/07/1990";
  string obtido = LerAniversarioDoTeclado();
  CHECK_EQ(obtido, esperado);
}

TEST_CASE("Testa_LerTelefoneDoTeclado") {
  // Print dos resultados do teste
  INFO("-------------------------------------------------------------------");
  INFO("Teste: Testa_LerTelefoneDoTeclado");
  INFO("-------------------------------------------------------------------");
  INFO("Valores de entrada: ");
  INFO("   esperado: (31) 99999-9999");
  INFO("   obtido: " << LerTelefoneDoTeclado());
  INFO("-------------------------------------------------------------------");

  string esperado = "(31) 99999-9999";
  string obtido = LerTelefoneDoTeclado();
  CHECK_EQ(obtido, esperado);
}

TEST_CASE("Testa_LerContatoDoTeclado") {
  // Print dos resultados do teste
  INFO("-------------------------------------------------------------------");
  INFO("Teste: Testa_LerContatoDoTeclado");
  INFO("-------------------------------------------------------------------");
  INFO("Valores de entrada: ");
  INFO("   esperado:");
  INFO("        nome: João da Silva");
  INFO("        telefone: (31) 99999-9999");
  INFO("        aniversario: 20/07/1990");
  INFO("   obtido:");
  INFO("        nome: " << LerContatoDoTeclado().nome);
  INFO("        telefone: " << LerContatoDoTeclado().telefone);
  INFO("        aniversario: " << LerContatoDoTeclado().aniversario);
  INFO("-------------------------------------------------------------------");

  Contato contatoEsperado;
  contatoEsperado.nome = "João da Silva";
  contatoEsperado.telefone = "(31) 99999-9999";
  contatoEsperado.aniversario = "20/07/1990";

  Contato contatoObtido = LerContatoDoTeclado();
  CHECK_EQ(contatoEsperado, contatoObtido);
}

TEST_CASE("Testa_ConsultarContatoPorNome") {
  // Print dos resultados do teste

  Contato contato;
  contato.nome = "João da Silva";
  contato.telefone = "(31) 99999-9999";
  contato.aniversario = "20/07/1990";
  INFO("-------------------------------------------------------------------");
  INFO("Teste: Testa_ConsultarContatoPorNome");
  INFO("-------------------------------------------------------------------");
  INFO("Valores de entrada: ");
  INFO("   esperado:");
  INFO("        nome: João da Silva");
  INFO("        telefone: (31) 99999-9999");
  INFO("        aniversario: 20/07/1990");
  INFO("   obtido:");
  INFO("        nome: " << ConsultarContatoPorNome("João da Silva", 1, &contato).nome);

}

TEST_CASE("Testa_InserirContatoNaAgenda") {
  // Print dos resultados do teste
  Contato contato;
  contato.nome = "João da Silva";
  contato.telefone = "(31) 99999-9999";
  contato.aniversario = "20/07/1990";

  int n = 0;
  Contato agenda[MAX];

  InserirContatoNaAgenda(contato, &n, agenda);

  INFO("-------------------------------------------------------------------");
  INFO("Teste: Testa_InserirContatoNaAgenda");
  INFO("-------------------------------------------------------------------");
  INFO("Valores de entrada: ");
  INFO("   esperado:");
  INFO("        nome: João da Silva");
  INFO("        telefone: (31) 99999-9999");
  INFO("        aniversario: 20/07/1990");
  INFO("   obtido:");
  INFO("        nome: " << agenda[n - 1].nome);
  INFO("        telefone: " << agenda[n - 1].telefone);
  INFO("        aniversario: " << agenda[n - 1].aniversario);
  INFO("-------------------------------------------------------------------");

  

  Contato contatoEsperado = contato;
  Contato contatoObtido = agenda[n - 1];
  CHECK_EQ(contatoEsperado, contatoObtido);
}

TEST_CASE("Testa_ApagarContato") {
  // Print dos resultados do teste
  Contato contato;
  contato.nome = "João da Silva";
  contato.telefone = "(31) 99999-9999";
  contato.aniversario = "20/07/1990";

  int n = 1;
  Contato agenda[MAX];
  agenda[0] = contato;

  ApagarContato("João da Silva", &n, agenda);

  INFO("-------------------------------------------------------------------");
  INFO("Teste: Testa_ApagarContato");
  INFO("-------------------------------------------------------------------");
  INFO("Valores de entrada: ");
  INFO("   esperado:");
  INFO("        nome: João da Silva");
  INFO("        telefone: (31) 99999-9999");
  INFO("        aniversario: 20/07/1990");
  INFO("   obtido:");
  INFO("        nome: " << agenda[0].nome);
  INFO("        telefone: " << agenda[0].telefone);
  INFO("        aniversario: " << agenda[0].aniversario);
  INFO("-------------------------------------------------------------------");

  

  Contato contatoEsperado;
  contatoEsperado.nome = "";
  Contato contatoObtido = agenda[0];
  CHECK_EQ(contatoEsperado, contatoObtido);
}
