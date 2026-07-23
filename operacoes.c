#include "polinomios.h"
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Calcula o valor do polinômio para um determinado 'x'
float valor_polinomio(polinomio p, float x){
  
  float resultado = 0;
  
  if(!polinomio_is_null(p)){

    for(int i = 0; i < p.grau; i++){

      resultado += p.coeficiente[i] * pow(x, i);

    }

    return resultado;
  }
  else{
    
    printf("Polinomio é NULL.");
    return 0;
    
  }
  
}
//Deriva o polinômio
polinomio deriva_polinomio(polinomio p) {
  
  //Cria o polinômio 'r' com um grau a menos do que o polinômio 'p'
  polinomio r = new_polinomio(p.grau - 1);
  
  //Checa se 'p' é não nulo
  if (!polinomio_is_null(p)){
    
    //Deriva p e armazena os resultados em 'r.coeficiente[j]'
    for (int i = 1, j = 0; i < p.grau; i++, j++) {

        r.coeficiente[j] = i*p.coeficiente[i];

    }
    
    return r;
  }

  else {

    printf("Polinômio é NULL");
  }

  return r;
  
}

//Função que retorna o polinômio de maior grau entre 2 polinômios
polinomio checa_grau(polinomio p, polinomio q) {

  polinomio r = new_polinomio(0);

  if (p.grau > q.grau || p.grau == q.grau) {

    r = new_polinomio(p.grau);

  }

  else {

    r = new_polinomio(q.grau);
  }

  return r;
}

//Função que calcula o polinômio soma entre 2 polinômios
polinomio soma_polinomios(polinomio p, polinomio q) {
  
  //Criação do polinômio resposta, a princípio nulo
  polinomio r = new_polinomio(0);

  //Se 'p' e 'q' forem não-nulos, realiza-se a soma
  if (!polinomio_is_null(p) && !polinomio_is_null(q)) {

    //Checa qual dos polinômios é maior e armazena seu tamanho em 'r'
    r = checa_grau(p, q);

    //Calcula a soma entre os 2 polinômios e armazena em 'r.coeficiente[i]'
    for (int i = 0; i < r.grau; i++) {

      if(r.grau == p.grau){
        
        r.coeficiente[i] = p.coeficiente[i] + q.coeficiente[i];
        
      }
        
      else{
        
        r.coeficiente[i] = q.coeficiente[i] + p.coeficiente[i];
      
      }
      
    }

    return r;

  }

  else {

    printf("Polinômios são NULL");
  }

  return r;
}

//Função que calcula o polinômio subtração entre 2 polinômios
polinomio subtracao_polinomios(polinomio p, polinomio q) {
  
  //Criação do polinômio resposta, a princípio nulo
  polinomio r = new_polinomio(0);

  //Se 'p' e 'q' forem não-nulos, realiza-se a subtração
  if (!polinomio_is_null(p) && !polinomio_is_null(q)) {

    //Checa qual dos polinômios é maior e armazena seu tamanho em 'r'
    r = checa_grau(p, q);

    //Calcula a subtração entre os 2 polinômios e armazena em 'r.coeficiente[i]
    for (int i = 0; i < r.grau; i++) {

     if(r.grau == p.grau){
       
        r.coeficiente[i] = p.coeficiente[i] - q.coeficiente[i];
       
     }
      else{
        
         r.coeficiente[i] = q.coeficiente[i] - p.coeficiente[i];
        
      }
    }

    return r;

  }

  else {

    printf("Polinômios são NULL");
  }

  return r;
  
}

//Função que calcula o produto de 2 polinômios
polinomio produto_polinomios(polinomio p, polinomio q){

  //Cria um polinômio resposta, do tamanho dos graus dos 2 fatores - 1
  polinomio r = new_polinomio((p.grau + q.grau)-1);

  //Checa se os polinômios 'p' e 'q' são não-nulos
  if(!polinomio_is_null(p) && !polinomio_is_null(q)){

    //Preenche o vetor de coeficientes com zeros
    for(int i = 0; i < (p.grau + q.grau); i++){
    
      r.coeficiente[i] = 0;
    
    }

    //Multiplica os 2 polinômios, armazenando os resultados em 'r.coeficiente[i + j]'
    for(int i = 0; i <= p.grau; i++){
      
      for(int j = 0; j <= q.grau; j++ ){
        
        r.coeficiente[i + j] += p.coeficiente[i] * q.coeficiente[j];
        
      }
      
    }
  
    return r;
  
  }

  else{
    
    printf("Os polinômios são NULL.");
  
  }

  return r;
  
}

//Função que integra um polinômio
polinomio integral_indef(polinomio p, float c){


  //Cria um polinômio resposta, do tamanho do polinômio p + 1
  polinomio r = new_polinomio(p.grau + 1);
  
  //Checa se 'p' é não-nulo
  if(!polinomio_is_null(p)){

    //Integra o polinômio, é importante notar que uma integral indefinida é sempre acomanhada de uma constante 'c', que fora armazenada no espaço '0' de r.coeficiente
    for(int i = 0; i < p.grau; i++){

      r.coeficiente[i+1] = p.coeficiente[i]/(i + 1);

    }

    r.coeficiente[0] = c;

    return r;
    
  }
    
  else{
    
    printf("Polinômio é NULL.");
  
  }
  
  return r;
  
}

//Calcula a integral definida em um certo intervalo [a, b] dado pelo usuário
float integral_def(polinomio p, float a, float b){

  //Cria as variáveis 'lim_inf' e 'lim_sup', que serão utilizadas no cálculo do 1° Teorema Fundamental do Cálculo. Além da variável 'integral', que armazenará os resultados do teorema e retornará um valor
  float lim_inf = 0, lim_sup = 0, integral = 0;

  //Cria um polinômio resposta com o tamanho do polinômio original (p) + 1
  polinomio r = new_polinomio(p.grau + 1);

  //r recebe a integral indefinida do polinômio 'p'
  r = integral_indef(p, b);

  //Checa se o polinômio 'p' é não-nulo
  if(!polinomio_is_null(p)){

    //Calcula a integral definida do polinômio 'p' em [a, b]
    for(int i = 0; i < p.grau; i++){
    
      lim_inf = lim_inf + (r.coeficiente[i+1] * pow(a, i+ 1));
      lim_sup = lim_sup + (r.coeficiente[i+1] * pow(b, i+1));
    
    }

    //Integral recebe a subtração de lim_sup e lim_inf
    integral = lim_sup - lim_inf;

    return integral;
  }

  else{

    printf("Polinômio é NULL.");
  
  }
  free_polinomio(&r);
  return integral;
  
}

//Função que calcula uma raiz do polinômio pelo método Newton-Rapshon
float new_rap(polinomio p, float x0, float epsilon, int t_max){

  //Cria as variáveis 'raiz', que armazenará uma das raízes do polinômio, e 'p_derivado' que receberá a derivada de 'p'
  float raiz = 0;
  polinomio p_derivado = new_polinomio(p.grau-1);

  //Checa se 'p' é não-nulo
  if(!polinomio_is_null(p)){

    //p_derivado recebe a derivada de 'p'
    p_derivado = deriva_polinomio(p);

    //Calcula a raiz do polinômio 'p' através do método Newton-Rapshon
    for(int i = 0; i <= t_max; i++){

      //Checa se o valor da derivada de p, para um certo valor de 'x', é diferente de 0. Pois, se for, causará uma indeterminação matemática
      if(valor_polinomio(p_derivado, x0) != 0){
        
        raiz = x0 - (valor_polinomio(p, x0)/valor_polinomio(p_derivado, x0));
        
        if(fabs(raiz - x0) < epsilon){

          break;

        }
        
        x0 = raiz;

      }

      else{
        
        printf("\nNão possui raiz real, pois há uma divisão por 0. \n");
        break;
        
      }
    
    }

    return raiz;
  
  }

  else{

    printf("Polinômio é NULL.");
    return 0;
    
  }

}
