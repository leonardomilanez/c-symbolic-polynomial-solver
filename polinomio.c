#include "polinomios.h"
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função que aloca espaço na memória para um polinômio
polinomio new_polinomio(int grau){

  polinomio p;
  p.grau = grau;
  p.coeficiente = (float *)malloc((grau+1)*sizeof(float));
  return p;
  
}

//Função que libera espaço na memória
void free_polinomio(polinomio *p) {

  if (p->coeficiente != NULL) {

    free(p->coeficiente);
    p->coeficiente = NULL;
  }
}

//Função que checa se um polinômio é nulo (ou não)
bool polinomio_is_null(polinomio p) {

  if (p.coeficiente == NULL) {
    return true;
  }

  return false;
}

//Função que lê os coeficientes de um dos arquivos 'polinomiox.txt'
polinomio read_polinomio(char *filename) {


  //Lê o arquivo
  FILE *file = fopen(filename, "r");

  //Cria um polinômio, a princípio nulo
  polinomio p = new_polinomio(0);

  //Checa se o arquivo foi aberto corretamente
  if(file == NULL){

  printf("Arquivo não encontrado. Por favor, tente inserir 'polinomio1.txt', 'polinomio2.txt' ou 'polinomio3.txt'\n");
    main();

  }

  else{

    //Libera espaço na memórmia do polinômio, até então nulo
    free_polinomio(&p);
    
    //Cria variáveis auxiliares
    char ch;
    int count = 0;

    //Lê o arquivo, linha por linha, e armazena o grau do polinômio baseando-se no número de linhas
    while (!feof(file)) {

      fscanf(file, "%c", &ch);
      
      if (ch != '\n') {
        
        if(ch == '-'){
          
          count = count;
          
        }
          
        else{
          
          count++;
          p.grau = count;

        }

      }

    }
    
    //Aloca espaço para 'p', agora com seu tamanho baseado em seu grau.
    p = new_polinomio(p.grau);
    rewind(file);

    //Lê o arquivo, linha por linha, e armazena os coeficientes em 'p.coeficiente[i]' (se p.grau != 0)
    if (p.grau != 0) {
      
      for (int i = 0; i < count; i++) {
        
        fscanf(file, "%f", &p.coeficiente[i]);
        
      }
      
      fclose(file);
      return p;
      
    } 
    
    else {
      
      printf("O polinômio é NULL.\n");
      
    }
    
  }
  
  fclose(file);
  return p;
  
}

//Função que imprime um polinômio na tela
void print_polinomio(polinomio p) {
  
  //Checa se o polinômio é não-nulo
  if (!polinomio_is_null(p)) {

    //Laço de repetição que imprime o polinômio na tela
    for (int i = 0; i < p.grau; i++) {

      if (i == 0) {

      printf("%f", p.coeficiente[i]);

      }

      if (p.coeficiente[i] != 0 && i != 0) {

        printf("+(%f)x^%d", p.coeficiente[i], i);

      }

    }

  }

  else{

    printf("Polinômio é NULL");

  }

}

