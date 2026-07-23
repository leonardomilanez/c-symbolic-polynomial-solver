#include "polinomios.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  setlocale(LC_ALL, "Portuguese");

  //Recebe qual será o arquivo com os coeficientes do primeiro polinômio, imprime na tela seu valor para um dado 'x' que o usuário inserirá e deriva o polinômio.
  printf("Insira o nome do arquivo do primeiro polinômio: ");
  char nome_pasta[100];
  scanf("%99s", nome_pasta);
  polinomio p = read_polinomio(nome_pasta);
  printf("O primeiro polinômio é:\n");
  printf("p(x) = ");
  print_polinomio(p);
  printf("\nInsira um valor, de x, para calcular o valor do primeiro polinômio: ");
  float x;
  scanf("%f", &x);
  printf("\nO valor do primeiro polinômio é:\n");
  printf("p(%f) = %f", x, valor_polinomio(p, x));
  printf("\nA derivada do primeiro polinômio é:\n");
  polinomio p_derivado = deriva_polinomio(p);
  printf("p'(x) = ");
  print_polinomio(p_derivado);
  free_polinomio(&p_derivado);
  
  //Recebe qual será o arquivo com os coeficientes do segundo polinômio, imprime na tela seu valor para um dado 'x' que o usuário inserirá e deriva o polinômio.
  printf("\nInsira o nome do arquivo do segundo polinômio: ");
  char nome_pasta2[100];
  scanf(" %99s", nome_pasta2);
  polinomio q = read_polinomio(nome_pasta2);
  printf("O segundo polinômio é: \n");
  printf("q(x) = ");
  print_polinomio(q);
  printf("\nInsira um valor, de x, para calcular o valor do segundo polinômio: ");
  scanf("%f", &x);
  printf("\nO valor do segundo polinômio é:\n");
  printf("q(%f) = %f", x, valor_polinomio(q, x));
  printf("\nA derivada do segundo polinômio é:\n");
  polinomio q_derivado = deriva_polinomio(q);
  printf("q'(x) = ");
  print_polinomio(q_derivado);
  free_polinomio(&q_derivado);

  //Imprime os resultados das operações de: soma, subtração e produto dos polinômios. Recebe um intervalo de integração do usuário, imprime na tela a integral definida nesse intervalo desses polinômios e imprime na tela uma raiz para o polinômio após receber os parâmetros, do usuário, para o método Newton-Raphson.

  printf("\nA soma dos polinômios é:\n");
  polinomio soma = soma_polinomios(p, q);
  printf("soma(x) = ");
  print_polinomio(soma);
  free_polinomio(&soma);

  printf("\nA subtração dos polinômios é:\n");
  polinomio sub = subtracao_polinomios(p, q);
  printf("sub(x) = ");
  print_polinomio(sub);
  free_polinomio(&sub);

  printf("\nO produto dos polinômios é:\n");
  polinomio prod = produto_polinomios(p, q);
  printf("prd(x) = ");
  print_polinomio(prod);
  free_polinomio(&prod);

  printf("\nInsira os valores dos limites de integração para primeiro polinômio: ");
  float a1, b1;
  scanf(" %f %f", &a1, &b1);
  printf("\nA integral do primeiro polinômio, nesse intervalo, é: ");
  float integral1 = integral_def(p, a1, b1);
  printf("%f ", integral1);
  
  printf("\nInsira os limites de integração para o segundo polinômio: ");
  float a2, b2;
  scanf("%f %f", &a2, &b2);
  printf("\nA integral do segundo polinômio, nesse intervalo, é: ");
  float integral2 = integral_def(q, a2, b2);
  printf("%f ", integral2);

  printf("\nInsira agora os parâmetros para o método Newton-Raphson:\n");
  printf("\nInsira um valor inicial para x: ");
  float x0;
  scanf(" %f", &x0);
  printf("\nInsira um valor para a precisão numérica de epsilon: ");
  float epsilon;
  scanf(" %f", &epsilon);
  printf("\nInsira um valor para o número máximo de iterações: ");
  int max_iteracoes;
  scanf("%d", &max_iteracoes);
  printf("\nUma raiz do primeiro polinômio é, aproximadamente: ");
  float raiz1 = new_rap(p, x0, epsilon, max_iteracoes);
  printf("%f", raiz1);
  printf("\nUma raiz do segundo polinômio é, aproximadamente: ");
  float raiz2 = new_rap(q, x0, epsilon, max_iteracoes);
  printf("%f", raiz2);
  
  return 0;

}
