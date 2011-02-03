#ifndef ITERACAO_H_
#define ITERACAO_H_

// Retorna o valor do fatorial de n.
int fat(int n);

// Retorna o m�ximo divisor comum entre a e b.
int mdc (int x, int y);

// Retorna o menor m�ltiplo comum de a e b.
int mmc(int a, int b);

// Retorna o n-�simo termo da s�rie de Fibonacci
int fib(int n);

// Retorna verdadeiro se n eh primo e false caso contrario.
bool primo(int n);

// Retorna o resto da divis�o interia de a por b.
int resto(int a, int b);

// Retorna o quociente da divis�o interia de a por b.
int div_(int a, int b);

// Retorna a raiz quadrada de n >= 1 (com precis�o de 0.001).
float sqrt_(float n);

// Retorna a soma dos digitos de um inteiro positivo n. Exemplo: dig(123) = 6.
int dig(int n);

// Escreve em ordem decrescente, todos os inteiros maiores que 0 e menores ou iguais a x.
void decrescente(int x);

// Escreve em ordem crescente, todos os inteiros maiores que 0 e menores ou iguais a x.
void crescente(int x);

#endif // ITERACAO_H_
