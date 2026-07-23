#include <stdbool.h>
#include <stdio.h>
typedef struct {

  float *coeficiente; //Ponteiro para alocação dos coeficientes
  int grau; //Variável que armazena o grau dos polinômios
} polinomio;

int main(void);

// Funções básicas do struct
polinomio new_polinomio(int grau);
polinomio read_polinomio(char *filename);
void free_polinomio(polinomio *p);
bool polinomio_is_null(polinomio p);
float valor_polinomio(polinomio p, float x);
void print_polinomio(polinomio p);

// Operações básicas entre polinômios
polinomio compara_grau(polinomio p, polinomio q);
polinomio soma_polinomios(polinomio p, polinomio q);
polinomio subtracao_polinomios(polinomio p, polinomio q);
polinomio produto_polinomios(polinomio p, polinomio q);

//Diferenciação e integração de um polinômio
polinomio deriva_polinomio(polinomio p);
polinomio integral_indef(polinomio p, float c);
float integral_def(polinomio r, float a, float b);

//Newton-Raphson
float new_rap(polinomio p, float x0, float epsilon, int t_max);