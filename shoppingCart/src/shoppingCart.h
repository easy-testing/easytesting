// copyright 2023 Universidade Federal de Minas Gerais (UFMG)
#include <string>
#include <vector>

using std::string;
using std::vector;    

struct Produto {
  std::string nome;
  float preco;
  int quantidade;
};

void limpaCarrinho();

void adicionarProduto(string nome, float preco, int quantidade);

void retirarProduto(string nome);

float getValorTotal();

int getNumeroItens();

void listarItens();
