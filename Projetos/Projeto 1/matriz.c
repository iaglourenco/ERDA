//matriz.c
// Projeto 1 matrizes
// Iago Lourenço 15610116
// Bruno Camilo 16080293
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "matriz.h"

struct no
{
  char nome[50];
  int m,n;
  float **Matriz;
  NO *prox;
};

float **alocarMatriz(int m, int n)
{
  int i=0, j=0;
  float **ptM;

  if(m <= 50 && n <= 50)
  {
    ptM = malloc(m *sizeof(float *));

    for (i = 0; i < m; i++) {
      /* code */
      ptM[i]= malloc(n *sizeof(float));
    }
    return ptM;
  }
}

void atribuiElemento(NO **lista,int linha,int coluna,float valor){

  NO *aux;
  aux= *lista;
  aux->Matriz[linha][coluna] = valor;

}

void atribuiElementoLinha(NO **lista,int linha,int totalcoluna,float vl[]){

  int j;
  NO *aux;
  aux = *lista;
  for(j=0;j<totalcoluna;j++){
  aux->Matriz[linha][j] = vl[j];
  }

}

void atribuiElementoColuna(NO **lista,int coluna,int totallinha,float vl[]){

  int i;
  NO *aux;
  aux = *lista;
  for(i=0;i<totallinha;i++){
  aux->Matriz[i][coluna] = vl[i];
  }
}
                  //elemento  ||a lista
float **transporMatriz(NO *l1,int **l,int **c){

  (*l)=l1->m;
  (*c)=l1->n;
  float **ptM=alocarMatriz(l1->m,l1->n);

  int i=0,j=0;
  int mcadastrada = 0;
  for(i=0;i<l1->n;i++){
    for(j=0;j<l1->m;j++){
      ptM[i][j] = l1->Matriz[j][i]; //transpoe a matriz e poe em ptM
    }
  }
  return ptM;
}

float **somaMatriz(NO *l1,NO *l2,int **l,int **c){

  (*l)=l1->m;
  (*c)=l1->n;
  float **ptM=alocarMatriz(l1->m,l1->n);

  int i=0,j=0;
  int mcadastrada = 0;
  for(i=0;i<l1->n;i++){
    for(j=0;j<l1->m;j++){
      ptM[i][j] = l1->Matriz[i][j] + l2->Matriz[i][j]; //soma as matrizes e poe em ptM
    }
  }

  return ptM;
}
float **divideElemento(NO *l1, NO *l2,int **l, int **c){
  (*l)=l1->m;
  (*c)=l1->n;
  float **ptM=alocarMatriz(l1->m,l1->n);

  int i=0,j=0;
  int mcadastrada = 0;
  for(i=0;i<l1->n;i++){
    for(j=0;j<l1->m;j++){
      ptM[i][j] = l1->Matriz[i][j] / l2->Matriz[i][j]; //soma as matrizes e poe em ptM
    }
  }

  return ptM;
}
float **multiplicaMatriz(NO *l1, NO *l2,int **l, int **c){

  (*l)=l1->m;
  (*c)=l1->n;
  float **ptM=alocarMatriz(l1->m,l1->n);

  int i=0,j=0,k=0,soma=0;
  for(j=0;j<l1->m;j++){
    for(i=0;i<l1->n;i++){
      for(k=0;k<l2->m;k++){

        soma += l1->Matriz[i][k] * l2->Matriz[k][j]; //soma as matrizes e poe em ptM

      }
       ptM[i][j] = soma;
       soma=0;
    }
  }

  return ptM;

}
float **multiplicaElemento(NO *l1, NO *l2,int **l, int **c){

  (*l)=l1->m;
  (*c)=l1->n;
  float **ptM=alocarMatriz(l1->m,l1->n);

  int i=0,j=0;
  int mcadastrada = 0;
  for(i=0;i<l1->n;i++){
    for(j=0;j<l1->m;j++){
      ptM[i][j] = l1->Matriz[i][j] * l2->Matriz[i][j]; //soma as matrizes e poe em ptM
    }
  }

  return ptM;
}
