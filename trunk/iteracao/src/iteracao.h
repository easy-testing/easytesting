#ifndef ITERACAO_H_
#define ITERACAO_H_

// Retorna o valor do fatorial de n.
int fat(int n);

// Retorna o máximo divisor comum entre a e b.
int mdc (int x, int y);

// Retorna o menor múltiplo comum de a e b.
int mmc(int a, int b);

// Retorna o n-ésimo termo da série de Fibonacci
int fib(int n);

// Retorna verdadeiro se n eh primo e false caso contrario.
bool primo(int n);

// Retorna o resto da divisão interia de a por b.
int resto(int a, int b);

// Retorna o quociente da divisão interia de a por b.
int div_(int a, int b);

// Retorna a raiz quadrada de n >= 1 (com precisão de 0.001).
float sqrt_(float n);

// Retorna a soma dos digitos de um inteiro positivo n. Exemplo: dig(123) = 6.
int dig(int n);

// Escreve em ordem decrescente, todos os inteiros maiores que 0 e menores ou iguais a x.
void decrescente(int x);

// Escreve em ordem crescente, todos os inteiros maiores que 0 e menores ou iguais a x.
void crescente(int x);

#endif // ITERACAO_H_
