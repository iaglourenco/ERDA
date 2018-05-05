//lista.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"

struct no
{
  char nome[50];
  int m, n;
  float **Matriz;
  NO *prox;
};

void criaVazia(NO **lista)
{
  *lista = NULL;
}

int inserirMatriz(NO **lista, float **ptM, char nome[], int m , int n)
{
  int cadMatriz = 0, i=0, j=0;
  NO *aux, *aux2, *insere;

  aux2 = *lista;

  while (aux2) {
    /* code */
    if (strcmp(aux2->nome, nome)==0) {
      /* code */
      cadMatriz = 1;
      break;
    }
    aux2 = aux2->prox;
  }
  if (cadMatriz == 1|| m > 50 || n > 50 || m < 1 || n < 1) {
    /* code */
    return 0;
  }
  else{
    /* code */
    insere = (NO *)malloc(sizeof(NO));
    strcpy(insere->nome, nome);
    insere->m = m;
    insere->n=n;
    insere->Matriz =  (float **)ptM;
    insere->prox = NULL;

    if (*lista) {
      /* code */
      aux = *lista;

      while (aux->prox) {
        /* code */
        aux = aux->prox;
      }
      aux->prox = insere;
    }
    else
    {
      *lista = insere;
    }
    return 1;
  }
}

int destruirMatriz(NO **lista, char nome[])
{
  NO *aux, *aux2=NULL;
  aux = *lista;
  int validar=0;

  if (aux != NULL) {
    /* code */
    while (aux) {
      /* code */
      if (strcmp(aux->nome, nome)==0) {
        /* code */
        validar=1;
        break;
      }
      aux2 = aux;
      aux = aux->prox;
    }
  }
  else
  {
    return(0);
  }

  if (validar == 1) {
    /* code */
    if (!aux2) {
      /* code */
      *lista = aux->prox;
      free(aux);
    }
    else
    {
      aux2->prox = aux->prox;
      free(aux);
    }
    return(1);
  }
  else
  {
    return(0);
  }
}

void imprimirMatriz(NO *lista, char nome[])
{
  int i, j, cadMatriz = 1;
  float **ptMatriz;

  while (lista) {
    /* code */
    if (strcmp(lista->nome, nome)==0) {
      /* code */
      cadMatriz = 0;
      break;
    }
    else{
      lista = lista->prox;
    }
  }

  if (cadMatriz == 0) {
    /* code */
    for (i = 0; i < lista->m; i++) {
      /* code */
      for (j = 0; j < lista->n; j++) {
        /* code */
        printf("%8.2f", lista->Matriz[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
  else
  {
    printf("ERRO\n");
  }
}

int validaAtribui(NO *lista,char nome[],int *m,int *n,int linha,int coluna){

  int elecadastrado =0,i,j;
  NO *aux;
  aux = lista;
  while(aux){

    if(strcmp(aux->nome,nome)==0){
      elecadastrado =1;
      break;
    }
    aux = aux->prox;
  }
  if(elecadastrado == 1){
    for(i=0;i<aux->m;i++){
      for(j=0;j<aux->n;j++){
        if(i == linha && j == coluna){
          *m =aux->m;
          *n=aux->n;
          return 1;
        }

      }
    }
    return 0;
  }


}

int validaAtribuiLinha(NO *lista,char nome[],int *m,int *n,int linha,int totalcoluna){

  int elecadastrado =0,i,j;
  NO *aux;
  aux = lista;
  if(totalcoluna == 0)
  {
    return 0;
  }
  while(aux){

    if(strcmp(aux->nome,nome)==0){
      elecadastrado =1;
      break;
    }
    aux = aux->prox;
  }
  if(elecadastrado == 1){

    if( totalcoluna > aux->n || linha > (aux->m)-1){
      return 0;
    }
        *m=aux->m;
        *n=aux->n;
        return 1;

  }else return 0;

}
int validaAtribuiColuna(NO *lista,char nome[],int *m,int *n,int coluna,int totallinha){

  int elecadastrado=0,i,j;
  NO *aux;
  aux = lista;
  if(totallinha == 0){
    return 0;
}
  while(aux){

    if(strcmp(aux->nome,nome)==0){
      elecadastrado =1;
      break;
    }
    aux = aux->prox;
  }
  if(elecadastrado == 1){

    if( totallinha > aux->m || coluna > (aux->n)-1){
      return 0;
    }
        *m=aux->m;
        *n=aux->n;
        return 1;



  }else return 0;

}
int validaTranspoe(NO *lista,char nome[],char nomeRes[]){
  NO *orig;
  int achei1,achei2;
    while(lista){
      if(strcmp(nome,lista->nome)==0){
        achei1 = 1;
        orig=lista;
        break;
      }
      lista=lista->prox;
    }

    while(lista){
      if(strcmp(nomeRes,lista->nome)==0){
        achei2 = 1;
        break;
      }
      lista=lista->prox;
    }

    if(achei1 == 1 && achei2 !=1){
      return 1;
    }else{
      return 0;
    }
}

int validaSoma(NO *lista,char nome[],char nome2[],char nomeRes[]){

  NO *m1,*m2;
  int achei1=0,achei2=0,achei3=0;
  while(lista){
    if(strcmp(nome,lista->nome)==0){  //nome1
      achei1 = 1;
      m1=lista;
      break;
    }
    lista=lista->prox;
  }

  while(lista){
    if(strcmp(nome2,lista->nome)==0){ //nome2
      achei2 = 1;
      m2=lista;
      break;
    }
    lista=lista->prox;
  }

  while(lista){
    if(strcmp(nomeRes,lista->nome)==0){ //resultado
      achei3 = 1;
      break;
    }
    lista=lista->prox;
  }

  if(achei1 == 0 || achei2 == 0 || achei3 == 1)return 0;

  if(m1->m != m2->m || m1->n != m2->n) return 0;

  return 1;
}
int validaDiv1(NO *lista,char nome[],char nome2[],char nomeRes[]){

  NO *m1,*m2;
  int achei1=0,achei2=0,achei3=0;
  while(lista){
    if(strcmp(nome,lista->nome)==0){  //nome1
      achei1 = 1;
      m1=lista;
      break;
    }
    lista=lista->prox;
  }

  while(lista){
    if(strcmp(nome2,lista->nome)==0){ //nome2
      achei2 = 1;
      m2=lista;
      break;
    }
    lista=lista->prox;
  }

  while(lista){
    if(strcmp(nomeRes,lista->nome)==0){ //resultado
      achei3 = 1;
      break;
    }
    lista=lista->prox;
  }


  for(int i=0;i<m2->m;i++){
    for(int j=0;j<m2->n;j++){
        if(m2->Matriz[i][j] == 0)return 0;
    }
  }

  if(achei1 == 0 || achei2 == 0 || achei3 == 1)return 0;

  if(m1->m != m2->m || m1->n != m2->n) return 0;

  return 1;
}
int validaMult1(NO *lista,char nome[],char nome2[],char nomeRes[]){

  NO *m1,*m2;
  int achei1=0,achei2=0,achei3=0;
  while(lista){
    if(strcmp(nome,lista->nome)==0){  //nome1
      achei1 = 1;
      m1=lista;
      break;
    }
    lista=lista->prox;
  }

  while(lista){
    if(strcmp(nome2,lista->nome)==0){ //nome2
      achei2 = 1;
      m2=lista;
      break;
    }
    lista=lista->prox;
  }

  while(lista){
    if(strcmp(nomeRes,lista->nome)==0){ //resultado
      achei3 = 1;
      break;
    }
    lista=lista->prox;
  }

  if(achei1 == 0 || achei2 == 0 || achei3 == 1)return 0;

  if(m1->m != m2->m || m1->n != m2->n) return 0;

  return 1;
}

void buscaMatriz( NO *lista, NO **lista2,char nome[]){

  while(lista){

    if(strcmp(lista->nome,nome)==0){
      *lista2 = lista;
      break;
    }
    lista = lista->prox;
  }

}
