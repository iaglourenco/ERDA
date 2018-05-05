//main.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "matriz.h"
#include "lista.h"


int main()
{
  char op[5], nome[50],nome2[50],nomeRes[50],valorn[50][50];
  int m, n,result=0,linha,coluna,i;
  float **ptM,valor,vln[50];
  NO *lista,*l1,*l2;
  int *l,*c;

  criaVazia(&lista);
  do {
    /* code */
    int i=0;

    scanf("%s", op);

    if(strcmp(op, "CM")==0)//criar matriz
    {
      scanf(" %s", nome);
      scanf(" %i %i", &m, &n);
      if(m > 0 || n > 0){
        ptM = alocarMatriz(m, n);
        result = inserirMatriz(&lista, ptM, nome, m, n);

    }
      if (result == 1) {
        /* code */
        printf("OK\n");
      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "DM")==0)//destruir matriz
    {

      scanf(" %s",nome);
      result = destruirMatriz(&lista,nome);

      if (result == 1) {
        /* code */
        printf("OK\n");
      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "IM")==0)//imprimir matriz
    {

      scanf(" %s",nome);
      imprimirMatriz(lista,nome);

    }
    else if(strcmp(op, "AE")==0)//atribuir um elemento a matriz
    {

      scanf(" %s",nome);
      scanf(" %d %d %f",&linha,&coluna,&valor);
        if(m > 0 || n > 0){
          linha--;
          coluna--;
          result=validaAtribui(lista,nome,&m,&n,linha,coluna);

    }
      if (result == 1) {
        /* code */
        buscaMatriz(lista,&l1,nome);
        atribuiElemento(&l1,linha,coluna,valor);
        printf("OK\n");
      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "AL")==0)//atribuir uma linha a matriz
    {

      scanf(" %s",nome);
      scanf(" %d",&linha);
      while(i != 51){
        scanf(" %s",valorn[i]);
        if(strcmp(valorn[i],"#") == 0) break; // se pegar # para
        vln[i] = atof(valorn[i]); //converte pra float
        i++;
      }
      if(m > 0 || n > 0){
        linha--;
        coluna--;
        result=validaAtribuiLinha(lista,nome,&m,&n,linha,i);
    }
      if (result == 1) {
        /* code */
        buscaMatriz(lista,&l1,nome);
        atribuiElementoLinha(&l1,linha,i,vln);
        printf("OK\n");
      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "AC")==0)//atribuir uma coluna a matriz
    {

      scanf(" %s",nome);
      scanf(" %i",&coluna);
      while(i != 51){
        scanf(" %s",valorn[i]);
        if(strcmp(valorn[i],"#") == 0) break; // se pegar # para
        vln[i] = atof(valorn[i]); //converte pra float
        i++;
      }
      if(m > 0 || n > 0){
        linha--;
        coluna--;
        result=validaAtribuiColuna(lista,nome,&m,&n,coluna,i);
    }
      if (result == 1) {
        /* code */
        buscaMatriz(lista,&l1,nome);
        atribuiElementoColuna(&l1,coluna,i,vln);
        printf("OK\n");
      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "TM")==0)//transpor uma matriz
    {

      scanf(" %s",nome);
      scanf(" %s",nomeRes);

      result=validaTranspoe(lista,nome,nomeRes);
      if (result == 1) {
        /* code */
        buscaMatriz(lista,&l1,nome);
        ptM=transporMatriz(l1,&l,&c);
        inserirMatriz(&lista,ptM,nomeRes,l,c);
        imprimirMatriz(lista,nomeRes);
        printf("\n");
      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "SM")==0)//somar duas matriz
    {
      scanf(" %s",nome);
      scanf(" %s",nome2);
      scanf(" %s",nomeRes);

      result=validaSoma(lista,nome,nome2,nomeRes);
      if (result == 1) {
        /* code */
        buscaMatriz(lista,&l1,nome);
        buscaMatriz(lista,&l2,nome2);
        ptM=somaMatriz(l1,l2,&l,&c);
        inserirMatriz(&lista,ptM,nomeRes,l,c);
        imprimirMatriz(lista,nomeRes);


        printf("\n");
      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "DV")==0)//dividir uma matriz por outra (elemento a elemento)
    {
        scanf(" %s",nome);
        scanf(" %s",nome2);
        scanf(" %s",nomeRes);
        result=validaDiv1(lista,nome,nome2,nomeRes);
      if (result == 1) {
        /* code */
        buscaMatriz(lista,&l1,nome);
        buscaMatriz(lista,&l2,nome2);
        ptM=divideElemento(l1,l2,&l,&c);
        inserirMatriz(&lista,ptM,nomeRes,l,c);
        imprimirMatriz(lista,nomeRes);


        printf("\n");
      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "MM")==0)//multiplicar uma matriz por outra
    {
      scanf("%s",nome);
      scanf("%s",nome2);
      scanf("%s",nomeRes);
      result=validaMult1(lista,nome,nome2,nomeRes);
      if (result == 1) {
        /* code */
        buscaMatriz(lista,&l1,nome);
        buscaMatriz(lista,&l2,nome2);
        ptM=multiplicaMatriz(l1,l2,&l,&c);
        inserirMatriz(&lista,ptM,nomeRes,l,c);
        imprimirMatriz(lista,nomeRes);
      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "ME")==0)//multiplicar uma matriz por outra (elemento a elemento)
    {
      scanf("%s",nome);
      scanf("%s",nome2);
      scanf("%s",nomeRes);
      result=validaMult1(lista,nome,nome2,nomeRes);
      if (result == 1) {
        /* code */
        buscaMatriz(lista,&l1,nome);
        buscaMatriz(lista,&l2,nome2);
        ptM=multiplicaElemento(l1,l2,&l,&c);
        inserirMatriz(&lista,ptM,nomeRes,l,c);
        imprimirMatriz(lista,nomeRes);
        printf("\n");

      }
      else
      {
        printf("ERRO\n");
      }
    }
    else if(strcmp(op, "FE")!=0)//finalizar a execução
    {
      printf("Opcao invalida\n");
    }
  } while(strcmp(op, "FE")!=0);
  return(0);
}
