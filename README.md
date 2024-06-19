# EasyTesting

## Visão Geral

EasyTesting é um projeto composto por listas de exercícios de diversas linguagens de programação, corrigidas automaticamente por testes de unidade. O projeto foi idealizado pelo professor Natã Goulart da Silva durante sua pós-graduação, sob a orientação do professor Thiago Ferreira de Noronha, e desenvolvido pelo aluno Rafael Oliveira Prado Nascimento durante sua graduação.

## Objetivos do Projeto

### Ensino de Programação

O ensino de linguagens de programação exige a resolução de muitos exercícios para desenvolver o raciocínio lógico sequencial necessário para solucionar problemas computacionais. A correção manual desses exercícios consome muito tempo dos professores e monitores, especialmente com o aumento do número de alunos. EasyTesting foi criado para:

- **Economia de Recursos:** Automatizar a correção, reduzindo custos e a carga de trabalho dos professores e monitores, permitindo que se concentrem em dúvidas mais complexas.
- **Melhorias no Aprendizado:** Fornecer feedback imediato aos alunos, acelerando o aprendizado e ajudando no desenvolvimento das habilidades de programação.
- **Padronização e Boas Práticas:** Introduzir boas práticas de programação desde o início da formação dos alunos, preparando-os melhor para o mercado de trabalho.

## Metodologia Empregada

As listas de exercícios são baseadas nos conteúdos das disciplinas e incluem:

- **Interfaces dos Métodos:** Arquivos com a definição das interfaces dos métodos necessários para resolver os exercícios.
- **Framework de Testes Doctest:** Biblioteca do framework de testes Doctest (2014).
- **Testes Codificados:** Diversos testes para cada questão da lista.

## Listas de Exercícios Disponíveis

1. **Estruturas de Dados Heterogêneas - Registros**
2. **Complexo Euclidiano**
3. **Complexo Polar**
4. **Condicionais**
5. **Listas Encadeadas - Deque**
6. **Funções**
7. **Iteração**
8. **Listas Encadeadas**
9. **Matrizes**
10. **Conjuntos Associativos - Árvore Binária de Busca**
11. **Multiconjuntos Associativos - Árvore Binária de Busca**
12. **Conjuntos - Árvores Binárias de Busca**
13. **Conjuntos - Listas Encadeadas**
14. **Filas de Prioridade**
15. **Listas Encadeadas - Array**
16. **Listas Encadeadas - Fila de Banco**
17. **Recursividade**
18. **Alocação Dinâmica - Pilha**
19. **Alocação Dinâmica - Listas Encadeadas**
20. **Conjunto Associativo - Hash**
21. **Multiconjuntos Associativos - Tabela de Dispersão**
22. **Conjuntos - Hash**
23. **Alocação Dinâmica - Vetores Dinâmicos**
24. **Vetores**

## Conteúdo Abordado em Cada Lista

### Estruturas de Dados Heterogêneas - Registros
Gerenciamento de uma agenda persistente utilizando C++, com dados armazenados em 'agenda.txt'.

### Complexo Euclidiano
Leitura de coeficientes de uma equação de segundo grau e impressão das raízes (possivelmente complexas).

### Complexo Polar
Operações matemáticas com números complexos polares.

### Condicionais
Implementação de um menu com funções definidas em arquivos .cpp e .h, leitura de parâmetros e exibição de resultados.

### Listas Encadeadas - Deque
Gerenciamento de uma fila de eventos com duas prioridades, seguindo protocolos LIFO e FIFO.

### Funções
Implementação de um menu para funções definidas em arquivos .cc e .h, leitura de parâmetros e exibição de resultados.

### Iteração
Implementação de um menu para funções definidas, leitura de parâmetros e exibição de resultados.

### Matrizes
Leitura de uma matriz triangular inferior e um vetor de um arquivo, resolução e exibição de um sistema de equações.

### Conjuntos Associativos - Árvore Binária de Busca
Leitura de um arquivo de palavras e impressão das palavras em ordem crescente com contagem de ocorrências.

### Multiconjuntos Associativos - Árvore Binária de Busca
Similar ao anterior, mas lidando com multiconjuntos.

### Conjuntos - Árvores Binárias de Busca e Listas Encadeadas
Gerenciamento de fornecedores de peças para uma montadora de carros.

### Filas de Prioridade
Ordenação de elementos de um vetor utilizando uma fila prioritária baseada em árvore binária de busca.

### Listas Encadeadas - Array e Fila de Banco
Gerenciamento de filas de clientes em um banco com prioridade para clientes idosos.

### Recursividade
Implementação de funções recursivas com um menu de opções.

### Alocação Dinâmica - Pilha e Listas Encadeadas
Leitura de expressões em notação prefixada e impressão em notação infixada.

### Conjuntos Associativos - Hash
Leitura de um arquivo de palavras e impressão das palavras em ordem crescente utilizando tabela hash.

### Multiconjuntos Associativos - Tabela de Dispersão
Similar ao anterior, mas utilizando tabela de dispersão.

### Conjuntos - Hash
Gerenciamento de fornecedores de peças para uma montadora de carros utilizando tabela hash.

### Alocação Dinâmica - Vetores Dinâmicos
Leitura de números reais de um arquivo, armazenamento em vetor, remoção de números negativos e impressão dos restantes em ordem crescente.

### Vetores
Leitura de um conjunto de números de um arquivo e cálculo da média e desvio padrão.

## Framework de Testes

O Doctest é um framework de testes para C++ que se destaca pela simplicidade e ausência de dependências. Suas características incluem:

- **Simplicidade e Leveza:** Implementação em uma única unidade de cabeçalho.
- **Expressividade nos Testes:** Macros intuitivas para criar casos de teste.
- **Sem Dependências Externas:** Facilita a integração em projetos.
- **Testes Inline:** Definição de casos de teste no local de uso.
- **Saída Rica em Informações:** Geração de saída detalhada em caso de falha.
- **Suporte a Fixtures:** Configuração e limpeza de estados antes e depois dos testes.
- **Compatibilidade com Outros Frameworks:** Facilita a transição de projetos existentes.
- **Autodetecção:** Detecta automaticamente os casos de teste na compilação.

---

Este projeto visa proporcionar uma experiência de ensino e aprendizado mais eficiente e prática, utilizando a automação para corrigir exercícios de programação e oferecendo feedback imediato aos alunos.


<p align="center"><img src="https://github.com/doctest/doctest/blob/master/scripts/data/logo/logo_1.svg"></p>

<b>
<table>
    <tr>
        <td>
            master branch
        </td>
        <td>
            <a href="https://github.com/doctest/doctest/actions?query=branch%3Amaster"><img src="https://github.com/doctest/doctest/workflows/CI/badge.svg?branch=master"></a>
        </td>
        <td>
            <a href="https://app.codecov.io/gh/doctest/doctest/branch/master"><img src="https://codecov.io/gh/doctest/doctest/branch/master/graph/badge.svg?token=fAdZl67WN7"/></a>
        </td>
    </tr>
    <tr>
        <td>
            dev branch
        </td>
        <td>
            <a href="https://github.com/doctest/doctest/actions?query=branch%3Adev"><img src="https://github.com/doctest/doctest/workflows/CI/badge.svg?branch=dev"></a>
        </td>
        <td>
            <a href="https://app.codecov.io/gh/doctest/doctest/branch/dev"><img src="https://codecov.io/gh/doctest/doctest/branch/dev/graph/badge.svg?token=fAdZl67WN7"/></a>
        </td>
    </tr>
</table>
</b>

**doctest** is a new C++ testing framework but is by far the fastest both in compile times (by [**orders of magnitude**](doc/markdown/benchmarks.md)) and runtime compared to other feature-rich alternatives. It brings the ability of compiled languages such as [**D**](https://dlang.org/spec/unittest.html) / [**Rust**](https://doc.rust-lang.org/book/second-edition/ch11-00-testing.html) / [**Nim**](https://nim-lang.org/docs/unittest.html) to have tests written directly in the production code thanks to a fast, transparent and flexible test runner with a clean interface.

[![Standard](https://img.shields.io/badge/c%2B%2B-11/14/17/20-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![download](https://img.shields.io/badge/download%20%20-link-blue.svg)](https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/503/badge)](https://bestpractices.coreinfrastructure.org/projects/503)
[![Chat - Discord](https://img.shields.io/badge/chat-Discord-blue.svg)](https://discord.gg/PGXn9YmyF3)
[![Try it online](https://img.shields.io/badge/try%20it-online-orange.svg)](https://godbolt.org/z/4s389Kbfs)
<!--
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![documentation](https://img.shields.io/badge/documentation%20%20-online-blue.svg)](https://github.com/doctest/doctest/blob/master/doc/markdown/readme.md#reference)
-->

The framework is and will stay free but needs your support to sustain its development. There are lots of <a href="https://github.com/doctest/doctest/issues/600"><b>new features</b></a> and maintenance to do. If you work for a company using **doctest** or have the means to do so, please consider financial support.

## Description

[Doctest](https://github.com/doctest/doctest) C++ testing framework repository.
