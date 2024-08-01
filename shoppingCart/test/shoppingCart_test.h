// copyright 2023 Universidade Federal de Minas Gerais (UFMG)

#include <iostream>
#include <string>
#include <vector>
#include "./src/shoppingCart.h"
#include "../doctest/doctest.h"

using std::string;
using std::vector;
using namespace std;

TEST_CASE("Testa a função limpaCarrinho") {

  adicionarProduto("Arroz", 5.0, 10);
  adicionarProduto("Feijão", 4.0, 5);
  adicionarProduto("Macarrão", 2.5, 2);

  CHECK_EQ(getNumeroItens(), 3);

  limpaCarrinho();

  CHECK_EQ(getNumeroItens(), 0);
  if (getNumeroItens() != 0 ){

    INFO("---------------------------------------------------");
    INFO("Erro na função: limpaCarrinho");
    INFO("---------------------------------------------------");
    INFO("Resultado esperado : 0");
    INFO("Resultado retornado : " << getNumeroItens());
    INFO("---------------------------------------------------");
  }
}

TEST_CASE("Testa a função adicionarProduto") {

  std::vector<Produto> produtos;

  adicionarProduto("Arroz", 5.0, 10);

  CHECK_EQ(getNumeroItens(), 1);

  CHECK_EQ(produtos[0].nome, "Arroz");
  CHECK_EQ(produtos[0].preco, 5.0);
  CHECK_EQ(produtos[0].quantidade, 10);
}

TEST_CASE("Testa a função retirarProduto") {

  adicionarProduto("Arroz", 5.0, 10);

  retirarProduto("Arroz");

  CHECK_EQ(getNumeroItens(), 0);
}

TEST_CASE("Testa a função getValorTotal") {

  adicionarProduto("Arroz", 5.0, 10);
  adicionarProduto("Feijão", 4.0, 5);
  adicionarProduto("Macarrão", 2.5, 2);

  CHECK_EQ(getValorTotal(), 37.5);
}

TEST_CASE("Testa a função getNumeroItens") {

  CHECK_EQ(getNumeroItens(), 0);

  adicionarProduto("Arroz", 5.0, 10);

  CHECK_EQ(getNumeroItens(), 1);

  adicionarProduto("Feijão", 4.0, 5);
  adicionarProduto("Macarrão", 2.5, 2);

  CHECK_EQ(getNumeroItens(), 3);

  retirarProduto("Arroz");

  CHECK_EQ(getNumeroItens(), 2);

  limpaCarrinho();

  CHECK_EQ(getNumeroItens(), 0);
}