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
  CarrinhoCompras carrinho;

  carrinho.adicionarProduto("Arroz", 5.0, 10);
  carrinho.adicionarProduto("Feijão", 4.0, 5);
  carrinho.adicionarProduto("Macarrão", 2.5, 2);

  EXPECT_EQ(carrinho.getNumeroItens(), 3);

  carrinho.limpaCarrinho();

  CHECK_EQ(carrinho.getNumeroItens(), 0);
  if (carrinho.getNumeroItens() != 0 ){

    INFO("---------------------------------------------------");
    INFO("Erro na função: limpaCarrinho");
    INFO("---------------------------------------------------");
    INFO("Resultado esperado : 0";
    INFO("Resultado retornado : " << carrinho.getNumeroItens();
    INFO("---------------------------------------------------");
  }
}

TEST_CASE("Testa a função adicionarProduto") {
  CarrinhoCompras carrinho;

  carrinho.adicionarProduto("Arroz", 5.0, 10);

  EXPECT_EQ(carrinho.getNumeroItens(), 1);

  EXPECT_EQ(carrinho.produtos[0].nome, "Arroz");
  EXPECT_EQ(carrinho.produtos[0].preco, 5.0);
  EXPECT_EQ(carrinho.produtos[0].quantidade, 10);
}

TEST_CASE("Testa a função retirarProduto") {
  CarrinhoCompras carrinho;

  carrinho.adicionarProduto("Arroz", 5.0, 10);

  carrinho.retirarProduto("Arroz");

  EXPECT_EQ(carrinho.getNumeroItens(), 0);
}

TEST_CASE("Testa a função getValorTotal") {
  CarrinhoCompras carrinho;

  carrinho.adicionarProduto("Arroz", 5.0, 10);
  carrinho.adicionarProduto("Feijão", 4.0, 5);
  carrinho.adicionarProduto("Macarrão", 2.5, 2);

  EXPECT_EQ(carrinho.getValorTotal(), 37.5);
}

TEST_CASE("Testa a função getNumeroItens") {
  CarrinhoCompras carrinho;

  EXPECT_EQ(carrinho.getNumeroItens(), 0);

  carrinho.adicionarProduto("Arroz", 5.0, 10);

  EXPECT_EQ(carrinho.getNumeroItens(), 1);

  carrinho.adicionarProduto("Feijão", 4.0, 5);
  carrinho.adicionarProduto("Macarrão", 2.5, 2);

  EXPECT_EQ(carrinho.getNumeroItens(), 3);

  carrinho.retirarProduto("Arroz");

  EXPECT_EQ(carrinho.getNumeroItens(), 2);

  carrinho.limpaCarrinho();

  EXPECT_EQ(carrinho.getNumeroItens(), 0);
}