# Biblioteca de Manipulação Simbólica de Polinômios em C

> Sistema em C para representação, operações algébricas simbólicas, cálculo e aproximação numérica de raízes de polinômios.

---

## Sobre o Projeto

Este projeto consiste em uma biblioteca em linguagem C desenvolvida para a disciplina de **Algoritmos e Técnicas de Programação 2**. O objetivo principal é realizar **operações algébricas em nível simbólico** em polinômios (como derivação e integração), em oposição a simples cálculos numéricos, aproximando-se do comportamento de ferramentas como o *WolframAlpha*.

A estrutura base do projeto utiliza `struct` para armazenar o grau e o vetor de coeficientes do polinômio, associada ao gerenciamento dinâmico de memória.

---

## Funcionalidades

- **Gerenciamento de Memória e I/O:**
  - Alocação e liberação dinâmica de memória para coeficientes.
  - Leitura e manipulação de coeficientes a partir de arquivos de texto.
  - Impressão formatada dos polinômios no terminal.

- **Operações Algébricas (Simbólicas):**
  - Avaliação do polinômio p(x) para um dado valor z.
  - Soma e Subtração entre polinômios de graus distintos.
  - Multiplicação/Produto entre polinômios.

- **Cálculo Diferencial e Integral:**
  - **Derivada Simbólica:** Retorna o polinômio resultante da derivada p'(x).
  - **Integral Indefinida:** Retorna o polinômio resultante com constante de integração C.
  - **Integral Definida:** Calcula a área sob a curva para limites [x_0, x_1] reutilizando a função de integral indefinida.

- **Métodos Numéricos:**
  - **Método de Newton-Raphson:** Algoritmo iterativo para estimar raízes reais com critérios de parada por tolerância (ε) ou limite de iterações (t_max).
  - Tratamento contra erros de divisão por zero.

---

## Tecnologias Utilizadas

- **Linguagem:** C 
- **Compilador:** GCC
- **Conceitos Chave:** `struct`, Alocação Dinâmica (`malloc`, `free`), Ponteiros, Manipulação de Arquivos (`FILE*`), Métodos Numéricos.

---

## Autor                                                         

Desenvolvido por Leonardo Milanez da Cunha Prado durante o curso de Ciências da Computação, contato: leonardocunhaprado@gmail.com                                          
