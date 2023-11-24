## Informações do projeto

EasyTesting

Este projeto é formando por um cojunto de listas de exercícios de linguagens de programação que são corrigidas automaticamente por testes de unidade. Idealizado e iniciado pelo professor Natã Goulart da Silva durante sua pós graduação, orientado pelo professor Thiago Ferreira de Noronha e desenvolvido pelo aluno Rafael Oliveira Prado Nascimento em sua graduação.

(i) Do que se trata:
O ensino de linguagens de programação de computadores, em todos os seus níveis, exige dos alunos a resolução de um grande número de exercícios, a fim de que eles desenvolvam o raciocínio lógico sequencial necessário para solucionar problemas computacionais. A correção destes exercícios demanda muito tempo dos professores e dos monitores das disciplinas. Com o crescimento do número de alunos nas disciplinas de ensino de programação, a correção manual de todos exercícios se tornará impraticável.
Nesse contexto a aplicação EasyTesting foi criada com o intuito de:
    • Economia de Recursos: A automação da correção economiza recursos financeiros e reduz a carga de trabalho dos professores e monitores, permitindo que se concentrem em dúvidas mais complexas apresentadas pelos alunos.
    • Melhorias no Aprendizado: A correção automática proporciona feedback imediato aos alunos, acelerando seu aprendizado e ajudando-os a desenvolver habilidades de programação.
    • Padronização e Boas Práticas: O projeto introduz os alunos desde o início de sua formação às boas práticas de programação, preparando-os melhor para o mercado de trabalho.

(ii) Qual a metodologia empregada:
Neste projeto são utilizadas listas de exercícios com enunciados construídos de acordo com a ementa da disciplina. Serão disponibilizados para cada lista arquivos com: 
    - As codificações das interfaces dos métodos utilizados para resolver as questões da lista. 
    - A biblioteca do framework de testes Doctest (2014). 
    - Vários testes codificados para cada uma das questões da lista.

(iii) Quais as listas de exercício disponíveis:
Estruturas de Dados Heterogêneas - Registros
Complexo Euclidiano
Complexo Polar
Condicionais
Listas Encadeadas - Deque
Funções
Iteração
Listas Encadeadas - Lista
Matrizes
Conjuntos Associativos - Arvore Binária de busca
Multiconjuntos Associativos - Arvore Binária de busca
Conjuntos - Árvores Binárias de Busca
Conjuntos - Listas Encadeadas
Filas de Prioridade
Listas Encadeadas - Array
Listas Encadeadas - Fila de Banco
Recursividade
Alocacão Dinâmica - Pilha
Alocacão Dinâmica - Listas Encadeadas
Conjunto Associativo - Hash
Multiconjuntos Associativos - Tabela de Dispersão
Conjuntos - Hash
Alocacão Dinâmica - Vetores Dinâmicos
Vetores


(iv) Qual o conteúdo que é abordado em cada uma delas:

Estruturas de Dados Heterogêneas - Registros
    - Lista sobre Estrutura de dados, Escreva um programa em C++ que gerencia uma agenda persistente, ou seja, cujos dados são armazenados no arquivo 'agenda.txt' e podem ser acessados em várias execuções do programa. A agenda pode conter até 1000 contatos.

Complexo Euclidiano
    - Lista sobre Complexo Euclidiano, Escreva um programa que lê do teclado os coeficientes reais de uma equação de segundo grau e imprime na tela as raízes (possivelmente complexas) desta equação.

Complexo Polar
    - Lista sobre Complexo Polar, escreva um programa para realizar operações matematicas sobre numeros complexos polares.

Condicionais
    - Lista sobre Condicionais, Escreva um programa que:
    (i) Apresenta um menu com as funções que serão implementadas no arquivo condicionais.cpp e condicionais.h
    (ii) Lê o valor dos parâmetros.
    (iii) Exibe o resultado da função.

Listas Encadeadas - Deque
    - Lista sobre Listas Encadeadas - Deque, deve se escrever um programa que gerencia uma fila de eventos com duas prioridades. Eventos de alta prioridade (high) tem precedência sobre eventos de baixa prioridade (low), ou seja, um evento de baixa prioridade só é atendido se não existir nenhum evendo de alta prioridade na fila. Eventos de alta prioridade são atendidos de acordo com um protocolo LIFO (Last In First Out), ou seja, o último evento de alta prioridade que foi inserido na fila é o próximo a ser atendido. Já os eventos de baixa prioridade são atendidos de acordo com um protocolo FIFO (First In First Out), ou seja, os eventos de baixa prioridade são atendidos na ordem em que entraram na fila. O seu programa deve ler de um arquivo (ou do teclado) operações do tipo "in" e "out". No caso de um operação do tipo "in" seu programa deve solicitar o nome e a prioridade do evento e inserir o nome do evento na fila de eventos. No caso de operações "out", o seu programa deve retirar o nome no próximo evento que será atendido e imprimi-lo na tela.

Funções
    - Lista sobre Funções,  Escreva um programa que:
        (i) Apresenta um menu com as funções implementadas nos arquivos: funcoes.cc e funcoes.h
        (ii) lê o valor dos parâmetros.
        (iii) exibe o resultado da função.

Iteração
    - Lista sobre iteração, Escreva um programa que: 
        (i) apresenta um menu com as funções que você programou na questão anterior e após o usuário escolher uma das funções.
        (ii) lê o valor dos parâmetros.
        (iii) exibe o resultado da função.

Listas Encadeadas 
    - Lista sobre Listas Encadeadas, Escreva um programa que lê do  teclado dois número naturais 'x' e 'd' e imprime na tela um numero 'y' que consiste no maior número que pode ser obtido removendo-se 'd' dígitos de 'x'. Por exemplo, para x = 6913274589 e d = 7, tem-se m = 989. Calcule a complexidade assintótica no pior caso do seu programa utilizando vetores e utilizando listas. 'x' pode ter entre 1 e 10^9 dígitos, ou seja, x nao pode ser representado por uma variável 'int'.

Matrizes
    - Lista sobre matrizes, deve-se implementar um programa que lê de um arquivo uma matriz triangular inferior e um vetor que representam um sistema de equações e imprime na tela a solução deste sistema.

Conjuntos Associativos - Arvore Binária de busca
    - Lista sobre conjuntos associativos utilizando Arvore Binária de Busca, deve-se implementar um programa para ler um arquivo contendo apenas palavras, e imprima as palavras em ordem crescente, seguidas do número de ocorrências da palavra no texto.
    
Multiconjuntos Associativos - Arvore Binária de busca
    - Lista sobre multiconjuntos associativos utilizando Arvore Binária de busca, deve-se implementar um programa que leia um arquivo contendo apenas palavras e imprima as palavras seguido do numero de ocorrencias de cada palavra no arquivo.

Conjuntos - Árvores Binárias de Busca
    - Lista sobre Conjuntos - Árvores Binárias de Busca, deve-se implementar um programa que gerencia os fornecedores para compra de peças em uma montadora de carros. As peças são identificadas por números inteiros entre 1 e 100 e os fornecedores são identificados por uma string.

Conjuntos - Listas Encadeadas
    - Lista sobre Conjuntos - Listas Encadeadas, deve-se implementar um programa que gerencia os fornecedores para compra de peças em uma montadora de carros. As peças são identificadas por números inteiros entre 1 e 100 e os fornecedores são identificados por uma string.

Filas de Prioridade
    - Lista sobre Filas de Prioridade - Árvore Binária de Busca, deve-se implementar um programa que ordena elementos de um vetor utilizando uma fila prioritária que utiliza árvore binária de busca.

Listas Encadeadas - Array 
    - Lista sobre Listas Encadeadas - Array, escreva um programa que gerencia uma fila de banco. Ao entrar na fila, o cliente dá seu nome e sua idade. Os clientes são atendidos por ordem de chegada. Entretanto, os clientes com 60 anos ou mais tem prioridade sobre os outros clientes, ou seja, um cliente com menos de 60 anos só é atendido se não houver nenhum cliente com 60 anos ou mais esperando na fila.

Listas Encadeadas - Fila
    - Lista sobre Listas Encadeadas - Fila de Banco, escreva um programa que gerencia uma fila de banco. Ao entrar na fila, o cliente dá seu nome e sua idade. Os clientes são atendidos por ordem de chegada. Entretanto, os clientes com 60 anos ou mais tem prioridade sobre os outros clientes, ou seja, um cliente com menos de 60 anos só é atendido se não houver nenhum cliente com 60 anos ou mais esperando na fila.

Recursividade
    - Lista de exercícios sobre Recusão, Escreva um programa que: 
        (i) Apresenta um menu com as funções que você programou na questão anterior e após o usuário escolher uma das funções.(ii) Lê o valor dos parâmetros. 
        (iii) Exibe o resultado da função.

Alocacão Dinâmica - Pilha
    - Lista de exercícios sobre Alocacão Dinâmica - Pilha,deve-se escrever um programa que: 
        (i) lê de um arquivo uma expressão em notação pré-fixada
        (ii) imprime na tela a mesma expressão em notação infixada totalmente parametrizada. 
        Por exemplo: para o arquivo contendo a expressão "- / + 4 * 3 4 2 1", o programa deve imprimir "( ( ( 4 + ( 3 * 4 ) ) / 2 ) - 1 )".

Alocacão Dinâmica - Lista Encadeada
    - Lista de exercícios sobre Alocacão Dinâmica - Lista Encadeada,deve-se escrever um programa que: 
        (i) lê de um arquivo uma expressão em notação pré-fixada
        (ii) imprime na tela a mesma expressão em notação infixada totalmente parametrizada. 
        Por exemplo: para o arquivo contendo a expressão "- / + 4 * 3 4 2 1", o programa deve imprimir "( ( ( 4 + ( 3 * 4 ) ) / 2 ) - 1 )".

Conjuntos associativos - Hash
    - Lista sobre multiconjuntos associativos, deve-se implementar um programa que leia um arquivo contendo apenas palavras e imprima as apalvras em ordem crescente, utilizando tabela hash.
    

Multiconjuntos Associativos - Tabela de Dispersão
    - Lista sobre multiconjuntos associativos, deve-se implementar um programa que leia um arquivo contendo apenas palavras e imprima as apalvras em ordem crescente, utilizando tabela de dispersão.

Conjuntos Associativos - Hash
    - Lista sobre Conjuntos associativos - Hash, deve-se implementar um programa que gerencia os fornecedores para compra de peças em uma montadora de carros. As peças são identificadas por números inteiros entre 1 e 100 e os fornecedores são identificados por uma string. O sistema deve ler de um arquivo o nome dos fornecedores de peças e a lista das peças que cada fornecedor vende.

Alocacão Dinâmica - Vetores Dinâmicos
    - Lista sobre alocacão dinâmica - vetores dinâmicos, deve-se implementar um programa que lê de um arquivo um conjunto de numeros reais, os armazena e um vetor, remove os numeros negativos e imprime o restante dos numeros ordenados de forma crescente.

Vetores
    - Lista de exercício sobre estruturas de dados homogêneas - Vetores, deve-se implementar um programa que lê um conjunto de numeros em um arquivo e imprime na tela a média e o desvio padrão desse conjunto de numeros.

Framework de testes: 


O doctest é um framework de teste para C++ que se destaca pela sua simplicidade e ausência de dependências.

 - Simplicidade e Leveza:
    O doctest é projetado para ser extremamente simples e leve.
    Sua implementação é uma única unidade de cabeçalho (header-only), facilitando a inclusão nos projetos.

 - Expressividade nos Testes:
    Fornece macros intuitivas e expressivas para criar casos de teste.
    A função CHECK é usada para verificar condições, enquanto INFO é usada para fornecer informações adicionais ao relatar falhas.

 - Não Possui Dependências Externas:
    Não há dependências externas para usar o doctest, o que simplifica a integração em projetos.

 - Testes Inline:
    Os casos de teste podem ser definidos diretamente no local em que são usados, não exigindo uma estrutura de teste separada.

 - Saída Rica em Informações:
    Em caso de falha, o doctest gera uma saída detalhada, incluindo informações sobre o que foi testado, valores reais e esperados, tornando a depuração mais fácil.

 - Suporte a Fixtures:
    Permite o uso de fixtures para configurar e limpar estados antes e depois dos casos de teste.

 - Compatibilidade com Outros Frameworks:
    Projetado para ser compatível com outros frameworks de teste, facilitando a transição de projetos existentes.

 - Autodetecção:
    Detecta automaticamente os casos de teste na compilação, eliminando a necessidade de registrar manualmente os testes.


<p align="center"><img src="scripts/data/logo/logo_1.svg"></p>

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