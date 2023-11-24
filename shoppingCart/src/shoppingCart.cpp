// copyright 2023 Universidade Federal de Minas Gerais (UFMG)
#include <iostream>
#include <string>
#include <vector>
#include "./src/shoppingCart.h"

using std::string;
using std::vector;    
using namespace std;



std::vector<Produto> produtos;

void limpaCarrinho() {
  produtos.clear();
}

void adicionarProduto(string nome, float preco, int quantidade) {
  produtos.push_back({nome, preco, quantidade});
}

void retirarProduto(string nome) {
  for (int i = 0; i < produtos.size(); i++) {
    if (produtos[i].nome == nome) {
      if (produtos[i].quantidade > 1) {
        produtos[i].quantidade--;
      } else {
        produtos.erase(produtos.begin() + i);
      }
      return;
    }
  }
}

float getValorTotal() {
  float valorTotal = 0.0f;
  for (int i = 0; i < produtos.size(); i++) {
    valorTotal += produtos[i].preco * produtos[i].quantidade;
  }
  return valorTotal;
}

int getNumeroItens() {
  return produtos.size();
}

void listarItens() {
  cout << "Itens no carrinho:" << endl;
  for (int i = 0; i < produtos.size(); i++) {
    cout << "  " << produtos[i].nome << ", Quantidade: " << produtos[i].quantidade << endl;
  }
}